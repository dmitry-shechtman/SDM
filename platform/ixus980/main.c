#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

long get_sensor_width()
{
    return 7600;  // 1/1.7"
}

void startup()
{
    long *bss = &link_bss_start;
    long *ptr;

    //sanity check (pointless with automemiso)
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
	started();
	shutdown();
    }

    //initialize .bss senment
    while (bss<&link_bss_end)
	*bss++ = 0;


    boot();
}



//from sd950, zoom steps and sensor size same
static const int fl_tbl[] = {7700, 9572, 11454, 13683, 16293, 19548, 23495, 28500};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
//sd950 uses wrong value
//#define CF_EFL 60869
//ewavr
//SD990 focal length range is 7,7 - 28,5 mm, 36 - 133 in 35-mm equivalent.
//So, CF_EFL = 36/7.7*10000=46753 or 133/28.5*10000=46666.
#define CF_EFL 46710 // split the difference

const int zoom_points = NUM_FL;

static const int fov_tbl[]={53,43,37,31,26,22,18,15};
static const int mav_tbl[] = {295,318,342,368,396,427,461,493};  // min Av
static const int xav_tbl[] = {578,601,635,651,679,710,744,776};  // max Av

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

//physw_ bit OK

long get_vbatt_min()
{
    return 3425; //hnikesch on forum
}

long get_vbatt_max()
{
    return 4000; //fresh off charger slightly greater
}
