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
    return (char*)0x10F6C860;
}

long hook_raw_size()
{
    return 0x9DCCE0;
}

void *vid_get_viewport_live_fb()
{
    return (void*)0;//0x10670ee0;
}

void *vid_get_bitmap_fb()       
{
    return (void*)0x10361000;
}

void *vid_get_viewport_fb()
{
    return (void*)0x1065A4D0; // 0x107D5FD0
}

void *vid_get_viewport_fb_d()
{
 //   return (void*)(*(int*)0x540C);  //5410
  //  return (void*)(*(int*)0x540C);  //5410
  int x=*(int*)0x540C;
// if we start camera in PB mode with movie on display, this pointer will be NULL
  return (void*) (x ? x : 0xFFC00000) ;
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
    return (char*)0x580CC;
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

