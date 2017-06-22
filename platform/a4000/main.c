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
 return 6170;          // 1/2.3"
}

// Focus length table in firmware 0xfffeabc8
#define NUM_FL      127 // 0 - 126, entries in firmware
#define NUM_DATA    2   // 2 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
//  5         28      ( 28/ 5) * 50 = 280  (min FL)
// 40        224      (224/40) * 50 = 280  (max FL)
#define CF_EFL      280
#define	CF_EFL_DIV  50

const int zoom_points = NUM_FL;

static const int fov_tbl[]={63,60,59,57,56,55,53,52,51,49,48,47,46,44,43,42,41,40,39,38,37,36,35,35,34,33,32,31,31,30,29,28,28,27,27,26,25,25,24,24,23,23,22,22,21,21,20,20,19,19,19,18,18,18,17,17,17,16,16,16,15,15,15,15};
static const int mav_tbl[] = {289,293,296,300,303,307,311,314,318,322,326,329,333,337,341,345,349,353,357,361,365,370,374,378,382,386,390,394,399,403,407,411,415,420,424,428,432,437,441,445,449,453,458,462,466,470,474,478,483,487,491,495,499,503,507,511,516,520,524,528,532,536,540,544};  // min Av
static const int xav_tbl[] = {570,574,577,581,584,588,592,595,599,603,607,610,614,618,622,626,630,634,638,642,646,651,655,659,663,667,671,675,680,684,688,692,696,701,705,709,713,718,722,726,730,734,739,743,747,751,755,759,764,768,772,776,780,784,788,792,797,801,805,809,813,817,821,825};
  // max Av

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

// TODO: is battery v min/max ok?
long get_vbatt_min()
{
    return 3000;
}

long get_vbatt_max()
{
    return 4150;
}
