#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "stdlib.h"

extern long link_bss_start;
extern long link_bss_end;
extern void boot();


long get_sensor_width()
{
 return 6170;          // 1/2.3"
}

void startup()
{

	long *bss = &link_bss_start;
	long *ptr;

	// sanity check
	if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
		started();
		shutdown();
	}

	// initialize .bss senment
	while (bss<&link_bss_end)
		*bss++ = 0;

	boot();
}

// Focus length table in firmware @0xfffea288
#define NUM_FL      64  // 0 - 63, entries in firmware
#define NUM_DATA    3   // 3 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 4.3       24       ( 24/ 4.3) * 43 = 240  (min FL)
// 21.5      120      (120/21.5) * 43 = 240  (max FL)
#define CF_EFL      240
#define	CF_EFL_DIV  43

const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp) {
    return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
}

int get_focal_length(int zp) {
    if (zp < 0) zp = 0;
    else if (zp >= NUM_FL) zp = NUM_FL-1;
    return focus_len_table[zp*NUM_DATA];
}

static const int fov_tbl[]={71,67,64,61,59,57,55,53,51,49,48,46,45,43,42,41,40,39,38,37,36,35,34,33,32,32,31,30,30,29,28,28,27,27,26,26,25,25,24,24,24,23,23,22,22,22,21,21,21,20,20,20,19,19,19,19,18,18,18,18,17,17,17,16};
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

void dumpFocalLengths()
{
 int fd,i;
 char fn[32];
 sprintf(fn,"A/focal.txt");
 fd=open(fn,O_WRONLY|O_CREAT, 0777);

   for(i=0;i<NUM_FL;i++)
    {
     sprintf(fn,"%d\n",focus_len_table[i*NUM_DATA]);
     write(fd,fn,strlen(fn));
    }
   close(fd); 
}

int get_zoom_x(int zp) {
    return get_focal_length(zp)*10/focus_len_table[0];
}

long get_vbatt_min()
{
	return 3280;  // min observed was 3.408, then it died
}

long get_vbatt_max()
{
	return 4057;  // fresh from change (actual was 4.127)
}
