#include "platform.h"
#include "keyboard.h"

void *hook_raw_fptr()
{
    return (void*)0x53B98; // find on "taskcreate_ImageSensorTask" 
}

void *hook_raw_ret_addr()
{
    return (void*)0xFF9AB668; // BL      nullsub_100
}

char *hook_raw_image_addr()
{
    return (char*)0x10E706A0; 
}

long hook_raw_size()
{
    return 0x8CAE10; 
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
    return (void*)(0x1065BA50); 
}

void *vid_get_viewport_fb_d()
{
    return (void*)(*(int*)0x94408); 
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
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?240:230;
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
    return (char*)0x12298;
}

long vid_get_bitmap_buffer_width() { return 360; }


long vid_get_bitmap_buffer_height() { return 240; }

