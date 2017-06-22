#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "stdlib.h"

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

// Focus length table in firmware @0xfffeabd8
#define NUM_FL      128 // 0 - 127, entries in firmware
#define NUM_DATA    2   // 2 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 5.0       28       ( 28/ 5.0) * 50 = 280  (min FL)
// 60.0      336      (336/60.0) * 50 = 280  (max FL)
#define CF_EFL      280
#define	CF_EFL_DIV  50

const int zoom_points = NUM_FL;

#define NUM_DATA    2   // 2 words each entry, first is FL   if necessary after NUM_FL

static const struct {
	int zp, fl,fov;
} fl_tbl[] = {
  {   0,    5000,63},
  {   16,   8225,41},
  {   32,   13080,27},
  {   48,   20270,17},
  {   64,   29150,12},
  {   80,   38125,9},
  {   96,   45750,8},
  {   112,  51650,7},
  {   127,  60000,6}
};

int get_fov(int zp) 
{
    int i;

    if (zp<fl_tbl[0].zp)
        return fl_tbl[0].fov;
    else if (zp>fl_tbl[NUM_FL-1].zp)
        return fl_tbl[NUM_FL-1].fov;
    else 
        for (i=1; i<NUM_FL; ++i) 
         {
           if (zp==fl_tbl[i-1].zp)         // value before current index
               return fl_tbl[i-1].fov;     
           else if (zp==fl_tbl[i].zp)      // value at current index
               return fl_tbl[i].fov;
           else if (zp<fl_tbl[i].zp)      // between before and current values
               return fl_tbl[i-1].fov-(zp-fl_tbl[i-1].zp)*(fl_tbl[i-1].fov-fl_tbl[i].fov)/(fl_tbl[i].zp-fl_tbl[i-1].zp);
        }
    return fl_tbl[NUM_FL-1].fov;
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
    return 2050; // Camera shutdown
}

long get_vbatt_max()
{
    return 2800; // Fully charged eneloops
}

