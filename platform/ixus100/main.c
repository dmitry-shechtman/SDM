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

   // sanity check (pointless with automemiso)
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
	started();
	shutdown();
    }

    // initialize .bss senment
    while (bss<&link_bss_end)
	*bss++ = 0;

    boot();
}




static const int fl_tbl[] = {5900,7170,8740,10550,12490,14780,17900};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 55932 

const int zoom_points = NUM_FL;

static const int fov_tbl[]={55,46,39,33,28,24,20};
static const int mav_tbl[] = {329,350,376,404,431,460,490};  // min Av
static const int xav_tbl[] = {604,625,651,679,706,735,765};  // max Av

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
    if (zp<0) return fl_tbl[0];
    else if (zp>NUM_FL-1) return fl_tbl[NUM_FL-1];
    else return fl_tbl[zp];
}

int get_zoom_x(int zp) {
    if (zp<1) return 10;
    else if (zp>NUM_FL-1) return fl_tbl[NUM_FL-1]*10/fl_tbl[0];
    else return fl_tbl[zp]*10/fl_tbl[0];
}

/*
physw_ bit OK
*/


//VERIFY_SD780 min observed
long get_vbatt_min()
{
    return 3375; // hnikesch on forum
}

//VERIFY_SD780 max observed
long get_vbatt_max()
{
    return 4125; // fresh off charger slightly greater
}


