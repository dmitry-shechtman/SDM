#include "../generic/main.c"

long get_vbatt_min()
{
    return 3500;
}

long get_vbatt_max()
{
    return 4100;
}

long get_sensor_width()
{
    return 5760;
}

static const int fl_tbl[] = {5800, 7109, 8462, 10093, 12120, 14421, 17400}; // exif for each zoom step
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 60345 // for 1/2,5" sensor (60345) for 1/1,8" sensor (47946)

const int zoom_points = NUM_FL;

static const int fov_tbl[]={53,44,38,32,27,23,19};
static const int mav_tbl[] = {290,312,336,362,391,420,448};                    // min Av
static const int xav_tbl[] = {570,592,616,642,671,700,728};                    // max Av

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


