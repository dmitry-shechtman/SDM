#include "../generic/main.c"

long get_sensor_width()
{
    return 5760;
}

long get_vbatt_min()
{
    return 3500;
}

long get_vbatt_max()
{
    return 4100;
}

//ixus800_sd700

//ixus950_sd850 (from EXIF), basically the same as in ixus800_sd700 (4x zoom lens)
  static const int fl_tbl[] = {5800, 6630, 7470, 8640, 9970,  11820, 14330, 18630, 23200};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 60345 // 60345 for 1/2.5" sensor, 47946 for 1/1.8" sensor

const int zoom_points = NUM_FL;

static const int fov_tbl[]={53,47,42,37,32,28,23,18,14};
static const int mav_tbl[] = {288,299,312,329,347,371,400,438,480};  // min Av from shooting.c
static const int xav_tbl[] = {563,574,587,604,622,646,675,713,755};  // max Av

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


