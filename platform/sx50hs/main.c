#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

#include "stdlib.h"

long get_sensor_width()
{
 return 6170;          // 1/2.3"
}

void startup()
{
	long *bss = &link_bss_start;

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

int screen_opened(void) {
	return (physw_status[2] & 0x00000200);
}

int screen_rotated(void) {
	return !(physw_status[2] & 0x00000100);
}


// Focus length table in firmware @ 0xfff4d5c4
#define NUM_FL      201 // 0 - 200, entries in firmware
#define NUM_DATA    1   // 1 int value each entry
extern int focus_len_table[NUM_FL*NUM_DATA];

#define CF_EFL      240
#define CF_EFL_DIV  43

// 4.3       24       ( 24/  4.3) * 43 = 240  (min FL)
// 215      1200      (1200/215) * 43 = 240  (max FL)

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

static const int fov_tbl[]={71,69,68,67,66,65,64,63,62,61,60,59,58,58,56,55,55,54,53,52,51,50,49,49,48,47,46,45,45,44,43,42,42,41,40,39,39,38,37,37,36,35,35,34,33,33,32,32,31,31,30,29,29,28,28,27,27,26,26,25,25,24,24,23,23,22,22,22,21,21,20,20,20,19,19,19,18,18,18,17,17,17,16,16,16,15,15,15,14,14,14,14,13,13,13,13,12,12,12,12,11,11,11,11,11,10,10,10,10,10,9,9,9,9,9,9,8,8,8,8,8,8,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
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

long get_vbatt_min()
{
	return 6450;
}

long get_vbatt_max()
{
	return 8200;
}

