#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

long get_sensor_width()
{
    return 6160;          // 1/2.3"
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

//debug_led(1);
    boot();
}

/*
http://www.usa.canon.com/consumer/controller?act=ModelInfoAct&fcategoryid=221&modelid=17482#ModelTechSpecsAct
Shooting Modes
	Auto, Easy, P, Portrait, Landscape, 
	Special Scene
		(Night Scene, Foliage, Snow, Beach, Sunset, Fireworks, Aquarium, ISO 3200),
	Indoor, Kids & Pets, Night Snapshot, Movie

Movie: 640 x 480 (30 fps/30 fps LP), 320 x 240 (30 fps) available up to 4GB or 60 minutes per clip, 160 x 120 (15 fps) up to 3 minutes per clip
canon mode list FFEB9B10 in 100c
*/



static const int fl_tbl[] = {6400, 6800, 7600, 8800, 10500, 12300, 14100, 16100, 18500, 21200, 24000, 27100, 30700, 35100, 38400};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))

// focal length range is 6.4 - 38.4 mm, 36 - 216 in 35-mm equivalent.
// So, CF_EFL = 36/6.4 * 1000 = 56250 or 216/38.4 * 1000 = 56250.
#define CF_EFL 5625

const int zoom_points = NUM_FL;

static const int fov_tbl[]={51,49,44,39,33,28,25,22,19,17,15,13,11,10,9};
static const int mav_tbl[] = {328,331,338,349,364,378,390,402,414,427,439,452,468,488,500};// min Av
static const int xav_tbl[] = {614,617,624,635,650,664,678,688,700,713,725,738,754,774,786};// max Av

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
	return (CF_EFL*get_focal_length(zp))/1000;
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
