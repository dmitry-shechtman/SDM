#include "platform.h"
#include "keyboard.h"

/***********
ROM:FF8EBD04 loc_FF8EBD04                            ; CODE XREF: sub_FF8EBA14+288j
ROM:FF8EBD04                                         ; sub_FF8EBA14+2A8j
ROM:FF8EBD04                 LDR     R5, =unk_4BB44
ROM:FF8EBD08                 MOV     R2, #0
ROM:FF8EBD0C                 MOV     R1, #0x220000
ROM:FF8EBD10                 LDR     R0, [R5]
ROM:FF8EBD14                 BL      unknown_libname_21 ; "Canon A-Series Firmware"
ROM:FF8EBD18                 MOV     R1, #0x220000
ROM:FF8EBD1C                 LDR     R0, [R5]
ROM:FF8EBD20                 BL      ClearEventFlag
ROM:FF8EBD24                 LDR     R3, =unk_4BB5C
ROM:FF8EBD28                 LDR     R2, =0x4BB58 <-- hook_raw_fptr
ROM:FF8EBD2C                 LDR     R0, [R3]
ROM:FF8EBD30                 MOV     LR, PC
ROM:FF8EBD34                 LDR     PC, [R2]
ROM:FF8EBD38                 BL      nullsub_46 <-- hook_raw_ret_addr points here
ROM:FF8EBD3C                 LDR     R3, =unk_5840
***********/

void *hook_raw_fptr()
{
    return (void*)0x4BB58; // find on "taskcreate_ImageSensorTask" 
}

void *hook_raw_ret_addr()
{
    return (void*)0xFF9B8524; // BL      nullsub_46
}



char *hook_raw_image_addr()
{
    return (char*)(0x10F00600);	
}

long hook_raw_size()
{
    return 0x8CAE10; 
}

void *vid_get_viewport_live_fb()
{
 return (void*)0; // 0x106571F0 + 0x7E900
}



void *vid_get_bitmap_fb()
{
    return (void*)0x10361000;	// 0x10360000 + 0x1000, see after "BmpDDev.c" in sub_FF960E00
}

/***********
ROM:FFB19720                 BL      sub_FF8BF204
ROM:FFB19724                 LDR     R2, =0x106571F0
ROM:FFB19728                 MOVL    R3, 0x7E900
ROM:FFB19730                 MOV     R1, R2
***********/

void *vid_get_viewport_fb()
{
    return (void*)0x106571F0;	// see after "VRAM Address  : %p" in loc_FFB19720
}

/***********
ROM:FF962874                 LDR     R1, =0x89818
ROM:FF962878                 ADD     R3, R3, R3,LSL#2
***********/

void *vid_get_viewport_fb_d()
{
    return (void*)(*(int*)0x89818); // see before "ImagePlayer.c" at loc_FF962874
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

char *camera_jpeg_count_str()
{
    return (char*)0x96F80;
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

