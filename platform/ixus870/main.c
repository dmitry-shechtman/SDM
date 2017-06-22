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




static const int fl_tbl[] = {5000, 5984, 6935, 8118, 9368, 10797, 12524, 14843, 17174, 19998};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
// Calculation taken from ixus980
// focal length range is 5,0 - 20 mm, 28 - 112 in 35-mm equivalent.
// So, CF_EFL = 28/5,0*10000=56000 or 112/20*10000=56000
#define CF_EFL 56000

const int zoom_points = NUM_FL;

static const int fov_tbl[]={63,54,48,42,36,32,28,23,20,18};
static const int mav_tbl[] = {290,307,325,347,367,389,413,443,470,494};                    // min Av
static const int xav_tbl[] = {475,492,510,532,552,574,598,628,655,679};                    // max Av

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
	return 3265; // observed with osd:
                     // 3320 -> blinking icon 3205
                     // 3205 -> warning and power off
}

long get_vbatt_max()
{
	return 4065; // max seen 4065
}

