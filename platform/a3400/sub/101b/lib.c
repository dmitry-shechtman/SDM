#include "platform.h"

char *hook_raw_image_addr()     {return (char*) 0x420B7FC0;}   //Found @xxx a3400 Search for BJPEG BUFF 
char *hook_alt_raw_image_addr() {return (char*) 0x420B7FC0;}   //Found @xxx a3400 Search for BJPEG BUFF 

void *vid_get_viewport_live_fb()
{
    return 0x0;
}

/*Auto generated for a3400*/
void *vid_get_bitmap_fb()        { return (void*)0x40411000; }             // Found @0xff852d54
void *vid_get_viewport_fb()      { return (void*)0x40566b80; }             // Found @0xffafb234
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x54)); } // Found @0xff868904 & 0xff86893c
char *camera_jpeg_count_str()    { return (char*)0x000b3004; }             // Found @0xff9dde78
long hook_raw_size()             { return 0x01794300; }                    // Found @0xffafe068
int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff98f638
