#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

long get_sensor_width()
{
    return 5750;          // 1/2.5"
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

//debug_led(1);
    boot();
}


// from sx100
//fl_tbl still the same as sx100
static const int fl_tbl[] = {6000, 6700, 7300, 8200, 9100, 10300, 11500, 12800, 14400, 16100, 18100, 20100, 22400, 25200, 28100, 31500, 34900, 38900, 42500, 46600, 51100, 55900, 60000};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
//#define CF_EFL 6000
#define CF_EFL 5600		//	1/2.3" as sx10

const int zoom_points = NUM_FL;

static const int fov_tbl[]={51,46,43,39,35,31,28,25,23,20,18,16,15,13,12,10,9,8,8,7,6,6,5};
static const int mav_tbl[] = {328,331,338,349,364,378,390,402,414,427,328,331,338,349,364,378,390,402,414,427,402,414,427};// min Av
static const int xav_tbl[] = {614,617,624,635,650,664,678,688,700,713,614,617,624,635,650,664,678,688,700,713,688,700,713};// max Av

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
	return (CF_EFL*get_focal_length(zp))/1000;
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

//end sx100

long get_vbatt_min()
{
    return 2300;		//from sx100, 4550 in sx10
}

long get_vbatt_max()
{
    return 2550;	//from sx100, 5150 in sx10
}
