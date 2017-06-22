#include "../generic/main.c"

long get_sensor_width()
{
    return 7200;
}


long get_vbatt_min()
{
    return 7000;
}

long get_vbatt_max()
{
    return 8300;
}

static const int fl_tbl[] = {7400, 8210, 9040, 9860, 10670, 12730, 14780, 16820, 18890, 21970, 25030, 29170, 36780, 44400};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 47297

const int zoom_points = NUM_FL;

static const int fov_tbl[]={52,47,43,40,37,32,27,24,22,19,16,14,11,9};

// **************** completely fictitious ! ***********************************
static const int mav_tbl[] = {290,307,325,347,367,389,413,443,470,494,518,542,566,590};  // min Av
static const int xav_tbl[] = {475,492,510,532,552,574,598,628,655,679,703,727,751,775};  // max Av

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




