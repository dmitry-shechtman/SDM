#include "platform.h"
#include "lolevel.h"

#define LED_PR 0xC0220120  //check this address
static char*    frame_buffer[2];

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


void ubasic_set_led(int led, int state, int bright) 
{
 static char led_table[7]={0,0,0,0,0,4,0};
 _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}


void shutdown()
{
	volatile long *p = (void*)LED_PR;

	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");

	*p = 0x44;  // power off.

	while(1);
}

void debug_led(int state)
{
	// using power LED, which defaults to on
	// for debugging turn LED off if state is 1 and on for state = 0
	// leaves LED on at end of debugging
    volatile long *p = (void*)LED_PR;
     *(int*)LED_PR=state ? 0x46 : 0x44;
}


void shutdown_soft()
{
   _PostLogicalEventForNotPowerType(0x1005,0);
}

int vid_get_viewport_width()
{
    // viewport width table for each image size
    // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
    static long vp_w[4] = { 360, 360, 360, 360 };
    return vp_w[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

long vid_get_viewport_height()
{
    // viewport height table for each image size
    // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
    static long vp_h[4] = { 240, 240, 240, 240 };
    return vp_h[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

int vid_get_viewport_xoffset() 
{
    // viewport width offset table for each image size
    // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
    static long vp_w[4] = { 0, 0, 0, 0 };               // should all be even values for edge overlay
    return vp_w[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

int vid_get_viewport_yoffset() 
{
    // viewport height offset table for each image size
    // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
    static long vp_h[4] = { 0, 0, 0, 0 };
    return vp_h[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

void vid_bitmap_refresh() {

    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

void *vid_get_bitmap_active_palette() {
        extern int active_palette_buffer;
        extern char* palette_buffer[];
        return (palette_buffer[active_palette_buffer]+4);
}

#ifdef CAM_LOAD_CUSTOM_COLORS
// Function to load CHDK custom colors into active Canon palette
// To do:
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
    return (void*)(*(int*)(0x54C4+0x18)); //Found @ loc_FF90CC3C a3400.101a  Not tested
}
