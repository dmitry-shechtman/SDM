#include "platform.h"

void *hook_raw_fptr()
{
    return (void*)0;
}

void *hook_raw_ret_addr()
{
    return (void*)0;
}

char *hook_raw_image_addr()
{
 return (char*) (*(int*)0x5684 ? 0x11F6B740 : 0x108057C0);
 //  return (char*)0x108057C0;
}

long hook_raw_size()
{
    return 0xEE9710;
}

void *vid_get_viewport_live_fb()
{
    return (void*)0;
}

void *vid_get_bitmap_fb()       
{
    return (void*)0x10361000;
}

void *vid_get_viewport_fb()
{
    return (void*)0x1065A560;
}

void *vid_get_viewport_fb_d()
{
    return (void*)(*(int*)0x53E8);  // 0x53A0 + 0x48
}


long vid_get_bitmap_width()
{
    return 360;
}

long vid_get_bitmap_height()
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

char *camera_jpeg_count_str()
{
    return (char*)0x5CB38;
}

long vid_get_bitmap_screen_width()
{
    return 360;
}

long vid_get_bitmap_screen_height()
{
    return 240;
}

long vid_get_bitmap_buffer_width() { return 360; }


long vid_get_bitmap_buffer_height() { return 240; }

#if defined(OPT_LIVE_VIEW)

long vid_get_image_buffer_width_for_ptp()
{
 return 720;
}

long vid_get_image_width_for_ptp()
{
 return 720; // VRAM DataSize
}


long vid_get_image_height_for_ptp()
{
 return 240; // VRAM DataSize
}

void *vid_get_bitmap_fb_for_ptp()
{
 return vid_get_bitmap_fb();
}

long vid_get_bitmap_buffer_width_for_ptp(){ return vid_get_bitmap_buffer_width();}
long vid_get_bitmap_width_for_ptp() {return vid_get_bitmap_buffer_width();}
long vid_get_bitmap_height_for_ptp() {return vid_get_bitmap_buffer_height();}

unsigned int *vid_get_palette() 
{
    static unsigned pal[16];         
    unsigned int*syspal= (unsigned int*)0x72850; // sub_FFD12444
    int i;
    for (i=0;i<16; i++) {  // big-endian to little-endian
    pal[i] = (syspal[i]>>24) | 
             ((syspal[i]<<8) & 0x00FF0000) |
             ((syspal[i]>>8) & 0x0000FF00) |
             (syspal[i]<<24);
    }
    return pal;
}
#endif


