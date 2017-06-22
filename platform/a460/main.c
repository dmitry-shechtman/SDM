#include "../generic/main.c"

long get_sensor_width()
{
    return 4800;
}

char * get_pbb()
{
 return (char *)0x104af740;
}

long get_vbatt_min()
{
    return 2300;
}

long get_vbatt_max()
{
    return 2550;
}

static const int fl_tbl[] = {5400, 6800, 8100, 9800, 11800, 14400, 17300, 21600};
static const int mav_tbl[] = {292,303,320,342,367,395,427,461};                    // min Av
static const int xav_tbl[] = {561,580,600,623,650,678,712,747};                    // max Av
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 70371

const int zoom_points = NUM_FL;

static const int fov_tbl[]={48,39,33,28,23,19,16,13};

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


