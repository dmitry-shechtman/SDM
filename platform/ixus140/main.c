#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();


void startup()
{
    long *bss = &link_bss_start;

    // sanity check (pointless with automemiso)
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
	started();
	shutdown();
    }

    // initialize .bss senment
    while (bss<&link_bss_end)
	*bss++ = 0;


    boot();
}

#include "stdlib.h"

long get_sensor_width()
{
 return 6170;          // 1/2.3"
}

/*
1/2.3 sensor 
*/

// Focus length table in firmware @FFF4A3E0
#define NUM_FL      101 // 101 zoom steps
#define NUM_DATA    2   // 2 words each entry, FL in MM*1000, 100
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 5         28       ( 28/5) * 60 = 336  (min FL)
// 40        224      (224/40) * 60 = 336  (max FL)
#define CF_EFL      336
#define	CF_EFL_DIV  60

const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp) {
    return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
}

int get_focal_length(int zp) {
    if (zp < 0) zp = 0;
    else if (zp >= NUM_FL) zp = NUM_FL-1;
    return focus_len_table[zp*NUM_DATA];
}

int get_zoom_x(int zp) {
    return get_focal_length(zp)*10/focus_len_table[0];
}

static const int fov_tbl[]={63,61,61,60,60,59,59,58,58,57,57,56,55,55,54,53,53,52,51,50,50,49,48,47,46,46,45,44,43,42,41,40,39,39,38,37,36,35,34,34,33,32,31,30,30,29,28,28,27,26,26,25,25,24,23,23,22,22,21,21,21,20,20,19,19,18,18,18,17,17,17,16,16,16,15,15,15,14,14,14,14,13,13,13,13,12,12,12,12,11,11,11,11,11,10,10,10,10,9,9,9};
static const int mav_tbl[] = {289,293,296,300,303,307,311,314,318,322,326,329,333,337,341,345,349,353,357,361,365,370,374,378,382,386,390,394,399,403,407,411,415,420,424,428,432,437,441,445,449,453,458,462,466,470,474,478,483,487,491,495,499,503,507,511,516,520,524,528,532,536,540,544};  // min Av
static const int xav_tbl[] = {569,573,576,580,583,587,591,594,598,602,606,609,613,617,621,625,629,633,637,641,645,650,654,658,662,666,670,674,679,683,687,691,695,700,704,708,712,717,721,725,729,733,738,742,746,750,754,758,763,767,771,775,779,783,787,791,796,800,804,808,812,816,820,824};  // max Av

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

// uses NB-11L, should be similar to other single cell li-ion
long get_vbatt_min()
{
    return 3250; // shutdown is around 3.1
}

long get_vbatt_max()
{
    return 4000;
}
