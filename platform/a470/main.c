#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"

extern long link_bss_start;
extern long link_bss_end;
extern void boot();

long get_sensor_width()
{
    return 5750;
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



static const int fl_tbl[] = {6300,8100,9800,12100,14800,17600,21600};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 60345

const int zoom_points = NUM_FL;

static const int fov_tbl[]={49,39,33,27,22,19,15};    
static const int mav_tbl[] = {307,333,360,391,426,457,495};  // min Av  Daniel Borland
static const int xav_tbl[] = {586,612,639,670,705,736,774};  // max Av

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




long get_vbatt_min()
{
    return 2300;
}

long get_vbatt_max()
{
    return 2550;
}
