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
static const struct {
	int zp, fl,fov;
} fl_tbl[] = {
  {   0,    5000,63},
  {   16,   8225,41},
  {   32,   13080,27},
  {   48,   20270,17},
  {   64,   29150,12},
  {   80,   38125,9},
  {   96,   45750,8},
  {   112,  51650,7},
  {   127,  60000,6}
};


#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))

// SX130 focal length range 5.0 - 60 mm (35 mm equivalent: 28 - 336 mm)(1/2.3" Type CCD, Scale Factor To 35 mm Equivalent: 5.6)
// 28/5.0*10000=56000
// 336/60*10000=56000
#define CF_EFL 56000

const int zoom_points = 128;

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

int get_effective_focal_length(int zp) 
{
    return ((CF_EFL/1000)*get_focal_length(zp))/10;
}

int get_focal_length(int zp) 
{
	int i;

	if (zp<fl_tbl[0].zp)
		return fl_tbl[0].fl;
	else if (zp>fl_tbl[NUM_FL-1].zp)
		return fl_tbl[NUM_FL-1].fl;
	else {
		for (i=1; i<NUM_FL; ++i) 
                {
			if (zp==fl_tbl[i-1].zp)
				return fl_tbl[i-1].fl;
			else if (zp==fl_tbl[i].zp)
				return fl_tbl[i].fl;
			else if (zp<fl_tbl[i].zp)
				return fl_tbl[i-1].fl+(zp-fl_tbl[i-1].zp)*(fl_tbl[i].fl-fl_tbl[i-1].fl)/(fl_tbl[i].zp-fl_tbl[i-1].zp);
		    }
	     }
	return fl_tbl[NUM_FL-1].fl;
}


int get_zoom_x(int zp) {
	return get_focal_length(zp)*10/fl_tbl[0].fl;
}


long get_vbatt_min()
{
    return 2050; // Camera shutdown
}

long get_vbatt_max()
{
    return 2800; // Fully charged eneloops
}

