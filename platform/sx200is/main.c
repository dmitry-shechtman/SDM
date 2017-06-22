#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

long get_sensor_width()
{
    return 6160;          // 1/2.3"
}

void startup()
{
	long *bss = &link_bss_start;
	long *ptr;
	
	// sanity check
	if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
		started();
		shutdown();
	}

	// initialize .bss senment
	while (bss<&link_bss_end)
		*bss++ = 0;

	boot();
}

//zoom position is get_parameter_data(87)
static const struct 
{
	int zp, fl,fov;
} 

fl_tbl[] = 
{
  {   0,   5000,63},
  {  16,   6800,49},
  {  32,   9100,37},
  {  62,  16200,22},
  {  78,  22300,16},
  { 102,  35900,10},
  { 125,  60000,6},
};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))


// Focal length range is 5.0 - 60,0 mm, 27.3 - 327.4 in 35-mm equivalent.
// So, CF_EFL = 27.3/5.0*10000=54600 or327.4/60*10000=54566.6
// diff = 54600 - 54566.6 = 33.3, split it 33.3 / 2 = 16.6
// add to base 54566.6 + 16.6 = 54583.2
// divide by 10 to avoid overflow in get_effective_focal_length()
#define CF_EFL  5458
const int zoom_points = 126;

static const int fov_tbl[]={53,48,44,41,38,32,28,25,22,19,17,14,12,11,9};
static const int mav_tbl[] = {307,307,325,347,367,389,413,443,470,494,518,542,566,590,614};  // min Av
static const int xav_tbl[] = {495,492,510,532,552,574,598,628,655,679,703,727,751,775,799};  // max Av

int get_mav(int zp)
{
 return mav_tbl[zp];
}

int get_xav(int zp)
{
 return xav_tbl[zp];
}

int get_fov(int zp) 
{
    int i;

    if (zp<fl_tbl[0].zp)
        return fl_tbl[0].fov;
    else if (zp>fl_tbl[NUM_FL-1].zp)
        return fl_tbl[NUM_FL-1].fov;
    else 
        for (i=1; i<NUM_FL; ++i) 
         {
           if (zp==fl_tbl[i-1].zp)         // value before current index
               return fl_tbl[i-1].fov;     
           else if (zp==fl_tbl[i].zp)      // value at current index
               return fl_tbl[i].fov;
           else if (zp<fl_tbl[i].zp)      // between before and current values
               return fl_tbl[i-1].fov-(zp-fl_tbl[i-1].zp)*(fl_tbl[i-1].fov-fl_tbl[i].fov)/(fl_tbl[i].zp-fl_tbl[i-1].zp);
        }
    return fl_tbl[NUM_FL-1].fov;
}

int get_effective_focal_length(int zp) {
	return (CF_EFL*get_focal_length(zp))/1000;
}

int get_focal_length(int zp) {
	int i;

	if (zp<fl_tbl[0].zp)
		return fl_tbl[0].fl;
	else if (zp>fl_tbl[NUM_FL-1].zp)
		return fl_tbl[NUM_FL-1].fl;
	else 
		for (i=1; i<NUM_FL; ++i) {
			if (zp==fl_tbl[i-1].zp) 
				return fl_tbl[i-1].fl;
			else if (zp==fl_tbl[i].zp) 
				return fl_tbl[i].fl;
			else if (zp<fl_tbl[i].zp)
				return fl_tbl[i-1].fl+(zp-fl_tbl[i-1].zp)*(fl_tbl[i].fl-fl_tbl[i-1].fl)/(fl_tbl[i].zp-fl_tbl[i-1].zp);
		}
	return fl_tbl[NUM_FL-1].fl;
}

int get_zoom_x(int zp) {
	return get_focal_length(zp)*10/fl_tbl[0].fl;
}

long get_vbatt_min()
{
	return 3280;  // min observed was 3.408, then it died
}

long get_vbatt_max()
{
	return 4057;  // fresh from change (actual was 4.127)
}

