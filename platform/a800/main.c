#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"

extern long link_bss_start;
extern long link_bss_end;
extern void boot();

long get_sensor_width()
{
 return 6170;          // 1/2.3"
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

// Focus length table in firmware @0xfffe2ee8
#define NUM_FL      7   // 0 - 6, entries in firmware
#define NUM_DATA    3   // 3 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 6.6       37       ( 37/ 6.6) * 66 = 370  (min FL)
// 21.6      122      (122/21.6) * 66 = 372.7  (max FL)
#define CF_EFL      370
#define	CF_EFL_DIV  66

const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp) {
    return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
}

int get_focal_length(int zp) {
    if (zp < 0) zp = 0;
    else if (zp >= NUM_FL) zp = NUM_FL-1;
    return focus_len_table[zp*NUM_DATA];
}

static const int fl_tbl[] = {6600,8060,9840,12050,14800,17550,21600};
static const int fov_tbl[]={50,42,35,29,24,20,16};
static const int mav_tbl[] = {311,332,360,390,425,457,495};  // min Av
static const int xav_tbl[] = {603,624,652,682,717,749,787};  // max Av

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

int get_zoom_x(int zp) 
{
    return get_focal_length(zp)*10/focus_len_table[0];
}

// TODO: is battery v min/max ok?
long get_vbatt_min()
{
    return 2300;
}

long get_vbatt_max()
{
    return 2550;
}

