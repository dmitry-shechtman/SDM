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
 return 7600;          // 1/1.7"
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

// Focus length table in firmware @0xfff4a4f8
#define NUM_FL      121 // 0 - 120, entries in firmware
#define NUM_DATA    2   // 2 words each entry
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 5.2       24       ( 24/ 5.2) * 52 = 240  (min FL)
// 26.0      120      (120/26.0) * 52 = 240  (max FL)
#define CF_EFL      240
#define	CF_EFL_DIV  52

const int zoom_points = NUM_FL;

static const unsigned char fov_tbl[]={72,69,68,66,65,63,62,61,59,58,57,56,55,54,53,52,51,50,49,48,47,47,46,45,44,44,43,42,42,41,41,40,39,39,38,38,37,37,36,36,35,35,34,34,34,33,33,32,32,32,31,31,31,30,30,30,29,29,29,28,28,28,27,27,27,27,26,26,26,26,25,25,25,25,24,24,24,24,24,23,23,23,23,23,22,22,22,22,22,21,21,21,21,21,21,20,20,20,20,20,20,20,19,19,19,19,19,19,19,18,18,18,18,18,18,18,18,17,17,17,17};

int get_fov(int zp)
{
 if (zp<0) return (int)fov_tbl[0];
 else if (zp>NUM_FL-1) return (int)fov_tbl[NUM_FL-1];
 else return (int)fov_tbl[zp];
}

int get_effective_focal_length(int zp) {
    return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
}

int get_focal_length(int zp) {
    if (zp < 0) zp = 0;
    else if (zp >= NUM_FL) zp = NUM_FL-1;
    return focus_len_table[zp*NUM_DATA];
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
    return 3200;
}

long get_vbatt_max()
{
    return 4050;
}

