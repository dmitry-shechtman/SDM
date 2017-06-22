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
	if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
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
    return 6170;          // 1/2.3"
}

//zoom position is get_parameter_data(87)

// Focus length table in firmware @ 0xfffea1cc
#define NUM_FL      126 // 0 - 125, entries in firmware
#define NUM_DATA    3   // 3 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 5.0       28       ( 28/ 5.0) * 50 = 280  (min FL)
// 70.0      392      (392/70.0) * 50 = 280  (max FL)
#define CF_EFL      280
#define	CF_EFL_DIV  50

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
    return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
}

int get_focal_length(int zp) {
    if (zp < 0) zp = 0;
    else if (zp >= NUM_FL) zp = NUM_FL-1;
    return focus_len_table[zp*NUM_DATA];
}

int get_zoom_x(int zp) {
    return get_focal_length(zp)*10/focus_len_table[0];
}

long get_vbatt_min()
{
	return 3280;  // min observed was 3.408, then it died
}

long get_vbatt_max()
{
	return 4057;  // fresh from change (actual was 4.127)
}
