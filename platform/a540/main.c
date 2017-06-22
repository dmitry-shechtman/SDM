#include "../generic/main.c"

long get_sensor_width()
{
    return 5760;
}

long get_vbatt_min()
{
    return 2100;
}

long get_vbatt_max()
{
    return 2800;
}



static const int fl_tbl[] = {5800, 6600, 7900, 9900, 12700, 16000, 19600, 23200};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 60345




const int zoom_points = NUM_FL;

static const int fov_tbl[]={53,47,40,32,26,20,17,14};
static const int mav_tbl[] = {277,308,336,363,388,411,439,480};  // min Copied from A530
static const int xav_tbl[] = {472,503,531,558,583,606,634,675};  // max Av

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



int is_mode_photo(){ //from 710 added
 int m=mode_get();
 return ((m&MODE_MASK) == MODE_REC )&&
                 !((m&MODE_SHOOTING_MASK)==MODE_VIDEO_STD || (m&MODE_SHOOTING_MASK)==MODE_VIDEO_SPEED || (m&MODE_SHOOTING_MASK)==MODE_VIDEO_COMPACT ||
                   (m&MODE_SHOOTING_MASK)==MODE_VIDEO_MY_COLORS || (m&MODE_SHOOTING_MASK)==MODE_VIDEO_COLOR_ACCENT);
 }
