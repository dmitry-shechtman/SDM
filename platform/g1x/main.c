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
 return 17900;          // http://www.dpreview.com/articles/0528662139/canon-powershot-g1-x-mark-ii-a-quick-summary
}

int screen_opened(void) {
	return (physw_status[2] & 0x00002000);
}

int screen_rotated(void) {
	return !(physw_status[2] & 0x00001000);
}

// Focus length table in firmware @ FFFEA5CC
#define NUM_FL      101 // 0 - 100, entries in firmware
#define NUM_DATA    2   // 2 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 15.1       28      ( 28/15.1) * 151 = 280  (min FL)
// 60.4      112      (112/60.4) * 151 = 280  (max FL)
#define CF_EFL      280
#define CF_EFL_DIV  151

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

static const int fov_tbl[]={69,66,64,62,61,59,57,56,54,52,51,49,48,46,45,43,42,41,39,38,37,36,35,34,33,32,31,30,29,28,27,27,26,25,25,24,23,23,22,22,21,21,20,20,19,19,18,18,17,17,17,16,16,16,15,15,15,14,14,14,13,13,13,12,12,12,12,11,11,11,10,10,10,10,9,9,9,9,9,8,8,8,8,7,7,7,7,7,6,6,6,6,6,5,5,5,5,5,4,4,4};

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
	return 6450;    // TODO
}

long get_vbatt_max()
{
	return 8300;    // TODO
}

