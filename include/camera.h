#ifndef CAMERA_H
#define CAMERA_H

//Camera-dependent settings

//----------------------------------------------------------
//Default values
//----------------------------------------------------------
    #undef  CAM_SZ				  //
    #undef  CAM_RAW_ROWPIX                  //Number of pixels in RAW row
    #undef  CAM_RAW_ROWS                    //Number of rows in RAW
    #undef  CAM_CURTAIN                     //Camera has flash second curtain option
    #undef  CAM_DRYOS                       //Camera is DryOS-based
  //  #define CAM_DIGIC                 3   //Cameras processor
    #undef  CAM_PROPSET                     //Camera's properties group (the generation)
    #undef  CAM_PB_MODE                     //Can you switch to playback mode with script using switch override method
    #undef  CAM_USE_PBB                     //Use first playback buffer
    #undef  CAM_USES_EXMEM                  //Uses extended memory
    #undef  CAM_NEED_HP                     //half-press
    #undef  CAM_MOVIE_PLE                   //movie mode by post logical event
    #undef  CAM_HAS_VIDEO_CONTROL_BUTTON    //Has video pushbutton for start/stop recording
    #define VIDEO_STD                  1
    #undef  CAM_HAS_PLAYBACK_PB             //Has playback pushbutton
    #define CAM_OUTLINE_MODE            1   //Supports outline mode
    #undef  CAM_SWIVEL_SCREEN               //Camera has rotated LCD screen
    #define CAM_USE_ZOOM_FOR_MF         1   //Zoom lever can be used for manual focus adjustments
    #undef  CAM_NEED_SET_ZOOM_DELAY         // Define to add a delay after setting the zoom position before resetting the focus position in shooting_set_zoom 
    #undef  CAM_USE_ALT_SET_ZOOM_POINT      // Define to use the alternate code in lens_set_zoom_point()
    #undef  CAM_USE_ALT_PT_MoveOpticalZoomAt// Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #undef  CAM_USE_OPTICAL_MAX_ZOOM_STATUS // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom in gui_std_kbd_process()
    #define CAM_HAS_DISP_BUTTON             1
    #define CAM_REMOTE                  1   //Camera supports USB-remote
    #define CAM_SYNCH                   1   //camera supports ordinary synch
    #undef  CAM_PRECISION_SYNCH		  //Camera supports SDM precision synch 
    #undef  CAM_SUPPORTS_SIO                //camera supports serial I/O
    #undef  CAM_MULTIPART                   //Camera supports SD-card multipartitioning
    #define CAM_HAS_ZOOM_LEVER          1   //Camera has dedicated zoom buttons
    #undef  CAM_DRAW_EXPOSITION             //Output expo-pair on screen (for cameras which (sometimes) don't do that)
    #define CAM_HAS_ERASE_BUTTON        1   //Camera has dedicated erase button
    #define CAM_HAS_IRIS_DIAPHRAGM      1   //Camera has real diaphragm mechanism
    #undef  CAM_HAS_ND_FILTER               //Camera has build-in ND filter
    #undef  CAM_HAS_NATIVE_RAW 
    #undef  CAM_TURNS_OFF_LCD
    #undef  STD_360_BUF
    #undef  NEW_REC_PLAY
    #undef  NEW_MOVIE
    #undef  CAM_STARTUP_CRASH_FILE_OPEN_FIX
    #define CAM_HAS_MANUAL_FOCUS            1   // Camera has native manual focus mode (disables MF shortcut feature)
    #undef  CAM_SD_OVER_IN_AF                   // Camera allows SD override if MF & AFL not set
    #undef  CAM_SD_OVER_IN_AFL                  // Camera allows SD override when AFL is set
    #undef  CAM_SD_OVER_IN_MF                   // Camera allows SD override when MF is set

    #define CAM_CAN_SD_OVER_NOT_IN_MF   1   //Camera allows subject distance (focus) override when not in manual focus mode
    #define CAM_CAN_SD_OVERRIDE         1   //Camera allows to do subject distance override
    #define CAM_HAS_MANUAL_FOCUS        1   //Camera has manual focus mode
    #define CAM_HAS_USER_TV_MODES       1   //Camera has tv-priority or manual modes with ability to set tv value
    #undef  CAM_SHOW_OSD_IN_SHOOT_MENU      //On some cameras Canon shoot menu has additional functionality and useful in this case to see CHDK OSD in this mode  
    #define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO  1 //Camera can unlock optical zoom in video (if it is locked)
    #undef  CAM_FEATURE_FEATHER             //Cameras with "feather" or touch wheel.
    #undef  CAM_CONSOLE_LOG_ENABLED         //Development: internal camera stdout -> A/stdout.txt
    #define CAM_CHDK_HAS_EXT_VIDEO_MENU 1   //In CHDK adjustable video compression has been implemented
    #undef  CAM_CAN_MUTE_MICROPHONE         //Camera has function to mute microphone
    #define CAM_BITMAP_PALETTE          1   //which color set is used for this camera
    #define CAM_X_STRETCH               1   // 1 = no stretch, 2 = 2x, 3 = 9/4 times
    #define CAM_EMUL_KEYPRESS_DELAY     40  // Delay to interpret <alt>-button press as longpress
    #define CAM_EMUL_KEYPRESS_DURATION  5   // Length of keypress emulation
    #define ANA_BUTTON                  KEY_SHOOT_HALF  // for anaglyph playback               
    #define DNG_SUPPORT                 1 
    #define EDGE_OVERLAY_COLOUR         0x66 // pink for palette 1 cameras               
    #define CAM_MAKE                    "Canon"
    #define CAM_SENSOR_BITS_PER_PIXEL   10  // Bits per pixel. 10 is standard, 12 is supported except for curves
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             31
    #define CAM_UNCACHED_BIT            0x10000000 // bit indicating the uncached memory
    #undef  CAN_CONTROL_AV_OUTPUT            // using uBasic enable_video_out
    #define MOVIE_TYPE                  "AVI"
    #define LOWRESIMG                      4 
    #define CAM_HAS_IS                     1
    #define ASPECT_XCORRECTION(x)   (x)
    #define EDGE_HMARGIN                    0   // define sup and inf screen margins on edge overlay without overlay.  Necessary to save memory buffer space. sx200is needs values other than 0
    #define CAM_TS_BUTTON_BORDER            0   // Define this to leave a border on each side of the OSD display for touch screen buttons.
                                                // Used on the IXUS 310 to stop the OSD from overlapping the on screen buttons on each side
    #define CAM_MENU_BORDERWIDTH            30  // Defines the width of the border on each side of the CHDK menu. The CHDK menu will have this
                                                // many pixels left blank to the on each side. Should not be less than 10 to allow room for the
                                                // scroll bar on the right.
    #define CAM_USES_ASPECT_CORRECTION      0
    #define CAM_SCREEN_WIDTH           360 // Width of bitmap screen in CHDK co-ordinates (360 or 480)
    #define CAM_SCREEN_HEIGHT          240 // Height of bitmap screen in CHDK co-ordinates (always 240 on all cameras so far)
    #define CAM_BITMAP_WIDTH           360 // Actual width of bitmap screen in bytes (may be larger than displayed area)
    #define CAM_BITMAP_HEIGHT          240 // Actual height of bitmap screen in rows (240 or 270)
    #undef CAM_DATE_FOLDER_NAMING          
    #undef CAM_DRIVE_MODE_FROM_TIMER_MODE    // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    #define CAMERA_MIN_DIST         0           // Define min distance that can be set in _MoveFocusLensToDistance (allow override - e.g. G12 min dist = 1)
    #define CAMERA_MAX_DIST         65535       // Define max distance that can be set in _MoveFocusLensToDistance (allow override for superzooms - SX30/SX40)
    #undef  LOW_LIGHT				// camera has Lowlight mode
    #undef  CAM_KEY_CLICK_DELAY                 // additional delay between press and release for scripted click
    #undef  STD_PERIOD				// for precision synch and movie synch
    #define PERIOD_REF			101
    #define CAM_USB_EVENTID         0x902       // Levent ID for USB control. Changed to 0x202 in DryOS R49 so needs to be overridable.
    #define SYNCH_FPS                  24
    #define SYNCH_SPEED			    4
    #define PERIOD_COUNT		((volatile int*)0xC0F07008) // LiveView refresh
    #undef CAM_FILE_COUNTER_IS_VAR              // file counter is variable file_counter_var in stubs, not a param
    #undef  CAM_HOTSHOE_OVERRIDE                // hot shoe flash-detection can be overridden
    #define CAM_REMOTE_USB_HIGHSPEED        1   // Enable highspeed measurements of pulse width & counts on USB port 
    #define CAM_REMOTE_HIGHSPEED_LIMIT 1000     // Set lowest timer value settable by user
    #define CAM_MARKET_ISO_BASE             100 // Base 'market' ISO value
    #undef CAM_HAS_CMOS
    #undef CAM_HAS_MOVIE_DIGEST_MODE
    #undef UI_CS_PROP
    #undef UI_CT_PROP
    #undef UI_AEB_PROP
    #undef COUNTS_BEFORE_INT
    #define ND_FACTOR			288
    #undef  CAM_HAS_JOGDIAL                     // Camera has a "jog dial"
    #undef  CAM_HAS_GPS                         
//----------------------------------------------------------
//Overridden values for each camera
//----------------------------------------------------------


//A-series

#if defined (CAMERA_a450)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CAM_PROPSET                 2
    #define CAM_RAW_ROWPIX              2664   //for 5 MP 1/3" sensor size
    #define CAM_RAW_ROWS                1968   //for 5 MP 1/3" sensor size
    #define CAM_MULTIPART               1
    #define CDM                         4  
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ZOOM_LEVER
    #define CAM_DRAW_EXPOSITION         1
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef  CAM_HAS_IS
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS                   10
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      652279,  1000000,-199279, 1000000, -101833, 1000000, \
     -159819,  1000000, 619308, 1000000,   78172, 1000000, \
      -58827,  1000000, 150963, 1000000,  264216, 1000000 

    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2592
    #define CAM_JPEG_HEIGHT 1944
    #define CAM_ACTIVE_AREA_X1 6
    #define CAM_ACTIVE_AREA_Y1 6
    #define CAM_ACTIVE_AREA_X2 2618
    #define CAM_ACTIVE_AREA_Y2 1962
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
     // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
   #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44
//----------------------------------------------------------
#elif defined (CAMERA_a460)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
 //   #define CAM_USE_PBB                 1
    #define CAM_PROPSET                 2
    #define CAM_RAW_ROWPIX              2664   //for 5 MP 1/3" sensor size
    #define CAM_RAW_ROWS                1968   //for 5 MP 1/3" sensor size
    #define CAM_MULTIPART               1
  //  #define CDM                         4   
    #define CDM                         99
    #define UI_CS_PROP			    0x8007  
    #define UI_CT_PROP			    0x8008 
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    10
    #undef  CAM_HAS_IS
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ZOOM_LEVER
    #define CAM_DRAW_EXPOSITION         1
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef  CAM_HAS_IS
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      649324,  1000000,-233893, 1000000, -88521, 1000000,  \
     -158955,  1000000, 593407, 1000000,  69775, 1000000,  \
      -44551,  1000000, 136891, 1000000, 254362, 1000000   

    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2592
    #define CAM_JPEG_HEIGHT 1944
    #define CAM_ACTIVE_AREA_X1 6
    #define CAM_ACTIVE_AREA_Y1 6
    #define CAM_ACTIVE_AREA_X2 2618
    #define CAM_ACTIVE_AREA_Y2 1962
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44
//----------------------------------------------------------
#elif defined (CAMERA_a470)
    #define DIGIC				    3
	#define CAM_PROPSET                 2
      #define CAM_PB_MODE                 1
	#define CAM_DRYOS                   1
     #undef  CAM_HAS_IS
     #define CAM_RAW_ROWPIX              3152   //for 7 MP
     #define CAM_RAW_ROWS                2340   //for 7 MP
     #define STD_PERIOD 		*(volatile int*)(0x00306014)
     #undef  SYNCH_FPS
     #define SYNCH_FPS			    20
     #undef  PERIOD_REF
     #define PERIOD_REF			   60
     #undef PERIOD_COUNT
     #define PERIOD_COUNT		      ((int*)0xC0F0700C)
     #undef  CAM_USE_ZOOM_FOR_MF
     #undef  CAM_HAS_ZOOM_LEVER
     #undef  CAM_HAS_ERASE_BUTTON
     #undef  CAM_HAS_IRIS_DIAPHRAGM
     #define CAM_HAS_ND_FILTER           1
     #undef  CAM_HAS_USER_TV_MODES
    #undef  CAM_HAS_MANUAL_FOCUS
     #define CAM_MULTIPART           1
    #undef  CAM_HAS_DISP_BUTTON 
     #define CDM                         4  
	#define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
	// color
	#define CAM_COLORMATRIX1                             \
	673251,  1000000,-200684, 1000000, -98680, 1000000,  \
	-163638, 1000000, 651247, 1000000,  74004, 1000000,  \
	14221,   1000000, 52979,  1000000, 265291, 1000000    
	#define cam_CalibrationIlluminant1 1 // Daylight
	// cropping
	#define CAM_JPEG_WIDTH  3096
	#define CAM_JPEG_HEIGHT 2324
	#define CAM_ACTIVE_AREA_X1 12
	#define CAM_ACTIVE_AREA_Y1 8
	#define CAM_ACTIVE_AREA_X2 3108
	#define CAM_ACTIVE_AREA_Y2 2332
	// camera name
	#define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData	
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44
//---------------------------------------------------------- 
	#elif defined (CAMERA_a480)
    #define DIGIC				    3 	   
      #define CAM_PROPSET                 2 
      #define CAM_NEED_HP                 1
      #define CAM_HAS_PLAYBACK_PB         1
      #define CAM_MOVIE_PLE               1
 	#define CAM_DRYOS                   1 
      #undef  ANA_BUTTON
      #define ANA_BUTTON                  KEY_SET
 	#define CAM_RAW_ROWPIX              3720    
 	#define CAM_RAW_ROWS                2772    	 
 	#undef  CAM_USE_ZOOM_FOR_MF 
      #undef  CAM_HAS_ZOOM_LEVER
      #define CAM_NEED_SET_ZOOM_DELAY          150  // Define to add a delay after setting the zoom position
      #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
      #define CAM_USE_ALT_SET_ZOOM_POINT       1    // Define to use the alternate code in lens_set_zoom_point()
      #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
 	#undef  CAM_HAS_ERASE_BUTTON 
 	#undef  CAM_HAS_IRIS_DIAPHRAGM 
 	#define CAM_HAS_ND_FILTER           1 
 	#undef  CAM_HAS_MANUAL_FOCUS 
 	#undef  CAM_HAS_USER_TV_MODES 
 	#undef  CAM_HAS_IS 
      #undef  CAMERA_MAX_DIST
      #define CAMERA_MAX_DIST			2000000
 	#define CAM_MULTIPART               1 
      #undef  CAM_HAS_DISP_BUTTON 
	#define NEW_REC_PLAY			1
	#define NEW_MOVIE			      1
      #define CDM                         99
      #define UI_CS_PROP			    0x8008  
      #define UI_CT_PROP			    0x8009  
      #define STD_PERIOD 			*(volatile int*)(0x00306014)
      #undef  PERIOD_REF
      #define PERIOD_REF		    200
      #undef  SYNCH_FPS
      #define SYNCH_FPS			    30
 	#undef  CAM_VIDEO_CONTROL 
 	#define CAM_REAR_CURTAIN            1 
 	#undef  DEFAULT_RAW_EXT  
 	#define DEFAULT_RAW_EXT             2   // use .CR2  
 	#define CAM_EXT_TV_RANGE            1 
 	#define CAM_AF_SCAN_DURING_VIDEO_RECORD 1 
 	#define CAM_CAN_MUTE_MICROPHONE     1 
 	#define CAM_EV_IN_VIDEO             1 
	#define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer. 
 	// pattern 
 	#define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue 
 	// color  
 	#define CAM_COLORMATRIX1 \
 	827547, 1000000, -290458, 1000000, -126086, 1000000,\
 	-12829,  1000000, 530507,  1000000, 50537,   1000000,\
 	5181,   1000000, 48183,   1000000, 245014,  1000000 	 
 	#define cam_CalibrationIlluminant1 1 // Daylight 
 	// cropping 
 	#define CAM_JPEG_WIDTH  3648 
 	#define CAM_JPEG_HEIGHT 2736 
 	#define CAM_ACTIVE_AREA_X1 6 
 	#define CAM_ACTIVE_AREA_Y1 12 
 	#define CAM_ACTIVE_AREA_X2 3690 
 	#define CAM_ACTIVE_AREA_Y2 2772 	 
 	// camera name 
 	#define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData 
 	#undef  CAM_SENSOR_BITS_PER_PIXEL 
 	#undef  CAM_WHITE_LEVEL 
 	#undef  CAM_BLACK_LEVEL 
 	#define CAM_SENSOR_BITS_PER_PIXEL   12 
 	#define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1) 
 	#define CAM_BLACK_LEVEL             127 	         
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44
//----------------------------------------------------------
#elif defined (CAMERA_a490)
    #define DIGIC				    3
    #define CAM_PROPSET                     3
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1
    #define CAM_NEED_HP                     1
    #define CAM_HAS_PLAYBACK_PB             1
    #define CAM_MOVIE_PLE                   1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_RAW_ROWPIX                  3720
    #define CAM_RAW_ROWS                    2772
    #define CAM_DATE_FOLDER_NAMING          0x100 //Value found in the last function, which is called in GetImageFolder. (first compare)
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_NEED_SET_ZOOM_DELAY          150  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT       1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1
    #define CAM_HAS_ND_FILTER               1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #undef  CAM_HAS_IS
    #define CAM_MULTIPART                   1
    #undef  CAM_HAS_DISP_BUTTON 
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1  
    #define CDM                             4  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  CAM_VIDEO_CONTROL
    #define CAM_REAR_CURTAIN                1
    #undef  DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                 2   // use .CR2
    #define CAM_EXT_TV_RANGE                1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_CAN_MUTE_MICROPHONE         1
    #define CAM_EV_IN_VIDEO                 1

    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              8

    // pattern
    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue
    // color

    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829,  1000000, 530507,  1000000, 50537,   1000000, \
      5181,   1000000, 48183,   1000000, 245014,  1000000

    #define cam_CalibrationIlluminant1      1   // Daylight
    // cropping
    #define CAM_JPEG_WIDTH                  3648
    #define CAM_JPEG_HEIGHT                 2736
    #define CAM_ACTIVE_AREA_X1              6
    #define CAM_ACTIVE_AREA_Y1              12
    #define CAM_ACTIVE_AREA_X2              3690
    #define CAM_ACTIVE_AREA_Y2              2772

    // camera name
    #define PARAM_CAMERA_NAME               4   // parameter number for GetParameterData to get camera name
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12
    #define CAM_WHITE_LEVEL                 ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL                 127
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX    1     // enable workaround for camera crash at startup when opening the conf / font files
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x55
    #define COLOR_GREY_P          0x55
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x57
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x57                                                    // see http://chdk.setepontos.com/index.php?topic=6179.0
//----------------------------------------------------------
#elif defined (CAMERA_a495)
    #define DIGIC				    3
    #define CAM_PROPSET                     3
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                     1
    #define CAM_RAW_ROWPIX                  3720
    #define CAM_RAW_ROWS                    2772
    #define CAM_HAS_PLAYBACK_PB             1
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1
    #define CAM_HAS_ND_FILTER               1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #undef  CAM_HAS_IS
    #define CAM_SZ				  1
    #define CAM_MULTIPART                   1
    #undef  CAM_HAS_DISP_BUTTON 
    #define NEW_REC_PLAY			1
    #define CDM                         99
    #define UI_CS_PROP			    0x8009 
    #define UI_CT_PROP			    0x800A 
    #define NEW_MOVIE			      1
    #define STD_PERIOD 			        *(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			      200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30
    #undef  CAM_VIDEO_CONTROL
    #define CAM_REAR_CURTAIN                1
    #undef  DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                 2   // use .CR2
    #define CAM_EXT_TV_RANGE                1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_CAN_MUTE_MICROPHONE         1
    #define CAM_EV_IN_VIDEO                 1
    #define CAM_QUALITY_OVERRIDE            1

    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              13

    #define CAM_DNG_LENS_INFO               { 66,10, 216,10, 30,10, 58,10 } // See comments in camera.h
    // pattern
    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue
    // color

    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829,  1000000, 530507,  1000000, 50537,   1000000, \
      5181,   1000000, 48183,   1000000, 245014,  1000000

    #define cam_CalibrationIlluminant1      1   // Daylight
    // cropping
    #define CAM_JPEG_WIDTH                  3648
    #define CAM_JPEG_HEIGHT                 2736
    #define CAM_ACTIVE_AREA_X1              6
    #define CAM_ACTIVE_AREA_Y1              12
    #define CAM_ACTIVE_AREA_X2              3690
    #define CAM_ACTIVE_AREA_Y2              2772

    // camera name
    #define PARAM_CAMERA_NAME               4   // parameter number for GetParameterData to get camera name
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1   // enable workaround for camera crash at startup when opening the conf / font files
                                                // see http://chdk.setepontos.com/index.php?topic=6179.0

    #define CAM_DATE_FOLDER_NAMING          0x100 //Value found in the last function, which is called in GetImageFolder. (first compare)
 //   #define CAM_DATE_FOLDER_NAMING         1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                // Used to enabled bracketing in custom timer, required on many recent cameras
                                                // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_HAS_ZOOM_LEVER               1    // Camera has dedicated zoom buttons
    #define CAM_USE_ZOOM_FOR_MF              1    // Zoom lever can be used for manual focus adjustments
    #define CAM_NEED_SET_ZOOM_DELAY          150  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT      1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x55
    #define COLOR_GREY_P          0x55
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x57
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x57
//----------------------------------------------------------
#elif defined (CAMERA_a530)
    #define DIGIC				    2
    #define CAM_PROPSET                 1
    #define CAM_PB_MODE                 1
    #define CAM_MOVIE_PLE               1
//  2672x1968 image - like most other 5m sensors
    #define CAM_RAW_ROWPIX              2672   //for 5 MP
    #define CAM_RAW_ROWS                1968   //for 5 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_HAS_ERASE_BUTTON	1
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #define CAM_HAS_MANUAL_FOCUS	1
    #define CAM_DRAW_EXPOSITION		1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU	1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_HAS_IS
    #define CDM                         2  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    250
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      725264,  1000000,-240542, 1000000, -122310, 1000000, \
     -210248,  1000000, 656077, 1000000,  52390,  1000000, \
      -11282,  1000000, 70400,  1000000,  300712, 1000000

    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2592
    #define CAM_JPEG_HEIGHT 1944
    #define CAM_ACTIVE_AREA_X1 12
    #define CAM_ACTIVE_AREA_Y1 20
    #define CAM_ACTIVE_AREA_X2 2628
    #define CAM_ACTIVE_AREA_Y2 1968
    // camera name
    #define PARAM_CAMERA_NAME 3 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a540)
    #define DIGIC				    2
    #define CAM_PROPSET                 1
    #define CAM_PB_MODE                 1
    #define CAM_MOVIE_PLE               1
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_RAW_ROWPIX              2888   //for 6 MP
    #define CAM_RAW_ROWS                2136   //for 6 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_HAS_ERASE_BUTTON	1
    #undef  CAM_HAS_ND_FILTER
    #define CAM_HAS_MANUAL_FOCUS	1
    #undef  CAM_DRAW_EXPOSITION
    #define CAM_SHOW_OSD_IN_SHOOT_MENU	1
    #undef  CAM_HAS_IS
    #define CDM                         2  
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      687147,  1000000,-201964, 1000000, -125024, 1000000, \
     -148403,  1000000, 566810, 1000000,   45401, 1000000, \
     -9472,    1000000, 63186,  1000000,  208602, 1000000

    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2816
    #define CAM_JPEG_HEIGHT 2112
    #define CAM_ACTIVE_AREA_X1 44
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 2884
    #define CAM_ACTIVE_AREA_Y2 2136
    // camera name
    #define PARAM_CAMERA_NAME 3 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a550)
    #define DIGIC				    2
    #define CAM_HAS_PLAYBACK_PB         1
    #define CDM                        			 99
    #define UI_CS_PROP			    		       0x8007
    #define UI_CT_PROP			    		       0x8008  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_PROPSET                 2
    #define CAM_RAW_ROWPIX              3152   //for 7 MP
    #define CAM_RAW_ROWS                2340   //for 7 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_MULTIPART               1
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef  CAM_HAS_IS
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      673251,  1000000,-200684, 1000000, -98680, 1000000,  \
     -163638,  1000000, 651247, 1000000,  74004, 1000000,  \
      14221,   1000000, 52979,  1000000, 265291, 1000000

    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3072
    #define CAM_JPEG_HEIGHT 2304
    #define CAM_ACTIVE_AREA_X1 36
    #define CAM_ACTIVE_AREA_Y1 12
    #define CAM_ACTIVE_AREA_X2 3148
    #define CAM_ACTIVE_AREA_Y2 2340
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a560)
    #define DIGIC				    3
    #define CAM_HAS_PLAYBACK_PB         1
    #define CDM                         0  
    #define CAM_PROPSET                 2
    #define CAM_NEED_HP                 1
    #define CAM_RAW_ROWPIX              3152   //for 7 MP
    #define CAM_RAW_ROWS                2340   //for 7 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_MULTIPART               1
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef  CAM_HAS_IS
    #define CAM_CAN_MUTE_MICROPHONE     1 
    #define CAM_TURNS_OFF_LCD           1 
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
      #undef  SYNCH_FPS
      #define SYNCH_FPS			    30
     #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      15265, 1, -6193, 1, -1558, 1,                        \
     -4125,  1, 12116, 1,  2010, 1,                        \
     -888,   1, 1639,  1,  5220, 1                         
    
    #define cam_CalibrationIlluminant1 17 // Standard light A
    // cropping
    #define CAM_JPEG_WIDTH  3072
    #define CAM_JPEG_HEIGHT 2304
    #define CAM_ACTIVE_AREA_X1 38
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 3146
    #define CAM_ACTIVE_AREA_Y2 2338
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1 
   #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x7F
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x7F
//----------------------------------------------------------
#elif defined (CAMERA_a570)
    #define DIGIC				    3
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 2
    #define CAM_RAW_ROWPIX              3152   // for 7 MP
    #define CAM_RAW_ROWS                2340   // for 7 MP
    #define CAM_MULTIPART               1
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define CDM                         99
    #define UI_CS_PROP			    0x8007 
    #define UI_CT_PROP			    0x8008
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
	#define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
	// color
	#define CAM_COLORMATRIX1                            \
    528283, 1000000,-144259, 1000000, -85966, 1000000,  \
    -202789, 1000000, 736563, 1000000, 73008, 1000000,  \
    -27130,  1000000, 107702, 1000000, 264543, 1000000

	#define cam_CalibrationIlluminant1 1 // Daylight
	// cropping
	#define CAM_JPEG_WIDTH  3072
	#define CAM_JPEG_HEIGHT 2304
	#define CAM_ACTIVE_AREA_X1 38
	#define CAM_ACTIVE_AREA_Y1 14
	#define CAM_ACTIVE_AREA_X2 3146
	#define CAM_ACTIVE_AREA_Y2 2338
	// camera name
	#define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a590)
    #define DIGIC				    3
    #define CAM_PB_MODE                 1
//  #define CAM_USE_PBB                 1
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 2
    #define CAM_DRYOS                   1
    #define CAM_RAW_ROWPIX              3336 //for new 8 MP CS614
    #define CAM_RAW_ROWS                2480 //for new 8 MP CS614
    #define CAM_USE_ZOOM_FOR_MF         1
    #undef  CAM_HAS_ND_FILTER	
    #define CAM_HAS_MANUAL_FOCUS        1  
    #define CDM                         99
    #define UI_CS_PROP			    0x8007	 
    #define UI_CT_PROP			    0x8008 
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   113
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F0700C)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    20   
    #undef  CAM_CAN_MUTE_MICROPHONE
    #define CAM_TURNS_OFF_LCD           1
#define cam_CFAPattern 0x01000201 // Green  Blue  Red  Green 
#define CAM_COLORMATRIX1                              \
 726857, 1000000, -176454, 1000000, -124118, 1000000, \
 -71340, 1000000,  592001, 1000000,   75622, 1000000, \
  63222, 1000000,   50547, 1000000,  219582, 1000000

#define cam_CalibrationIlluminant1 1 // Daylight
// cropping
#define CAM_JPEG_WIDTH  3264
#define CAM_JPEG_HEIGHT 2448
// #define CAM_ACTIVE_AREA_X1 12
// #define CAM_ACTIVE_AREA_Y1 10
// note: the above contains some pixels which have valid data, 
// but are not at the same levels as the rest of the frame
// the values below crop the "different" looking pixels.
#define CAM_ACTIVE_AREA_X1 16
#define CAM_ACTIVE_AREA_Y1 18
#define CAM_ACTIVE_AREA_X2 3300
#define CAM_ACTIVE_AREA_Y2 2480
#define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
#undef  CAMERA_MIN_DIST
#define CAMERA_MIN_DIST                 100     // Override min subject distance
#undef  CAMERA_MAX_DIST
#define CAMERA_MAX_DIST                 52855   // Override max subject distance

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a610)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              2672   //for 5 MP
    #define CAM_RAW_ROWS                1968   //for 5 MP
    #define CAM_CURTAIN                 1
    #define CAM_SWIVEL_SCREEN           1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF 
    #undef  CAM_HAS_IS
    #define CDM                         2  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_SUPPORTS_SIO            1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      15887,  10000, -6524, 10000, -1622, 10000,           \
     -5467,   10000, 13449, 10000,  2209, 10000,           \
     -1325,   10000, 1859,  10000,  5172, 10000
    
    #define cam_CalibrationIlluminant1 17 // Standard light A
    // cropping
    #define CAM_JPEG_WIDTH  2592
    #define CAM_JPEG_HEIGHT 1944
    #define CAM_ACTIVE_AREA_X1 14
    #define CAM_ACTIVE_AREA_Y1 10
    #define CAM_ACTIVE_AREA_X2 2626
    #define CAM_ACTIVE_AREA_Y2 1966
    // camera name
    #define PARAM_CAMERA_NAME 3 // parameter number for GetParameterData
    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                 62      // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                 43517   // Override max subject distance
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a620)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              3152   //for 7 MP
    #define CAM_RAW_ROWS                2340   //for 7 MP
    #define CAM_CURTAIN                 1
    #define CAM_SWIVEL_SCREEN           1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_HAS_IS  
    #define CDM                         99
    #define UI_CS_PROP			    0x8007	
    #define UI_CT_PROP			    0x8008  
    #define STD_PERIOD 			   *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_SUPPORTS_SIO            1
    #define cam_CFAPattern              0x02010100 // Red  Green  Green  Blue

    #define CAM_COLORMATRIX1                               \
     15265, 10000, -6193, 10000, -1558, 10000,             \
     -4125, 10000, 12116, 10000,  2010, 10000,             \
     -888,  10000,  1639, 10000,  5220, 10000
    
    #define cam_CalibrationIlluminant1 17 // Standard light A
    // cropping
    #define CAM_JPEG_WIDTH  3072
    #define CAM_JPEG_HEIGHT 2304
    #define CAM_ACTIVE_AREA_X1 38
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 3146
    #define CAM_ACTIVE_AREA_Y2 2338
    #define PARAM_CAMERA_NAME 3         // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a630)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              3344   //for 8 MP
    #define CAM_RAW_ROWS                2484   //for 8 MP
    #define CAM_CURTAIN                 1 
    #define CAM_SWIVEL_SCREEN           1
    #define CAM_MULTIPART               1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_HAS_IS
    #define CDM                         2  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   50
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      656080,  1000000,-226478, 1000000, -85884, 1000000,  \
     -194636,  1000000, 687905, 1000000,  37862, 1000000,  \
       22873,  1000000,  75523, 1000000, 265822, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3264
    #define CAM_JPEG_HEIGHT 2448
    #define CAM_ACTIVE_AREA_X1 14
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3298
    #define CAM_ACTIVE_AREA_Y2 2476
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a640)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              3736   //for 10 MP
    #define CAM_RAW_ROWS                2772   //for 10 MP
    #define CAM_CURTAIN                 1   
    #define CAM_SWIVEL_SCREEN           1
    #define CAM_MULTIPART               1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_HAS_IS
    #define CDM                         99
    #define UI_CS_PROP			    0x8007	
    #define UI_CT_PROP			    0x8008  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   50
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      13124,  10000, -5329, 10000, -1390, 10000,           \
      -3602,  10000, 11658, 10000,  1944, 10000,           \
      -1612,  10000,  2863, 10000,  4885, 10000
    
    #define cam_CalibrationIlluminant1 17 // Standard light A
    // cropping
    #define CAM_JPEG_WIDTH  3648
    #define CAM_JPEG_HEIGHT 2736
    #define CAM_ACTIVE_AREA_X1 14
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3682
    #define CAM_ACTIVE_AREA_Y2 2764
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a650)
    #define DIGIC				    3
    #define CAM_PB_MODE                 1
    #define CAM_PROPSET                 2
    #define CAM_DRYOS                   1
    #define CAM_RAW_ROWPIX              4104   //for 12 MP
    #define CAM_RAW_ROWS                3048   //for 12 MP
    #define CAM_CURTAIN                 1
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION  10
    #define CAM_SWIVEL_SCREEN           1
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define CDM                         1  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      913762, 1000000, -261578, 1000000, -135582, 1000000, \
     -99049,  1000000, 1067089, 1000000,   61442, 1000000, \
      48717,  1000000, 96802,   1000000,  412056, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  4000
    #define CAM_JPEG_HEIGHT 3000
    #define CAM_ACTIVE_AREA_X1 52
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 4076
    #define CAM_ACTIVE_AREA_Y2 3030
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a700)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              2888   //for 6 MP
    #define CAM_RAW_ROWS                2136   //for 6 MP
    #undef  CAM_HAS_IS
    #define CDM                         2  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
     14062, 10000, -5199, 10000, -1446, 10000,             \
     -4712, 10000, 12470, 10000,  2243, 10000,             \
     -1286, 10000,  2028, 10000,  4836, 10000
    
    #define cam_CalibrationIlluminant1 17 // Standard light A
    // cropping
    #define CAM_JPEG_WIDTH  2816
    #define CAM_JPEG_HEIGHT 2112
    #define CAM_ACTIVE_AREA_X1 44
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 2884
    #define CAM_ACTIVE_AREA_Y2 2136
    // camera name
    #define PARAM_CAMERA_NAME 3 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a710)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              3152   //for 7 MP
    #define CAM_RAW_ROWS                2340   //for 7 MP
    #define CAM_CURTAIN                 1
    #define CAM_MULTIPART               1
    #define CDM                         2  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                   \
     13349, 10000, -4141, 10000, -2128, 10000, \
     -4189, 10000, 13178, 10000,  1044, 10000, \
     -1037, 10000,  2326, 10000,  4720, 10000   
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3072
    #define CAM_JPEG_HEIGHT 2304
    #define CAM_ACTIVE_AREA_X1 38
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 3146
    #define CAM_ACTIVE_AREA_Y2 2338
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1 
   #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a720)
    #define DIGIC				    3
    #define CAM_PB_MODE                 1
    #define CAM_PROPSET                 2
    #define CAM_DRYOS                   1
    #define CAM_RAW_ROWPIX              3336   //for new 8 MP
    #define CAM_RAW_ROWS                2480   //for new 8 MP
    #define CAM_CURTAIN                 1
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define CDM                         2  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define cam_CFAPattern 0x01000201 // Green  Blue  Red  Green
    // color
    #define CAM_COLORMATRIX1                               \
      640019, 1000000, -220031, 1000000, -96241, 1000000,  \
     -77419,  1000000, 639766,  1000000,  44009, 1000000,  \
      17965,  1000000, 78396,   1000000, 231868, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3264
    #define CAM_JPEG_HEIGHT 2448
    #define CAM_ACTIVE_AREA_X1 10
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3302
    #define CAM_ACTIVE_AREA_Y2 2474
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                 59      // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                 58686   // Override max subject distance
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a800)
    #define DIGIC				    3
    #define CAM_PROPSET                     4  //processor DIGIC III, but release date (Phil) and properties like PROPCASE_OPTICAL_ZOOM_POSITION, PROPCASE_SHOOTING,PROPCASE_IS_FLASH_READY as propset4.h
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39 				1 // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47 				1 // Defined for cameras with DryOS version R47 or higher
    #define CAM_USE_ALT_SET_ZOOM_POINT       1    // Define to use the alternate code in lens_set_zoom_point()
    //#define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoo
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #undef  CAM_HAS_DISP_BUTTON 
    #define CAM_RAW_ROWPIX                  3720 //do stub_entry.S
    #define CAM_RAW_ROWS                    2772 //do stub_entry.S
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc29904
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800C 
    #define UI_CT_PROP			    0x800D 
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   55
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F0700C)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30   // 29.97
    #define CAM_SZ			    1	
    #define LOW_LIGHT                   1
    #undef  CAM_USE_ZOOM_FOR_MF  //zoom with buton and not lever
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1
    #define CAM_HAS_ND_FILTER               1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #undef  CAM_HAS_IS
    #define CAM_MULTIPART                   1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_REAR_CURTAIN                1
    #undef  DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                 2   // use .CR2
    #define CAM_EXT_TV_RANGE                1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_CAN_MUTE_MICROPHONE         1
    #define CAM_EV_IN_VIDEO                 1
	#define CAM_QUALITY_OVERRIDE            1

    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              18

    #define CAM_DNG_LENS_INFO               { 66,10, 216,10, 30,10, 58,10 } // See comments in camera.h
    // pattern
    #define cam_CFAPattern                  0x01000201 // Green Blue Red Green
    // color

    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829,  1000000, 530507,  1000000, 50537,   1000000, \
      5181,   1000000, 48183,   1000000, 245014,  1000000

    #define cam_CalibrationIlluminant1      1   // Daylight
    // cropping
    #define CAM_JPEG_WIDTH                  3648
    #define CAM_JPEG_HEIGHT                 2736
    #define CAM_ACTIVE_AREA_X1              6
    #define CAM_ACTIVE_AREA_Y1              12
    #define CAM_ACTIVE_AREA_X2              3690
    #define CAM_ACTIVE_AREA_Y2              2772
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME               4   // parameter number for GetParameterData to get camera name
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

	#define CAM_STARTUP_CRASH_FILE_OPEN_FIX    1     // enable workaround for camera crash at startup when opening the conf / font files
                                                    // see http://chdk.setepontos.com/index.php?topic=6179.0

    #define CAM_DATE_FOLDER_NAMING          0x400 //Value found in the last function, which is called in GetImageFolder. (first compare)

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                // Used to enabled bracketing in custom timer, required on many recent cameras
    #define CAM_NEED_SET_ZOOM_DELAY         300  // Define to add a delay after setting the zoom position    
    #define CAM_USE_ALT_SET_ZOOM_POINT      1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS 1   // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom in gui_std_kbd_process()
      // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1                                              // see http://chdk.setepontos.com/index.php/topic,3994.405.html
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x55
    #define COLOR_GREY_P          0x55
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x57
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x57
 
//----------------------------------------------------------
#elif defined (CAMERA_a810)
    #define DIGIC				    4
    #define CAM_DRYOS                       1
    #define CAM_PROPSET                     4
   // #undef CAM_DIGIC
   // #define CAM_DIGIC			        4
    #define CAM_DRYOS_2_3_R31               1       // Define for cameras with DryOS release R31 or greater -> G10
    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_RAW_ROWPIX                  4704 // Found @0xff92def4 a810
    #define CAM_RAW_ROWS                    3504 // Found @0xff92df00 a810
    #undef  CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                 200
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff832e74 a810
    #define STD_360_BUF				1
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
 
    #define CDM                         99
    #define UI_CS_PROP			    0x800D
    #define UI_CT_PROP			    0x800E
    #define NEW_MOVIE			      1 
    #define STD_PERIOD				*(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    300	
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    25 // 1280x720,640x480 at 30 fps
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #define CAM_JPEG_WIDTH                  4608     
    #define CAM_JPEG_HEIGHT                 3456    
    #define CAM_ACTIVE_AREA_X1              16    	
    #define CAM_ACTIVE_AREA_Y1              26
    #define CAM_ACTIVE_AREA_X2              4640
    #define CAM_ACTIVE_AREA_Y2              3486
 
    #define CAM_DNG_LENS_INFO               { 50,10, 250,10, 28,10, 69,10 } // See comments in camera.h a810

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define cam_CFAPattern                  0x01000201   // [Green Blue Red Green]
    
    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000

    #define cam_CalibrationIlluminant1      1       // Daylight

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized

    #define CAM_ZEBRA_ASPECT_ADJUST         1
    #define CAM_ZEBRA_NOBUF                 1

    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData

    #define CAM_HAS_ND_FILTER               1

    #define CAM_EXT_TV_RANGE                1

    #define CAM_VIDEO_QUALITY_ONLY          1

    #define CAM_DETECT_SCREEN_ERASE         1

    #define DNG_VERT_RLE_BADPIXELS          1

    #define CAM_DATE_FOLDER_NAMING          0x400

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1

    #undef  CAM_HAS_IRIS_DIAPHRAGM

    #undef  CAM_HAS_ERASE_BUTTON

    #undef  CAM_HAS_IS                              // Camera does not have an image stabilizer

    #undef  CAM_HAS_MANUAL_FOCUS

    #undef  CAM_VIDEO_CONTROL

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              19 
    
 //   #define CAM_LOAD_CUSTOM_COLORS          1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                 0x90    // Start color index for CHDK colors loaded into camera palette

    #define CAM_HAS_VARIABLE_ASPECT         1
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720   // Actual width of bitmap screen in bytes
 
    #undef  CAM_HAS_DISP_BUTTON 
    #define CAM_FIRMWARE_MEMINFO             1

    #define CAM_HAS_ZOOM_LEVER               1    // Camera has dedicated zoom buttons
    #define CAM_USE_ZOOM_FOR_MF              1    // Zoom lever can be used for manual focus adjustments    
    #define CAM_NEED_SET_ZOOM_DELAY          300  // Define to add a delay after setting the zoom position
    #define CAM_USE_ALT_SET_ZOOM_POINT       1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoo

//    #define CAM_AF_SCAN_DURING_VIDEO_RECORD  1  //TODO: Disabled until find a solution.
    #define CAM_QUALITY_OVERRIDE             1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.
    #define CAM_MISSING_RAND                 1    // srand()/rand() functions not found in firmware. If defined, CHDK use functions implemented in C

//	#define REMOTE_SYNC_STATUS_LED 	0xC0220130		// TODO specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_a1000)
    #define DIGIC				    3
    #define CAM_PROPSET                 2
    #define CAM_DRYOS                   1
    #define CDM                         0  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_MOVIE_PLE               1
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX             1
    #define CAM_RAW_ROWPIX              3720   // 
    #define CAM_RAW_ROWS                2772   // for new 10 MP
    #define CAM_JPEG_WIDTH              3648
    #define CAM_JPEG_HEIGHT             2736
    #define CAM_EV_IN_VIDEO             1
    #define CAM_CAN_MUTE_MICROPHONE     1
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_NEED_HP                 1
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST			2000000
    #undef  CAM_HAS_USER_TV_MODES 
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12
    #define CAM_WHITE_LEVEL                 ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL                 127

    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue
    #define CAM_COLORMATRIX1                              \
     827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829, 1000000,  530507, 1000000,   50537, 1000000, \
       5181, 1000000,   48183, 1000000,  245014, 1000000
    
    #define cam_CalibrationIlluminant1      1       // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3648
    #define CAM_JPEG_HEIGHT 2736
    #define CAM_ACTIVE_AREA_X1 14
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3682
    #define CAM_ACTIVE_AREA_Y2 2764
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a2000)

		////////////////////////////////
		// Sure values
		////////////////////////////////
    #define DIGIC				    3
    #define CAM_MAKE                    "Canon"
    #define CAM_PROPSET                 2
    #define NEW_REC_PLAY			1
    #define CDM                         0 
    #define NEW_MOVIE			      1
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_DRYOS                   1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_MOVIE_PLE               1
    #define CAM_RAW_ROWPIX              3720  
    #define CAM_RAW_ROWS                2772  
    #define CAM_JPEG_WIDTH  3648
    #define CAM_JPEG_HEIGHT 2736
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_USER_TV_MODES
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST			2000000
    ////////////////////////////////
    // Almost sure, sensor data taken from 
    // ixus870_sd880 which should have same sensor..
    ////////////////////////////////
    #undef CAM_SENSOR_BITS_PER_PIXEL
    #undef CAM_WHITE_LEVEL
    #undef CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127
    
    #define cam_CFAPattern              0x02010100 // Red  Green  Green  Blue
    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829,  1000000, 530507,  1000000, 50537,   1000000, \
      5181,   1000000, 48183,   1000000, 245014,  1000000 
    #define cam_CalibrationIlluminant1  1 // Daylight

    // cropping (from ixus870_sd880)
    #define CAM_ACTIVE_AREA_X1          14
    #define CAM_ACTIVE_AREA_Y1          8
    #define CAM_ACTIVE_AREA_X2          3682
    #define CAM_ACTIVE_AREA_Y2          2764

    #undef  CAM_HAS_MANUAL_FOCUS
// for the purposes of CHDK, the FACE button is treated as the erase button
//    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_a2200)
    #define DIGIC				    4
    #define CAM_DRYOS			1
	#define CAM_PROPSET			4
	#define CAM_DRYOS_2_3_R39	1		// Defined for cameras with DryOS version R39 or higher
	#define CAM_DRYOS_2_3_R47	1		// Defined for cameras with DryOS version R47 or higher
    #define STD_360_BUF			1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         3 
    #define STD_PERIOD 			*(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    300
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30	// 29.97 HD
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE            21

    #define CAM_RAW_ROWPIX		4416		// Found @0xff937b24
	#define CAM_RAW_ROWS		3296		// Found @0xff937b2c
	
	#undef  CAM_UNCACHED_BIT
	#define CAM_UNCACHED_BIT	0x40000000	// Found @0xff83a6a8
	
    #define CAM_JPEG_WIDTH		4320
	#define CAM_JPEG_HEIGHT		3240
	#define CAM_ACTIVE_AREA_X1	16
	#define CAM_ACTIVE_AREA_Y1	29
	#define CAM_ACTIVE_AREA_X2	4352
	#define CAM_ACTIVE_AREA_Y2	3275
	
	#define	CAM_DNG_LENS_INFO	{ 50,10, 200,10, 27,10, 56,10 } // See comments in camera.h
	
	// Almost sure values
	#undef	CAM_SENSOR_BITS_PER_PIXEL
	#define	CAM_SENSOR_BITS_PER_PIXEL	12
	
	#define	cam_CFAPattern		0x01000201	// Green  Blue  Red  Green
	
	#define CAM_COLORMATRIX1                             \
	827547, 1000000, -290458, 1000000, -126086, 1000000, \
	-12829, 1000000,  530507, 1000000,   50537, 1000000, \
	  5181, 1000000,   48183, 1000000,  245014, 1000000
	
	#define cam_CalibrationIlluminant1	1	// Daylight
 
    #undef CAM_SCREEN_HEIGHT
    #define CAM_SCREEN_HEIGHT	240
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH	720
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_HEIGHT	240
	
	#undef 	CAM_USES_ASPECT_CORRECTION
	#define	CAM_USES_ASPECT_CORRECTION	1	//camera uses the modified graphics primitives to map screens an viewports to buffers more sized
	
	#define	CAM_ZEBRA_NOBUF 1
	
	#define PARAM_CAMERA_NAME	4		// parameter number for GetParameterData
    
    #define CAM_HAS_ND_FILTER	1
	
	#define CAM_EXT_TV_RANGE	1
	
	#define	CAM_VIDEO_QUALITY_ONLY		1
	
	#define	DNG_VERT_RLE_BADPIXELS		1
	
	#define	CAM_DATE_FOLDER_NAMING		0x400
	
	#define CAM_DRIVE_MODE_FROM_TIMER_MODE 1
	
	#define	CAM_STARTUP_CRASH_FILE_OPEN_FIX	1
	
	#undef  CAM_HAS_IRIS_DIAPHRAGM
	
	#undef  CAM_HAS_ERASE_BUTTON

      #undef  CAM_HAS_IS   
	
	#undef  CAM_HAS_MANUAL_FOCUS
	
	#undef  CAM_VIDEO_CONTROL

	//#define CAM_LOAD_CUSTOM_COLORS          1       // Enable loading CHDK colors into the camera palette memory/hardware
	#define CHDK_COLOR_BASE                 0xA2    // Start color index for CHDK colors loaded into camera palette.
	
	//#define CAM_CAN_SD_OVER_IN_AF_LOCK      1   // Camera allows subject distance (focus) override when in AF Lock mode
	#undef  CAM_CAN_SD_OVER_NOT_IN_MF
	#define CAM_CAN_SD_OVER_IN_AF_LOCK_ONLY 1		//exact meaning: SD override works in AF lock or movie mode
	
	#define CAM_SHOW_OSD_IN_SHOOT_MENU	1
 
	// Not sure values
	//
	//#undef  CAM_USE_ZOOM_FOR_MF
	//#define	CAM_AF_SCAN_DURING_VIDEO_RECORD	1
	//#undef	CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
	#define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO  1
    #define CAM_HAS_ZOOM_LEVER               1    // Camera has dedicated zoom buttons
    #define CAM_USE_ZOOM_FOR_MF              1    // Zoom lever can be used for manual focus adjustments
    #define CAM_NEED_SET_ZOOM_DELAY         300     // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS 1       // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT      1       // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1      // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_a2300)
    #define DIGIC				    4
    #define CAM_DRYOS                       1
    #define CAM_PROPSET                     5
    #define CAM_DRYOS_2_3_R31               1       // Define for cameras with DryOS release R31 or greater -> G10
    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher
    #define STD_360_BUF				  1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define STD_PERIOD				*(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    300
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    25 // 1280x720,640x480 at 30 fps  AS A810
    #define CAM_PRECISION_SYNCH         1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800D
    #define UI_CT_PROP			    0x800E  	
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE            19
    #define CAM_RAW_ROWPIX                  4704    // Found @0xff92e1c4  a2300
    #define CAM_RAW_ROWS                    3504    // Found @0xff92e1d0  a2300

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff834324 a2300

    #define CAM_JPEG_WIDTH                  4608     
    #define CAM_JPEG_HEIGHT                 3456    
    #define CAM_ACTIVE_AREA_X1              16		//Not verified
    #define CAM_ACTIVE_AREA_Y1              26		//Not verified
    #define CAM_ACTIVE_AREA_X2              4640	//Not verified
    #define CAM_ACTIVE_AREA_Y2              3486	//Not verified

    #define CAM_DNG_LENS_INFO               { 50,10, 250,10, 28,10, 69,10 } // See comments in camera.h   a2300is

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12
    
    #define cam_CFAPattern                  0x01000201   // [Green Blue Red Green]
    
    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000
      
    #define cam_CalibrationIlluminant1      1       // Daylight

    #define CAM_ZEBRA_NOBUF                 1

    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData

    #define CAM_HAS_ND_FILTER               1

    #define CAM_EXT_TV_RANGE                1

    #define CAM_HAS_VIDEO_BUTTON            1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE                   1
    #define CAM_VIDEO_QUALITY_ONLY          1

    #define DNG_VERT_RLE_BADPIXELS          1

    #define CAM_DATE_FOLDER_NAMING          0x400

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1

    #undef  CAM_HAS_IRIS_DIAPHRAGM
	
    #undef  CAM_HAS_ERASE_BUTTON
    
    #undef  CAM_HAS_IS                              // Camera does not have an image stabilizer

    #undef  CAM_HAS_MANUAL_FOCUS
   
 //   #define CAM_LOAD_CUSTOM_COLORS          1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                 0xD0    // Start color index for CHDK colors loaded into camera palette

    #define CAM_HAS_VARIABLE_ASPECT         1
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720   // Actual width of bitmap screen in bytes
 
    #undef  CAM_HAS_DISP_BUTTON 

    #define CAM_HAS_ZOOM_LEVER               1    // Camera has dedicated zoom buttons
    #define CAM_USE_ZOOM_FOR_MF              1    // Zoom lever can be used for manual focus adjustments    
    #define CAM_NEED_SET_ZOOM_DELAY          300  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT       1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define CAM_QUALITY_OVERRIDE             1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.
    #define CAM_MISSING_RAND                 1    // srand()/rand() functions not found in firmware. If defined, CHDK use functions implemented in C
    #define MKDIR_RETURN_ONE_ON_SUCCESS      1    // mkdir() return 1 on success, 0 on fail.

//	#define REMOTE_SYNC_STATUS_LED 	0xC0223030		// TODO specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_a2400)
    #define DIGIC				    4
    #define CAM_DRYOS                       1
    #define CAM_PROPSET                     5
    #define CAM_DRYOS_2_3_R31               1       // Define for cameras with DryOS release R31 or greater -> G10
    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher
    #define STD_360_BUF				  1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_RAW_ROWPIX                  4704 // Found @0xff92def4 a810
    #define CAM_RAW_ROWS                    3504 // Found @0xff92df00 a810

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff832e74 a810
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
 
    #define CDM                         4  
    #define STD_PERIOD				*(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    300	
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    25 // 1280x720,640x480 at 30 fps
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #define CAM_RAW_ROWPIX                  4704 // Found @0xff932e60 a3400
    #define CAM_RAW_ROWS                    3504 // Found @0xff932e6c

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff8342d0 a3400

    #define CAM_JPEG_WIDTH                  4608     
    #define CAM_JPEG_HEIGHT                 3456    
    #define CAM_ACTIVE_AREA_X1              16    	//Not Checked
    #define CAM_ACTIVE_AREA_Y1              26      //Not Checked
    #define CAM_ACTIVE_AREA_X2              4640    //Not Checked
    #define CAM_ACTIVE_AREA_Y2              3486    //Not Checked

    #define CAM_DNG_LENS_INFO               { 50,10, 250,10, 28,10, 69,10 } // See comments in camera.h

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define cam_CFAPattern                  0x01000201   // [Green Blue Red Green]
    
    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000

    #define cam_CalibrationIlluminant1      1       // Daylight

    #define CAM_ZEBRA_NOBUF                 1

    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData

    #define CAM_HAS_ND_FILTER               1

    #define CAM_EXT_TV_RANGE                1

    #define CAM_HAS_VIDEO_BUTTON            1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY          1
    #define CAM_CAN_MUTE_MICROPHONE         1

    #define DNG_VERT_RLE_BADPIXELS          1

    #define CAM_DATE_FOLDER_NAMING          0x400

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1

    #undef  CAM_HAS_IRIS_DIAPHRAGM

    #undef  CAM_HAS_ERASE_BUTTON

    #undef  CAM_HAS_MANUAL_FOCUS

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              19      // palette number reserved in core/gui_draw.h
 
  //  #define CAM_LOAD_CUSTOM_COLORS          1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                 0xD0    // Start color index for CHDK colors loaded into camera palette

    #define CAM_HAS_VARIABLE_ASPECT         1
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720   // Actual width of bitmap screen in bytes
    #undef  CAM_HAS_DISP_BUTTON 
 
    #define CAM_HAS_ZOOM_LEVER               1    // Camera has dedicated zoom buttons
    #define CAM_USE_ZOOM_FOR_MF              1    // Zoom lever can be used for manual focus adjustments    
    #define CAM_NEED_SET_ZOOM_DELAY          300  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT       1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define CAM_QUALITY_OVERRIDE             1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.
    #define CAM_MISSING_RAND                 1    // srand()/rand() functions not found in firmware. If defined, CHDK use functions implemented in C
    #define MKDIR_RETURN_ONE_ON_SUCCESS      1    // mkdir() return 1 on success, 0 on fail.
     // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
   #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_a2500)
    #define DIGIC				    4
    #define CAM_DRYOS                       1
    #define CAM_PROPSET                     6
    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher
    #define STD_360_BUF				  1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_UP
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define STD_PERIOD				*(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    300
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    25 // 1280x720,640x480 at 30 fps  AS A810
//    #define CAM_PRECISION_SYNCH         1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1 
    #define CDM                         99
    #define UI_CS_PROP			    0x800D
    #define UI_CT_PROP			    0x800E
    #define CAM_RAW_ROWPIX                  4704   // Found @0xff945828
    #define CAM_RAW_ROWS                    3504   // Found @0xff945834

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff83200c

    #define CAM_JPEG_WIDTH                  4608    //To do
    #define CAM_JPEG_HEIGHT                 3456    //To do
    #define CAM_ACTIVE_AREA_X1              16      //To do
    #define CAM_ACTIVE_AREA_Y1              26      //To do
    #define CAM_ACTIVE_AREA_X2              4640    //To do
    #define CAM_ACTIVE_AREA_Y2              3486    //To do

    #define CAM_DNG_LENS_INFO               { 50,10, 250,10, 28,10, 69,10 } // See comments in camera.h

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define cam_CFAPattern                  0x01000201   // [Green Blue Red Green]

    //TODO
    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000
    #define cam_CalibrationIlluminant1      1       // Daylight

    // no separate erase button
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_DISP_BUTTON

    #define CAM_ZEBRA_NOBUF                 1

    #define PARAM_CAMERA_NAME               3       // parameter number for GetParameterData

    #define CAM_HAS_ND_FILTER               1

    #define CAM_EXT_TV_RANGE                1

    #define CAM_HAS_VIDEO_BUTTON            1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_VIDEO_QUALITY_ONLY          1

    #define DNG_VERT_RLE_BADPIXELS          1

    #define CAM_DATE_FOLDER_NAMING          0x80

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

    #undef  CAM_HAS_IRIS_DIAPHRAGM

    #undef  CAM_HAS_IS                              // Camera does not have an image stabilizer

    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              27      // palette number reserved in core/gui_draw.h
//    #define CAM_LOAD_CUSTOM_COLORS          1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                 0xD0    // Start color index for CHDK colors loaded into camera palette

    //To do
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720   // Actual width of bitmap screen in bytes
    #undef  CAM_HAS_DISP_BUTTON 

    #define CAM_HAS_FILEWRITETASK_HOOK      1
    #define CAM_FILEWRITETASK_SEEKS         1

    #undef CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_ZOOM_LEVER              1       // Camera has dedicated zoom buttons

//To do
    #define CAM_FILE_COUNTER_IS_VAR         1       // file counter is variable file_counter_var in stubs, not a param

    #define CAM_QUALITY_OVERRIDE            1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                 0x202   // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.
    #define MKDIR_RETURN_ONE_ON_SUCCESS     1       // mkdir() return 1 on success, 0 on fail.

    #define REMOTE_SYNC_STATUS_LED 0xC0220094       // specifies an LED that turns on while camera waits for USB remote to sync

//    #undef  CAM_AF_LED
//    #define CAM_AF_LED                          0   // Index of AF led in camera_set_led function
 
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_a3200)
    #define DIGIC				    4
    #define CAM_DRYOS                       1
    #define CAM_PROPSET                     4
    #define CAM_DRYOS_2_3_R39               1
    #define CAM_DRYOS_2_3_R47               1

    #define CAM_RAW_ROWPIX    				4416 // a3200 Found @0xff93a144
	#define CAM_RAW_ROWS      				3296 // a3200 Found @0xff93a14c

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000  // a3200 Found @0xff83a6c0 
    #undef  PERIOD_REF
    #define PERIOD_REF			    300
 //   #undef CAM_DIGIC
 //   #define CAM_DIGIC			    4
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON 0
    #define CAM_MOVIE_PLE               1
    #define CDM                         99
    #define UI_CS_PROP			    0x800C
    #define UI_CT_PROP			    0x800D	 
    #define NEW_MOVIE			      1 
    #define STD_PERIOD 			*(volatile int*)(0x00386014)	
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30 // 29.97 HD
    #define LOW_LIGHT                   0
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE          20
 

    #define CAM_JPEG_WIDTH                  4320    // a3200 from dpreview
    #define CAM_JPEG_HEIGHT                 3240    // a3200 from dpreview

//loc_ffb20c48:
//ffb20c48:       e3a00d45        mov     r0, #4416       ; 0x1140
//ffb20c4c:       e5810000        str     r0, [r1]
//ffb20c50:       e3a00ece        mov     r0, #3296       ; 0xce0
    #define CAM_ACTIVE_AREA_X1              96		// 
    #define CAM_ACTIVE_AREA_Y1              56		//
    #define CAM_ACTIVE_AREA_X2              4416	//	a3200 found @ffb20c48
    #define CAM_ACTIVE_AREA_Y2              3296	//	a3200 found @ffb20c50

    #define DNG_VERT_RLE_BADPIXELS          1
    #define CAM_DNG_LENS_INFO               { 50,10, 250,10, 28,10, 59,10 } // See comments in camera.h   a3300is

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720 // Actual width of bitmap screen in bytes

    #define cam_CFAPattern                  0x02010100  // Red  Green  Green  Blue

    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000

    #define cam_CalibrationIlluminant1      1       // Daylight

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       // camera uses the modified graphics primitives to map screens an viewports to buffers more sized

    #define CAM_QUALITY_OVERRIDE            1

    #define CAM_ZEBRA_ASPECT_ADJUST         1
    #define CAM_ZEBRA_NOBUF                 1		// ??

    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData

    #define CAM_HAS_ND_FILTER               1       //

    #define CAM_VIDEO_QUALITY_ONLY          1       //

    #define CAM_DATE_FOLDER_NAMING          0x400       // ??

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1       // ??

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1       // ??

    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_VIDEO_CONTROL

    #define CHDK_COLOR_BASE                 0x1D    // Start color index for CHDK colors loaded into camera palette.

    #define CAM_HAS_ZOOM_LEVER               1    // Camera has dedicated zoom buttons
    #define CAM_USE_ZOOM_FOR_MF              1    // Zoom lever can be used for manual focus adjustments    
    #define CAM_NEED_SET_ZOOM_DELAY          300  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoo
 
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_a3400)
    #define DIGIC				    4
    #define CAM_DRYOS                       1
    #define CAM_PROPSET                     5
    #define CAM_DRYOS_2_3_R31               1       // Define for cameras with DryOS release R31 or greater -> G10
    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher

    #define CAM_RAW_ROWPIX                  4704 // Found @0xff932e60 a3400
    #define CAM_RAW_ROWS                    3504 // Found @0xff932e6c
    #undef  CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                 200
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff8342d0 a3400
    #define CAM_PRECISION_SYNCH         1
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    0
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800D
    #define UI_CT_PROP			    0x800E
    #define STD_PERIOD				*(volatile int*)(0x00386014)	
    #undef  PERIOD_REF
    #define PERIOD_REF			    300
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    25 // 1280x720,640x480 at 30 fps As A810
    #define LOW_LIGHT                   0
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"


    #define CAM_JPEG_WIDTH                  4608     
    #define CAM_JPEG_HEIGHT                 3456    
    #define CAM_ACTIVE_AREA_X1              16    	//Not Checked
    #define CAM_ACTIVE_AREA_Y1              26      //Not Checked
    #define CAM_ACTIVE_AREA_X2              4640    //Not Checked
    #define CAM_ACTIVE_AREA_Y2              3486    //Not Checked

    #define CAM_DNG_LENS_INFO               { 50,10, 250,10, 28,10, 69,10 } // See comments in camera.h

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define cam_CFAPattern                  0x01000201   // [Green Blue Red Green]
    
    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000

    #define cam_CalibrationIlluminant1      1       // Daylight

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized

    #define CAM_ZEBRA_NOBUF                 1

    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData

    #define CAM_HAS_ND_FILTER               1

    #define CAM_EXT_TV_RANGE                1

    #define CAM_VIDEO_QUALITY_ONLY          1

    #define DNG_VERT_RLE_BADPIXELS          1

    #define CAM_DATE_FOLDER_NAMING          0x400

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1

    #undef  CAM_HAS_IRIS_DIAPHRAGM

    #undef  CAM_HAS_ERASE_BUTTON

    #undef  CAM_HAS_MANUAL_FOCUS

    #undef  CAM_VIDEO_CONTROL

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              19      // palette number reserved in core/gui_draw.h
 
 //   #define CAM_LOAD_CUSTOM_COLORS          1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                 0xD0    // Start color index for CHDK colors loaded into camera palette

    #define CAM_HAS_VARIABLE_ASPECT         1
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720   // Actual width of bitmap screen in bytes
    #undef  CAM_HAS_DISP_BUTTON 

    #define CAM_FIRMWARE_MEMINFO             1

    #define CAM_HAS_ZOOM_LEVER               1    // Camera has dedicated zoom buttons
    #define CAM_USE_ZOOM_FOR_MF              1    // Zoom lever can be used for manual focus adjustments    
    #define CAM_NEED_SET_ZOOM_DELAY         300  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS 1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT      1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define CAM_QUALITY_OVERRIDE             1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.
    #define CAM_MISSING_RAND                 1    // srand()/rand() functions not found in firmware. If defined, CHDK use functions implemented in C
    #define MKDIR_RETURN_ONE_ON_SUCCESS      1    // mkdir() return 1 on success, 0 on fail.

//  #define REMOTE_SYNC_STATUS_LED 	0xC0220130		// TODO specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_SD_OVER_IN_AF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_a4000)
    #define DIGIC				    4
    #define CAM_DRYOS                       1
    #define CAM_PROPSET                     5
    #define CAM_DRYOS_2_3_R31               1       // Define for cameras with DryOS release R31 or greater -> G10
    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher

    #define CAM_RAW_ROWPIX                  4704 // Found @0xff92edac a4000 100c
    #define CAM_RAW_ROWS                    3504 // Found @0xff92edb8 a4000 100c

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff8342c4 a4000 100c
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    0
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
 
    #define CDM                         4  // Canon drive mode	
    #define STD_PERIOD 			    *(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    300
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    25 // 1280x720,640x480 at 30 fps As A810
    #define CAM_PRECISION_SYNCH         1
    #define LOW_LIGHT                   0
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              19  

    #define CAM_JPEG_WIDTH                  4608     
    #define CAM_JPEG_HEIGHT                 3456    
    #define CAM_ACTIVE_AREA_X1              16    	//Not Checked
    #define CAM_ACTIVE_AREA_Y1              26      //Not Checked
    #define CAM_ACTIVE_AREA_X2              4640    //Not Checked
    #define CAM_ACTIVE_AREA_Y2              3486    //Not Checked

    #define CAM_DNG_LENS_INFO               { 50,10, 400,10, 30,10, 59,10 } // See comments in camera.h a4000

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define cam_CFAPattern                  0x01000201   // [Green Blue Red Green]
    
    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000

    #define cam_CalibrationIlluminant1      1       // Daylight

    #define CAM_ZEBRA_NOBUF                 1

    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData

    #define CAM_HAS_ND_FILTER               1

    #define CAM_EXT_TV_RANGE                1

    #define CAM_HAS_VIDEO_BUTTON            1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY          1
    #define CAM_CAN_MUTE_MICROPHONE         1

    #define DNG_VERT_RLE_BADPIXELS          1

    #define CAM_DATE_FOLDER_NAMING          0x400

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1

    #undef  CAM_HAS_IRIS_DIAPHRAGM

    #undef  CAM_HAS_ERASE_BUTTON

    #undef  CAM_HAS_MANUAL_FOCUS
 
 //   #define CAM_LOAD_CUSTOM_COLORS          1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                 0xD0    // Start color index for CHDK colors loaded into camera palette

    #define CAM_HAS_VARIABLE_ASPECT         1
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720   // Actual width of bitmap screen in bytes
    #undef  CAM_HAS_DISP_BUTTON 

    #define CAM_HAS_FILEWRITETASK_HOOK       1
    #define CAM_FILEWRITETASK_SEEKS       1

    #define CAM_HAS_ZOOM_LEVER               1    // Camera has dedicated zoom buttons
    #define CAM_USE_ZOOM_FOR_MF              1    // Zoom lever can be used for manual focus adjustments    
    #define CAM_NEED_SET_ZOOM_DELAY          300  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT       1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define CAM_QUALITY_OVERRIDE             1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.
    #define CAM_MISSING_RAND                 1    // srand()/rand() functions not found in firmware. If defined, CHDK use functions implemented in C
    #define MKDIR_RETURN_ONE_ON_SUCCESS      1    // mkdir() return 1 on success, 0 on fail.

//	#define REMOTE_SYNC_STATUS_LED 	0xC0220130		// TODO specifies an LED that turns on while camera waits for USB remote to sync

    #undef  CAM_AF_LED
    #define CAM_AF_LED                       1   // Index of AF led in camera_set_led function
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A

//----------------------------------------------------------
//G-series
//----------------------------------------------------------

#elif defined (CAMERA_g1x)
    #define DIGIC				    5
    #define CAM_PROPSET                         4
    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1   // Draw pixels on active bitmap buffer only. Requires active_bitmap_buffer location in stubs_min.S or stubs_entry.S.

    #undef  CAM_AF_LED
    #define CAM_AF_LED                          3   // Index of AF led in camera_set_led function

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000 // Found @0xff02ac74

 //   #define CAM_HAS_ND_FILTER                   1 // ****** enable after finding aperture data ************
    #define CAM_HAS_NATIVE_ND_FILTER            1   // Camera has built-in ND filter with Canon menu support for enable/disable
    #define CAM_SWIVEL_SCREEN                   1
    #undef  CAM_HAS_DISP_BUTTON  
 // #define CAM_DISP_BUTTON_NAME                "METER"

    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CAM_HAS_NATIVE_RAW	    1
    #define CDM                         99
    #define UI_CS_PROP			    0x800C
    #define UI_CT_PROP			    0x800D
    #define CAM_PRECISION_SYNCH         1	
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F070C8)	
    #define STD_PERIOD 			    _EngDrvRead(0xC0F06014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    500
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_EMUL_KEYPRESS_DELAY
    #define CAM_EMUL_KEYPRESS_DELAY     50

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_VIDEO_QUALITY_ONLY              1
    #define CAM_BRACKETING                      1
    #undef  CAM_VIDEO_CONTROL                       // Crashes camera if enabled
    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                     2   // use .CR2 

    #undef  CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH                10

    #undef  CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                 200 // Override base 'market' ISO value
    #define CAM_MIN_ISO_OVERRIDE                100 // Defines min market (non-zero) ISO override value - lower value may crash if flash used [0 = AUTO, so always allowed]

    // bayer sensor pattern
    #define cam_CFAPattern                      0x02010100 // Red  Green  Green  Blue

    #define CAM_DNG_LENS_INFO                   { 151,10, 604,10, 28,10, 58,10 }    // See comments in camera.h

    //From G1 X native RAW file as converted to DNG by Adobe convertor
    #define cam_CalibrationIlluminant1          17      // Standard Light A
    #define CAM_COLORMATRIX1    \
      8138, 10000,  -2281, 10000,   -659, 10000, \
     -3453, 10000,  11006, 10000,   2816, 10000, \
      -297, 10000,   1118, 10000,   6471, 10000
    #define cam_CalibrationIlluminant2          21      // D65
    #define CAM_COLORMATRIX2    \
      7378, 10000,  -1255, 10000,  -1043, 10000, \
     -4088, 10000,  12251, 10000,   2048, 10000, \
      -876, 10000,   1946, 10000,   5805, 10000
    #define CAM_CAMERACALIBRATION1    \
     10102, 10000,      0, 10000,      0, 10000, \
         0, 10000,  10000, 10000,      0, 10000, \
         0, 10000,  00000, 10000,  10233, 10000
    #define CAM_CAMERACALIBRATION2    \
     10102, 10000,      0, 10000,      0, 10000, \
         0, 10000,  10000, 10000,      0, 10000, \
         0, 10000,  00000, 10000,  10233, 10000
    #define CAM_FORWARDMATRIX1    \
      7310, 10000,    833, 10000,   1500, 10000, \
      2013, 10000,   8875, 10000,   -888, 10000, \
        34, 10000,  -4122, 10000,  12339, 10000
    #define CAM_FORWARDMATRIX2    \
      7010, 10000,   1653, 10000,    980, 10000, \
      2351, 10000,   9551, 10000,  -1902, 10000, \
       177, 10000,  -2144, 10000,  10218, 10000

    // Sensor size, DNG image size & cropping
    #define CAM_RAW_ROWPIX                      4496    // Found @0xff190c98
    #define CAM_RAW_ROWS                        3366    // Found @0xff190ca4
    #define CAM_JPEG_WIDTH                      4400
    #define CAM_JPEG_HEIGHT                     3308
    #define CAM_ACTIVE_AREA_X1                  80
    #define CAM_ACTIVE_AREA_Y1                  52
    #define CAM_ACTIVE_AREA_X2                  4484
    #define CAM_ACTIVE_AREA_Y2                  3364

    // camera name
    #define PARAM_CAMERA_NAME                   4       // parameter number for GetParameterData - Camera Model name
    #define PARAM_OWNER_NAME                    7       // parameter number for GetParameterData - Owner name
    #define PARAM_ARTIST_NAME                   157     // parameter number for GetParameterData - Artist name
    #define PARAM_COPYRIGHT                     158     // parameter number for GetParameterData - Copyright
    #define PARAM_DISPLAY_MODE1                 59      // param number for LCD display mode when camera in playback
    #define PARAM_DISPLAY_MODE2                 62      // param number for LCD display mode when camera in record view hold mode
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           14

    #define CAM_EXT_TV_RANGE                    1
    #undef CAM_EXT_AV_RANGE
    #define CAM_EXT_AV_RANGE                    0       // G1X can't go below F/16 so set this to 0
    #define CAM_QUALITY_OVERRIDE                1
    #define CAM_REAR_CURTAIN                    1

    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                    960     // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT                   270     // Actual height of bitmap screen in rows

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  26 	  // same as SX40hs
  
    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN 2

    #define CAM_DATE_FOLDER_NAMING              0x400

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX     1       // enable fix for camera crash at startup when opening the conf / font files
                                                        // see http://chdk.setepontos.com/index.php?topic=6179.0

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60      // delay after a press

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                        // Used to enabled bracketing in custom timer, required on many recent cameras
                                                        // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_AV_OVERRIDE_IRIS_FIX            1       // for cameras that require _MoveIrisWithAv function to override Av in bracketing.

    #define CAM_DISABLE_RAW_IN_HQ_BURST         1       // For cameras with 'HQ Burst' mode that does not work with raw define this
    #define CAM_DISABLE_RAW_IN_HANDHELD_NIGHT_SCN 1     // For cameras with 'HandHeld Night Scene' mode that does not work with raw define this
    #define  CAM_HAS_MOVIE_DIGEST_MODE          1       // Changes the values in the 'movie_status' variable if the camera has this mode
 
//  #define CAM_LOAD_CUSTOM_COLORS              1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                     0xA8    // Start color index for CHDK colors loaded into camera palette.

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.
 
//	#define REMOTE_SYNC_STATUS_LED 	0xC0xxyyyy		// specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_HAS_CMOS                        1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     275     // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     660067  // Override max subject distance

    // Define shortcut overrides where defaults are not suitable
    #define SHORTCUT_TOGGLE_ZEBRA           KEY_ERASE   // On camera Shutter Half Press + Up = switch MF on/off

    #define CAM_HAS_FILEWRITETASK_HOOK          1   // file write hook for remote capture etc
 
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
 
//----------------------------------------------------------
  #elif defined (CAMERA_g7)
    #define DIGIC				    3
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_PROPSET                 1
    #define CDM                         0  
    #define CAM_NEED_HP                 1
    #define CAM_RAW_ROWPIX              3736   //for 10 MP
    #define CAM_RAW_ROWS                2772   //for 10 MP
    #define CAM_CURTAIN                 1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_HAS_JOGDIAL             1
    #define CAM_MULTIPART               1
    #define CAM_HAS_ND_FILTER           1
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_HOTSHOE_OVERRIDE        1
    #define STD_PERIOD				*(volatile int*)(0x00386014)	
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30 
    #define CAM_USB_EVENTID_VXWORKS             0x1085 // LogicalEvent ID for ConnectUSBCable, needed to enable USB mode switch
                                                       // NOTE switching back to play reportedly does not work on this camera
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                              \
      575419, 1000000,-185557, 1000000, -77898,  1000000, \
     -213702, 1000000, 733569, 1000000,   81514, 1000000, \
      -24604, 1000000, 131906, 1000000,  280378, 1000000

    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3648
    #define CAM_JPEG_HEIGHT 2736
    #define CAM_ACTIVE_AREA_X1 14
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3682
    #define CAM_ACTIVE_AREA_Y2 2764
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData

    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
      #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44
//----------------------------------------------------------

  #elif defined (CAMERA_g9)
    #define DIGIC				    3
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_PROPSET                 2
    #define CDM                         99
    #define UI_CS_PROP			    0x8007 
    #define UI_CT_PROP			    0x8008   
   // #define CAM_HAS_NATIVE_RAW	    1  // no need to detect Canon RAW as independent vertical menu not affected by it
    #define CAM_NEED_HP                 1
    #define CAM_DRYOS                   1
    #define CAM_RAW_ROWPIX              4104   //for 12 MP
    #define CAM_RAW_ROWS                3048   //for 12 MP
    #define CAM_CURTAIN                 1
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION  10
    #define CAM_MULTIPART               1 
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_HAS_JOGDIAL                 1
    #define CAM_BRACKETING                  1
    #define CAM_EXT_TV_RANGE                1
    #define CAM_TURNS_OFF_LCD           1
    #define STD_PERIOD				*(volatile int*)(0x00386014)	
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    // camera name
    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData

    #define CAM_DNG_LENS_INFO               { 74,10, 444,10, 28,10, 48,10 } // See comments in camera.h
    // pattern
    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue
    // color (alternativ: http://lclevy.free.fr/cr2/)
    #define CAM_COLORMATRIX1                              \
    1679727, 1000000,  422803, 1000000,  803343, 1000000, \
     220204, 1000000, 1784845, 1000000,  -63290, 1000000, \
    -282882, 1000000, -475034, 1000000, 4502592, 1000000

    #define cam_CalibrationIlluminant1      1  // Daylight

    // cropping
    #define CAM_JPEG_WIDTH                  4000
    #define CAM_JPEG_HEIGHT                 3000
    #define CAM_ACTIVE_AREA_X1              52
    #define CAM_ACTIVE_AREA_Y1              14
    #define CAM_ACTIVE_AREA_X2              4076
    #define CAM_ACTIVE_AREA_Y2              3030
    #define REMOTE_SYNC_STATUS_LED 	0xC022006C	                          
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44
//----------------------------------------------------------

#elif defined (CAMERA_g10)
    #define CAM_HAS_PLAYBACK_PB         1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_DOWN
    #define CAM_DRYOS                       1

    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION         7   // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)
    #define CAM_NEED_HP                 1
    #define CAM_PROPSET                     2

    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_HAS_ND_FILTER               1
    #define CAM_HAS_NATIVE_ND_FILTER        1   // Camera has built-in ND filter with Canon menu support for enable/disable

    #define CAM_HAS_HI_ISO_AUTO_MODE        1

    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION      10

    #define CAM_ADJUSTABLE_ALT_BUTTON       1
    #define CAM_ALT_BUTTON_NAMES            { "Print", "Disp",  "AE Lock", "Jump" }
    #define CAM_ALT_BUTTON_OPTIONS          { KEY_PRINT, KEY_DISPLAY, KEY_AE_LOCK, KEY_METERING}

    #define CAM_RAW_ROWPIX                  4480    // G10 auto found @0xffacde38
    #define CAM_RAW_ROWS                    3348    // G10 auto found @0xffacde3c

    #define CAM_JPEG_WIDTH                  4416    // taken from G10 jpg header info
    #define CAM_JPEG_HEIGHT                 3312    // "

    #define CAM_ACTIVE_AREA_X1              12      // calibrated with G10 RAW picture converted with rawconvert.exe (rawconvert -12to8 -pgm -w=4480 -h=3348 g10.crw g10.pgm)
    #define CAM_ACTIVE_AREA_Y1              12      // "
    #define CAM_ACTIVE_AREA_X2              4440    // "
    #define CAM_ACTIVE_AREA_Y2              3334    // "

    #define CAM_QUALITY_OVERRIDE            1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_RESET_AEL_AFTER_VIDEO_AF    1   // Cam needs AE Lock state reset after AF in video recording
    #define CAM_HAS_JOGDIAL                 1

    #define CAM_BRACKETING                  1
    #define CAM_MULTIPART               1
    #define STD_360_BUF				1
    #define CDM                         99
    #define UI_CS_PROP			    0x8008 
    #define UI_CT_PROP			    0x8008  
    #define STD_PERIOD 			*(volatile int*)(0x00406014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   250	
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000  // G10 auto found @0xff828844

    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData
    #define PARAM_DISPLAY_MODE1             57      // param number for LCD display mode when camera in playback
    #define PARAM_DISPLAY_MODE2             58      // param number for LCD display mode when camera in record view hold mode

 // #define CAM_LOAD_CUSTOM_COLORS          1      // Enable loading CHDK colors into the camera palette memory/hardware

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #undef  CAM_USES_ASPECT_CORRECTION   
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720 // Actual width of bitmap screen in bytes

    #undef  EDGE_HMARGIN 
    #define EDGE_HMARGIN 28

    #define CAM_DNG_LENS_INFO               { 61,10, 305,10, 28,10, 45,10 } // See comments in camera.h
    // G10 pattern
    #define cam_CFAPattern                  0x01000201   // 0x01000201 = Green Blue Red Green    
                                                        // 0x02010100 = Red  Green  Green  Blue   

    // G10 color - values from dcraw for G10 Canon RAW files
    #define cam_CalibrationIlluminant1      17 // standard light A   
    #define CAM_COLORMATRIX1 \
        11093,  1000000,    -3906,  1000000,    -1028,  1000000, \
        -5047,  1000000,    12492,  1000000,     2879,  1000000, \
        -1003,  1000000,     1750,  1000000,     5561,  1000000

    // zebra 
    #define CAM_ZEBRA_NOBUF                 1

    #define CAM_USE_ALT_SET_ZOOM_POINT      1   // Define to use the alternate code in lens_set_zoom_point()

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                    // Used to enabled bracketing in custom timer, required on many recent cameras
                                                    // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define REMOTE_SYNC_STATUS_LED          0xC02200DC  // specifies an LED that turns on while camera waits for USB remote to sync

    #undef  CAM_AF_LED
    #define CAM_AF_LED                      5       // Index of AF led in camera_set_led function

    #define CAM_HOTSHOE_OVERRIDE            1

    #define CAM_SD_OVER_IN_AF               1
    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

    #define CAM_HAS_FILEWRITETASK_HOOK      1
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE    32
#define COLOR_GREY            0x14
#define COLOR_GREY_P          0x14
#define COLOR_LIGHT_GREY      0x10
#define COLOR_DARK_GREY       0x18
#define COLOR_LIGHT_GREY_P    0x10
#define COLOR_DARK_GREY_P     0x18
 
#elif defined (CAMERA_g11)
    #define DIGIC				    4
    #undef  EDGE_OVERLAY_COLOUR 
    #define EDGE_OVERLAY_COLOUR         0xE0
    #define CAM_HAS_PLAYBACK_PB         1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_DOWN
    #define CAM_DRYOS_2_3_R39		    1
    #define CAM_PROPSET                 3
    #define CAM_DRYOS                   1
    //#undef CAM_DIGIC
    //#define CAM_DIGIC			    4
    #define CAM_NEED_HP                 1
    #define CAM_RAW_ROWPIX              3744   // See g11 lib.c
    #define CAM_RAW_ROWS                2784   // See g11 lib.c
    #define CAM_CURTAIN                 1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    // #define CAM_HAS_ND_FILTER        1 // crashes camera so not supported
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION  10
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX    1
    #define CAM_QUALITY_OVERRIDE 1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_HAS_JOGDIAL             1
    #undef  CAM_CONSOLE_LOG_ENABLED         // Development: internal camera stdout -> A/stdout.txt
    #define CAM_BRACKETING              1
    #define CAM_MULTIPART               1
    #define STD_360_BUF				1
    #define CDM                         99
    #define UI_CS_PROP			    0x8008 
    #define UI_CT_PROP			    0x8009
    #define STD_PERIOD 			*(volatile int*)(0x00406014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   250	
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
   // #define CAM_HAS_NATIVE_RAW	    1
    #define LOW_LIGHT                   1
    #define CAM_EXT_TV_RANGE            1
    #undef OPT_CURVES
    #undef CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT            0x40000000  // G11 @FF888204(via ExMem.FreeCacheable)

	#define CAM_SWIVEL_SCREEN			1
	#define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127

    #undef CAM_USES_ASPECT_CORRECTION   
    #undef CAM_USES_ASPECT_YCORRECTION  
    #define CAM_USES_ASPECT_CORRECTION  1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #define CAM_USES_ASPECT_YCORRECTION  0  //only uses mappings on x coordinate
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE    2
   

    #undef ASPECT_XCORRECTION
	#define ASPECT_XCORRECTION(x)  ( ( ((x)<<3) + (x) )  >>2 )


   #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows
    #undef ASPECT_GRID_XCORRECTION
    #define ASPECT_GRID_XCORRECTION(x)  ( ((x)<<3)/9  )  //grids are designed on a 360x240 basis and screen is 320x240, we need x*320/360=x*8/9
    #undef ASPECT_GRID_YCORRECTION
    #define ASPECT_GRID_YCORRECTION(y)  ( (y) )       //y correction for grids  made on a 360x240 As the buffer is 720x240 we have no correction here.

    #undef ASPECT_VIEWPORT_XCORRECTION 
    #define ASPECT_VIEWPORT_XCORRECTION(x) ASPECT_GRID_XCORRECTION(x) //viewport is 360x240 and screen 320x240, we need x*320/360=x*8/9, equal than grids, used by edgeoverlay
    #undef ASPECT_VIEWPORT_YCORRECTION 
    #define ASPECT_VIEWPORT_YCORRECTION(y) ( (y) ) 
    #undef EDGE_HMARGIN 
    #define EDGE_HMARGIN 20
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    //need fixing *****************************************************
    #define CAM_COLORMATRIX1                               \
      14134, 1000000, -5576, 1000000, -1527, 1000000, \
     -1991,  1000000, 10719,  1000000, 1273,   1000000, \
      -1158,   1000000, 1929,   1000000, 3581,  1000000
    #define cam_CalibrationIlluminant1 17 // Standard Light A

    // cropping
    #define CAM_JPEG_WIDTH  3600
    #define CAM_JPEG_HEIGHT 2700
    #define CAM_ACTIVE_AREA_X1 52
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 3648
    #define CAM_ACTIVE_AREA_Y2 2736
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x14
    #define COLOR_GREY_P          0x14
    #define COLOR_LIGHT_GREY      0x10
    #define COLOR_DARK_GREY       0x18
    #define COLOR_LIGHT_GREY_P    0x10
    #define COLOR_DARK_GREY_P     0x18
//----------------------------------------------------------
#elif defined (CAMERA_g12)
    #define DIGIC				    4
    #define CAM_PROPSET                 4
   // #undef CAM_DIGIC
   // #define CAM_DIGIC			    4	
    #define CAM_DRYOS                   1
    #define CAM_DRYOS_2_3_R39		    1
    #define CAM_USES_EXMEM              1
    #define CAM_NEED_HP                 1
    #define CAM_RAW_ROWPIX              3744
    #define CAM_RAW_ROWS                2784
    #define CAM_SWIVEL_SCREEN			1
    #define STD_360_BUF                 1
    #define CAM_NEED_HP                 1
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION  10
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_MULTIPART               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800A
    #define UI_CT_PROP			    0x800B
    #define STD_PERIOD 			    *(volatile int*)(0x00406014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    24  // 23.976 HD
   // #define CAM_HAS_NATIVE_RAW	    1
    #define LOW_LIGHT                   1
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_HOTSHOE_OVERRIDE        1
    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST             68      // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST             258065  // Override max subject distance
    #define CAM_HAS_JOGDIAL             1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS 1   // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_NEED_SET_ZOOM_DELAY     1000
    #define CAM_HAS_ND_FILTER               1
    #define CAM_BRACKETING              1
    #define CAM_MOVIE_PLE               1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY		1
    #define CAM_EXT_TV_RANGE            1
    #define CAM_QUALITY_OVERRIDE 1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    #undef CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT            0x40000000  // S90 @FF8875FC(via ExMem.FreeCacheable)
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT             2   // use .CR2 
    #undef CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH	10
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #undef  CAM_WHITE_LEVEL
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #undef  CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL             127

    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE    8

    #undef CAM_USES_ASPECT_CORRECTION
    #undef ASPECT_XCORRECTION
    #define CAM_USES_ASPECT_CORRECTION  1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #define ASPECT_XCORRECTION(x)  ( ((x)<<1) )
   #undef CAM_USES_ASPECT_YCORRECTION
    #define CAM_USES_ASPECT_YCORRECTION  0  //only uses mappings on x coordinate

    #undef EDGE_HMARGIN
    #define EDGE_HMARGIN 2

    // bayer sensor pattern
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue

	#define	CAM_DNG_EXPOSURE_BIAS		0,1		// Specify DNG exposure bias value to 0 (to override default of -0.5 in the dng.c code)

	//need fixing *****************************************************
    #define cam_CalibrationIlluminant1	17		// Standard Light A
/*
    #define CAM_COLORMATRIX1                               \
      14134, 100000, -5576, 100000, -1527, 100000, \
      -1991, 100000, 10719, 100000,  1273, 100000, \
      -1158, 100000,  1929, 100000,  3581, 100000
*/
    // From dcraw
    #define CAM_COLORMATRIX1                       \
      13244, 10000, -5501, 10000, -1248, 10000, \
      -1508, 10000,  9858, 10000,  1935, 10000, \
       -270, 10000,  1083, 10000,  4366, 10000

    // cropping
    #define CAM_JPEG_WIDTH  3684
    #define CAM_JPEG_HEIGHT 2760
    #define CAM_ACTIVE_AREA_X1 52
    #define CAM_ACTIVE_AREA_Y1 12
    #define CAM_ACTIVE_AREA_X2 (CAM_RAW_ROWPIX-8)
    #define CAM_ACTIVE_AREA_Y2 (CAM_RAW_ROWS-12)

	#define CAM_ZEBRA_ASPECT_ADJUST 1

	//zebra letterbox for saving memory
	#undef ZEBRA_HMARGIN0
	#define ZEBRA_HMARGIN0  30 //this 30 rows are not used by the display buffer is 720x240 effective, no 960x270, i.e. (270-240) reduction in widht possible but not done (more difficult to manage it and slower).
	
	#define	CAM_DATE_FOLDER_NAMING	0x400

	#define	CAM_STARTUP_CRASH_FILE_OPEN_FIX	1				// enable fix for camera crash at startup when opening the conf / font files
															// see http://chdk.setepontos.com/index.php?topic=6179.0

#define CAM_FIRMWARE_MEMINFO    1       // Use 'GetMemInfo' to get free memory size.
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_g15)
    #define DIGIC				    5
    #define CAM_PROPSET                         5
    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1   // Draw pixels on active bitmap buffer only. Requires active_bitmap_buffer location in stubs_min.S or stubs_entry.S.

    #undef  CAM_AF_LED
    #define CAM_AF_LED                          3   // Index of AF led in camera_set_led function
    #define STD_360_BUF                 1
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800D
    #define UI_CT_PROP			    0x800E
    #define UI_AEB_PROP			    0x8010
    #define CAM_PRECISION_SYNCH         1	
    #define STD_PERIOD 			    _EngDrvRead(0xC0F06014)
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F070C8)
    #undef  PERIOD_REF
    #define PERIOD_REF			    1201
    #undef SYNCH_SPEED
    #define SYNCH_SPEED 				8 
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef  CAM_HAS_DISP_BUTTON
    #define CAM_HAS_ND_FILTER                   1
    #define CAM_HAS_NATIVE_ND_FILTER            1   // Camera has built-in ND filter with Canon menu support for enable/disable

    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_VIDEO_QUALITY_ONLY              1
    #define CAM_BRACKETING                      1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                     2   // use .CR2 

    #undef  CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH                10

    #define CAM_DNG_LENS_INFO                   { 61,10, 305,10, 18,10, 28,10 }    // See comments in camera.h

    // From G15 native RAW file as converted to DNG using Adobe DNG Converter
    // http://www.adobe.com/support/downloads/product.jsp?product=106&platform=Windows
    // Matrices from converted DNG's EXIF data
    #define cam_CalibrationIlluminant1          17      // Standard Light A
    #define cam_CalibrationIlluminant2          21      // D65
    #define CAM_COLORMATRIX1    \
      8204, 10000,  -3475, 10000,    326, 10000, \
     -2919, 10000,   9461, 10000,   4065, 10000, \
       159, 10000,    225, 10000,   4291, 10000
    #define CAM_COLORMATRIX2    \
      7474, 10000,  -2301, 10000,   -567, 10000, \
     -4056, 10000,  11456, 10000,   2975, 10000, \
      -222, 10000,    716, 10000,   4181, 10000
    #define CAM_CAMERACALIBRATION1    \
     10051, 10000,      0, 10000,      0, 10000, \
         0, 10000,  10000, 10000,      0, 10000, \
         0, 10000,      0, 10000,   9487, 10000
    #define CAM_CAMERACALIBRATION2    \
     10051, 10000,      0, 10000,      0, 10000, \
         0, 10000,  10000, 10000,      0, 10000, \
         0, 10000,      0, 10000,   9487, 10000
    #define CAM_FORWARDMATRIX1    \
      6648, 10000,   2566, 10000,    429, 10000, \
      1970, 10000,   9994, 10000,  -1964, 10000, \
      -894, 10000,  -2304, 10000,  11450, 10000
    #define CAM_FORWARDMATRIX2    \
      6617, 10000,   3849, 10000,   -823, 10000, \
      2400, 10000,  11138, 10000,  -3538, 10000, \
       -62, 10000,  -1147, 10000,   9460, 10000
    #define CAM_DNG_EXPOSURE_BIAS -3,4

    #define CAM_RAW_ROWPIX    4160 // Found @0xff1a77cc
    #define CAM_RAW_ROWS      3124 // Found @0xff1a77d4

    #define CAM_JPEG_WIDTH                      4034
    #define CAM_JPEG_HEIGHT                     3040
    // G15 native RAW converted to DNG's EXIF data: Active Area
    #define CAM_ACTIVE_AREA_X1                  104
    #define CAM_ACTIVE_AREA_Y1                  11
    #define CAM_ACTIVE_AREA_X2                  4152
    #define CAM_ACTIVE_AREA_Y2                  3059
    // G15 native RAW converted to DNG's EXIF data: CFA Pattern
    #define cam_CFAPattern                      0x02010100 // [Red,Green][Green,Blue]

    #define PARAM_CAMERA_NAME                   4       // parameter number for GetParameterData - Camera Model name
    #define PARAM_OWNER_NAME                    7       // parameter number for GetParameterData - Owner name
    #define PARAM_DISPLAY_MODE1                 59      // param number for LCD display mode when camera in playback
    #define PARAM_DISPLAY_MODE2                 62      // param number for LCD display mode when camera in record view hold mode
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1
    #define CAM_QUALITY_OVERRIDE                1
    #define CAM_REAR_CURTAIN                    1

    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                    960     // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT                   270     // Actual height of bitmap screen in rows

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  31
  
    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN 2

    #define CAM_DATE_FOLDER_NAMING              0x400

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX     1       // enable fix for camera crash at startup when opening the conf / font files
                                                        // see http://chdk.setepontos.com/index.php?topic=6179.0

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60      // delay after a press

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                        // Used to enabled bracketing in custom timer, required on many recent cameras
                                                        // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_AV_OVERRIDE_IRIS_FIX            1       // for cameras that require _MoveIrisWithAv function to override Av in bracketing.
    #define CAM_HAS_MOVIE_DIGEST_MODE          1       // Changes the values in the 'movie_status' variable if the camera has this mode

  //  #define CAM_LOAD_CUSTOM_COLORS              1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                     0xC0    // Start color index for CHDK colors loaded into camera palette.

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

    #define CAM_HAS_CMOS                        1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     70     // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     10567  // Override max subject distance

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1       // mkdir() return 1 on success, 0 on fail.

    // Define shortcut overrides where defaults are not suitable
    #define SHORTCUT_TOGGLE_ZEBRA           KEY_ERASE   // On camera Shutter Half Press + Up = switch MF on/off

    #define CAM_HAS_FILEWRITETASK_HOOK                  1
    #define CAM_FILEWRITETASK_SEEKS                     1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
//SD-Series (IXUS-Series)
//----------------------------------------------------------
#elif defined (CAMERA_ixus40)
    #define DIGIC				    2
    #define CAM_PROPSET                 1
    #define CDM                         0 
    #define STD_PERIOD 			*(volatile int*)(0x00306014)	
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_RAW_ROWPIX              2400
    #define CAM_RAW_ROWS                1766
    #define CAM_USE_ZOOM_FOR_MF 1
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_TURNS_OFF_LCD           1
    #undef  CAM_HAS_IS
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                                 \
      652674,  1000000, -172074, 1000000, -107575,  1000000, \
      -139063, 1000000, 594517,  1000000,  60252,   1000000, \
      -9088,   1000000, 82013,   1000000,  238080,  1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2272
    #define CAM_JPEG_HEIGHT 1704
    #define CAM_ACTIVE_AREA_X1 12
    #define CAM_ACTIVE_AREA_Y1 12
    #define CAM_ACTIVE_AREA_X2 2356
    #define CAM_ACTIVE_AREA_Y2 1764
    // camera name
    #define PARAM_CAMERA_NAME 2 // parameter number for GetParameterData
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------

#elif defined (CAMERA_ixus50)
    #define DIGIC				    2
    #define CAM_MOVIE_PLE               1
    #define CDM                         0  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  CAM_HAS_IS
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              2672   //for 5 MP
    #define CAM_RAW_ROWS                1968   //for 5 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                                  \
      685247,  1000000, -204939,  1000000, -106531,  1000000, \
     -267616,  1000000,  790509,  1000000,   73359,  1000000, \
       32401,  1000000,   15655,  1000000,  314892,  1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2592
    #define CAM_JPEG_HEIGHT 1944
    #define CAM_ACTIVE_AREA_X1 12
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 2628
    #define CAM_ACTIVE_AREA_Y2 1968
    // camera name
    #define PARAM_CAMERA_NAME 2 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus55)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CDM                         0  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_MOVIE_PLE               1
    #undef  CAM_HAS_IS
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              2672   //for 5 MP
    #define CAM_RAW_ROWS                1968   //for 5 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                                \
      536034,  1000000, -173429, 1000000, -89823,  1000000, \
      -290416, 1000000, 735807,  1000000,  47894,  1000000, \
      -71455,  1000000, 114314,  1000000,  274533, 1000000          
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2592
    #define CAM_JPEG_HEIGHT 1944
    #define CAM_ACTIVE_AREA_X1 12
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 2628
    #define CAM_ACTIVE_AREA_Y2 1968
    // camera name
    #define PARAM_CAMERA_NAME 3 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus60)
    #define DIGIC				    2
    #define CAM_MOVIE_PLE               1
    #define CDM                         0  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  CAM_HAS_IS
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              2888   //for 6 MP
    #define CAM_RAW_ROWS                2136   //for 6 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_FEATURE_FEATHER         1
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                                \
      767398,  1000000, -227658, 1000000, -144213, 1000000, \
      -217466, 1000000, 669319,  1000000,  38180,  1000000, \
      -23152,  1000000, 77743,  1000000,   238669, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2816
    #define CAM_JPEG_HEIGHT 2112
    #define CAM_ACTIVE_AREA_X1 44
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 2884
    #define CAM_ACTIVE_AREA_Y2 2136
    // camera name
    #define PARAM_CAMERA_NAME 3 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------

#elif defined (CAMERA_ixus65)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CDM                         0  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
 // #define CAM_MOVIE_PLE               1
    #undef  CAM_HAS_IS
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              2888   //for 6 MP
    #define CAM_RAW_ROWS                2136   //for 6 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_FEATURE_FEATHER         1
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                                \
      783384,  1000000, -227078, 1000000, -127919, 1000000, \
      -181247, 1000000, 661743,  1000000,  58868,  1000000, \
       25727,  1000000, 43891,   1000000,  247655, 1000000          
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2816
    #define CAM_JPEG_HEIGHT 2112
    #define CAM_ACTIVE_AREA_X1 44
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 2884
    #define CAM_ACTIVE_AREA_Y2 2136
    // camera name
    #define PARAM_CAMERA_NAME 3 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------

#elif defined (CAMERA_ixus70)
    #define DIGIC				    3
    #define CAM_PB_MODE                 1
    #define CDM                         99
    #define UI_CS_PROP			    0x8007 
    #define UI_CT_PROP			    0x8008 
    #define CAM_PRECISION_SYNCH         1 
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F0708C)
    #undef  PERIOD_REF
    #define PERIOD_REF			   81
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_PROPSET                 2       
 //   #undef  CAM_OUTLINE_MODE  
    #define CAM_RAW_ROWPIX              3152   //for 7 MP
    #define CAM_RAW_ROWS                2340   //for 7 MP
    #define CAM_MULTIPART               1 
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_TURNS_OFF_LCD           1
    #undef  CAM_HAS_IS
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                                \
      652674,  1000000, -172074, 1000000, -107575, 1000000, \
      -139063, 1000000, 594517,  1000000,  60252,  1000000, \
       -9088,  1000000, 82013,   1000000,  238048, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3072
    #define CAM_JPEG_HEIGHT 2304
    #define CAM_ACTIVE_AREA_X1 38
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 3146
    #define CAM_ACTIVE_AREA_Y2 2338
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY		    0xAF
    #define COLOR_GREY_P          0x7F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x3F
    #define COLOR_LIGHT_GREY_P    0xEE
    #define COLOR_DARK_GREY_P     0xDD

//---------------------------------------------------------- 

    #elif defined (CAMERA_ixus75)
    #define DIGIC				    3
    #define CAM_HAS_PLAYBACK_PB         1
    #define CDM                         0  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_PROPSET                 2
    #define CAM_NEED_HP                 1
    #define CAM_RAW_ROWPIX              3152        //for 7 MP 
    #define CAM_RAW_ROWS                2340        //for 7 MP 	     
    #undef CAM_USE_ZOOM_FOR_MF                      //Zoom lever can be used for manual focus adjustments 
    #define CAM_MULTIPART              1            //Camera supports SD-card multipartitioning
    #undef  CAM_DRAW_EXPOSITION                     //Output expo-pair on screen (for cameras which (sometimes) don't do that) 
    #undef CAM_HAS_ERASE_BUTTON                     //Camera has dedicated erase button 
    #undef CAM_HAS_IRIS_DIAPHRAGM                   //Camera has real diaphragm mechanism 
    #define  CAM_HAS_ND_FILTER         1            //Camera has build-in ND filter 
    #undef CAM_CAN_SD_OVER_NOT_IN_MF                //Camera allows subject distance (focus) override when not in manual focus mode 
    #undef CAM_CAN_SD_OVERRIDE                      //Camera allows to do subject distance override 
    #undef CAM_HAS_MANUAL_FOCUS                     //Camera has manual focus mode 
    #define CAM_HAS_USER_TV_MODES       1           //Camera has tv-priority or manual modes with ability to set tv value 
    #define  CAM_SHOW_OSD_IN_SHOOT_MENU 1           //On some cameras Canon shoot menu has additional functionality and useful in this case to see CHDK OSD in this mode   
    #define  CAM_FEATURE_FEATHER        1           //Cameras with "feather" or touch wheel. 
    #undef CAM_HAS_IS                               //Camera has image stabilizer
 
     #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                                \
      689833,  1000000, -198299, 1000000, -101299, 1000000, \
      -164267, 1000000, 667466,  1000000,  74132,  1000000, \
       -36515,  1000000, 123872,   1000000,  248498, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3072
    #define CAM_JPEG_HEIGHT 2304
    #define CAM_ACTIVE_AREA_X1 38
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 3146
    #define CAM_ACTIVE_AREA_Y2 2338
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1         
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus80)
    #define DIGIC				    3
    #define CAM_PB_MODE                 1
    #define CDM                         99
    #define UI_CS_PROP			    0x8007
    #define UI_CT_PROP			    0x8008    
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_PROPSET                 2
    #define CAM_DRYOS                   1

    #define CAM_RAW_ROWPIX              3336   //for new 8 MP
    #define CAM_RAW_ROWS                2480   //for new 8 MP

    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO 1
    #undef  CAM_CAN_MUTE_MICROPHONE
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 0
    #define cam_CFAPattern 0x01000201 // Green  Blue  Red  Green
    // color
    #define CAM_COLORMATRIX1                                \
      893969,  1000000, -343107, 1000000, -119590, 1000000, \
      -41350,  1000000, 581255,  1000000,  49523,  1000000, \
       24221,  1000000, 47554,   1000000,  209996, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3264
    #define CAM_JPEG_HEIGHT 2448
    #define CAM_ACTIVE_AREA_X1 6
    #define CAM_ACTIVE_AREA_Y1 6
    #define CAM_ACTIVE_AREA_X2 3304
    #define CAM_ACTIVE_AREA_Y2 2476
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
 #elif defined (CAMERA_ixus85)
    #define DIGIC				    3

   #define CAM_PROPSET                     2
    #define CAM_DRYOS                       1

    #define CAM_RAW_ROWPIX                  3720
    #define CAM_RAW_ROWS                    2772
    #define CAM_PB_MODE                 1
    #define CDM                         0  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30	
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_MULTIPART                   1
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER               1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_HAS_HI_ISO_AUTO_MODE        1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_EXT_TV_RANGE                1       // CHDK can make exposure time longer than 64s

    #define CAM_DNG_LENS_INFO               { 62,10, 186,10, 28,10, 49,10 } // See comments in camera.h
    // pattern
    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                              \
     827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829, 1000000,  530507, 1000000,   50537, 1000000, \
       5181, 1000000,   48183, 1000000,  245014, 1000000
    #define cam_CalibrationIlluminant1      1       // Daylight

    // cropping
    #define CAM_JPEG_WIDTH                  3648
    #define CAM_JPEG_HEIGHT                 2736
    #define CAM_ACTIVE_AREA_X1              6
    #define CAM_ACTIVE_AREA_Y1              12
    #define CAM_ACTIVE_AREA_X2              3690
    #define CAM_ACTIVE_AREA_Y2              2772

    // camera name
    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12
	
	#define REMOTE_SYNC_STATUS_LED 	0xc02200D4		// specifies an LED that turns on while camera waits for USB remote to sync
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------

#elif defined (CAMERA_ixus90)
    #define DIGIC				    3
    #define CAM_PROPSET                 2
    #define NEW_REC_PLAY			1
    #define CDM                         0  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_DRYOS                   1
    #define CAM_NEED_HP                 1
    #define CAM_RAW_ROWPIX              3720
    #define CAM_RAW_ROWS                2772
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #undef CAM_USE_ZOOM_FOR_MF
    #undef CAM_HAS_ERASE_BUTTON
    #define CAM_MULTIPART               1
    #undef CAM_HAS_IRIS_DIAPHRAGM
    #undef CAM_HAS_MANUAL_FOCUS
    #define CAM_HAS_ND_FILTER           1
    #undef CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
	 #define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO 1
    #define CAM_HAS_JOGDIAL             1
    #undef CAM_VIDEO_CONTROL
    #define CAM_EXT_TV_RANGE            1          // CHDK can make exposure time longer than 64s
    // pattern
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829,  1000000, 530507,  1000000, 50537,   1000000, \
      5181,   1000000, 48183,   1000000, 245014,  1000000
    #define cam_CalibrationIlluminant1 1 // Daylight

    // cropping 
    #define CAM_JPEG_WIDTH  3648
    #define CAM_JPEG_HEIGHT 2736
    #define CAM_ACTIVE_AREA_X1 6
    #define CAM_ACTIVE_AREA_Y1 12
    #define CAM_ACTIVE_AREA_X2 3690
    #define CAM_ACTIVE_AREA_Y2 2772

    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus95)
    #define DIGIC				    4
	#define CAM_PROPSET                  2 
	#define CAM_DRYOS                    1
      //#undef CAM_DIGIC
      //#define CAM_DIGIC			       4
      #define CAM_NEED_HP                  1
      #define CAM_HAS_PLAYBACK_PB          1
	#define CAM_RAW_ROWPIX               3720
	#define CAM_RAW_ROWS                 2772
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
	#undef   CAM_HAS_ERASE_BUTTON
	#define  CAM_USE_ZOOM_FOR_MF         1
	#define  CAM_MULTIPART               1
    #define STD_360_BUF				1
     #define NEW_REC_PLAY			1
    #define CDM                         99
    #define UI_CS_PROP			    0x8008
    #define UI_CT_PROP			    0x8009  
    #define STD_PERIOD 			*(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			      200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
	#undef   CAM_HAS_IRIS_DIAPHRAGM
	#define  CAM_HAS_ND_FILTER           1
      #undef  CAMERA_MAX_DIST
      #define CAMERA_MAX_DIST			2000000
	#undef CAM_SYNCH

	#define CAM_HAS_ZOOM_LEVER          1

	#undef  CAM_HAS_MANUAL_FOCUS
	#define  CAM_HAS_USER_TV_MODES		 1 
	#define  CAM_SHOW_OSD_IN_SHOOT_MENU	 1
	#define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO  1
	//#define CAM_AF_SCAN_DURING_VIDEO_RECORD       1
	#undef CAM_AF_SCAN_DURING_VIDEO_RECORD		//TODO: change to define and find NSTUB    
	#define  CAM_CHDK_HAS_EXT_VIDEO_MENU	 1
	#undef CAM_HAS_JOGDIAL
      #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
	#undef   CAM_VIDEO_CONTROL
	#define  CAM_VIDEO_QUALITY_ONLY		 	1
      #define CAM_TURNS_OFF_LCD           1
	//#define CAM_EXT_TV_RANGE            1

	#undef   CAM_UNCACHED_BIT            // shut up compiler
	#define  CAM_UNCACHED_BIT            0x40000000

	#undef   CAM_BITMAP_PALETTE
	#define  CAM_BITMAP_PALETTE          5

	#undef ZEBRA_HMARGIN0
	#define ZEBRA_HMARGIN0              150			//zebra adjust 

	#define CAM_QUALITY_OVERRIDE 1	
	#undef   CAM_SENSOR_BITS_PER_PIXEL
	#define  CAM_SENSOR_BITS_PER_PIXEL   12
	#undef   CAM_WHITE_LEVEL
	#define  CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
	#undef   CAM_BLACK_LEVEL
	#define  CAM_BLACK_LEVEL             127

/*
	// pattern
	#define  cam_CFAPattern 0x01000201 // Green  Blue  Red  Green

	// color preliminary
	// Stole this from sd990 VERIFY_SD1200
	#define  CAM_COLORMATRIX1                             \
    837237, 1000000, -290137, 1000000, -128156, 1000000, \
    -127762, 1000000, 643909, 1000000, 52973, 1000000, \
    4446, 1000000, 88354, 1000000, 224246, 1000000
*/
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue

	// color preliminary
	// from para in forum
	#define  CAM_COLORMATRIX1                             \
    1484685, 1000000, -530958, 1000000, -208054, 1000000, \
    143142, 1000000, 793552, 1000000, 83907, 1000000, \
    146290, 1000000, -44679, 1000000, 430414, 1000000

	#define  cam_CalibrationIlluminant1 1 // Daylight

	// cropping 
	#define  CAM_JPEG_WIDTH  3648
	#define  CAM_JPEG_HEIGHT 2736
	#define  CAM_ACTIVE_AREA_X1 8
	#define  CAM_ACTIVE_AREA_Y1 12
	#define  CAM_ACTIVE_AREA_X2 3692
	#define  CAM_ACTIVE_AREA_Y2 2772
    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720 // Actual width of bitmap screen in bytes

	// camera name
	#define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------

#elif defined (CAMERA_ixus100)
    #define DIGIC				    4
    #undef  EDGE_OVERLAY_COLOUR 
    #define EDGE_OVERLAY_COLOUR         0xA7
    #define CAM_PROPSET                 2 // all values checked so far match propset 2
    #define CAM_DRYOS                   1
 //   #undef CAM_DIGIC
 //   #define CAM_DIGIC			    4
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
//VERIFY_SD780 Found RAW #s by searching " CrwAddress %lx, CrwSize H %ld V %ld\r"
    #define CAM_RAW_ROWPIX              4080 // 12 MP 12bpp
    #define CAM_RAW_ROWS                3048
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_MULTIPART               1
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST			2000000
    #define STD_360_BUF                 1
    #define CDM                         99
    #define UI_CS_PROP			    0x8008
    #define UI_CT_PROP			    0x8009  
    #define STD_PERIOD 			*(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   250
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30  // 1280x720
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #define  CAM_HAS_MANUAL_FOCUS	    1
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX    1
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE    	    5
    #define CAM_QUALITY_OVERRIDE 1
    #undef CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #undef CAM_WHITE_LEVEL
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #undef CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL             127
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
/*
    // pattern
    //RealRom:FFA99FB4                    ADR     R0, aObRG1G2BLdLdLd ; "\n  OB : (R, G1, G2, B) = (%ld, %ld, %ld"...
    #define cam_CFAPattern              0x02010100		// Red  Green  Green  Blue

    // color preliminary (see DNG4PS2 wiki)
    #define CAM_COLORMATRIX1                               \
      661840,  1000000, -185671, 1000000, -97110,  1000000, \
      -83661,  1000000, 578860, 1000000,   32308,  1000000, \
      -8681,    1000000, 70356,   1000000, 207341, 1000000

    //Here is an alternate CAM_COLORMATRIX1 - Current one is nice for me but hey I'm no colour expert.
    //XYZ -> Camera matrix:
    //0.459395 -0.129083 -0.068085
    //-0.055837 0.400827 0.020378
    //-0.004622 0.048662 0.139970

    #define cam_CalibrationIlluminant1  17			// Standard Light A

	// cropping
    #define CAM_JPEG_WIDTH              4000
    #define CAM_JPEG_HEIGHT             3000
    #define CAM_ACTIVE_AREA_X1          40
    #define CAM_ACTIVE_AREA_Y1          24
    #define CAM_ACTIVE_AREA_X2          4056
    #define CAM_ACTIVE_AREA_Y2          3040
*/
    #define cam_CFAPattern 0x02010100 // 0xFFE7AC54  Red  Green  Green  Blue 
    // color
    #define CAM_COLORMATRIX1                               \
      913762, 1000000, -261578, 1000000, -135582, 1000000, \
      -99049, 1000000, 1067089, 1000000,  61442,  1000000, \
      48717,  1000000, 96802,   1000000,  412056, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  4000
    #define CAM_JPEG_HEIGHT 3000
    #define CAM_ACTIVE_AREA_X1 48
    #define CAM_ACTIVE_AREA_Y1 12
    #define CAM_ACTIVE_AREA_X2 4080
    #define CAM_ACTIVE_AREA_Y2 3036
    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    // camera name
    #define PARAM_CAMERA_NAME           4			// parameter number for GetParameterData sd990: OK
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_ixus105)
    #define DIGIC				    4
    #define CAM_DRYOS_2_3_R39		    1
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1
    #define CAM_PROPSET                 3
    #define CAM_DRYOS                   1
  //  #undef CAM_DIGIC
  //  #define CAM_DIGIC			    4
    #define CAM_NEED_HP                 1
    #define CAM_MULTIPART               1
    #define STD_360_BUF				1
    #define	CAM_DATE_FOLDER_NAMING	    0x400
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x8009
    #define UI_CT_PROP			    0x800A 
    #define STD_PERIOD 			*(volatile int*)(0x00386014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  PERIOD_REF
    #define PERIOD_REF			   70
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F0700C)
    #define LOW_LIGHT                   1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_MOVIE_PLE               1
 //   #define CAM_USES_EXMEM              1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_RAW_ROWPIX              4104
    #define CAM_RAW_ROWS                3048 
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_VIDEO_QUALITY_ONLY          1
    #undef  CAM_VIDEO_CONTROL
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef CAM_HAS_ERASE_BUTTON
    #define  CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_EXT_TV_RANGE            1
    #define CAM_HAS_ND_FILTER           1
    #define  cam_CFAPattern 0x01000201 // Green  Blue  Red  Green

    #define cam_CalibrationIlluminant1      21      // D65
    // D10 profile
    #define CAM_COLORMATRIX1                        \
      14052, 10000,   -5229, 10000,   -1156, 10000, \
      -1325, 10000,    9420, 10000,    2252, 10000, \
       -498, 10000,    1957, 10000,    4116, 10000

    // cropping
    #define CAM_JPEG_WIDTH    4000
    #define CAM_JPEG_HEIGHT   3000
    #define CAM_ACTIVE_AREA_X1   8
    #define CAM_ACTIVE_AREA_Y1  24
    #define CAM_ACTIVE_AREA_X2 4008
    #define CAM_ACTIVE_AREA_Y2 3024


    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127
    
    //nandoide sept-2009
    #undef CAM_USES_ASPECT_CORRECTION   
    #undef CAM_USES_ASPECT_YCORRECTION  
    #define CAM_USES_ASPECT_CORRECTION  1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #define CAM_USES_ASPECT_YCORRECTION  0  //only uses mappings on x coordinate

    //default mappings
    #undef ASPECT_XCORRECTION
    #define ASPECT_XCORRECTION(x)  ( ( ((x)<<3) + (x) )  >>2 )   //correction x*screen_buffer_width/screen_width = x*720/320 = x*9/4 = (x<<3 + x)>>2

    //grids
    #undef ASPECT_GRID_XCORRECTION
    #define ASPECT_GRID_XCORRECTION(x)  ( ((x)<<3)/9  )  //grids are designed on a 360x240 basis and screen is 320x240, we need x*320/360=x*8/9
    #undef ASPECT_GRID_YCORRECTION
    #define ASPECT_GRID_YCORRECTION(y)  ( (y) )       //y correction for grids  made on a 360x240 As the buffer is 720x240 we have no correction here.
    
    //viewport
    #undef ASPECT_VIEWPORT_XCORRECTION 
    #define ASPECT_VIEWPORT_XCORRECTION(x) ASPECT_GRID_XCORRECTION(x) //viewport is 360x240 and screen 320x240, we need x*320/360=x*8/9, equal than grids, used by edgeoverlay
    #undef ASPECT_VIEWPORT_YCORRECTION 
    #define ASPECT_VIEWPORT_YCORRECTION(y) ( (y) ) 
    #undef EDGE_HMARGIN 
    #define EDGE_HMARGIN 20
    
    //games mappings
    #undef GAMES_SCREEN_WIDTH
    #undef GAMES_SCREEN_HEIGHT
    #define GAMES_SCREEN_WIDTH 360
    #define GAMES_SCREEN_HEIGHT 240
    #undef ASPECT_GAMES_XCORRECTION
    #define ASPECT_GAMES_XCORRECTION(x)   ( ((x)<<1) )  
    #undef ASPECT_GAMES_YCORRECTION
    #define ASPECT_GAMES_YCORRECTION(y)   ( (y) )  //none
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE          9
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_ixus115)
    #define DIGIC				    4
    #define CAM_PROPSET                     4
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1
    #define CAM_DRYOS_2_3_R47               1

    #define CAM_RAW_ROWPIX                  4168
    #define CAM_RAW_ROWS                    3060    // actual size from fw 12754080pix at FF375484 -> 19131120/12*8
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000

    #define CAM_JPEG_WIDTH                  4000
    #define CAM_JPEG_HEIGHT                 3000
    #define CAM_ACTIVE_AREA_X1              92      // note: wide angle shots have a dark border (that area is excluded from vignetting correction)
    #define CAM_ACTIVE_AREA_Y1              16
    #define CAM_ACTIVE_AREA_X2              4164
    #define CAM_ACTIVE_AREA_Y2              3060
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_UP
    #define STD_360_BUF                 1
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #undef  VIDEO_STD
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         10  // Canon drive mode	
    #define STD_PERIOD 			    _EngDrvRead(0xC0F06014)
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F0700C)
    #undef  PERIOD_REF
    #define PERIOD_REF			    391
    #define CAM_PRECISION_SYNCH         1
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV" 
    #undef  CAM_HAS_DISP_BUTTON
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION      10
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_BRACKETING                  1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY          1
    #define CAM_EXT_TV_RANGE                1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_HAS_MOVIE_DIGEST_MODE       1
	//#define CAM_EV_IN_VIDEO               1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1
    #define CAM_QUALITY_OVERRIDE            1

    #define CAM_HAS_ZOOM_LEVER               1    // Camera has dedicated zoom buttons
//    #define CAM_USE_ZOOM_FOR_MF              1    // Zoom lever can be used for manual focus adjustments    
    #define CAM_NEED_SET_ZOOM_DELAY          100  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoo

    #define CAM_HAS_CMOS                    1
    #define CAM_HAS_ND_FILTER               1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_IRIS_DIAPHRAGM

    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1
    #define DNG_VERT_RLE_BADPIXELS          1
    #define CAM_AV_OVERRIDE_IRIS_FIX        1       // for cameras that require _MoveIrisWithAv function to override Av.
    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY             60      // delay after a press
 
    #define CAM_HAS_VIDEO_BUTTON            1
    #undef  DNG_BADPIXEL_VALUE_LIMIT
    #define DNG_BADPIXEL_VALUE_LIMIT        16      // Camera sensor apparently has bad pixels with value > 0 & <=16

    #define CAM_DNG_LENS_INFO               { 50,10, 200,10, 28,10, 59,10 } // See comments in camera.h
    #define cam_CFAPattern  0x02010100

    #define CAM_COLORMATRIX1    \
    544808, 1000000, -174047, 1000000, -80399, 1000000, \
    -75055, 1000000,  440444, 1000000,  11367, 1000000, \
     -5801, 1000000,   71589, 1000000, 118914, 1000000

    #define cam_CalibrationIlluminant1      1

    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12
    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              22
 //   #define CAM_LOAD_CUSTOM_COLORS          1
    #define CHDK_COLOR_BASE                 0xE1

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                    10

    #define CAM_ZEBRA_NOBUF                 1

    #define CAM_QUALITY_OVERRIDE            1
    #define CAM_DATE_FOLDER_NAMING          0x400

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1


    #define REMOTE_SYNC_STATUS_LED 	0xC0220130   // specifies an LED that turns on while camera waits for USB remote to sync


    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                // Used to enabled bracketing in custom timer, required on many recent cameras
                                                //    see http://chdk.setepontos.com/index.php/topic,3994.405.html
 
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_ixus130)
    #define DIGIC				    4
    #define CAM_PROPSET                     3
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1

    #define CAM_RAW_ROWPIX                  4416        // 14 MP 12bpp
    #define CAM_RAW_ROWS                    3296        //

    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_MULTIPART                   1
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER               1

    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY          1

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000

    #define CAM_MAKE                        "Canon"

    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes

    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #define CAM_ZEBRA_NOBUF                 1

    #define CAM_QUALITY_OVERRIDE            1
    #undef CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_DNG_LENS_INFO               { 50,10, 200,10, 28,10, 59,10 } // See comments in camera.h

    #define cam_CFAPattern                  0x02010100        // Red  Green  Green  Blue

    #define CAM_COLORMATRIX1 510370, 1000000, -68998, 1000000,  -86859, 1000000, \
                            -279980, 1000000, 766686, 1000000,   67944, 1000000, \
                             -14382, 1000000, 113688, 1000000,  239853, 1000000

    #define cam_CalibrationIlluminant1      17            // Standard Light A

    #define CAM_ACTIVE_AREA_X1              48
    #define CAM_ACTIVE_AREA_Y1              28
    #define CAM_ACTIVE_AREA_X2              4416-48
    #define CAM_ACTIVE_AREA_Y2              3296-28

    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         12  // Canon drive mode	
    #define STD_PERIOD 			    _EngDrvRead(0xC0F06014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              15 

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized

    // cropping
    #define CAM_JPEG_WIDTH                  4320
    #define CAM_JPEG_HEIGHT                 3240
    // camera name
    #define PARAM_CAMERA_NAME               4            // parameter number for GetParameterData sd990: OK
    #define CAM_DATE_FOLDER_NAMING          0x100

    #define CAM_HAS_FILEWRITETASK_HOOK      1

    #define CAM_SD_OVER_IN_AF               1
    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

    #define CAM_IS_VID_REC_WORKS            1   // is_video_recording() function works
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_ixus132)
    #define DIGIC				    4
    #define CAM_PROPSET                     6
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher

    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION         6   // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    #define CAM_RAW_ROWPIX                  4704 // Found @0xff1be31c
    #define CAM_RAW_ROWS                    3504 // Found @0xff1be328

    #define CAM_JPEG_WIDTH                  4608
    #define CAM_JPEG_HEIGHT                 3456

    // TODO: defined to pixels containing any data, commented excludes darker border
    #define CAM_ACTIVE_AREA_X1              12   // 28
    #define CAM_ACTIVE_AREA_Y1              10   // 20
    #define CAM_ACTIVE_AREA_X2              4666 // 4652
    #define CAM_ACTIVE_AREA_Y2              3492 // 3480

    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
 
    #define CDM                         12  // Canon drive mode	
    #define STD_PERIOD 			    _EngDrvRead(0xC0F06014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              19 

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT  0x40000000 // Found @0xff038dd4

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_DNG_LENS_INFO               { 50,10, 400,10, 32,10, 69,10 } // See comments in camera.h

    #define cam_CFAPattern                  0x01000201 // Green  Blue  Red  Green

    // TODO C&P from D10
    #define CAM_COLORMATRIX1                        \
      14052, 10000,   -5229, 10000,   -1156, 10000, \
      -1325, 10000,    9420, 10000,    2252, 10000, \
       -498, 10000,    1957, 10000,    4116, 10000
    #define cam_CalibrationIlluminant1      21      // D65

    // no separate erase button
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_DISP_BUTTON
    #define CAM_HAS_VIDEO_BUTTON            1
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER               1

    // long shutter is actually user TV, may work ?
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #undef  CAM_VIDEO_CONTROL
// not working
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
//    #define CAM_VIDEO_QUALITY_ONLY          1
//    #define CAM_CHDK_HAS_EXT_VIDEO_MENU     1

    // TODO
//    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1

    #undef CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO  // unlocked in canon firmware by default

    #undef  CAM_HAS_MANUAL_FOCUS

    // MakeDirectory_Fut not found, using mkdir
    #define MKDIR_RETURN_ONE_ON_SUCCESS

    //aspect correction
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720 // Actual width of bitmap screen in bytes

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY 1   // Draw pixels on active bitmap buffer only.
//    #define CHDK_COLOR_BASE                 0x73
//    #define CAM_LOAD_CUSTOM_COLORS          1   // Enable loading CHDK colors into the camera palette memory/hardware
    // doesn't seem to conflict badly with anything

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                    // Used to enabled bracketing in custom timer, required on many recent cameras
                                                    // see http://chdk.setepontos.com/index.php/topic,3994.405.html
    #undef  CAM_HAS_DISP_BUTTON 

    // verified
    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                 0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                 20      // Override min subject distance in macro mode
    #undef CAMERA_MAX_DIST
    // TODO largest value obtained focusing at distant things
    #define CAMERA_MAX_DIST                 775194       // Define max distance that can be set in _MoveFocusLensToDistance (allow override for superzooms - SX30/SX40)

    // TODO
    #define CAM_DATE_FOLDER_NAMING          0x80

    #define PARAM_CAMERA_NAME               3       // parameter number for GetParameterData

    #define CAM_FILE_COUNTER_IS_VAR         1       // file counter is variable file_counter_var in stubs, not a param

    #define  CAM_HAS_FILEWRITETASK_HOOK     1   // FileWriteTask hook is available (local file write can be prevented)
    #define  CAM_FILEWRITETASK_SEEKS        1   // Camera's FileWriteTask can do Lseek() - DryOS r50 or higher, the define could also be CAM_DRYOS_2_3_R50

    #define CAM_USE_ALT_SET_ZOOM_POINT       1
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1

    // TODO
    // only non-AF led available
    #define REMOTE_SYNC_STATUS_LED          0xC0220094  // specifies an LED that turns on while camera waits for USB remote to sync

    #undef CAM_AF_LED
    #define CAM_AF_LED                      1

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE 1     // For cameras with 'low light' mode that does not work with raw define this
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_ixus140)
    #define DIGIC				    4
    #define CAM_PROPSET                     6
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher

    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION         6   // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    #define CAM_RAW_ROWPIX                  4704    // Found @0xff1be31c
    #define CAM_RAW_ROWS                    3504    // Found @0xff1be328

    #define CAM_JPEG_WIDTH                  4608
    #define CAM_JPEG_HEIGHT                 3456

    // defined to pixels containing any data, commented excludes darker border
    #define CAM_ACTIVE_AREA_X1              12      // 28
    #define CAM_ACTIVE_AREA_Y1              10      // 20
    #define CAM_ACTIVE_AREA_X2              4666    // 4652
    #define CAM_ACTIVE_AREA_Y2              3492    // 3480

    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #undef  VIDEO_STD
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800D
    #define UI_CT_PROP			    0x800E 
    #define STD_PERIOD 			    _EngDrvRead(0xC0F06014) 
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    25  // 1280x720
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
 // #define CAM_LOAD_CUSTOM_COLORS          1 
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              19 
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff038dd4

    #undef CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_DNG_LENS_INFO               { 50,10, 400,10, 32,10, 69,10 } // See comments in camera.h

    // verified
    #define cam_CFAPattern                  0x01000201 // Green  Blue  Red  Green

    // TODO C&P from D10
    #define CAM_COLORMATRIX1                        \
      14052, 10000,   -5229, 10000,   -1156, 10000, \
      -1325, 10000,    9420, 10000,    2252, 10000, \
       -498, 10000,    1957, 10000,    4116, 10000
    #define cam_CalibrationIlluminant1      21      // D65

    #define CAM_HAS_VIDEO_BUTTON            1
    // no separate erase button
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_DISP_BUTTON
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER               1

    // long shutter is actually user TV, may work ?
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #undef  CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                 200 // Override base 'market' ISO value

    #undef  CAM_VIDEO_CONTROL
// not working
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU

    // TODO
//    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO  // unlocked in canon firmware by default

    #undef  CAM_HAS_MANUAL_FOCUS

    // MakeDirectory_Fut not found, using mkdir
    #define MKDIR_RETURN_ONE_ON_SUCCESS

    //aspect correction
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720     // Actual width of bitmap screen in bytes

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY 1     // Draw pixels on active bitmap buffer only.

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                    // Used to enabled bracketing in custom timer, required on many recent cameras
                                                    // see http://chdk.setepontos.com/index.php/topic,3994.405.html
    #undef  CAM_HAS_DISP_BUTTON 

    // verified
    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                 0x202   // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                 20      // Override min subject distance in macro mode
    #undef CAMERA_MAX_DIST
    // TODO largest value obtained focusing at distant things
    #define CAMERA_MAX_DIST              775194       // Define max distance that can be set in _MoveFocusLensToDistance (allow override for superzooms - SX30/SX40)

    // TODO the following is required to make the IN_AF_LOCK_ONLY logic work, even though the camera has no MF
    // this requires PROPCASE_AFLOCK be set if using set_aflock from script
    #undef CAM_CAN_SD_OVER_NOT_IN_MF
    #define  CAM_CAN_SD_OVER_IN_AF_LOCK_ONLY 1      // Camera allows subject distance (focus) override only when in AF Lock mode OR in movie mode

    #define CAM_DATE_FOLDER_NAMING          0x80

    #define PARAM_CAMERA_NAME               3       // parameter number for GetParameterData

    #define CAM_FILE_COUNTER_IS_VAR         1       // file counter is variable file_counter_var in stubs, not a param

    #define  CAM_HAS_FILEWRITETASK_HOOK     1       // FileWriteTask hook is available (local file write can be prevented)
    #define  CAM_FILEWRITETASK_SEEKS        1       // Camera's FileWriteTask can do Lseek() - DryOS r50 or higher, the define could also be CAM_DRYOS_2_3_R50

//    only non-AF led available
    #define REMOTE_SYNC_STATUS_LED          0xC0220094 // specifies an LED that turns on while camera waits for USB remote to sync

    #undef CAM_AF_LED
    #define CAM_AF_LED                      1

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE 1     // For cameras with 'low light' mode that does not work with raw define this

    #define SHORTCUT_TOGGLE_RAW             KEY_VIDEO  // conflicts with adjustable alt, but not many to choose from

    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS 1       // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT      1       // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1      // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define CAM_IS_VID_REC_WORKS                1   // is_video_recording() function works
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_ixus220)
    #define DIGIC				    4
    #define CAM_DRYOS_2_3_R47               1
    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1
    #define DNG_VERT_RLE_BADPIXELS          1
    #define CAM_AV_OVERRIDE_IRIS_FIX        1       // for cameras that require _MoveIrisWithAv function to override Av.
    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY             60      // delay after a press
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1
 //   #undef CAM_DIGIC
 //   #define CAM_DIGIC			        4
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                       10 
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    24 // 23.976 actual 1920x1080 HD,also 120 fps at 640x480 and 29.97 at 1280x720, 240 fps at 320x240	
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              22 
    #undef  CAM_HAS_DISP_BUTTON
    #define CAM_DRYOS_2_3_R39               1
    #define CAM_PROPSET                     4
    #define CAM_DATE_FOLDER_NAMING          0x400
    #define CAM_DRYOS                       1
    #define CAM_RAW_ROWPIX                  4168
    #define CAM_RAW_ROWS                    3060    // actual size from fw 12754080pix at FF375484 -> 19131120/12*8
    #define CAM_HAS_ND_FILTER               1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #define CAM_CAN_SD_OVER_IN_AF_LOCK      1
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON            1
    #define CAM_VIDEO_QUALITY_ONLY          1
    #undef  CAM_VIDEO_CONTROL
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_UNCACHED_BIT                        // shut up compiler
    #define CAM_UNCACHED_BIT                0x40000000

    #undef  DNG_BADPIXEL_VALUE_LIMIT
    #define DNG_BADPIXEL_VALUE_LIMIT        16      // Camera sensor apparently has bad pixels with value > 0 & <=16

    #define CAM_DNG_LENS_INFO               { 43,10, 215,10, 27,10, 59,10 } // See comments in camera.h
    #define cam_CFAPattern  0x02010100
  
    #define CAM_COLORMATRIX1    \
    544808, 1000000, -174047, 1000000, -80399, 1000000, \
    -75055, 1000000,  440444, 1000000,  11367, 1000000, \
     -5801, 1000000,   71589, 1000000, 118914, 1000000
    
    #define cam_CalibrationIlluminant1      1
   
    #define CAM_JPEG_WIDTH                  4000
    #define CAM_JPEG_HEIGHT                 3000
    #define CAM_ACTIVE_AREA_X1              120
    #define CAM_ACTIVE_AREA_Y1              36
    #define CAM_ACTIVE_AREA_X2              4136
    #define CAM_ACTIVE_AREA_Y2              3040
    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12
    #define CAM_EXT_TV_RANGE                1
    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #define CAM_HAS_VARIABLE_ASPECT         1
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                    10

    #define CAM_ZEBRA_NOBUF                 1

    #define CAM_QUALITY_OVERRIDE            1

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1

    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #undef  CAM_HAS_MANUAL_FOCUS
    
    #define CAM_USE_ALT_SET_ZOOM_POINT      1   // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1  // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define CAM_HAS_CMOS                    1
	

	#define REMOTE_SYNC_STATUS_LED 	0xC0220130		// specifies an LED that turns on while camera waits for USB remote to sync
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1

 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_ixus700)
    #define DIGIC				    2
    #define CAM_PROPSET                 1
    #define CDM                         0  
    #define CAM_RAW_ROWPIX              3152   //for 7 MP
    #define CAM_RAW_ROWS                2340   //for 7 MP
    #undef  CAM_SYNCH
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_DRAW_EXPOSITION         1
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #undef  CAM_CAN_SD_OVERRIDE
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef  CAM_HAS_IS
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1         \
      15265, 1, -6193,  1, -1558, 1, \
     -4125,  1,  12116, 1,  2010, 1, \
      -888,  1,  1639,  1,  5220, 1
    
    #define cam_CalibrationIlluminant1 17 // Standard light A
    // cropping
    #define CAM_JPEG_WIDTH  3072
    #define CAM_JPEG_HEIGHT 2304
    #define CAM_ACTIVE_AREA_X1 38
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 3146
    #define CAM_ACTIVE_AREA_Y2 2338
    // camera name
    #define PARAM_CAMERA_NAME 2 // parameter number for GetParameterData
 
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0xEE
    #define COLOR_DARK_GREY       0xEF
    #define COLOR_LIGHT_GREY_P    0xEE
    #define COLOR_DARK_GREY_P     0xEF

//----------------------------------------------------------

#elif defined (CAMERA_ixus750)
    #define DIGIC				    2
    #define CAM_PROPSET                     1
    #define CDM                             0    // *********** CHECK **********
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_RAW_ROWPIX                  3152    // for 7 MP
    #define CAM_RAW_ROWS                    2340    // for 7 MP

    #define CAM_DRAW_EXPOSITION             1
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER               1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1
    #undef  CAM_HAS_IS
    #define CAM_MULTIPART                   1

    #define CAM_DNG_LENS_INFO               { 77,10, 231,10, 28,10, 49,10 } // See comments in camera.h
    // pattern
    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      580280, 1000000, -172239, 1000000, -89707,  1000000, \
     -206596, 1000000,  634926, 1000000,  63877,  1000000, \
       10377, 1000000,   62053, 1000000, 242646,  1000000

    #define cam_CalibrationIlluminant1      1       // Daylight
    // cropping
    #define CAM_JPEG_WIDTH                  3072
    #define CAM_JPEG_HEIGHT                 2304
    #define CAM_ACTIVE_AREA_X1              36
    #define CAM_ACTIVE_AREA_Y1              12
    #define CAM_ACTIVE_AREA_X2              3148
    #define CAM_ACTIVE_AREA_Y2              2340
    // camera name
    #define PARAM_CAMERA_NAME               3       // parameter number for GetParameterData
	
//	#define REMOTE_SYNC_STATUS_LED 	0xC0xxyyyy		// specifies an LED that turns on while camera waits for USB remote to sync

    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus800)
    #define DIGIC				    2
    #define CAM_PB_MODE                 1
    #define CDM                         0  
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              2888   //for 6 MP
    #define CAM_RAW_ROWS                2136   //for 6 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_DRAW_EXPOSITION         1
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_TURNS_OFF_LCD           1
 // Warning! DNG4PS2 has both ixus800 and sd700 support with different CFA patterns and color matrices. 
 // Used settings for IXUS800

    // pattern
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1          \
      14062, 1, -5199,  1, -1446,  1, \
      -4712, 1,  12470, 1,  2243,  1, \
      -1286, 1,  2028,  1,  4836,  1
    
    #define cam_CalibrationIlluminant1 17 // Standard light A
    // cropping
    #define CAM_JPEG_WIDTH  2816
    #define CAM_JPEG_HEIGHT 2112
    #define CAM_ACTIVE_AREA_X1 44
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 2884
    #define CAM_ACTIVE_AREA_Y2 2136
    // camera name
    #define PARAM_CAMERA_NAME 3 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus850)
    #define DIGIC				    3
    #define CAM_PB_MODE                 1
    #define CDM                         99
    #define UI_CS_PROP			    0x8007
    #define UI_CT_PROP			    0x8008   
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              3152   //for 7 MP
    #define CAM_RAW_ROWS                2340   //for 7 MP
    #define CAM_MULTIPART               1 
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_TURNS_OFF_LCD           1
        #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      661014, 1000000, -189364, 1000000, -115797, 1000000, \
     -168772, 1000000,  661827, 1000000,   47392, 1000000, \
      -35846, 1000000,  107148, 1000000,  233705, 1000000

    #define cam_CalibrationIlluminant1 17 // Standard light A
    // cropping
    #define CAM_JPEG_WIDTH  3072
    #define CAM_JPEG_HEIGHT 2304
    #define CAM_ACTIVE_AREA_X1 12
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3108
    #define CAM_ACTIVE_AREA_Y2 2332
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus860)
    #define DIGIC				    3
    #define CAM_HAS_PLAYBACK_PB         1
    #define NEW_REC_PLAY			1
    #define CDM                         99
    #define UI_CS_PROP			    0x8007
    #define UI_CT_PROP			    0x8008  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)

    #undef  PERIOD_REF
    #define PERIOD_REF			    200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_PROPSET                 2
    #define CAM_NEED_HP                 1
    #define CAM_DRYOS                   1
    #define CAM_RAW_ROWPIX              3336   //for new 8 MP
    #define CAM_RAW_ROWS                2480   //for new 8 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
//  #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
        #define cam_CFAPattern 0x01000201 // Green  Blue  Red  Green
    // color
    #define CAM_COLORMATRIX1                               \
      747939, 1000000, -268233, 1000000, -129266, 1000000, \
     -50633,  1000000, 515687,  1000000,  23509,  1000000, \
     -21341,  1000000, 76495,   1000000, 186385,  1000000

    #define cam_CalibrationIlluminant1 1 // Daylight            	
    // cropping
    #define CAM_JPEG_WIDTH  3264
    #define CAM_JPEG_HEIGHT 2448
    #define CAM_ACTIVE_AREA_X1 10
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3302
    #define CAM_ACTIVE_AREA_Y2 2474
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0xAA
    #define COLOR_GREY_P          0xE7
    #define COLOR_LIGHT_GREY      0xEE
    #define COLOR_DARK_GREY       0xDD
    #define COLOR_LIGHT_GREY_P    0xEE
    #define COLOR_DARK_GREY_P     0xDD
    
//----------------------------------------------------------
#elif defined (CAMERA_ixus870)
    #define DIGIC				    4
    // Camera details
    #define CAM_MAKE                    "Canon"
    #define CDM                         0  
    #define STD_PERIOD 			*(volatile int*)(0x00346014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_DRYOS                   1
    //#undef CAM_DIGIC
    //#define CAM_DIGIC			    4
    #define CAM_PROPSET                 2
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_BRACKETING              1   //XXX   
    #define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO 1
    #define CAM_EXT_TV_RANGE            1
    #define CAM_HAS_IS                  1
    #define CAM_HAS_JOGDIAL             1
    #define CAM_HAS_ND_FILTER           1
    #define CAM_HAS_ZOOM_LEVER          1
    #define CAM_MULTIPART               1
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST			2000000
    #define PARAM_CAMERA_NAME           4 //parameter number for GetParameterData
    #undef  CAM_CAN_MUTE_MICROPHONE         //XXX
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES           //XXX
    #undef  CAM_EV_IN_VIDEO                 //XXX
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef  CAM_REAR_CURTAIN 
    #define CAM_JPEG_WIDTH              3648
    #define CAM_JPEG_HEIGHT             2736
    #define CAM_RAW_ROWPIX              3720
    #define CAM_RAW_ROWS                2772
    #undef  CAM_CONSOLE_LOG_ENABLED 
    #undef  CAM_DRAW_EXPOSITION             //XXX
    #undef  CAM_FEATURE_FEATHER             //XXX
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_VIDEO_CONTROL               //XXX
    #define CAM_ACTIVE_AREA_X1          14       // XXX
    #define CAM_ACTIVE_AREA_Y1          8        // XXX
    #define CAM_ACTIVE_AREA_X2          3682     // XXX
    #define CAM_ACTIVE_AREA_Y2          2764     // XXX

    #undef CAM_SENSOR_BITS_PER_PIXEL
    #undef CAM_WHITE_LEVEL
    #undef CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1) // XXX
    #define CAM_BLACK_LEVEL             127 // XXX

    #define cam_CFAPattern              0x02010100 // Red  Green  Green  Blue
    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829,  1000000, 530507,  1000000, 50537,   1000000, \
      5181,   1000000, 48183,   1000000, 245014,  1000000    // XXX
    #define cam_CalibrationIlluminant1  1 // Daylight       XXX
    #define CAM_SD_OVER_IN_AFL 1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

#elif defined (CAMERA_ixus900)
    #define DIGIC				    3
    #define CAM_PB_MODE                 1
    #define CDM                         0 
    #define STD_PERIOD 			*(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX                  3736
    #define CAM_RAW_ROWS                    2772
    #define CAM_MULTIPART               1 
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_HAS_HI_ISO_AUTO_MODE        1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern                  0x02010100   // Red  Green  Green  Blue
    // color (from G7)
    #define CAM_COLORMATRIX1                              \
      575419, 1000000,-185557, 1000000, -77898,  1000000, \
     -213702, 1000000, 733569, 1000000,   81514, 1000000, \
      -24604, 1000000, 131906, 1000000,  280378, 1000000

    #define cam_CalibrationIlluminant1      1       // ToDo: Daylight (first selectable Illuminant Calibration mode ?)
    // cropping
    #define CAM_JPEG_WIDTH                  3648
    #define CAM_JPEG_HEIGHT                 2736
    #define CAM_ACTIVE_AREA_X1              12
    #define CAM_ACTIVE_AREA_Y1              6
    #define CAM_ACTIVE_AREA_X2              3684
    #define CAM_ACTIVE_AREA_Y2              2766
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF               1
    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus950)
    #define DIGIC				    3
    #define CAM_PB_MODE                 1
    #define CDM                         0  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_MOVIE_PLE               1
    #define CAM_PROPSET                 2
    #define CAM_RAW_ROWPIX              3336   //for new 8 MP
    #define CAM_RAW_ROWS                2480   //for new 8 MP
    #define CAM_MULTIPART               1 
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_TURNS_OFF_LCD           1
    #define cam_CFAPattern 0x01000201 // Green  Blue  Red  Green
    // color
    #define CAM_COLORMATRIX1        \
      14573, 1, -5482, 1, -1546, 1, \
     -1266,  1, 9799,  1, 1468,  1, \
     -1040,  1, 1912,  1, 3810,  1

    #define cam_CalibrationIlluminant1 1 // Daylight            	
    // cropping
    #define CAM_JPEG_WIDTH  3264
    #define CAM_JPEG_HEIGHT 2448
    #define CAM_ACTIVE_AREA_X1 10
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3302
    #define CAM_ACTIVE_AREA_Y2 2474
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus960)
    #define DIGIC				    3
    #define CAM_HAS_PLAYBACK_PB         1
    #define CDM                         0  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    15  // in 'high resolution' 1024x768 mode.
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_PROPSET                 2
    #define CAM_NEED_HP                 1
    #define CAM_DRYOS                   1
    #define CAM_RAW_ROWPIX              4104   //for 12 MP
    #define CAM_RAW_ROWS                3048   //for 12 MP
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX    1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
      913762, 1000000, -261578, 1000000, -135582, 1000000, \
      -99049, 1000000, 1067089, 1000000,  61442,  1000000, \
      48717,  1000000, 96802,   1000000,  412056, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  4000
    #define CAM_JPEG_HEIGHT 3000
    #define CAM_ACTIVE_AREA_X1 48
    #define CAM_ACTIVE_AREA_Y1 12
    #define CAM_ACTIVE_AREA_X2 4080
    #define CAM_ACTIVE_AREA_Y2 3036
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
 #elif defined (CAMERA_ixus970)
    #define DIGIC				    3
    #define CAM_PROPSET                 2
    #define CDM                         0  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define CAM_DRYOS                   1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_RAW_ROWPIX              3720
    #define CAM_RAW_ROWS                2772
    #undef CAM_USE_ZOOM_FOR_MF
    #undef CAM_HAS_ERASE_BUTTON
    #undef CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef CAM_HAS_MANUAL_FOCUS
    #define CAM_MULTIPART               1
    #define CAM_HAS_JOGDIAL             1
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO 1
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue

    // color
    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829,  1000000, 530507,  1000000, 50537,   1000000, \
      5181,   1000000, 48183,   1000000, 245014,  1000000
    #define cam_CalibrationIlluminant1 1 // Daylight

    // cropping 
    #define CAM_JPEG_WIDTH  3648
    #define CAM_JPEG_HEIGHT 2736
    #define CAM_ACTIVE_AREA_X1 6
    #define CAM_ACTIVE_AREA_Y1 12
    #define CAM_ACTIVE_AREA_X2 3690
    #define CAM_ACTIVE_AREA_Y2 2772

    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData

    // 12 bit support
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_ixus980)
    #define DIGIC				    4
    #undef  EDGE_OVERLAY_COLOUR 
    #define EDGE_OVERLAY_COLOUR         0x8F
    #define CDM                         0  
    #define CAM_SZ			    1
    #define CAM_PROPSET                 2 //all values checked so far match propset 2
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_DRYOS                   1
   // #undef CAM_DIGIC
   // #define CAM_DIGIC			    4
    #define STD_PERIOD 			    *(volatile int*)(0x00406014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   65
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F0700C)
    #define CAM_NEED_HP                 1
    #define CAM_RAW_ROWPIX              4480 //14.7 MP 12bpp
    #define CAM_RAW_ROWS                3348   
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_MULTIPART               1
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST			2000000
    #define CAM_TURNS_OFF_LCD           1
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX    1
    #define  CAM_HAS_MANUAL_FOCUS		1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_CHDK_HAS_EXT_VIDEO_MENU 1
    #undef  CAM_VIDEO_CONTROL
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_UNCACHED_BIT  //shut up compiler
    #define CAM_UNCACHED_BIT    0x40000000
    #undef CAM_X_STRETCH               
    #define CAM_X_STRETCH               2
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720 // Actual width of bitmap screen in bytes
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE          3
    #undef GRID_X_CORRECTION
    #define GRID_X_CORRECTION(x)        ((x<<1))
    #undef CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
	#undef CAM_WHITE_LEVEL
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
	#undef CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL             127
    // pattern
    #define cam_CFAPattern 0x01000201 // Green  Blue  Red  Green
    // color preliminary
    #define CAM_COLORMATRIX1                               \
      837237, 1000000, -290137, 1000000, -128156, 1000000, \
      -127762, 1000000, 643909, 1000000,  52973,  1000000, \
      4446,  1000000, 88354,   1000000,  224246, 1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping 
    #define CAM_JPEG_WIDTH  4416
    #define CAM_JPEG_HEIGHT 3312
    #define CAM_ACTIVE_AREA_X1 12
    #define CAM_ACTIVE_AREA_Y1 12
    #define CAM_ACTIVE_AREA_X2 4444
    #define CAM_ACTIVE_AREA_Y2 3324
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData sd990: OK
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
//S-Series
//----------------------------------------------------------

#elif defined (CAMERA_s2is)
    #define DIGIC				    2
    #define CAM_HAS_VIDEO_CONTROL_BUTTON            1
    #define CDM                         8  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              2672   //for 5 MP
    #define CAM_RAW_ROWS                1968   //for 5 MP
    #define CAM_CURTAIN                 1
    #define CAM_SWIVEL_SCREEN           1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                                \
      547708,  1000000, -143462, 1000000,  -99243, 1000000, \
     -186838,  1000000, 663925,  1000000,   50970, 1000000, \
     -5810,    1000000, 79162,   1000000,  266988, 1000000

    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  2592
    #define CAM_JPEG_HEIGHT 1944
    #define CAM_ACTIVE_AREA_X1 14
    #define CAM_ACTIVE_AREA_Y1 10
    #define CAM_ACTIVE_AREA_X2 2626
    #define CAM_ACTIVE_AREA_Y2 1966
    // camera name
    #define PARAM_CAMERA_NAME 2 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_s3is)
    #define DIGIC				    2
    #define CAM_HAS_VIDEO_CONTROL_BUTTON            1
    #define CDM                         8  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_PROPSET                 1
    #define CAM_RAW_ROWPIX              2888   //for 6 MP
    #define CAM_RAW_ROWS                2136   //for 6 MP
    #define CAM_USB_EVENTID_VXWORKS             0x1085 // LogicalEvent ID for ConnectUSBCable, needed to enable USB mode switch
                                                       // NOTE switching back to play reportedly does not work on this camera 
    #define CAM_CURTAIN                 1
    #undef  CAM_SYNCH 
    #define CAM_SWIVEL_SCREEN           1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                               \
     14062, 10000, -5199, 10000, -1446, 10000,             \
     -4712, 10000, 12470, 10000,  2243, 10000,             \
     -1286, 10000,  2028, 10000,  4836, 10000
    
    #define cam_CalibrationIlluminant1 17 // Standard light A
    // cropping
    #define CAM_JPEG_WIDTH  2816
    #define CAM_JPEG_HEIGHT 2112
    #define CAM_ACTIVE_AREA_X1 44
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 2884
    #define CAM_ACTIVE_AREA_Y2 2136
    // camera name
    #define PARAM_CAMERA_NAME 3 // parameter number for GetParameterData

    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_s5is)
    #define DIGIC				    3
    #define CAM_HAS_VIDEO_CONTROL_BUTTON            1
    #define CDM                         8  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_PROPSET                 2
    #define CAM_DRYOS                   1
    #define CAM_RAW_ROWPIX              3336   //for new 8 MP
    #define CAM_RAW_ROWS                2480   //for new 8 MP
    #define CAM_CURTAIN                 1
    #define CAM_SWIVEL_SCREEN           1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #define cam_CFAPattern 0x01000201 // Green  Blue  Red  Green
    // color
    #define CAM_COLORMATRIX1                               \
      650591, 1000000, -199585, 1000000, -123118, 1000000, \
     -69617,  1000000, 583926,  1000000,  34354,  1000000, \
     -19113,  1000000, 82163,   1000000, 210786,  1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3264
    #define CAM_JPEG_HEIGHT 2448
    #define CAM_ACTIVE_AREA_X1 10
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3302
    #define CAM_ACTIVE_AREA_Y2 2474
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData

    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_s90)
    #define DIGIC				    4
    #undef  EDGE_OVERLAY_COLOUR 
    #define EDGE_OVERLAY_COLOUR         0x9A
    #define CAM_DRYOS_2_3_R39			1
    #define CAM_PROPSET                 3
    #define CAM_DRYOS                   1
    //#undef CAM_DIGIC
    //#define CAM_DIGIC			    4
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x8008
    #define UI_CT_PROP			    0x8009    
    #define STD_PERIOD 			    *(volatile int*)(0x00406014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    250
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    30
    #define LOW_LIGHT                   1
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_MOVIE_PLE               1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS 1   // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_RAW_ROWPIX              3744   // See g11 lib.c
    #define CAM_RAW_ROWS                2784   // See g11 lib.c
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION  10
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    #define CAM_QUALITY_OVERRIDE 1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_HAS_JOGDIAL             1
    #undef  CAM_CONSOLE_LOG_ENABLED         // Development: internal camera stdout -> A/stdout.txt
    #define CAM_BRACKETING              1
    #define CAM_MULTIPART               1
    #define CAM_EXT_TV_RANGE            1
    #undef OPT_CURVES
    #undef CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT            0x40000000  // S90 @FF8875FC(via ExMem.FreeCacheable)
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX    1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127
    #undef CAM_USES_ASPECT_CORRECTION   
    #undef CAM_USES_ASPECT_YCORRECTION  
    #define CAM_USES_ASPECT_CORRECTION  1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #define CAM_USES_ASPECT_YCORRECTION  0  //only uses mappings on x coordinate
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

   #define CAM_USES_ASPECT_YCORRECTION  0  //only uses mappings on x coordinate
    //games mappings
	#undef GAMES_SCREEN_WIDTH
	#undef GAMES_SCREEN_HEIGHT
	#define GAMES_SCREEN_WIDTH 360
	#define GAMES_SCREEN_HEIGHT 240

    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE    6

    #undef ASPECT_XCORRECTION
	#define ASPECT_XCORRECTION(x)  ( ( ((x)<<3) + (x) )  >>2 )
	#undef ASPECT_GAMES_XCORRECTION 
	#define ASPECT_GAMES_XCORRECTION(x)   ( ((x)<<1) )  
	#undef ASPECT_GAMES_YCORRECTION
	#define ASPECT_GAMES_YCORRECTION(y)   ( (y) )  //none

    #undef ASPECT_GRID_XCORRECTION
    #define ASPECT_GRID_XCORRECTION(x)  ( ((x)<<3)/9  )  //grids are designed on a 360x240 basis and screen is 320x240, we need x*320/360=x*8/9
    #undef ASPECT_GRID_YCORRECTION
    #define ASPECT_GRID_YCORRECTION(y)  ( (y) )       //y correction for grids  made on a 360x240 As the buffer is 720x240 we have no correction here.

    #undef ASPECT_VIEWPORT_XCORRECTION 
    #define ASPECT_VIEWPORT_XCORRECTION(x) ASPECT_GRID_XCORRECTION(x) //viewport is 360x240 and screen 320x240, we need x*320/360=x*8/9, equal than grids, used by edgeoverlay
    #undef ASPECT_VIEWPORT_YCORRECTION 
    #define ASPECT_VIEWPORT_YCORRECTION(y) ( (y) ) 
    #undef EDGE_HMARGIN 
    #define EDGE_HMARGIN 20

	/**** From SX200IS, ok for S90 ?*/
    // pattern
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    //need fixing *****************************************************
    #define CAM_COLORMATRIX1                               \
      14134, 1000000, -5576, 1000000, -1527, 1000000, \
     -1991,  1000000, 10719,  1000000, 1273,   1000000, \
      -1158,   1000000, 1929,   1000000, 3581,  1000000
    #define cam_CalibrationIlluminant1 17 // Standard Light A

    // cropping
    #define CAM_JPEG_WIDTH  3600
    #define CAM_JPEG_HEIGHT 2700
    #define CAM_ACTIVE_AREA_X1 52
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 3648
    #define CAM_ACTIVE_AREA_Y2 2736

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x14
    #define COLOR_GREY_P          0x14
    #define COLOR_LIGHT_GREY      0x10
    #define COLOR_DARK_GREY       0x18
    #define COLOR_LIGHT_GREY_P    0x10
    #define COLOR_DARK_GREY_P     0x18
    
//----------------------------------------------------------
#elif defined (CAMERA_s95)
    #define DIGIC				    4
    #define CAM_DRYOS_2_3_R39	          1
    #define CAM_USES_EXMEM              1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_PROPSET                 4
    #define CAM_DRYOS                   1
    #undef CAM_DIGIC
    #define CAM_DIGIC			    4
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800A 
    #define UI_CT_PROP			    0x800B 
    #undef SYNCH_SPEED
    #define SYNCH_SPEED 	           2
    #define STD_PERIOD 			    *(volatile int*)(0x00406014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			    24 // 23.976 actual HD at 1280x720.
    #define CAM_PRECISION_SYNCH         1	
    #define COUNTS_BEFORE_INT          *(volatile int*)(0x0040713C)	
    #define CAM_HAS_NATIVE_RAW	    1
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST         32722
    #define LOW_LIGHT                   1
    #define CAM_DATE_FOLDER_NAMING      0x400
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS 1   // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_RAW_ROWPIX              3744
    #define CAM_RAW_ROWS                2784
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION  10
    #undef CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH	10
	#define CAM_QUALITY_OVERRIDE 1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_HAS_JOGDIAL             1
	#undef CAM_HAS_ERASE_BUTTON
    #undef  CAM_CONSOLE_LOG_ENABLED         // Development: internal camera stdout -> A/stdout.txt
    #define CAM_BRACKETING              1
	#undef  CAM_VIDEO_CONTROL
	#define CAM_VIDEO_QUALITY_ONLY		1
    #define CAM_MULTIPART               1
    #define CAM_EXT_TV_RANGE            1
    #undef OPT_CURVES
    #undef CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT            0x40000000  // S90 @FF8875FC(via ExMem.FreeCacheable)
	#define CAM_SHOW_OSD_IN_SHOOT_MENU  1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #undef  CAM_WHITE_LEVEL
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #undef  CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL             127
    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION  1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_USES_ASPECT_YCORRECTION
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

  #undef CAM_USES_ASPECT_YCORRECTION
    #define CAM_USES_ASPECT_YCORRECTION  0  //only uses mappings on x coordinate

    //games mappings
	#undef GAMES_SCREEN_WIDTH
	#define GAMES_SCREEN_WIDTH 360
	#undef GAMES_SCREEN_HEIGHT
	#define GAMES_SCREEN_HEIGHT 240

    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE    8

    #undef ASPECT_XCORRECTION
	#define ASPECT_XCORRECTION(x)  ( ( ((x)<<3) + (x) )  >>2 )
	#undef ASPECT_GAMES_XCORRECTION
	#define ASPECT_GAMES_XCORRECTION(x)   ( ((x)<<1) )
	#undef ASPECT_GAMES_YCORRECTION
	#define ASPECT_GAMES_YCORRECTION(y)   ( (y) )  //none

    #undef ASPECT_GRID_XCORRECTION
    #define ASPECT_GRID_XCORRECTION(x)  ( ((x)<<3)/9  )  //grids are designed on a 360x240 basis and screen is 320x240, we need x*320/360=x*8/9
    #undef ASPECT_GRID_YCORRECTION
    #define ASPECT_GRID_YCORRECTION(y)  ( (y) )       //y correction for grids  made on a 360x240 As the buffer is 720x240 we have no correction here.

    #undef ASPECT_VIEWPORT_XCORRECTION
    #define ASPECT_VIEWPORT_XCORRECTION(x) ASPECT_GRID_XCORRECTION(x) //viewport is 360x240 and screen 320x240, we need x*320/360=x*8/9, equal than grids, used by edgeoverlay
    #undef ASPECT_VIEWPORT_YCORRECTION
    #define ASPECT_VIEWPORT_YCORRECTION(y) ( (y) )
    #undef EDGE_HMARGIN
    #define EDGE_HMARGIN 28
 
    // pattern
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color

    #define CAM_COLORMATRIX1                               \
      14134, 1000000, -5576, 1000000, -1527, 1000000, \
     -1991,  1000000, 10719,  1000000, 1273,   1000000, \
      -1158,   1000000, 1929,   1000000, 3581,  1000000
    #define cam_CalibrationIlluminant1 17 // Standard Light A
    // cropping
    #define CAM_JPEG_WIDTH  3648
    #define CAM_JPEG_HEIGHT 2736
    #define CAM_ACTIVE_AREA_X1 64
    #define CAM_ACTIVE_AREA_Y1 22
    #define CAM_ACTIVE_AREA_X2 3728
    #define CAM_ACTIVE_AREA_Y2 2762

   #define CAM_ZEBRA_ASPECT_ADJUST 1

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A

    
//----------------------------------------------------------
#elif defined (CAMERA_s100)
    #define DIGIC				    5
    #define CAM_DRYOS         1
    #define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
    #define CAM_RAW_ROWPIX    4160 // Found @0xff190f44
    #define CAM_RAW_ROWS      3124 // Found @0xff190f4c
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02bd84
    #define CAM_PROPSET                     4
    #define CAM_DRYOS                       1
  //  #undef CAM_DIGIC
  //  #define CAM_DIGIC			        5
    #define CAM_HAS_GPS                   1
    #define STD_360_BUF                 1
    #define NEW_REC_PLAY			1
    #define CDM                         99
    #define UI_CS_PROP			    0x800C 
    #define UI_CT_PROP			    0x800D
    #define UI_AEB_PROP			    0x800F
    #define STD_PERIOD 			        *(volatile int*)(0x00606014)
    #undef  PERIOD_REF
    #define PERIOD_REF			         1200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       24 // 23.976 actual 1920x1080 HD,also 120 fps at 640x480 and 29.97 at 1280x720, 240 fps at 320x240
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F070C8)
    #define CAM_PRECISION_SYNCH         1	
    #define CAM_HAS_NATIVE_RAW	        1
    #define LOW_LIGHT                       1
    #define CAM_HAS_ND_FILTER               1
    #define CAM_HAS_NATIVE_ND_FILTER        1
    #undef CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                 200
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                     1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #undef  CAM_HAS_DISP_BUTTON
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #define  CAM_NEED_SET_ZOOM_DELAY        150
    #undef  CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH            10
    #define CAM_QUALITY_OVERRIDE            1
    #define CAM_HAS_JOGDIAL                 1
    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_KEY_CLICK_DELAY             10
    #define CAM_BRACKETING                  1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY          1
    #define CAM_MULTIPART                   1
    #define CAM_EXT_TV_RANGE                1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME               4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              17

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                    28

    #define CAM_DNG_LENS_INFO               { 52,10, 260,10, 20,10, 59,10 }

    #define cam_CFAPattern                  0x01000201 // = [Green Blue Red Green]
    // TODO: find correct values
    #define CAM_COLORMATRIX1                  \
      14134, 1000000, -5576, 1000000, -1527, 1000000, \
      -1991, 1000000, 10719, 1000000,  1273, 1000000, \
      -1158, 1000000,  1929, 1000000,  3581, 1000000
    #define cam_CalibrationIlluminant1      17  // TODO:

    // TODO: check these values
    #define CAM_JPEG_WIDTH                  4000
    #define CAM_JPEG_HEIGHT                 3000
    #define CAM_ACTIVE_AREA_X1              104
    #define CAM_ACTIVE_AREA_Y1              12
    #define CAM_ACTIVE_AREA_X2              (CAM_RAW_ROWPIX-8)
    #define CAM_ACTIVE_AREA_Y2              (CAM_RAW_ROWS-64)

    #define CAM_ZEBRA_ASPECT_ADJUST         1

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1   // enable workaround for camera crash at startup when opening the conf / font files
                                                // see http://chdk.setepontos.com/index.php?topic=6179.0

    #define CAM_FIRMWARE_MEMINFO            1   // Use 'GetMemInfo' to get free memory size.

    // TODO: - we may need this to save memory
    //#define CAM_ZEBRA_NOBUF                 1

    #define CAM_DATE_FOLDER_NAMING              0x400
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   //  // TODO: use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                // Used to enabled bracketing in custom timer, required on many recent cameras
                                                // see http://chdk.setepontos.com/index.php/topic,3994.405.html
    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID         0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

	#define REMOTE_SYNC_STATUS_LED 	0xC022C30C // specifies an LED that turns on while camera waits for USB remote to sync

    #undef CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #undef CAM_AF_SCAN_DURING_VIDEO_RECORD
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
    #define  CAM_HAS_MOVIE_DIGEST_MODE	1
//----------------------------------------------------------
#elif defined (CAMERA_s110)
    #define DIGIC				    5
    #define CAM_PROPSET                         5
    #define CAM_DRYOS         1
    #define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1   // Draw pixels on active bitmap buffer only. Requires active_bitmap_buffer location in stubs_min.S or stubs_entry.S.

    #undef  CAM_AF_LED
    #define CAM_AF_LED                          0 // Index of AF led in camera_set_led function

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000 // Found @0xf8039b1c

    #define CAM_HAS_ND_FILTER                   1 // **** requires adding the max and min aperture tables code.
    #define CAM_HAS_NATIVE_ND_FILTER            1   // Camera has built-in ND filter with Canon menu support for enable/disable
    #define CDM                         99
    #define UI_CS_PROP			    0x800D 
    #define UI_CT_PROP			    0x800E
    #define STD_360_BUF                 1
    #define NEW_REC_PLAY			1
    #define STD_PERIOD 			        *(volatile int*)(0x00606014)
    #undef  PERIOD_REF
    #define PERIOD_REF			         1200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       24 // 23.976 actual 1920x1080 HD,also 120 fps at 640x480 and 29.97 at 1280x720, 240 fps at 320x240
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      ((int*)0xC0F070C8)
    #define CAM_PRECISION_SYNCH         1	
    #define CAM_HAS_NATIVE_RAW	        1
    #define LOW_LIGHT                       1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                     1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #undef  CAM_HAS_DISP_BUTTON
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_VIDEO_QUALITY_ONLY              1
    #define CAM_BRACKETING                      1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                     2   // use .CR2 

    #undef  CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH                10

    #define CAM_DNG_LENS_INFO               { 52,10, 260,10, 20,10, 59,10 }

    // From S110 native RAW file as converted to DNG using Adobe DNG Converter
    // http://www.adobe.com/support/downloads/product.jsp?product=106&platform=Windows
    // Matrices from converted DNG's EXIF data
    #define cam_CalibrationIlluminant1          17      // Standard Light A
    #define cam_CalibrationIlluminant2          21      // D65
    #define CAM_COLORMATRIX1    \
      9063, 10000,  -4110, 10000,    240, 10000, \
     -2713, 10000,   9326, 10000,   3987, 10000, \
       140, 10000,    247, 10000,   4262, 10000
    #define CAM_COLORMATRIX2    \
      8039, 10000,  -2643, 10000,   -654, 10000, \
     -3783, 10000,  11230, 10000,   2930, 10000, \
      -206, 10000,    690, 10000,   4194, 10000
    #define CAM_CAMERACALIBRATION1    \
     10099, 10000,      0, 10000,      0, 10000, \
         0, 10000,  10000, 10000,      0, 10000, \
         0, 10000,      0, 10000,   9551, 10000
    #define CAM_CAMERACALIBRATION2    \
     10099, 10000,      0, 10000,      0, 10000, \
         0, 10000,  10000, 10000,      0, 10000, \
         0, 10000,      0, 10000,   9551, 10000
    #define CAM_FORWARDMATRIX1    \
      6336, 10000,   2874, 10000,    433, 10000, \
      1716, 10000,  10221, 10000,  -1937, 10000, \
      -769, 10000,  -2436, 10000,  11483, 10000
    #define CAM_FORWARDMATRIX2    \
      6304, 10000,   4163, 10000,   -825, 10000, \
      2185, 10000,  11354, 10000,  -3539, 10000, \
       -54, 10000,  -1114, 10000,   9419, 10000
    #define CAM_DNG_EXPOSURE_BIAS -3,4 // EXIF: Baseline Exposure

    #define CAM_RAW_ROWPIX    4160 // Found @0xf81fdae4
    #define CAM_RAW_ROWS      3124 // Found @0xf81fdaec

    #define CAM_JPEG_WIDTH                      4034
    #define CAM_JPEG_HEIGHT                     3040
    // S110 native RAW converted to DNG's EXIF data: Active Area
    #define CAM_ACTIVE_AREA_X1                  104
    #define CAM_ACTIVE_AREA_Y1                  11
    #define CAM_ACTIVE_AREA_X2                  4152
    #define CAM_ACTIVE_AREA_Y2                  3059
    // S110 native RAW converted to DNG's EXIF data: CFA Pattern
    #define cam_CFAPattern                      0x02010100 // [Red,Green][Green,Blue]

    #define PARAM_CAMERA_NAME                   4       // parameter number for GetParameterData - Camera Model name
    #define PARAM_OWNER_NAME                    7       // parameter number for GetParameterData - Owner name
    #define PARAM_DISPLAY_MODE1                 59      // param number for LCD display mode when camera in playback
    #define PARAM_DISPLAY_MODE2                 62      // param number for LCD display mode when camera in record view hold mode
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1
    #define CAM_QUALITY_OVERRIDE                1
    #define CAM_REAR_CURTAIN                    1

    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                    960     // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT                   270     // Actual height of bitmap screen in rows

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  25 	  // same as sx240hs
  
    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN 2

    #define CAM_DATE_FOLDER_NAMING              0x400

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX     1       // enable fix for camera crash at startup when opening the conf / font files
                                                        // see http://chdk.setepontos.com/index.php?topic=6179.0

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60      // delay after a press

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                        // Used to enabled bracketing in custom timer, required on many recent cameras
                                                        // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_AV_OVERRIDE_IRIS_FIX            1       // for cameras that require _MoveIrisWithAv function to override Av in bracketing.
    #define CAM_HAS_MOVIE_DIGEST_MODE           1       // Changes the values in the 'movie_status' variable if the camera has this mode

//    #define CAM_LOAD_CUSTOM_COLORS              1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                     0xAF    // Start color index for CHDK colors loaded into camera palette.

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.
 
//	#define REMOTE_SYNC_STATUS_LED 	0xC0xxyyyy		// specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_HAS_CMOS                        1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     74 // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     131579  // Override max subject distance

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1       // mkdir() return 1 on success, 0 on fail.

    // Define shortcut overrides where defaults are not suitable
    #define SHORTCUT_TOGGLE_ZEBRA           KEY_ERASE   // On camera Shutter Half Press + Up = switch MF on/off

    #define CAM_HAS_FILEWRITETASK_HOOK                  1
    #define CAM_FILEWRITETASK_SEEKS                     1
 
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//==========================================================
//SX-Series
//==========================================================
#elif defined (CAMERA_sx1)
    #define DIGIC				    4
    #define CAM_PROPSET                 2
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         0  
    #define STD_PERIOD 			    *(volatile int*)(0x00406014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30
  //  #define CAM_HAS_NATIVE_RAW	    1  // as of Firmware ver. 2.0.0.0 2009-03-02 ?
    #define CAM_DRYOS                   1
    //#undef CAM_DIGIC
    //#define CAM_DIGIC			    4
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON            1
    #define CAM_RAW_ROWPIX              4152 
    #define CAM_RAW_ROWS                2772      
    #define CAM_SWIVEL_SCREEN           1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_VIDEO_QUALITY_ONLY          1  
    #define CAM_BRACKETING              1 
    #undef  CAM_VIDEO_CONTROL
    #define CAM_MULTIPART               1
    #define CAM_HAS_JOGDIAL             1
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST			2000000
    #define CAM_HAS_VARIABLE_ASPECT     1 
    #undef CAM_SCREEN_WIDTH
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_SCREEN_WIDTH                480 // Width of bitmap screen in CHDK co-ordinates
    #define CAM_BITMAP_WIDTH                480 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color

    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829,  1000000, 530507,  1000000, 50537,   1000000, \
      5181,   1000000, 48183,   1000000, 245014,  1000000

    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3648
    #define CAM_JPEG_HEIGHT 2736
    #define CAM_ACTIVE_AREA_X1 344
    #define CAM_ACTIVE_AREA_Y1 24
    #define CAM_ACTIVE_AREA_X2 3991
    #define CAM_ACTIVE_AREA_Y2 2759 
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44
    #define CAM_HAS_CMOS		1
//---------------------------------------------------------- 
#elif defined (CAMERA_sx10)
    #define DIGIC				    4
    #define CAM_PROPSET                 2
//    #define CDM                         0 
    #define CDM                         99
    #define UI_CS_PROP	         0x8008 
    #define UI_CT_PROP	         0x8009 
    #define STD_PERIOD 			    *(volatile int*)(0x00346014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30
    #define CAM_DRYOS                   1
  //  #undef CAM_DIGIC
  //  #define CAM_DIGIC			    4
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_UP
    #define CAM_NEED_HP                 1
    #define CAM_HOTSHOE_OVERRIDE        1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_RAW_ROWPIX              3720   
    #define CAM_RAW_ROWS                2772   
    #define CAM_HAS_VIDEO_CONTROL_BUTTON            1
    #define CAM_SWIVEL_SCREEN           1
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST			2000000
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #define CAM_BRACKETING              1 
    #undef  CAM_VIDEO_CONTROL
    #define CAM_MULTIPART               1
    #define CAM_HAS_JOGDIAL             1
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color

    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
     -12829,  1000000, 530507,  1000000, 50537,   1000000, \
      5181,   1000000, 48183,   1000000, 245014,  1000000

    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3648
    #define CAM_JPEG_HEIGHT 2736
    #define CAM_ACTIVE_AREA_X1 6
    #define CAM_ACTIVE_AREA_Y1 12
    #define CAM_ACTIVE_AREA_X2 3690
    #define CAM_ACTIVE_AREA_Y2 2772
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44
    
//==========================================================
#elif defined (CAMERA_sx20)
    #define DIGIC				    4
	#define CAM_PROPSET				   3
     // #undef CAM_DIGIC
     // #define CAM_DIGIC			    4				   
	#define CAM_DRYOS					   1
	#define CAM_DRYOS_2_3_R39			   1
      // #define CAM_USES_EXMEM                       1
      #define NEW_REC_PLAY			1
      #define NEW_MOVIE			      1
      #define STD_360_BUF			1
      #define CDM                         99
      #define UI_CS_PROP			    0x8008
      #define UI_CT_PROP			    0x8009 
      #define STD_PERIOD 			    *(volatile int*)(0x00386014)
      #undef  PERIOD_REF
      #define PERIOD_REF			         250
      #undef  SYNCH_FPS
      #define SYNCH_FPS			       30    // 1280x720
      #define CAM_DATE_FOLDER_NAMING               0x100
      #undef  ANA_BUTTON
      #define ANA_BUTTON                  KEY_SET
      #define CAM_NEED_HP                          1
      #define CAM_HOTSHOE_OVERRIDE        	   1
      #define CAM_HAS_PLAYBACK_PB                  1
	#define CAM_RAW_ROWPIX				   4080
	#define CAM_RAW_ROWS				   3048
	#define CAM_SWIVEL_SCREEN			   1
	#undef  CAM_CAN_SD_OVER_NOT_IN_MF
	#undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
	#define CAM_HAS_VIDEO_CONTROL_BUTTON		         1
	#define CAM_VIDEO_QUALITY_ONLY		   1
      #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
	#define CAM_BRACKETING				   1
	#undef  CAM_VIDEO_CONTROL
	#define CAM_MULTIPART				   1
	#define CAM_HAS_JOGDIAL				   1
	#undef  CAM_USE_ZOOM_FOR_MF
	#undef  CAM_UNCACHED_BIT			   // shut up compiler
	#define CAM_UNCACHED_BIT			   0x40000000
      #define CAM_STARTUP_CRASH_FILE_OPEN_FIX	   1
	// pattern
	#define cam_CFAPattern 0x02010100            // Red  Green  Green  Blue
	// color

	#define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
      -12829, 1000000,  530507, 1000000,   50537, 1000000, \
        5181, 1000000,   48183, 1000000,  245014, 1000000

	#define cam_CalibrationIlluminant1	      1 // Daylight
	// cropping
	#define CAM_JPEG_WIDTH				4000
	#define CAM_JPEG_HEIGHT				3000
	#define CAM_ACTIVE_AREA_X1			24
	#define CAM_ACTIVE_AREA_Y1			12
	#define CAM_ACTIVE_AREA_X2			4080-48
	#define CAM_ACTIVE_AREA_Y2			3048-24
      #undef  MOVIE_TYPE
      #define MOVIE_TYPE                  "MOV"
	// camera name
	#define PARAM_CAMERA_NAME			4 // parameter number for GetParameterData
	#undef  CAM_SENSOR_BITS_PER_PIXEL
	#undef  CAM_WHITE_LEVEL
	#undef  CAM_BLACK_LEVEL
	#define CAM_SENSOR_BITS_PER_PIXEL	      12
	#define CAM_WHITE_LEVEL				((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
	#define CAM_BLACK_LEVEL				127
	#define CAM_EXT_TV_RANGE			1
	#define CAM_QUALITY_OVERRIDE		      1
	#undef CAM_BITMAP_PALETTE
	#define CAM_BITMAP_PALETTE		      10
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows
    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                 88      // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                 66490   // Override max subject distance
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
    
//==========================================================

#elif defined (CAMERA_sx40hs)
    #define DIGIC				    5
    #define CAM_PROPSET                         4
    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1   // Draw pixels on active bitmap buffer only.

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000 // Found @0xff02bea8
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800C	
    #define UI_CT_PROP			    0x800D
    #define STD_PERIOD 			    *(volatile int*)(0x00606014)
    #undef  PERIOD_REF
    #define PERIOD_REF			         500
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       24 // 23.976 at 1920x1080,29.97 at 1280x720,120 fps at 640x480,240 fps at 320x240	
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      	((int*)0xC0F0703C)
    #define CAM_PRECISION_SYNCH         1
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #define CAM_HAS_ND_FILTER                   1
    #define CAM_SWIVEL_SCREEN                   1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_VIDEO_QUALITY_ONLY              1
    #define CAM_BRACKETING                      1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                     2   // use .CR2 

    #undef  CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH                10

    #undef  CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                 200 // Override base 'market' ISO value
    #define CAM_ISO_LIMIT_IN_HQ_BURST           930 // Defines max ISO override value for HQ Burst mode (higher values crash camera)
    #define CAM_MIN_ISO_OVERRIDE                70  // Defines min (non-zero) ISO override value - lower value may crash if flash used [0 = AUTO, so always allowed]

    // bayer sensor pattern
    #define cam_CFAPattern                      0x02010100 // Red  Green  Green  Blue

    #define CAM_DNG_EXPOSURE_BIAS               0,1     // Specify DNG exposure bias value to 0 (to override default of -0.5 in the dng.c code)

    #define CAM_DNG_LENS_INFO                   { 43,10, 1505,10, 27,10, 58,10 }    // See comments in camera.h

    //need fixing *****************************************************
    #define cam_CalibrationIlluminant1  1
    #define CAM_COLORMATRIX1    \
    544808, 100000, -174047, 100000, -80399, 100000, \
    -75055, 100000,  440444, 100000,  11367, 100000, \
     -5801, 100000,   71589, 100000, 118914, 100000

    // Sensor size, DNG image size & cropping
    #define CAM_RAW_ROWPIX                      4176    // Found @0xff18e050
    #define CAM_RAW_ROWS                        3060    // Found @0xff18e05c
    #define CAM_JPEG_WIDTH                      4072
    #define CAM_JPEG_HEIGHT                     3044
    #define CAM_ACTIVE_AREA_X1                  96
    #define CAM_ACTIVE_AREA_Y1                  16
    #define CAM_ACTIVE_AREA_X2                  4168
    #define CAM_ACTIVE_AREA_Y2                  3060

    // camera name
    #define PARAM_CAMERA_NAME                   4       // parameter number for GetParameterData - Camera Model name
    #define PARAM_OWNER_NAME                    7       // parameter number for GetParameterData - Owner name
    #define PARAM_DISPLAY_MODE1                 59      // param number for LCD display mode when camera in playback
    #define PARAM_DISPLAY_MODE2                 62      // param number for LCD display mode when camera in record view hold mode
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1
    #define CAM_QUALITY_OVERRIDE                1

    // copied from the SX200 which has the same video buffer size
    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                    960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT                   270 // Actual height of bitmap screen in rows

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  26
  
    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN 2

    #define CAM_DATE_FOLDER_NAMING              0x400

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX     1       // enable fix for camera crash at startup when opening the conf / font files
                                                        // see http://chdk.setepontos.com/index.php?topic=6179.0

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60      // delay after a press

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                        // Used to enabled bracketing in custom timer, required on many recent cameras
                                                        // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_AV_OVERRIDE_IRIS_FIX            1       // for cameras that require _MoveIrisWithAv function to override Av in bracketing.

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1       // For cameras with 'low light' mode that does not work with raw define this
    #define CAM_DISABLE_RAW_IN_HQ_BURST         1       // For cameras with 'HQ Burst' mode that does not work with raw define this
    #define CAM_DISABLE_RAW_IN_HANDHELD_NIGHT_SCN 1     // For cameras with 'HandHeld Night Scene' mode that does not work with raw define this
    #define CAM_HAS_MOVIE_DIGEST_MODE           1       // Changes the values in the 'movie_status' variable if the camera has this mode

//  #define CAM_LOAD_CUSTOM_COLORS              1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                     0xA8    // Start color index for CHDK colors loaded into camera palette.

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.
 
//	#define REMOTE_SYNC_STATUS_LED 	0xC0xxyyyy		// specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_HAS_CMOS                        1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     95      // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     9523810 // Override max subject distance

    #define CAM_ZOOM_ASSIST_BUTTON_CONTROL      1       // Activate the menu option to allow disabling the zoom assist button

    #define CAM_HAS_SPORTS_MODE                 1   // Camera has SPORTS mode, enable RAW exception override control

    // Define shortcut overrides where defaults are not suitable
    #define SHORTCUT_TOGGLE_ZEBRA               KEY_ERASE   // On camera Shutter Half Press + Up = switch MF on/off
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A

//==========================================================
#elif defined (CAMERA_sx50hs)
    #define DIGIC				    5
    #define CAM_PROPSET                         5
    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT  0x40000000 // Found @0xff020984
    #define STD_360_BUF                 1
    #define CAM_NEED_HP                 1
    #define CAM_HOTSHOE_OVERRIDE        1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_DOWN
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800D
    #define UI_CT_PROP			    0x800E	
    #define UI_AEB_PROP			    0x8010
    #define STD_PERIOD 			    _EngDrvRead(0xC0F06014)
    #undef  PERIOD_REF
    #define PERIOD_REF			         833
    #undef SYNCH_SPEED
    #define SYNCH_SPEED 	           6
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       24 // 23.976 at 1920x1080,29.97 at 1280x720,120 fps at 640x480,240 fps at 320x240	
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      	((int*)0xC0F0703C)
    #define CAM_PRECISION_SYNCH         1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #define CAM_HAS_ND_FILTER                   1
    #define CAM_SWIVEL_SCREEN                   1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_VIDEO_QUALITY_ONLY              1
	#define CAM_CHDK_HAS_EXT_VIDEO_TIME         1
	
    #define CAM_BRACKETING                      1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                     2   // use .CR2 

    #undef  CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH                10
    #undef  CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                 200
    // bayer sensor pattern
    #define cam_CFAPattern                      0x02010100 // Red  Green  Green  Blue

    #define CAM_DNG_EXPOSURE_BIAS               0,1     // Specify DNG exposure bias value to 0 (to override default of -0.5 in the dng.c code)

    #define CAM_DNG_LENS_INFO                   { 43,10, 2150,10, 34,10, 65,10 }    // See comments in camera.h

    //need fixing *****************************************************
    #define cam_CalibrationIlluminant1  1
    #define CAM_COLORMATRIX1    \
    544808, 100000, -174047, 100000, -80399, 100000, \
    -75055, 100000,  440444, 100000,  11367, 100000, \
     -5801, 100000,   71589, 100000, 118914, 100000

    // Sensor size, DNG image size & cropping
	#define CAM_RAW_ROWPIX    4176 // Found @0xff1ae73c
	#define CAM_RAW_ROWS      3062 // Found @0xff1ae748

    #define CAM_JPEG_WIDTH                      4072
    #define CAM_JPEG_HEIGHT                     3044
    #define CAM_ACTIVE_AREA_X1                  96
    #define CAM_ACTIVE_AREA_Y1                  16
    #define CAM_ACTIVE_AREA_X2                  4168
    #define CAM_ACTIVE_AREA_Y2                  3060

    // camera name
    #define PARAM_CAMERA_NAME                   4       // parameter number for GetParameterData - Camera Model name
    #define PARAM_OWNER_NAME                    7       // parameter number for GetParameterData - Owner name
    #define PARAM_DISPLAY_MODE1                 59      // param number for LCD display mode when camera in playback
    #define PARAM_DISPLAY_MODE2                 62      // param number for LCD display mode when camera in record view hold mode
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1
    #define CAM_QUALITY_OVERRIDE                1

    // copied from the SX200 which has the same video buffer size
    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  27
  
    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN 2

    #define CAM_DATE_FOLDER_NAMING              0x400

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX     1       // enable fix for camera crash at startup when opening the conf / font files
                                                        // see http://chdk.setepontos.com/index.php?topic=6179.0

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60      // delay after a press

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                        // Used to enabled bracketing in custom timer, required on many recent cameras
                                                        // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_AV_OVERRIDE_IRIS_FIX            1       // for cameras that require _MoveIrisWithAv function to override Av in bracketing.

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1       // For cameras with 'low light' mode that does not work with raw define this
    #define CAM_DISABLE_RAW_IN_HQ_BURST         1       // For cameras with 'HQ Burst' mode that does not work with raw define this
    #define CAM_DISABLE_RAW_IN_HANDHELD_NIGHT_SCN 1     // For cameras with 'HandHeld Night Scene' mode that does not work with raw define this
    #define CAM_ISO_LIMIT_IN_HQ_BURST           1420    // Defines max market ISO override value for HQ Burst mode (higher values crash camera)
    #define CAM_HAS_MOVIE_DIGEST_MODE           1       // Changes the values in the 'movie_status' variable if the camera has this mode

  //  #define CAM_LOAD_CUSTOM_COLORS              1       // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                     0xC0    // Start color index for CHDK colors loaded into camera palette.

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

    #define CAM_HAS_CMOS                        1
    #define CAM_HAS_NATIVE_RAW	            1
    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     95      // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     9523810 // Override max subject distance

    #define CAM_ZOOM_ASSIST_BUTTON_CONTROL      1       // Activate the menu option to allow disabling the zoom assist button
    #define MKDIR_RETURN_ONE_ON_SUCCESS         1       // mkdir() return 1 on success, 0 on fail.

    #define CAM_USE_ALT_SET_ZOOM_POINT          1      // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt    1      // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #undef  CAM_AF_LED                                  // AF Lamp index for camera_set_led()
    #define CAM_AF_LED                          1       //

    #define CAM_HAS_FILEWRITETASK_HOOK                  1
    #define CAM_FILEWRITETASK_SEEKS                     1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
    
//----------------------------------------------------------
#elif defined (CAMERA_sx100is)
    #define DIGIC				    3
    #define CAM_HAS_PLAYBACK_PB         1
    #define CDM                         0  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30
    #define CAM_PROPSET                 2
    #define CAM_NEED_HP                 1
    #define CAM_MULTIPART               1
    #define CAM_HAS_JOGDIAL                             1
    #define CAM_DRYOS                   1
    #define CAM_RAW_ROWPIX              3336   //for new 8 MP
    #define CAM_RAW_ROWS                2480   //for new 8 MP
    #define CAM_CAN_MUTE_MICROPHONE     1 
    #define cam_CFAPattern 0x01000201 // Green  Blue  Red  Green
    // color
    #define CAM_COLORMATRIX1                               \
      656793, 1000000, -168702, 1000000, -108030, 1000000, \
      -2711,  1000000, 661538,  1000000,  37919,  1000000, \
      77255,  1000000, 48834,   1000000, 241797,  1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3264
    #define CAM_JPEG_HEIGHT 2448
    #define CAM_ACTIVE_AREA_X1 10
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3302
    #define CAM_ACTIVE_AREA_Y2 2474
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44


//==========================================================
#elif defined (CAMERA_sx110is)
    #define DIGIC				    3
    #define CAM_PROPSET                 2
    #define CDM                         0  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    200
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30
    #define CAM_NEED_HP                 1
    #define CAM_DRYOS                   1
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX    1
    #define CAM_HAS_PLAYBACK_PB         1
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST			2000000
    #define CAM_RAW_ROWPIX              3720  
    #define CAM_RAW_ROWS                2772  
    #define CAM_CAN_MUTE_MICROPHONE     1 
    #define CAM_REAR_CURTAIN            1
    #define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO 1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1 
    #undef  CAM_VIDEO_CONTROL					
    #define CAM_MULTIPART               1
	#define CAM_COLORMATRIX1                               \
      530200, 1000000, -42600,  1000000, -33000,  1000000, \
     -525400,  1000000, 1092700,  1000000,  223700,  1000000, \
     -103700,  1000000, 117900,   1000000,  421600,  1000000
    #define CAM_ACTIVE_AREA_X1 8
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 3688
    #define CAM_ACTIVE_AREA_Y2 2772
	#undef CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
	#undef CAM_WHITE_LEVEL
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
	// black level set to 128 per reports on the forum
    #undef  CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL             128
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    #define cam_CalibrationIlluminant1 1 // Daylight
    #define CAM_JPEG_WIDTH  3456 
    #define CAM_JPEG_HEIGHT 2592
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

//----------------------------------------------------------
#elif defined (CAMERA_sx120is)
    #define DIGIC				    4
    #undef  EDGE_OVERLAY_COLOUR 
    #define EDGE_OVERLAY_COLOUR         0x9A

    #define CAM_COLORMATRIX1                               \
	728616, 1000000, -224281, 1000000, -104767, 1000000, \
	4176, 1000000, 440179, 1000000, 45782, 1000000, \
	26983, 1000000, 68443, 1000000, 186465, 1000000

    #define CAM_ACTIVE_AREA_X1 12
    #define CAM_ACTIVE_AREA_Y1 10
    #define CAM_ACTIVE_AREA_X2 3664
    #define CAM_ACTIVE_AREA_Y2 2768

    #define CAM_EXT_TV_RANGE 1
    #define CAM_PROPSET                 3
    #define CAM_DRYOS                   1
    //#undef CAM_DIGIC
    //#define CAM_DIGIC			    4
    #define STD_PERIOD 			    *(volatile int*)(0x00386014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_NEED_HP                 1
    #define CAM_RAW_ROWPIX              3728 // see platform/sub/*/lib.c
    #define CAM_RAW_ROWS                2778
    #define CAM_CAN_MUTE_MICROPHONE     1 
    #define CAM_SHOW_OSD_IN_SHOOT_MENU  0
    #define CAM_REAR_CURTAIN            1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    #define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO 1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1 
    #undef  CAM_VIDEO_CONTROL					
    #define CAM_MULTIPART               1
    #define CDM                        			 99
    #define UI_CS_PROP			    		       0x8008
    #define UI_CT_PROP			    		       0x8009     
    #define CAM_HAS_JOGDIAL             1
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS  1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT       1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_UNCACHED_BIT  // shut up compiler
    #define CAM_UNCACHED_BIT    0x40000000
  	#undef CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
  	#undef CAM_WHITE_LEVEL
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
	// black level set to 128 per reports on the forum
    #undef  CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL             128
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #define cam_CFAPattern 0x01000201 // Green  Blue  Red  Green
    #define cam_CalibrationIlluminant1 1 // Daylight
    #define CAM_JPEG_WIDTH  3648 
    #define CAM_JPEG_HEIGHT 2736
	#undef CAM_BITMAP_PALETTE
	#define CAM_BITMAP_PALETTE 7
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720 // Actual width of bitmap screen in bytes
	#undef CAM_USES_ASPECT_YCORRECTION
    #define CAM_USES_ASPECT_YCORRECTION		0
	#undef ASPECT_XCORRECTION
    #define ASPECT_XCORRECTION(x) 		(x)
    #undef ASPECT_YCORRECTION
    #define ASPECT_YCORRECTION(y)		(y)
    #undef ASPECT_GRID_XCORRECTION
    #define ASPECT_GRID_XCORRECTION(x)		(((x)<<1))
    #undef ASPECT_GRID_YCORRECTION
    #define ASPECT_GRID_YCORRECTION(y)		(y)
    #undef ASPECT_VIEWPORT_XCORRECTION
    #define ASPECT_VIEWPORT_XCORRECTION(x)	(((x)<<1))
    #undef ASPECT_VIEWPORT_YCORRECTION
    #define ASPECT_VIEWPORT_YCORRECTION(y)	(y)
    #undef GAMES_SCREEN_WIDTH
    #define GAMES_SCREEN_WIDTH 360
    #undef GAMES_SCREEN_HEIGHT
    #define GAMES_SCREEN_HEIGHT 240
    #undef ASPECT_GAMES_XCORRECTION
    #define ASPECT_GAMES_XCORRECTION(x)		(((x)<<1))
    #undef ASPECT_GAMES_YCORRECTION
    #define ASPECT_GAMES_YCORRECTION(y)		(y)
	
	
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_sx130is)
    #define DIGIC				    4
    #define CAM_PROPSET						  4
    //#undef CAM_DIGIC
    //#define CAM_DIGIC			                    4
    #define CAM_DRYOS                                   1
    #define CAM_DRYOS_2_3_R39                           1
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX             1
    #define CAN_CONTROL_AV_OUTPUT                       1
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_HAS_PLAYBACK_PB                         1
    #define CAM_NEED_HP                                 1
    #define CAM_RAW_ROWPIX                              4080
    #define CAM_RAW_ROWS                                3048
    #define CAM_MOVIE_PLE                               1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_VIDEO_QUALITY_ONLY                      1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE              1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    #define CAM_BRACKETING                              1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_MULTIPART                               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                        			 99
    #define UI_CS_PROP			    		       0x800A
    #define UI_CT_PROP			    		       0x800B   
    #define STD_PERIOD 			    *(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			                  250
    #undef  SYNCH_FPS
    #define SYNCH_FPS			                   30    // 29.97 HD at 1280x720
    #define CAM_PRECISION_SYNCH         1
    #define LOW_LIGHT                                   1
    #define CAM_HAS_JOGDIAL                             1
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                            0x40000000
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                                  "MOV"
    // pattern
    #define cam_CFAPattern                              0x02010100 // Red  Green  Green  Blue
    // color

/*
    #define CAM_COLORMATRIX1                               \
      827547, 1000000, -290458, 1000000, -126086, 1000000, \
      -12829, 1000000,  530507, 1000000,   50537, 1000000, \
        5181, 1000000,   48183, 1000000,  245014, 1000000
*/
// By DAS using dcraw
#define CAM_COLORMATRIX1                 \
    12886,10000,-6125,10000,-1331,10000, \
     -922,10000,7568,10000,3355,10000,   \
       56,10000,-833,10000,7753,10000

// By Doug with DNG4PS2
/*
#define CAM_COLORMATRIX1                 \
    1387996,1000000,601368,1000000,527950,10000, \
     222430,1000000,1816913,1000000,-193440,1000000,   \
     -218708,1000000,-405195,1000000,4684842,1000000
*/
    #define cam_CalibrationIlluminant1                  1 // Daylight

    // cropping
    #define CAM_JPEG_WIDTH                              4000
    #define CAM_JPEG_HEIGHT                             3000
    #define CAM_ACTIVE_AREA_X1                          36
    #define CAM_ACTIVE_AREA_Y1                          20
    #define CAM_ACTIVE_AREA_X2                          4036
    #define CAM_ACTIVE_AREA_Y2                          3020
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME                           4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL                   12
    #undef  CAM_WHITE_LEVEL
    #define CAM_WHITE_LEVEL                             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #undef  CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL                             127

    #define CAM_EXT_TV_RANGE                            1
    #define CAM_QUALITY_OVERRIDE                        1

    // copied from the SX200 which has the same video buffer size
    #undef CAM_USES_ASPECT_CORRECTION
    #undef CAM_USES_ASPECT_YCORRECTION
    #define CAM_USES_ASPECT_CORRECTION                  1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #define CAM_USES_ASPECT_YCORRECTION                 0  //only uses mappings on x coordinate
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720 // Actual width of bitmap screen in bytes
    #undef ASPECT_XCORRECTION
    #define ASPECT_XCORRECTION(x)                       ((((x)<<3)(x))>>2)  //correction x*screen_buffer_width/screen_width = x*720/320 = x*9/4 = (x<<3  x)>>2
    #undef ASPECT_GRID_XCORRECTION
    #define ASPECT_GRID_XCORRECTION(x)                  ((((x)<<3)/9))  //grids are designed on a 360x240 basis and screen is 320x240, we need x*320/360=x*8/9
    #undef ASPECT_GRID_YCORRECTION
    #define ASPECT_GRID_YCORRECTION(y)                  ((y))  //y correction for grids  made on a 360x240 As the buffer is 720x240 we have no correction here.

    #undef ASPECT_VIEWPORT_XCORRECTION 
    #define ASPECT_VIEWPORT_XCORRECTION(x)              ASPECT_GRID_XCORRECTION(x)
    #undef ASPECT_VIEWPORT_YCORRECTION 
    #define ASPECT_VIEWPORT_YCORRECTION(y)              ((y))

    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                          11

    //zebra letterbox for saving memory
    #undef ZEBRA_HMARGIN0
    #define ZEBRA_HMARGIN0                              30 //this 30 rows are not used by the display buffer is 720x240 effective, no 960x270, i.e. (270-240) reduction in widht possible but not done (more difficult to manage it and slower).

    //#undef EDGE_HMARGIN
    //#define EDGE_HMARGIN                                28
    // #define CAM_CHDK_PTP 1     
    #define CAM_DATE_FOLDER_NAMING                      0x400 //Value found in the last function, which is called in GetImageFolder. (first compare)

    // Menu width like in g11 and s90
    #undef CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH                        10
    // CR2 accesible through USB 
    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                             2
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A

//----------------------------------------------------------
#elif defined (CAMERA_sx150is)
    #define DIGIC				    4
    #define CAM_PROPSET                                 4
    #define CAM_DRYOS                                   1
    #define CAM_DRYOS_2_3_R39                           1
    #define CAM_DRYOS_2_3_R47                           1 // Defined for cameras with DryOS version R47 or higher

    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_VIDEO_QUALITY_ONLY                      1
    #define CAM_BRACKETING                              1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_MULTIPART                               1
    #define CAM_HAS_JOGDIAL                             1
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                            0x40000000

 //   #undef CAM_DIGIC
 //   #define CAM_DIGIC			        4
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800C 
    #define UI_CT_PROP			    0x800D 
    #define STD_PERIOD 			    *(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    250
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30	// 1280x720
    #define CAM_PRECISION_SYNCH         1
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              23 
    #define CAM_DNG_LENS_INFO                           { 50,10, 600,10, 34,10, 56,10 } // See comments in camera.h
    // pattern
    #define cam_CFAPattern                              0x01000201 // Green  Blue  Red  Green
    // color
    #define CAM_COLORMATRIX1                               \
      1301431, 1000000,  -469837, 1000000, -102652, 1000000, \
      -200195, 1000000,   961551, 1000000,  238645, 1000000, \
       -16441, 1000000,   142319, 1000000,  375979, 1000000
    #define cam_CalibrationIlluminant1                  1 // Daylight
 
    // Sensor size, DNG image size & cropping
    #define CAM_RAW_ROWPIX                  4464
    #define CAM_RAW_ROWS                    3276
    #define CAM_JPEG_WIDTH                  4368
    #define CAM_JPEG_HEIGHT                 3254
    #define CAM_ACTIVE_AREA_X1              24
    #define CAM_ACTIVE_AREA_Y1              10
    #define CAM_ACTIVE_AREA_X2              (CAM_RAW_ROWPIX-72)
    #define CAM_ACTIVE_AREA_Y2              (CAM_RAW_ROWS-12)

    // camera name
    #define PARAM_CAMERA_NAME                           4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL                   12

    #define CAM_EXT_TV_RANGE                            1
    #define CAM_QUALITY_OVERRIDE                        1

    // copied from the SX200 which has the same video buffer size
    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION                  1 //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720 // Actual width of bitmap screen in bytes
 
    #define CAM_ZEBRA_NOBUF                             1

    //#undef EDGE_HMARGIN
    //#define EDGE_HMARGIN                              28

    #define CAM_DATE_FOLDER_NAMING                      0x400

    // Menu width like in g11 and s90
    #undef CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH                        10
    // CR2 accesible through USB
    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                             2

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX             1 // enable fix for camera crash at startup when opening the conf / font files
                                                          // see http://chdk.setepontos.com/index.php?topic=6179.0

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE              1 // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                          // Used to enabled bracketing in custom timer, required on many recent cameras
                                                          // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                             0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

    #define REMOTE_SYNC_STATUS_LED                      0xC0220014		// specifies an LED that turns on while camera waits for USB remote to sync
    #define CAM_USE_ALT_SET_ZOOM_POINT                  1   // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt            1   // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #define CAM_NEED_SET_ZOOM_DELAY                     300 // http://chdk.setepontos.com/index.php?topic=6953.msg119736#msg119736
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x1A
    #define COLOR_GREY_P          0x1A
    #define COLOR_LIGHT_GREY      0x16
    #define COLOR_DARK_GREY       0x62
    #define COLOR_LIGHT_GREY_P    0x16
    #define COLOR_DARK_GREY_P     0x62
//----------------------------------------------------------
#elif defined (CAMERA_sx160is)
    #define DIGIC				    4
    #define CAM_PROPSET                                 5
    #define CAM_DRYOS                                   1
    #define CAM_DRYOS_2_3_R39                           1
    #define CAM_DRYOS_2_3_R47                           1 // Defined for cameras with DryOS version R47 or higher
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX             1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_BRACKETING                              1
    #define CAM_HAS_JOGDIAL                             1
    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         2 
    #define STD_PERIOD 			    _EngDrvRead(0xC0F06014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    301
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       25	// 1280x720
    #define CAM_PRECISION_SYNCH         1
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef  CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                 200
 
    // pattern
    #define cam_CFAPattern                              0x01000201 // Green  Blue  Red  Green
    // color
    #define CAM_COLORMATRIX1                               \
      1301431, 1000000,  -469837, 1000000, -102652, 1000000, \
      -200195, 1000000,   961551, 1000000,  238645, 1000000, \
       -16441, 1000000,   142319, 1000000,  375979, 1000000
    #define cam_CalibrationIlluminant1                  1 // Daylight
 
    // Sensor size, DNG image size & cropping
    #define CAM_RAW_ROWPIX                            4704 // Found @0xff95b0b8 sx160is 100a
    #define CAM_RAW_ROWS                              3504 // Found @0xff95b0c4 sx160is 100a

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000 // Found @0xff82ec94 sx160is 100a

    #define CAM_JPEG_WIDTH                            4608
    #define CAM_JPEG_HEIGHT                           3456
    #define CAM_ACTIVE_AREA_X1                          32
    #define CAM_ACTIVE_AREA_Y1                          26
    #define CAM_ACTIVE_AREA_X2                        4640
    #define CAM_ACTIVE_AREA_Y2                        3486

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL                   12

    #define CAM_DNG_LENS_INFO                           { 50,10, 800,10, 35,10, 59,10 } // See comments in camera.h

    #define CAM_EXT_TV_RANGE                            1
    #define CAM_QUALITY_OVERRIDE                        1

    #define CAM_HAS_VIDEO_BUTTON                        1
    #define CAM_VIDEO_QUALITY_ONLY                      1
    #undef  CAM_VIDEO_CONTROL

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION                  1
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                          960 // Actual width of bitmap screen in bytes (may be larger than displayed area)
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_HEIGHT                         270 // Actual height of bitmap screen in rows (240 or 270)
    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY           1   // Draw pixels on active bitmap buffer only.

    #define CAM_HAS_FILEWRITETASK_HOOK                  1
    #define CAM_FILEWRITETASK_SEEKS                     1

    #define CAM_ZEBRA_NOBUF                             1

    #define PARAM_CAMERA_NAME                           4 // parameter number for GetParameterData

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                         27 // palette number reserved in core/gui_draw.h
 // #define CAM_LOAD_CUSTOM_COLORS                      1 // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                          0xD0 // Start color index for CHDK colors loaded into camera palette

    #define CAM_DATE_FOLDER_NAMING                  0x400

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE              1 // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                          // Used to enabled bracketing in custom timer, required on many recent cameras
                                                          // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_DETECT_SCREEN_ERASE                     1 // Turn on guard pixels to detect screen erase and redraw CHDK buttons and menus

    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_HAS_ZOOM_LEVER                          1 // Camera has dedicated zoom buttons
    #define CAM_NEED_SET_ZOOM_DELAY                   300 // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS             1 // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT                  1 // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt            1 // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()


    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                         0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.


//  define REMOTE_SYNC_STATUS_LED              0xC0220120 // specifies an LED that turns on while camera waits for USB remote to sync

    #define MKDIR_RETURN_ONE_ON_SUCCESS                 1 // mkdir() return 1 on success, 0 on fail.
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_sx170is)
    #define CAM_PROPSET                     6
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher

    #define STD_360_BUF                 1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_SET
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         99
    #define UI_CS_PROP			    0x800E
    #define UI_CT_PROP			    0x800F
    #define STD_PERIOD 			    _EngDrvRead(0xC0F06014)
    #undef  PERIOD_REF
    #define PERIOD_REF			    301
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       25	// 1280x720
 //   #define CAM_PRECISION_SYNCH         1
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                         27

   #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION         6   // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    #define CAM_RAW_ROWPIX                  4704    // Found @0xff959c2c
    #define CAM_RAW_ROWS                    3504    // Found @0xff959c38

    #define CAM_JPEG_WIDTH                  4608    //To do
    #define CAM_JPEG_HEIGHT                 3456    //To do

    #define CAM_ACTIVE_AREA_X1              16      //To do
    #define CAM_ACTIVE_AREA_Y1              26      //To do
    #define CAM_ACTIVE_AREA_X2              4640    //To do
    #define CAM_ACTIVE_AREA_Y2              3486    //To do

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT          0x40000000    // Found @0xff815f04

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_DNG_LENS_INFO               { 50,10, 800,10, 35,10, 59,10 } // See comments in camera.h

    #define cam_CFAPattern                  0x01000201   // [Green Blue Red Green]

    // TODO C&P from D10
    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000
    #define cam_CalibrationIlluminant1      1       // Daylight

    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_HAS_ND_FILTER                   1

    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_HAS_MOVIE_DIGEST_MODE           1   // camera doesn't actually have digest mode, this is needed by is_video_recording
    #define CAM_IS_VID_REC_WORKS                1   // is_video_recording() function works

    #define  CAM_EXT_TV_RANGE                   1    // CHDK can make exposure time longer than 64s

    #undef  CAM_VIDEO_CONTROL
// not working
    #undef CAM_CHDK_HAS_EXT_VIDEO_MENU
//    #define CAM_VIDEO_QUALITY_ONLY            1
//    #define CAM_CHDK_HAS_EXT_VIDEO_MENU       1

    // MakeDirectory_Fut not found, using mkdir
    #define MKDIR_RETURN_ONE_ON_SUCCESS

    //aspect correction
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION              1   //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                      720   // Actual width of bitmap screen in bytes

//  #define CAM_LOAD_CUSTOM_COLORS                  1   // Enable loading CHDK colors into the camera palette memory/hardware

    #define CAM_HAS_JOGDIAL                         1
    #define CAM_ADJUSTABLE_ALT_BUTTON               1
    #define CAM_ALT_BUTTON_NAMES                    { "Playback", "Disp", "Video" }
    #define CAM_ALT_BUTTON_OPTIONS                  { KEY_PLAYBACK, KEY_DISPLAY, KEY_VIDEO }

    // TODO
    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                         0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

    // TODO
    #define CAM_DATE_FOLDER_NAMING                  0x400

    #define PARAM_CAMERA_NAME                       3 // parameter number for GetParameterData

    #define CAM_FILE_COUNTER_IS_VAR                 1 // file counter is variable file_counter_var in stubs, not a param

    #define  CAM_HAS_FILEWRITETASK_HOOK             1 // FileWriteTask hook is available (local file write can be prevented)
    #define  CAM_FILEWRITETASK_SEEKS                1 // Camera's FileWriteTask can do Lseek() - DryOS r50 or higher, the define could also be CAM_DRYOS_2_3_R50

    #define CAM_HAS_ZOOM_LEVER                      1 // Camera has dedicated zoom buttons
    #define CAM_NEED_SET_ZOOM_DELAY                 300 // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS         1 // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT              1 // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt        1 // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

//To do
//  #define REMOTE_SYNC_STATUS_LED  0xC0220130???     // specifies an LED that turns on while camera waits for USB remote to sync

    #undef  CAM_AF_LED
    #define CAM_AF_LED                          1   // Index of AF led in camera_set_led function

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                     120  // delay after a press - Required by zoom_in/zoom_out buttons

    #define CAM_SD_OVER_IN_AF                       1
    #define CAM_SD_OVER_IN_AFL                      1
    #define CAM_SD_OVER_IN_MF                       1

    #define  DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY      1
    
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE          1
    #undef  CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                     200 // Override base 'market' ISO value, from isobase.lua 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_sx200is)
    #define DIGIC				    4
  // copied from SX10 and modified
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1
    #undef  EDGE_OVERLAY_COLOUR 
    #define EDGE_OVERLAY_COLOUR         0x9A
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_PROPSET                 2
    #define CAM_DRYOS                   1
    //#undef CAM_DIGIC
    //#define CAM_DIGIC			    4
    #define CAM_RAW_ROWPIX              4080 //from calcs see 100C lib.c 
    #define CAM_RAW_ROWS                3048 //"     "    "    "    "  
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #define CAM_MULTIPART               1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_UP
    #define STD_360_BUF				1
    #define CDM                         10  
    #define STD_PERIOD 			    *(volatile int*)(0x00386014)
    #undef  PERIOD_REF
    #define PERIOD_REF			   250
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30 // 1280x720
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef CAM_X_STRETCH               
    #define CAM_X_STRETCH               3
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE          4
    #undef CAM_HAS_ERASE_BUTTON
    #define  CAM_SHOW_OSD_IN_SHOOT_MENU 1
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    //need fixing *****************************************************
    #define CAM_COLORMATRIX1                               \
      14134, 1000000, -5576, 1000000, -1527, 1000000, \
     -1991,  1000000, 10719,  1000000, 1273,   1000000, \
      -1158,   1000000, 1929,   1000000, 3581,  1000000

    #define cam_CalibrationIlluminant1 17 // Standard Light A
    // cropping
    #define CAM_JPEG_WIDTH  4000
    #define CAM_JPEG_HEIGHT 3000
    #define CAM_ACTIVE_AREA_X1 52
    #define CAM_ACTIVE_AREA_Y1 14
    #define CAM_ACTIVE_AREA_X2 4052
    #define CAM_ACTIVE_AREA_Y2 3014
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                 58      // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                 68447   // Override max subject distance
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_sx210is)
    #define DIGIC				    4
    // copied from SX200 and modified
    #define CAM_DRYOS_2_3_R39			1
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_PROPSET			3

    #define	CAM_DATE_FOLDER_NAMING	0x100

    #define CAM_DRYOS                   1
    //#undef CAM_DIGIC
    //#define CAM_DIGIC			    4
    #define CAM_RAW_ROWPIX              4416 // from calcs see 100C lib.c   //ASM1989 08.20.2010  4416
    #define CAM_RAW_ROWS                3296 //  "     "    "    "    "  //ASM1989 08.20.2010   3296

    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define STD_360_BUF                 1
    #define CAM_HAS_VIDEO_BUTTON		1
    #define CAM_VIDEO_QUALITY_ONLY          1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_MULTIPART               1
    #define CDM                         9  
    #define STD_PERIOD 			    *(volatile int*)(0x003C6014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30  // 29.97 HD at 1280x720
    #define LOW_LIGHT                   1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1
   #define CAM_HAS_JOGDIAL             1
    #undef  CAM_USE_ZOOM_FOR_MF

    #define CAM_BRACKETING				1

    #define   CAM_STARTUP_CRASH_FILE_OPEN_FIX   1

    #undef  CAM_UNCACHED_BIT  // shut up compiler
    #define CAM_UNCACHED_BIT    0x40000000
    // pattern
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    // seem good asm1989

    #define	CAM_DNG_LENS_INFO               { 50,10, 700,10, 31,10, 59,10 }	// See comments in camera.h

    #define CAM_COLORMATRIX1                          \
1026340, 1000000, -412992, 1000000, -158934, 1000000, \
-59169, 1000000, 421214, 1000000, 23459, 1000000,     \
28948, 1000000, 10693, 1000000, 127339,  1000000

    #define cam_CalibrationIlluminant1 17 // Standard Light A
    // cropping  //ASM1989 08.20.2010
    #define CAM_JPEG_WIDTH  4320
    #define CAM_JPEG_HEIGHT 3240

    // This works
    #define CAM_ACTIVE_AREA_X1			48
	#define CAM_ACTIVE_AREA_Y1			28
	#define CAM_ACTIVE_AREA_X2			4416-48
	#define CAM_ACTIVE_AREA_Y2			3296-28
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #undef  CAM_WHITE_LEVEL
    #undef  CAM_BLACK_LEVEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #define CAM_BLACK_LEVEL             127

    #define CAM_EXT_TV_RANGE            1

    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE         15
    #undef CAM_HAS_ERASE_BUTTON
    #define  CAM_SHOW_OSD_IN_SHOOT_MENU  1

  #define CAM_HAS_VARIABLE_ASPECT 1

    //nandoide sept-2009
    #undef CAM_USES_ASPECT_CORRECTION
    #undef CAM_USES_ASPECT_YCORRECTION
    #define CAM_USES_ASPECT_CORRECTION  1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #define CAM_USES_ASPECT_YCORRECTION  0  //only uses mappings on x coordinate

	    #undef ASPECT_GRID_XCORRECTION
	    #define ASPECT_GRID_XCORRECTION(x)  ( ((x)<<3)/8  )  //grids are designed on a 360x240 basis and screen is 320x240, we need x*320/360=x*8/9  ,  8 is the right value for sx210
	    #undef ASPECT_GRID_YCORRECTION
	    #define ASPECT_GRID_YCORRECTION(y)  ( (y) )       //y correction for grids  made on a 360x240 As the buffer is 720x240 we have no correction here.


	    #undef ASPECT_VIEWPORT_XCORRECTION
	    #define ASPECT_VIEWPORT_XCORRECTION(x) ASPECT_GRID_XCORRECTION(x) //viewport is 360x240 and screen 320x240, we need x*320/360=x*8/9, equal than grids, used by edgeoverlay
	    #undef ASPECT_VIEWPORT_YCORRECTION
    #define ASPECT_VIEWPORT_YCORRECTION(y) ( (y) )


    #undef EDGE_HMARGIN
    #define EDGE_HMARGIN 10			//10 fits video mode of sx210

    //games mappings
   #undef GAMES_SCREEN_WIDTH
   #undef GAMES_SCREEN_HEIGHT
   #define GAMES_SCREEN_WIDTH 360
   #define GAMES_SCREEN_HEIGHT 240
   #undef ASPECT_GAMES_XCORRECTION
   // 720/360=2 same aspect than grids and viewport but another approach: there is a lot of corrections to do in game's code, and we decide to paint directly on display buffer wirh another resolution
   // used by gui.c that configures the draw environment (trhough new draw_gui function) depending on gui_mode: we have then 360x240 for games (but deformed output:circles are not circles) and 320x240 for
   // other modes in perfect aspect ratio 4/3: slightly better visualization: file menus more readable, ...
   #define ASPECT_GAMES_XCORRECTION(x)   ( ((x)<<1) )
   #undef ASPECT_GAMES_YCORRECTION
   #define ASPECT_GAMES_YCORRECTION(y)   ( (y) )  //none

   //zebra letterbox for saving memory
   #undef ZEBRA_HMARGIN0
   #define ZEBRA_HMARGIN0  30 //this 30 rows are not used by the display buffer is 720x240 effective, no 960x270, i.e. (270-240) reduction in widht possible but not done (more difficult to manage it and slower).

//Testing Zebra stuff asmp1989 Dec2010
    #define CAM_ZEBRA_ASPECT_ADJUST 1
    #define CAM_ZEBRA_NOBUF 1

   //end nandoide sept-2009
   #define CAM_QUALITY_OVERRIDE 1
   #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x12
    #define COLOR_GREY_P          0x12
    #define COLOR_LIGHT_GREY      0x16
    #define COLOR_DARK_GREY       0x22
    #define COLOR_LIGHT_GREY_P    0x16
    #define COLOR_DARK_GREY_P     0x22
//----------------------------------------------------------

#elif defined (CAMERA_sx220hs)
    #define DIGIC				    4
    #define CAM_NEED_HP                 1
    #define CAM_HAS_PLAYBACK_PB         1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    1
    #define CAM_MOVIE_PLE               1
    #define STD_360_BUF                 1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_DOWN
    #define CDM                         99
    #define UI_CS_PROP			    0x800C
    #define UI_CT_PROP			    0x800D
    #define STD_PERIOD 			    *(volatile int*)(0x00406014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       24 // 23.976 at 1920x1080,29.97 at 1280x720,120 fps at 640x480,240 fps at 320x240
    #undef  PERIOD_REF
    #define PERIOD_REF			    701
    #define CAM_PRECISION_SYNCH         1	
    #define COUNTS_BEFORE_INT          *(volatile int*)(0x0040713C)
    #define LOW_LIGHT                   1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  "MOV"
    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1
    #define DNG_VERT_RLE_BADPIXELS              1
    #define CAM_AV_OVERRIDE_IRIS_FIX            1   // for cameras that require _MoveIrisWithAv function to override Av.
    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60  // delay after a press
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1
    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1   // Draw pixels on active bitmap buffer only.

    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1
    #define CAM_PROPSET                         4
    #define CAM_DATE_FOLDER_NAMING              0x400
    #define CAM_DRYOS                           1
    #define CAM_RAW_ROWPIX                      4168
    #define CAM_RAW_ROWS                        3060 // actual size from fw 12754080pix at FF375484 -> 19131120/12*8

    #define CAM_HAS_CMOS                        1
    #define CAM_HAS_ND_FILTER                   1
    #define CAM_HAS_JOGDIAL                     1
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_HAS_MOVIE_DIGEST_MODE           1

    #undef  CAM_HAS_ERASE_BUTTON

    #undef  CAM_CAN_SD_OVER_NOT_IN_MF

    #define CAM_VIDEO_QUALITY_ONLY              1
    #undef  CAM_VIDEO_CONTROL
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO

    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT                    // shut up compiler
    #define CAM_UNCACHED_BIT                    0x40000000

    #define CAM_DNG_LENS_INFO                   { 50,10, 700,10, 31,10, 59,10 } // See comments in camera.h
    #define cam_CFAPattern                      0x02010100

    #define CAM_COLORMATRIX1                            \
    544808, 1000000, -174047, 1000000, -80399, 1000000, \
    -75055, 1000000,  440444, 1000000,  11367, 1000000, \
     -5801, 1000000,   71589, 1000000, 118914, 1000000

    #define cam_CalibrationIlluminant1          17
   
    #define CAM_JPEG_WIDTH                      4000
    #define CAM_JPEG_HEIGHT                     3000
    #define CAM_ACTIVE_AREA_X1                  96
    #define CAM_ACTIVE_AREA_Y1                  24
    #define CAM_ACTIVE_AREA_X2                  4168
    #define CAM_ACTIVE_AREA_Y2                  3060

    #define PARAM_CAMERA_NAME                   4   // parameter number for GetParameterData - Camera Model name
    #define PARAM_OWNER_NAME                    7   // parameter number for GetParameterData - Owner name
    
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1
    #define CAM_CHDK_HAS_EXT_VIDEO_TIME         1

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  24
 
//    #define CAM_LOAD_CUSTOM_COLORS              1   // Enable loading CHDK colors into the camera palette memory
    #define CHDK_COLOR_BASE                     0xA8// Start color index for CHDK colors loaded into camera palette.

    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #define CAM_HAS_VARIABLE_ASPECT             1
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1   //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_SCREEN_WIDTH
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_SCREEN_WIDTH                    480 // Width of bitmap screen in CHDK co-ordinates
    #define CAM_BITMAP_WIDTH                    960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT                   270 // Actual height of bitmap screen in rows

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                        10

    #define CAM_ZEBRA_NOBUF                     1

    //#define CAM_QUALITY_OVERRIDE                1 // works not really

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX     1

    #define CAM_USE_ALT_SET_ZOOM_POINT          1   // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt    1   // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     99  // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     2000000 // Override max subject distance 1739131 //testscript=1098902

    #define REMOTE_SYNC_STATUS_LED              0xC0220130 // specifies an LED that turns on while camera waits for USB remote to sync

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY           0x16
    #define COLOR_GREY_P         0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
    
//----------------------------------------------------------

#elif defined (CAMERA_sx230hs)
    #define DIGIC				    4
    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1
    #define DNG_VERT_RLE_BADPIXELS          1
    #define CAM_AV_OVERRIDE_IRIS_FIX        1
    #define CAM_KEY_CLICK_DELAY             150
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1
    #define STD_360_BUF                 1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_DOWN
    #define CDM                         99
    #define UI_CS_PROP			    0x800C 
    #define UI_CT_PROP			    0x800D 
    #define STD_PERIOD 			    *(volatile int*)(0x00406014)
    #undef  PERIOD_REF
    #define PERIOD_REF			      700
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       24 // 23.976 at 1920x1080,29.97 at 1280x720,120 fps at 640x480,240 fps at 320x240	
    #define CAM_PRECISION_SYNCH             1
    #define LOW_LIGHT                       1
    #define CAM_NEED_HP                     1
    #define CAM_HAS_PLAYBACK_PB             1
    //#undef CAM_DIGIC
    //#define CAM_DIGIC			        4
    #define CAM_DRYOS_2_3_R39               1
    #define CAM_DRYOS_2_3_R47               1
    #define CAM_PROPSET                     4
    #define CAM_DATE_FOLDER_NAMING          0x400
    #define CAM_DRYOS                       1
    #define CAM_RAW_ROWPIX                  4168
    #define CAM_RAW_ROWS                    3060

    #define CAM_HAS_CMOS                    1

    #define CAM_HAS_ND_FILTER               1
        
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_CONTROL_BUTTON            1
    #define CAM_VIDEO_QUALITY_ONLY          1
 
    #undef  CAM_VIDEO_CONTROL
   
    #define CAM_HAS_JOGDIAL                 1
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000

    #define CAM_DNG_LENS_INFO               { 50,10, 700,10, 31,10, 59,10 } // See comments in camera.h
    #define cam_CFAPattern                  0x02010100
  
    #define CAM_COLORMATRIX1                            \
    544808, 1000000, -174047, 1000000, -80399, 1000000, \
    -75055, 1000000,  440444, 1000000,  11367, 1000000, \
     -5801, 1000000,   71589, 1000000, 118914, 1000000
 
    #define cam_CalibrationIlluminant1      17
   
    #define CAM_JPEG_WIDTH                  4000
    #define CAM_JPEG_HEIGHT                 3000
                                                
    #define CAM_ACTIVE_AREA_X1              96
    #define CAM_ACTIVE_AREA_Y1              24
    #define CAM_ACTIVE_AREA_X2              4168
    #define CAM_ACTIVE_AREA_Y2              3060

    #define PARAM_CAMERA_NAME               4
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_EXT_TV_RANGE                1
    
    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              24
    #undef CAM_HAS_ERASE_BUTTON
    #define  CAM_SHOW_OSD_IN_SHOOT_MENU     1

    #define CAM_HAS_VARIABLE_ASPECT         1
    #undef ASPECT_XCORRECTION
    #define ASPECT_XCORRECTION(x)  (((x)<<1))
    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_SCREEN_WIDTH
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_SCREEN_WIDTH                480 // Width of bitmap screen in CHDK co-ordinates
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows
    
    #undef EDGE_HMARGIN
    #define EDGE_HMARGIN                    10

    #undef ZEBRA_HMARGIN0
    #define ZEBRA_HMARGIN0                  30

    #define CAM_ZEBRA_ASPECT_ADJUST         1
    #define CAM_ZEBRA_NOBUF                 1

    //#define CAM_QUALITY_OVERRIDE            1
    
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1
    
    #define CAM_HAS_GPS                     1
    #define CAM_CHDK_HAS_EXT_VIDEO_TIME     1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY           0x16
    #define COLOR_GREY_P         0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
    #define  CAM_HAS_MOVIE_DIGEST_MODE	1
//----------------------------------------------------------

#elif defined (CAMERA_sx240hs)
    #define DIGIC				    5
    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1
    #define DNG_VERT_RLE_BADPIXELS              1
    #define CAM_AV_OVERRIDE_IRIS_FIX            1
    #define CAM_HAS_ND_FILTER                   1 // Camera has built-in ND filter (in addition to iris)
    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60      // delay after a press
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1
    #define STD_360_BUF                 1
    #define CAM_NEED_HP                 		1
    #define CAM_HAS_PLAYBACK_PB         		1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    	1
    #define NEW_REC_PLAY			1
    #define NEW_MOVIE			      1
    #define CDM                         		10  // Canon drive mode	
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_UP
    #define STD_PERIOD 			        	*(volatile int*)(0x00606014)
    #undef  PERIOD_REF
    #define PERIOD_REF			         	1201
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       	24 // 23.976 actual 1920x1080 HD,also 120 fps at 640x480 and 29.97 at 1280x720, 240 fps at 320x240
    #define CAM_PRECISION_SYNCH                 1
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      	((int*)0xC0F070C8)	
    #undef SYNCH_SPEED
    #define SYNCH_SPEED 				8 
    #define LOW_LIGHT                   		1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  		"MOV"

    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1
    #define CAM_PROPSET                         5
    #define CAM_DATE_FOLDER_NAMING              0x400
    #define CAM_DRYOS                           1
    #define CAM_RAW_ROWPIX                      4176        //ASM1989 FINSIG  Found @0xff17db40
    #define CAM_RAW_ROWS                        3060        // Found @0xff17db4c
    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1           // Draw pixels on active bitmap buffer only.

    #define CAM_HAS_CMOS                        1

    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_VIDEO_QUALITY_ONLY              1

    #undef  CAM_VIDEO_CONTROL

    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000

    #define CAM_DNG_LENS_INFO                   { 45,10,900,10,35,10,68,10 } // See comments in camera.h  -> finsig finds the focus_len_table address at 0xfff4bcf0.This is using DNG_LENS_INFO defined as { 45,10, 900,10, 35,10, 68,10 },
    #define cam_CFAPattern                      0x02010100

    #define CAM_COLORMATRIX1                            \
    544808, 1000000, -174047, 1000000, -80399, 1000000, \
    -75055, 1000000,  440444, 1000000,  11367, 1000000, \
     -5801, 1000000,   71589, 1000000, 118914, 1000000

    #define cam_CalibrationIlluminant1          17

    #define CAM_JPEG_WIDTH                      4000
    #define CAM_JPEG_HEIGHT                     3000

    #define CAM_ACTIVE_AREA_X1                  96
    #define CAM_ACTIVE_AREA_Y1                  24
    #define CAM_ACTIVE_AREA_X2                  4176
    #define CAM_ACTIVE_AREA_Y2                  3060

    #define PARAM_CAMERA_NAME                   4
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  25
    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1           //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                    960         // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT                   270         // Actual height of bitmap screen in rows
    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                        10

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX     1           // enable workaround for camera crash at startup when opening the conf / font files
                                                            // see http://chdk.setepontos.com/index.php?topic=6179.0

    #define CAM_HAS_FILEWRITETASK_HOOK          1
    #define CAM_FILEWRITETASK_SEEKS             1

    #define CAM_ZEBRA_NOBUF                     1

    #define CAM_QUALITY_OVERRIDE                1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     100         // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     1550000     // Override max subject distance; manually checked up to 1550388, with MF max 1369863 (double step)

//    #define CAM_HAS_GPS                         1           // Only valid for sx260

    #define CAM_USE_SUNRISE                     1

    #define CAM_CHDK_HAS_EXT_VIDEO_TIME         1

 //   #define CAM_LOAD_CUSTOM_COLORS              1           // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                     0xA8        // Start color index for CHDK colors loaded into camera palette.

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202       // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.

    #define CAM_HAS_MOVIE_DIGEST_MODE           1 

    #define CAM_USE_ALT_SET_ZOOM_POINT          1           // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt    1           // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1    // mkdir() return 1 on success, 0 on fail.

    #define CAM_DISABLE_RAW_IN_AUTO             1 // For cameras that don't have valid raw in AUTO mode

    #undef  REMOTE_SYNC_STATUS_LED
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------

#elif defined (CAMERA_sx260hs)
    #define DIGIC				    5
    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1
    #define DNG_VERT_RLE_BADPIXELS              1
    #define CAM_AV_OVERRIDE_IRIS_FIX            1
    #define CAM_HAS_ND_FILTER                   1           // Camera has built-in ND filter (in addition to iris)
    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60          // delay after a press
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1
    #define STD_360_BUF                         1
    #define CAM_NEED_HP                 		1
    #define CAM_HAS_PLAYBACK_PB         		1
    #define CAM_HAS_VIDEO_CONTROL_BUTTON    	1
    #define NEW_REC_PLAY			      1
    #define NEW_MOVIE			            1
    #undef  ANA_BUTTON
    #define ANA_BUTTON                  KEY_UP
    #define CDM                         		10  // Canon drive mode	
    #define STD_PERIOD 			        	 _EngDrvRead(0xC0F06014)
    #undef  PERIOD_REF
    #define PERIOD_REF			         	1201
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       	24 // 23.976 actual 1920x1080 HD,also 120 fps at 640x480 and 29.97 at 1280x720, 240 fps at 320x240
    #define CAM_PRECISION_SYNCH                 1
    #undef PERIOD_COUNT
    #define PERIOD_COUNT		      	((int*)0xC0F070C8)	
    #undef SYNCH_SPEED
    #define SYNCH_SPEED 				8 
    #define LOW_LIGHT                   		1
    #undef  MOVIE_TYPE
    #define MOVIE_TYPE                  		"MOV"
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1
    #define CAM_PROPSET                         5
    #define CAM_DATE_FOLDER_NAMING              0x400
    #define CAM_DRYOS                           1
    #define CAM_RAW_ROWPIX                      4176        //ASM1989 FINSIG  Found @0xff17db40
    #define CAM_RAW_ROWS                        3060        // Found @0xff17db4c
    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1           // Draw pixels on active bitmap buffer only.

    #define CAM_HAS_CMOS                        1

    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_VIDEO_QUALITY_ONLY              1

    #undef  CAM_VIDEO_CONTROL

    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000

    #define CAM_DNG_LENS_INFO                   { 45,10,900,10,35,10,68,10 } // See comments in camera.h  -> finsig finds the focus_len_table address at 0xfff4bcf0.This is using DNG_LENS_INFO defined as { 45,10, 900,10, 35,10, 68,10 },
    #define cam_CFAPattern                      0x02010100

    #define CAM_COLORMATRIX1                            \
    544808, 1000000, -174047, 1000000, -80399, 1000000, \
    -75055, 1000000,  440444, 1000000,  11367, 1000000, \
     -5801, 1000000,   71589, 1000000, 118914, 1000000

    #define cam_CalibrationIlluminant1          17

    #define CAM_JPEG_WIDTH                      4000
    #define CAM_JPEG_HEIGHT                     3000

    #define CAM_ACTIVE_AREA_X1                  96
    #define CAM_ACTIVE_AREA_Y1                  24
    #define CAM_ACTIVE_AREA_X2                  4176
    #define CAM_ACTIVE_AREA_Y2                  3060

    #define PARAM_CAMERA_NAME                   4
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  25
    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1           //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                    960         // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT                   270         // Actual height of bitmap screen in rows
    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                        10

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX     1           // enable workaround for camera crash at startup when opening the conf / font files
                                                            // see http://chdk.setepontos.com/index.php?topic=6179.0

    #define CAM_HAS_FILEWRITETASK_HOOK          1
    #define CAM_FILEWRITETASK_SEEKS             1

    #define CAM_ZEBRA_NOBUF                     1

    #define CAM_QUALITY_OVERRIDE                1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     100         // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     1550000     // Override max subject distance; manually checked up to 1550388, with MF max 1369863 (double step)

    #define CAM_HAS_GPS                         1

    #define CAM_USE_SUNRISE                     1

    #define CAM_CHDK_HAS_EXT_VIDEO_TIME         1

//  #define CAM_LOAD_CUSTOM_COLORS              1           // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                     0xA8        // Start color index for CHDK colors loaded into camera palette.

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202       // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.

    #define CAM_HAS_MOVIE_DIGEST_MODE           1 

    #define CAM_USE_ALT_SET_ZOOM_POINT          1           // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt    1           // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1    // mkdir() return 1 on success, 0 on fail.

    #define CAM_DISABLE_RAW_IN_AUTO             1 // For cameras that don't have valid raw in AUTO mode

    #undef  REMOTE_SYNC_STATUS_LED

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
 
    #define COLOR_GREY            0x16
    #define COLOR_GREY_P          0x16
    #define COLOR_LIGHT_GREY      0x0E
    #define COLOR_DARK_GREY       0x1A
    #define COLOR_LIGHT_GREY_P    0x0E
    #define COLOR_DARK_GREY_P     0x1A
//----------------------------------------------------------
#elif defined (CAMERA_tx1)
    #define DIGIC				    3
    #define CAM_HAS_VIDEO_CONTROL_BUTTON            1
    #define CDM                         0  
    #define STD_PERIOD 			    *(volatile int*)(0x00306014)
    #undef  SYNCH_FPS
    #define SYNCH_FPS			       30  // 1280x720
    #define CAM_PROPSET                 2
    #undef  CAM_OUTLINE_MODE  
    #define CAM_SWIVEL_SCREEN           1
 // #define CAM_HAS_ND_FILTER           1
    #undef  CAM_HAS_MANUAL_FOCUS
    #define CAM_RAW_ROWPIX		    3152 //for 7 MP
    #define CAM_RAW_ROWS		    2340 //for 7 MP
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_MULTIPART               1 
    #define cam_CFAPattern 0x02010100 // Red  Green  Green  Blue
    // color
    #define CAM_COLORMATRIX1                                \
      510370,  1000000, -68998,  1000000, -86859,  1000000, \
      -279980, 1000000, 766686,  1000000,  67944,  1000000, \
      -14382,  1000000, 113688,  1000000, 239853,  1000000
    
    #define cam_CalibrationIlluminant1 1 // Daylight
    // cropping
    #define CAM_JPEG_WIDTH  3072
    #define CAM_JPEG_HEIGHT 2304
    #define CAM_ACTIVE_AREA_X1 12
    #define CAM_ACTIVE_AREA_Y1 8
    #define CAM_ACTIVE_AREA_X2 3108
    #define CAM_ACTIVE_AREA_Y2 2332

    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                480 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               271 // Actual height of bitmap screen in rows

    // camera name
    #define PARAM_CAMERA_NAME 4 // parameter number for GetParameterData
    // Warning : SD override for this camera with these values has not been tested
    #define CAM_CAN_SD_OVERRIDE_UNKNOWN_STATUS 1
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL 1
    #define CAM_SD_OVER_IN_MF  1
    #define COLOR_GREY            0x3F
    #define COLOR_GREY_P          0x3F
    #define COLOR_LIGHT_GREY      0x1F
    #define COLOR_DARK_GREY       0x44
    #define COLOR_LIGHT_GREY_P    0x1F
    #define COLOR_DARK_GREY_P     0x44

#else
#error camera type not defined
#endif
 
#if defined(OPT_NEW_ZEBRA)
typedef struct 
{
    int     width, height, size;                        // Size of bitmap screen in CHDK co-ordinates
    int     physical_width;                             // Actual width of bitmap screen in pixels
    int     buffer_width, buffer_height, buffer_size;   // Physical size of bitmap screen
    int     edge_hmargin, ts_button_border;             // margin and touch-screen adjustment values
    int     zebra_nobuf, zebra_aspect_adjust;           // zebra feature settings
    int     has_variable_aspect;                        // zebra feature settings
    int     menu_border_width;                          // Width of border on each side of CHDK menu
} _cam_screen;

extern _cam_screen camera_screen;

typedef struct
{
    struct
    {
      int aspect_ratio;
      int shooting;
    } props;
} _cam_info;

extern _cam_info camera_info;
#endif

#endif
