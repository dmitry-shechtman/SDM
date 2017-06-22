#include "platform.h"

void *hook_raw_fptr()
{
    return (void*)0x36A90;
}

void *hook_raw_ret_addr()
{
    return (void*)0xFFCB4C5C;
}

char *hook_raw_image_addr()
{
    return (char*)0x105B8AC0;
}

long hook_raw_size()
{
    return 0x75A8F0;
}

/**
 * OSD screen
 */
void *vid_get_bitmap_fb()
{
    return (void*)0x103C79A0;
}

/**
 * TODO: ??????
 */
void *vid_get_viewport_live_fb()
{
    return (void*)0;
}

/**
 * IMG viewport in 'rec' mode
 */
void *vid_get_viewport_fb()
{
    return (void*)0x10559570;
}

/**
 * IMG viewport in 'play' mode
 */
void *vid_get_viewport_fb_d()
{
    return (void*)0x104AFCA0;   
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
    //TODO: fix this!!
    return (char*)0x10B80;
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

int movie_status = 0;
