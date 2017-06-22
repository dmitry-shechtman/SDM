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

#include "stdlib.h"

long get_sensor_width()
{
 return 6170;          // 1/2.3"
}

// Focus length table in firmware @0xfffe2f88
#define NUM_FL      12  // 0 - 11, entries in firmware
#define NUM_DATA    3   // 3 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 5.0       28       ( 28/ 5.0) * 50 = 280  (min FL)
// 25.0      140      (140/25.0) * 50 = 280  (max FL)
#define CF_EFL      280
#define	CF_EFL_DIV  50

const int zoom_points = NUM_FL;

static const int fov_tbl[]={63,60,59,57,56,55,53,52,51,49,48,47};
static const int mav_tbl[] = {289,293,296,300,303,307,311,314,318,322,326,329};  // min Av
static const int xav_tbl[] = {569,573,576,580,583,587,591,594,598,602,606,609};  // max Av

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

long get_vbatt_min()
{
	return 3050; 
}


long get_vbatt_max()
{
	return 4100; 
}
