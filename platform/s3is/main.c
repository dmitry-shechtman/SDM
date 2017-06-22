#include "../generic/main.c"

long get_sensor_width()
{
    return 5780;
}

long get_vbatt_min()
{
    return 4550;
}

long get_vbatt_max()
{
    return 5150;
}

static const struct {
    int zp, fl,fov;
} fl_tbl[] = {
    {   0,   6000,51 },
    {  11,   6400,49 },
    {  41,  12100,27 },
    {  64,  21300,15 },
    {  86,  41600,8 },
    { 105,  61400,5 },
    { 128,  72000,5 },
};

#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 6000

const int zoom_points = 129;

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
    return (CF_EFL*get_focal_length(zp))/1000;
}

int get_focal_length(int zp) {
    int i;

    if (zp<fl_tbl[0].zp)
        return fl_tbl[0].fl;
    else if (zp>fl_tbl[NUM_FL-1].zp)
        return fl_tbl[NUM_FL-1].fl;
    else 
        for (i=1; i<NUM_FL; ++i) {
           if (zp==fl_tbl[i-1].zp) 
               return fl_tbl[i-1].fl;
           else if (zp==fl_tbl[i].zp) 
               return fl_tbl[i].fl;
           else if (zp<fl_tbl[i].zp)
               return fl_tbl[i-1].fl+(zp-fl_tbl[i-1].zp)*(fl_tbl[i].fl-fl_tbl[i-1].fl)/(fl_tbl[i].zp-fl_tbl[i-1].zp);
        }
    return fl_tbl[NUM_FL-1].fl;
}

int get_zoom_x(int zp) {
    return get_focal_length(zp)*10/fl_tbl[0].fl;
}


int screen_opened(void) {
	return !(physw_status[1] & 0x00000001);
}

int screen_rotated(void) {
	return !(physw_status[1] & 0x00000002);
}

