#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"

extern long link_bss_start;
extern long link_bss_end;
extern void boot();

long get_sensor_width()
{
    return 6160;
}

void startup()
{
	long *bss = &link_bss_start;
	long *ptr;

	//sanity check
	if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)) {
		started();
		shutdown();
	}

	//initialize .bss segment
	while (bss<&link_bss_end)
		*bss++ = 0;

	boot();
}



static const int fl_tbl[] = {6600, 7800, 9000, 10300, 11900,13500, 15400, 17700, 20400, 23700, 28000, 33000};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 56060

const int zoom_points = NUM_FL;

static const int fov_tbl[]={50,43,38,33,29,26,23,20,17,15.13,11};
static const int mav_tbl[] = {326,340,355,369,383,396,408,422,436,452,471,490};  // min Av  from shooting.c
static const int xav_tbl[] = {601,615,630,644,658,671,683,697,711,727,746,765};  // max Av

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

int get_effective_focal_length(int zp)
{
	return (CF_EFL*get_focal_length(zp))/10000;
}

int get_focal_length(int zp)
{
	if (zp<0) {
		return fl_tbl[0];
	} else if (zp>NUM_FL-1) {
		return fl_tbl[NUM_FL-1];
	} else {
		return fl_tbl[zp];
	}
}

int get_zoom_x(int zp)
{
	if (zp<1) {
		return 10;
	} else if (zp>NUM_FL-1) {
		return fl_tbl[NUM_FL-1]*10/fl_tbl[0];
	} else {
		return fl_tbl[zp]*10/fl_tbl[0];
	}
}


long get_vbatt_min()
{
	return 3500;
}

long get_vbatt_max()
{
	return 4100;
}
