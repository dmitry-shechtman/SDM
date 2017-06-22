#include "platform.h"
#include "lolevel.h"

char *hook_raw_image_addr()
{
	return (char*) 0x10e59860;  // a800 1.00b at ffe7307C 
}

void *vid_get_viewport_live_fb()   // Live picture buffer (shoot not pressed)
{
	return (void*)0;
}

// OSD buffer
long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe72ff4
void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc3fafc
void *vid_get_viewport_fb()      { return (void*)0x1068c2e0; }             // Found @0xffe6fb54
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2588+0x54)); } // Found @0xffc543b8 & 0xffc543f0
long vid_get_bitmap_screen_width() { return 360; }
long vid_get_bitmap_screen_height() { return 240; }
long vid_get_viewport_height() { return 240; }
long vid_get_bitmap_buffer_width() { return 360; }
long vid_get_bitmap_buffer_height() { return 240; }

char *camera_jpeg_count_str()    { return (char*)0x00088994; }             // Found @0xffd810bc

//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xffd3af20


