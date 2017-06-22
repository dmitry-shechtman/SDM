#include "platform.h"
#include "lolevel.h"

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

long vid_get_bitmap_width(){ return 360; }
long vid_get_bitmap_screen_width() { return 360; }
long vid_get_bitmap_height(){ return 240; }
long vid_get_bitmap_screen_height() { return 240; }
long vid_get_bitmap_buffer_width() { return 720; }
long vid_get_bitmap_buffer_height() { return 240; }

void switch_mode(int mode)
{
    if ( mode == 0 ) 
    {
     _Rec2PB();
     _set_control_event(0x80000000|CAM_USB_EVENTID); // 0x10A5 ConnectUSBCable
    } 
    else if ( mode == 1 ) 
    {
     _set_control_event(CAM_USB_EVENTID); // 0x10A6 DisconnectUSBCable
     _PB2Rec();
    } 
}

//To do: Check this address
#define LED_PR 0xC0220094

//TODO: From ixus140
//TODO: not really complete, last call from task_Bye
void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}

void debug_led(int state)
{
    // using power LED, which defaults to on
    // for debugging turn LED off if state is 1 and on for state = 0
     *(int*)LED_PR=state ? 0x46 : 0x44;
}

void ubasic_set_led(int led, int state, int bright) 
{
 static char led_table[7]={0,0,0,0,0,4,0};
 _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}



int get_flash_params_count(void) { return 0x91; }
char *hook_raw_image_addr()      {return (char*) 0x420e5c30;}   //Found @0xffb16a34 a2500 100a
long hook_raw_size()             { return 0x01794300; }         //Found @0xffb18970 a2500 100a

int vid_get_viewport_width()     { return 360;  }
long vid_get_viewport_height()   { return 240;  }


// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.
void *vid_get_bitmap_fb()        { return (void*)0x40431000; } // Found @0xff85cf34
void *vid_get_viewport_fb()      { return (void*)0x40586b80; } // Found @0xffb17000

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

//To do
void *vid_get_viewport_live_fb()
{
    extern char active_viewport_buffer;
    extern void* viewport_buffers[];

    if (MODE_IS_VIDEO(mode_get()) || (movie_status==VIDEO_RECORD_IN_PROGRESS))
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    // verified -1 gives best response
    return viewport_buffers[(active_viewport_buffer-1)&3];
}


void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

void *vid_get_bitmap_active_palette() // from ixus140_elph130
{
    extern int active_palette_buffer;
    extern int** palette_buffer_ptr;
    int *p = palette_buffer_ptr[active_palette_buffer];
    // active_palette_buffer can point at null when
    // func and menu are opened for the first time
    if(!p) {
        p = palette_buffer_ptr[0]; // rec mode buffer appears to always be initialized
    }
    return (p+1);
}

#ifdef CAM_LOAD_CUSTOM_COLORS
// Function to load CHDK custom colors into active Canon palette

void load_chdk_palette() {

        extern int active_palette_buffer;
        // Only load for the standard record and playback palettes
        if ((active_palette_buffer == 0) || (active_palette_buffer == 5))
        {
                int *pal = (int*)vid_get_bitmap_active_palette();
                if (pal[CHDK_COLOR_BASE+0] != 0x33ADF62)
                {
                        pal[CHDK_COLOR_BASE+0]  = 0x33ADF62;  // Red
                        pal[CHDK_COLOR_BASE+1]  = 0x326EA40;  // Dark Red
                        pal[CHDK_COLOR_BASE+2]  = 0x34CD57F;  // Light Red
                        pal[CHDK_COLOR_BASE+3]  = 0x373BFAE;  // Green
                        pal[CHDK_COLOR_BASE+4]  = 0x34BD6CA;  // Dark Green
                        pal[CHDK_COLOR_BASE+5]  = 0x395AB95;  // Light Green
                        pal[CHDK_COLOR_BASE+6]  = 0x34766F0;  // Blue
                        pal[CHDK_COLOR_BASE+7]  = 0x31250F3;  // Dark Blue
                        pal[CHDK_COLOR_BASE+8]  = 0x37F408F;  // Cyan
                        pal[CHDK_COLOR_BASE+9]  = 0x3512D5B;  // Magenta
                        pal[CHDK_COLOR_BASE+10] = 0x3A9A917;  // Yellow
                        pal[CHDK_COLOR_BASE+11] = 0x3819137;  // Dark Yellow
                        pal[CHDK_COLOR_BASE+12] = 0x3DED115;  // Light Yellow

                        extern char palette_control;
                        palette_control = 1;
                        vid_bitmap_refresh();
        }
    }
}
#endif

// Functions for PTP Live View system
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x5C50+0x18)); //found @ loc_ff924924 a2500 100a
}

