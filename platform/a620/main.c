#include "../generic/main.c"

long get_sensor_width()
{
    return 7200;
}

char * get_pbb()
{
 return (char *)0x104afaa0;
}

long get_vbatt_min()
{
    return 4550;
}

long get_vbatt_max()
{
    return 5150;
}

static const int fl_tbl[] = {7300, 8460, 9565, 10835, 12565, 14926, 17342, 21709, 29200};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 47946
static const int fov_tbl[]={52,46,41,37,32,27,23,19,14};

int get_fov(int zp)
{
 if (zp<0) return fov_tbl[0];
 else if (zp>NUM_FL-1) return fov_tbl[NUM_FL-1];
 else return fov_tbl[zp];
}

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

int screen_opened(void) 
{
	return !(physw_status[2] & 0x00008000);
}

int screen_rotated(void) 
{
    return !(physw_status[2] & 0x00004000);
}


