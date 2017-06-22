#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
 
extern long link_bss_start;
extern long link_bss_end;
extern void boot();

long get_sensor_width()
{
    return 7600;          // 1/1.7"
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
  {   0,   6100,64},
  {   1,   6800,58},
  {   2,   7400,54},
  {   3,   8100,50},
  {   4,   8900,46},
  {   5,   9800,42},
  {   6,   10800,39},
  {   7,   12100,35},
  {   8,   13800,31},
  {   9,   15700,27},
  {  10,   18100,24},
  {  11,   21500,20},
  {  12,   25000,17},
  {  13,   30500,14},
};

#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
// G11 focal lenght range 6.1 - 30.5 mm (35 mm equivalent: 27.8 - 139.1 mm)(1/1.7" Type CCD, Scale Factor To 35 mm Equivalent: 4.6)
// 27,8/6,1*10000=45574
// 139,1/30,5*10000=45607
#define CF_EFL 45900  // based on Canon's spec

const int zoom_points = NUM_FL;

static const int fov_tbl[]={53,48,44,41,38,32,28,25,22,19,17,14,12,11};
static const int mav_tbl[] = {307,307,325,347,367,389,413,443,470,494,518,542,566,590};  // min Av
static const int xav_tbl[] = {495,492,510,532,552,574,598,628,655,679,703,727,751,775};  // max Av

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
 if (zp<0) return fov_tbl[0];
 else if (zp>NUM_FL-1) return fov_tbl[NUM_FL-1];
 else return fov_tbl[zp];
}

int get_effective_focal_length(int zp) {
    return (CF_EFL*get_focal_length(zp))/10000;
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
    return 6600; /* G11 shuts down after reaching 6,6V*/
}

long get_vbatt_max()
{
    return 8100;
}

int screen_opened(void)
{
	if ( physw_status[2] & 0x04000000 )
		 return 1;
	else
		return 0;
}

// 0 not rotated, non-zero rotated
int screen_rotated(void)
{
	if ( physw_status[2] & 0x02000000 )
		 return 1;
	else
		return 0;
}

