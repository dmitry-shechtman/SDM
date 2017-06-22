#include "platform.h"

char *hook_raw_image_addr()
{
	//ffe7b424: 	e59f60dc 	ldr	r6, [pc, #220]	; ffe7b508: (41d64ecc)  *"...AJPEG BUFF       %p ( %lx )"
	return (char*)(0x41d64ecc);
}

long hook_raw_size()
{
	//ffe7b480: 	e59f10dc 	ldr	r1, [pc, #220]	; ffe7b564: (011e4ee0) 
    //ffe7b484: 	e28f00dc 	add	r0, pc, #220	; ffe7b568: (57415243)  *"CRAW BUFF SIZE  %p"
  return 0x11e4ee0;
}

// Live picture buffer
void *vid_get_viewport_live_fb()
{
    //void **fb=(void **)0x43f8; //4420 or 4410                // ffcbcaac: 	e51f5860 	ldr	r5, [pc, #-2144]	; ffcbc254: (00004270)  
    //void **fb=(void **)0x4408;
    //unsigned char buff = *((unsigned char*)0x4270);          
    //return fb[0];
    //if (buff == 0) buff = 2;  else buff--;    
    //return fb[buff];
    return (void*)0x0;
}

// OSD buffer
void *vid_get_bitmap_fb()
{
	return (void*)0x403F1000;                              // ffdf2d00: 	e59f5230 	ldr	r5, [pc, #560]	; ffdf2f38: (403f1000) 
}

// Live picture buffer (shoot half-pressed)
void *vid_get_viewport_fb()
{
	return (void*)0x40507700;                              // ffe780c8: 	e59f1228 	ldr	r1, [pc, #552]	; ffe782f8: (40507700)  *".wP@SumY %ld Size %ld"
}

// Histo etc. when in play mode maybe ?
void *vid_get_viewport_fb_d() 
{
 return (void*)(*(int*)(0x2670 + 0x54));                     // sub_FFC57E38
}

char *camera_jpeg_count_str()
{
 return (void*)0x77fdc;                                      // ffd83ba4: 	e59f013c 	ldr	r0, [pc, #316]	; ffd83ce8: (00077fdc) 
                                                             // ffd83ba8: 	e28f1e13 	add	r1, pc, #304	; ffd83ce0: (39393939)  *"9999"
}

/******************************************************************************
TODO: below this line, everything's todo:
*/

long vid_get_bitmap_screen_width()
{
	return 360;
}

long vid_get_bitmap_screen_height()
{
	return 240;
}

int vid_get_viewport_width()
{
    return 360;
}

long vid_get_viewport_height()
{
    return 240;
}

long vid_get_bitmap_width()
{
	return 360;
}

long vid_get_bitmap_height()
{
	return 240;
}

//ffcd60d8: 	e3a00e2d 	mov	r0, #720	; 0x2d0
//ffcd60dc: 	e3a010f0 	mov	r1, #240	; 0xf0

long vid_get_bitmap_buffer_width() { return 720; }

long vid_get_bitmap_buffer_height() { return 240; }

//ptp
long vid_get_image_buffer_width_for_ptp()
{
    return 720;
}

long vid_get_image_width_for_ptp()
{
    return 720;
}


long vid_get_image_height_for_ptp()
{
    return 240;
}


void *vid_get_bitmap_fb_for_ptp()
{
    return (void*)(*(int*)(0x5744+0x14)); //"Add: %p Width : %ld Hight : %ld", FF8E62DC
}

long vid_get_bitmap_buffer_width_for_ptp(){ return vid_get_bitmap_buffer_width();}
long vid_get_bitmap_width_for_ptp() {return 720;}
long vid_get_bitmap_height_for_ptp() {return 240;}

unsigned int *vid_get_palette() // sorry, I don't know how to read alpha channel for sx10 (on sx10 it is only 0 or 3 :(
{
    static unsigned pal[16];         
    unsigned int*syspal=(unsigned int*) *(unsigned int*)(0x5744+0x28); // FF8E6230 (sx200)
    int i;
    for (i=0;i<16; i++) {
     pal[i]=syspal[i];
     if ((pal[i]>>24)==3) pal[i]|=0xFF000000;
    }
    return pal;
}
