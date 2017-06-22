#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

long get_sensor_width()
{
    return 7490;          // 1/1.7"
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

int screen_opened(void) {
	return !(physw_status[0] & 0x80000000);
}

int screen_rotated(void) {
	return !(physw_status[0] & 0x40000000);
}

// Focus length table in firmware @ FFFE2A80
#define NUM_FL 14		// 0 - 13, entries in firmware (3 words each entry, first is FL)
extern int focus_len_table[NUM_FL*3];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 6.1       28       (28/6.1) * 61 = 280  (min FL)
// 30.5      140      (140/30.5) * 61 = 280  (max FL)
#define CF_EFL 280
#define	CF_EFL_DIV 61

const int zoom_points = NUM_FL;  // OK
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
	return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
}

int get_focal_length(int zp) {
	if (zp < 0) zp = 0;
	else if (zp >= NUM_FL) zp = NUM_FL-1;
	return focus_len_table[zp*3];
}

int get_zoom_x(int zp) {
	return get_focal_length(zp)*10/focus_len_table[0];
}



long get_vbatt_min()
{
	return 6500;
}

long get_vbatt_max()
{
	return 8150;
}

