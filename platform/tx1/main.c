#include "../generic/main.c"

long get_sensor_width()
{
    return 5760;  
}

long get_vbatt_min()
{
    return 3350;
}

long get_vbatt_max()
{
    return 4010;
}

static const struct {
    int zp, fl, fov;
} fl_tbl[] = {
    {  0,   6500,48 },
    {  1,   6803,46 },
    {  2,   6934,45 },
    {  3,   7067,44 },
    {  4,   7203,44 },
    {  5,   7340,43 },
    {  7,   7620,41 },
    {  9,   7908,40 },
    {  11,  8207,39 },
    {  14,  8665,37 },
    {  19,  9472,34 },
    {  41, 13743,24 },
    {  64, 20189,16 },
    {  72, 23145,14 },
    {  86, 29387,11 },
    { 105, 40494,8 },
    { 107, 41960,8 },
    { 124, 65000,5 },
};

#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 6035 

const int zoom_points = 125;

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

int get_focal_length(int zp) 
{
    int i;

    if (zp<fl_tbl[0].zp)
        return fl_tbl[0].fl;
    else if (zp>fl_tbl[NUM_FL-1].zp)
        return fl_tbl[NUM_FL-1].fl;
    else 
        for (i=1; i<NUM_FL; ++i) 
       {
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
	return 0;
}

int screen_rotated(void) {
	return 0;
}

