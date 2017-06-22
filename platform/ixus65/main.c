
#include "../generic/main.c"

long get_sensor_width()
{
    return 5760;
}

void movie_record_task()
{
}

long get_vbatt_min()
{
    return 3550;
}

long get_vbatt_max()
{
    return 4110;
}

static const int fl_tbl[] = {5800, 7109, 8462, 10093, 12120, 14421, 17400};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 60345

const int zoom_points = NUM_FL;

static const int fov_tbl[]={53,44,38,32,27,23,19};

static const int mav_tbl[] = {290,313,337,363,391,420,448};  // min Av  Larry Xu
static const int xav_tbl[] = {475,498,522,548,576,605,633};  // max Av

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


