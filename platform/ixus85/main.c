#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"

extern long link_bss_start;
extern long link_bss_end;
extern void boot();

void startup()
{
	long *bss = &link_bss_start;
	long *ptr;

	// sanity check
	if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)) {
		started();
		shutdown();
	}

	// initialize .bss senment
	while (bss<&link_bss_end)
		*bss++ = 0;

	boot();
}

long get_sensor_width()
{
 return 5760;
}

// Focus length table in firmware @0xfffe297c
#define NUM_FL      7   // 0 - 6, entries in firmware
#define NUM_DATA    3   // 3 words each entry, first is FL

static const int fl_tbl[] = {6200, 7230, 8295, 9681, 11614, 14303, 18600};

#define CF_EFL 61291

const int zoom_points = NUM_FL;

static const int fov_tbl[]={50,43,39,33,28,23,18};
static const int mav_tbl[] = {292,308,326,348,375,409,449};                    // min Av
static const int xav_tbl[] = {580,596,614,636,663,697,737};                    // max Av

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

#if 0
int rec_switch_state(void) {
// play/rec without override ? This camera has play button, so not clear
//	mode  = (physw_status[1] & 0x00010000) ? MODE_REC : MODE_PLAY;
	return (physw_status[1] & 0x00010000);
}
#endif

long get_vbatt_min()
{
	return 3500;
}

long get_vbatt_max()
{
	return 4100;
}
