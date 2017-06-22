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

static const struct 
{
	int zp, fl,fov;
} 

fl_tbl[] = 
{
  {   0,   5000,63},
  {  16,   6828,49},
  {  32,   9362,36},
  {  62,  17309,20},
  {  78,  23772,15},
  { 102,  37910,9},
  { 125,  70000,5},
};
#define SDM_NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))

// Focus length table in firmware @FFF4A3DC 
#define NUM_FL 126		// 0 - 125, entries in firmware (3 words each entry, first is FL)
#define NUM_DATA    3   // 3 words each entry, first is FL
extern int focus_len_table[NUM_FL*3];

// Focal length range is 5.0 - 70,0 mm, 28 - 392 in 35-mm equivalent.
// So, CF_EFL = 28/5.0*10000=56000 or392/70*10000=56000
// divide by 10 to avoid overflow in get_effective_focal_length()
#define CF_EFL  5600
const int zoom_points = 126;


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
    int i;

    if (zp<fl_tbl[0].zp)
        return fl_tbl[0].fov;
    else if (zp>fl_tbl[SDM_NUM_FL-1].zp)
        return fl_tbl[SDM_NUM_FL-1].fov;
    else 
        for (i=1; i<SDM_NUM_FL; ++i) 
         {
           if (zp==fl_tbl[i-1].zp)         // value before current index
               return fl_tbl[i-1].fov;     
           else if (zp==fl_tbl[i].zp)      // value at current index
               return fl_tbl[i].fov;
           else if (zp<fl_tbl[i].zp)      // between before and current values
               return fl_tbl[i-1].fov-(zp-fl_tbl[i-1].zp)*(fl_tbl[i-1].fov-fl_tbl[i].fov)/(fl_tbl[i].zp-fl_tbl[i-1].zp);
        }
    return fl_tbl[SDM_NUM_FL-1].fov;
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

//TODO
int get_effective_focal_length(int zp) {
	return (CF_EFL*get_focal_length(zp))/1000;
}

//TODO
int get_focal_length(int zp) {
	
	if (zp < 0) zp = 0;
	else if (zp >= NUM_FL) zp = NUM_FL-1;
	return focus_len_table[zp*3];
/*	
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
*/
}

//TODO
int get_zoom_x(int zp) {
	return get_focal_length(zp)*10/focus_len_table[0];
	//return get_focal_length(zp)*10/fl_tbl[0].fl;
}


//TODO
long get_vbatt_min()
{
	return 3280;  // min observed was 3.408, then it died
}

//TODO
long get_vbatt_max()
{
	return 4057;  // fresh from change (actual was 4.127)
}
