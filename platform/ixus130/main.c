#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "stdlib.h"

//#include "sd1400_debug.h"

extern long link_bss_start;
extern long link_bss_end;
extern void boot();

//#define LED 0xC0220130 // IO, green
//#define DELAY 500000

void startup()
{
    long *bss = &link_bss_start;

    // sanity check (pointless with automemiso)
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
	started();
	shutdown();
    }

    // initialize .bss senment
    while (bss < &link_bss_end)
	*bss++ = 0;

    boot();
}

long get_sensor_width()
{
 return 6170;          // 1/2.3"
}

// Ixus130 Focal length: 5mm-20mm, 35mm equivalent 28mm-112mm, so:
// CF_EFL = 28/5*10000 = 56000 or 112/20*10000 = 56000
static const int fl_tbl[] = { 5000, 6400, 7400, 9000, 11200, 13000, 15600, 20000 };
#define NUM_FL (sizeof fl_tbl / sizeof *fl_tbl)
#define CF_EFL 56000

const int zoom_points = NUM_FL;

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

static const int fov_tbl[] = {53,46,41,35,30,24,19};
static const int mav_tbl[] = {307,307,325,347,367,389,413};  // min Av **** TO DO ****
static const int xav_tbl[] = {495,492,510,532,552,574,598};  // max Av **** TO DO ****


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




//TODO: VBatt min/max
long get_vbatt_min()
{
    return 3425; // hnikesch on forum
}

long get_vbatt_max()
{
    return 4000; // fresh off charger slightly greater
}

