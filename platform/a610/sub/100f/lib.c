#include "platform.h"

void *hook_raw_fptr()
{
    return (void*)0x367D0;
}

void *hook_raw_ret_addr()
{
    return (void*)0xFFCB4C5C;
}

char *hook_raw_image_addr()
{
    return (char*)0x1058EBD4;
}

long hook_raw_size()
{
    return 0x644C40;
}

void *vid_get_viewport_live_fb()
{
    return (void*)0x10670d50;
}

void *vid_get_bitmap_fb()
{
    return (void*)0x103C79A0;
}

void *vid_get_viewport_fb()
{
    return (void*)0x10559570;
}

void *vid_get_viewport_fb_d()
{
  //  return (void*)(*(int*)0x7279c);
    int x=(*(int*)0x7279c);
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

long vid_is_bitmap_shown()
{
    return 1;
}

long vid_get_bitmap_screen_width()
{
    return 360;
}

long vid_get_bitmap_screen_height()
{
    return 240;
}

char *camera_jpeg_count_str()
{
    return (char*)0x80A90;
}

long vid_get_bitmap_buffer_width() { return 360; }


long vid_get_bitmap_buffer_height() { return 240; }
