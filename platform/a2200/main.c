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

void startup() {
	
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

//static const int fl_tbl[] = {5000, 6400, 7400, 9100, 10900, 13000, 15700, 20000};
//#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))

// Focus length table in firmware @FFFE2A98 (1.00B)
#define NUM_FL 8
#define NUM_DATA    2   // 2 words each entry, first is FL
extern int focus_len_table[NUM_FL*3];

// A2200 focal length range is 5 - 20 mm (28 - 112 mm with lense), so CF_EFL = 28/5*10000=56000
#define CF_EFL 56000

const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp) {
	
    return (CF_EFL*get_focal_length(zp))/10000;
}

int get_focal_length(int zp) {
	
	if (zp < 0) zp = 0;
	else if (zp >= NUM_FL) zp = NUM_FL-1;
	return focus_len_table[zp*3];
}

static const int fov_tbl[]={63,51,45,37,32,27,22,18};
static const int mav_tbl[] = {295,319,338,366,393,423,456,501};  // min Av
static const int xav_tbl[] = {588,612,631,659,686,716,749,794};  // max Av

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

long get_vbatt_min() {
	
	return 3000;	// Measured on the battery without load (3350)
}

long get_vbatt_max() {
	
	return 4150;	// Measured on the battery (4170)
}

