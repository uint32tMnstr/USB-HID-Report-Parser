#include "report_usage.h"

int8_t *ri_GenericDesktop(int32_t usage)
{
    switch (usage)
    {
    case GD_Pointer:
        return "Pointer";
    case GD_Mouse:
        return "Mouse";
    case GD_Joystick:
        return "Joystick";
    case GD_Game_Pad:
        return "Game Pad";
    case GD_Keyboard:
        return "Keyboard";
    case GD_Keypad:
        return "Keypad";
    case GD_Multiaxis_Controller:
        return "Multi-axis Controller";
    case GD_Tablet_PC_Sys_Controls:
        return "Tablet PC System Controls";
    case GD_X:
        return "X";
    case GD_Y:
        return "Y";
    case GD_Z:
        return "Z";
    case GD_Rx:
        return "Rx";
    case GD_Ry:
        return "Ry";
    case GD_Rz:
        return "Rz";
    case GD_Slider:
        return "Slider";
    case GD_Dial:
        return "Dial";
    case GD_Wheel:
        return "Wheel";
    case GD_Hat_Switch:
        return "Switch";
    case GD_Counted_Buffer:
        return "Counted Buffer";
    case GD_Byte_Count:
        return "Byte Count";
    case GD_Motion_Wakeup:
        return "Motion Wakeup";
    case GD_Start:
        return "Start";
    case GD_Select:
        return "Select";
    case GD_Vx:
        return "Vx";
    case GD_Vy:
        return "Vy";
    case GD_Vz:
        return "Vz";
    case GD_Vbrx:
        return "Vbrx";
    case GD_Vbry:
        return "Vbry";
    case GD_Vbrz:
        return "Vbrz";
    case GD_Vno:
        return "Vno";
    case GD_Feature_Notification:
        return "Feature Notification";
    case GD_Resolution_Multiplier:
        return "Resolution Multiplier";
    case GD_Sys_Control:
        return "System Control";
    case GD_Sys_Power_Down:
        return "System Power Down";
    case GD_Sys_Sleep:
        return "System Sleep";
    case GD_Sys_Wake_Up:
        return "System Wake Up";
    case GD_Sys_Context_Menu:
        return "System Context Menu";
    case GD_Sys_Main_Menu:
        return "System Main Menu";
    case GD_Sys_App_Menu:
        return "System App Menu";
    case GD_Sys_Menu_Help:
        return "System Menu Help";
    case GD_Sys_Menu_Exit:
        return "System Menu Exit";
    case GD_Sys_Menu_Select:
        return "System Menu Select";
    case GD_Sys_Menu_Right:
        return "System Menu Right";
    case GD_Sys_Menu_Left:
        return "System Menu Left";
    case GD_Sys_Menu_Up:
        return "System Menu Up";
    case GD_Sys_Menu_Down:
        return "System Menu Down";
    case GD_Sys_Cold_Restart:
        return "System Cold Restart";
    case GD_Sys_Warm_Restart:
        return "System Warm Restart";
    case GD_D_pad_Up:
        return "D-pad Up";
    case GD_D_pad_Down:
        return "D-pad Down";
    case GD_D_pad_Right:
        return "D-pad Right";
    case GD_D_pad_Left:
        return "D-pad Left";
    case GD_Sys_Dock:
        return "System Dock";
    case GD_Sys_Undock:
        return "SYstem Undock";
    case GD_Sys_Setup:
        return "System Setup";
    case GD_Sys_Break:
        return "System Break";
    case GD_Sys_Debugger_Break:
        return "System Debugger Break";
    case GD_Application_Break:
        return "Application Break";
    case GD_Application_Debugger_Break:
        return "Application Debugger Break";
    case GD_Sys_Speaker_Mute:
        return "System Speaker Mute";
    case GD_Sys_Hibernate:
        return "System Hibernate";
    case GD_Sys_Display_Invert:
        return "System Display Invert";
    case GD_Sys_Display_Internal:
        return "System Display Internal";
    case GD_Sys_Display_External:
        return "System Display External";
    case GD_Sys_Display_Both:
        return "System Display Both";
    case GD_Sys_Display_Dual:
        return "System Display Dual";
    case GD_Sys_Display_Toggle:
        return "System Display Toggle";
    case GD_Sys_Display_Swap:
        return "System Display Swap";
    case GD_Sys_Display_LCD_Autoscale:
        return "System Display LCD Autoscale";
    default:
        return "Unknown";
    }
}

int8_t *ri_SimulationControls(int32_t usage)
{
    switch (usage)
    {
    case SC_SimuDev_Flight:
        return "Flight Simulation Device";
    case SC_SimuDev_Automobile:
        return "Automobile Simulation Device";
    case SC_SimuDev_Tank:
        return "Tank Simulation Device";
    case SC_SimuDev_Spaceship:
        return "Spaceship Simulation Device";
    case SC_SimuDev_Submarine:
        return "Submarine Simulation Device";
    case SC_SimuDev_Sailing:
        return "Sailing Simulation Device";
    case SC_SimuDev_Motorcycle:
        return "Motorcycle Simulation Device";
    case SC_SimuDev_Sports:
        return "Sports Simulation Device";
    case SC_SimuDev_Airplane:
        return "Airplane Simulation Device";
    case SC_SimuDev_Helicopter:
        return "Helicopter Simulation Device";
    case SC_SimuDev_MagicCarpet:
        return "MagicCarpet Simulation Device";
    case SC_SimuDev_Bicycle:
        return "Bicycle Simulation Device";
    case SC_Flight_Control_Stick:
        return "Flight Control Stick";
    case SC_Flilght_Stick:
        return "Flilght Stick";
    case SC_Cyclic_Control:
        return "Cyclic Control";
    case SC_Cyclic_Trim:
        return "Cyclic Trim";
    case SC_Flight_Yoke:
        return "Flight Yoke";
    case SC_Track_Control:
        return "Track Control";
    case SC_Aileron:
        return "Aileron";
    case SC_Aileron_Trim:
        return "Aileron Trim";
    case SC_Anti_Torque_Control:
        return "Anti Torque Control";
    case SC_Autopilot_Enable:
        return "Autopilot Enable";
    case SC_Chaff_Release:
        return "Chaff Release";
    case SC_Collective_Control:
        return "Collective Control";
    case SC_Dive_Brake:
        return "Dive Brake";
    case SC_Electronic_Countermeasures:
        return "Electronic Countermeasures";
    case SC_Elevator:
        return "Elevator";
    case SC_Elevator_Trim:
        return "Elevator Trim";
    case SC_Rudder:
        return "Rudder";
    case SC_Throttle:
        return "Throttle";
    case SC_Flight_Communications:
        return "Flight Communications";
    case SC_Flare_Release:
        return "Flare Release";
    case SC_Landing_Gear:
        return "Landing Gear";
    case SC_Toe_Brake:
        return "Toe Brake";
    case SC_Trigger:
        return "Trigger";
    case SC_Weapons_Arm:
        return "Weapons Arm";
    case SC_Weapons_Select:
        return "Weapons Select";
    case SC_Wing_Flaps:
        return "Wing Flaps";
    case SC_Accelerator:
        return "Accelerator";
    case SC_Brake:
        return "Brake";
    case SC_Clutch:
        return "Clutch";
    case SC_Shifter:
        return "Shifter";
    case SC_Steering:
        return "Steering";
    case SC_Turret_Direction:
        return "Turret Direction";
    case SC_Barrel_Elevation:
        return "Barrel Elevation";
    case SC_Dive_Plane:
        return "Dive Plane";
    case SC_Ballast:
        return "Ballast";
    case SC_Bicycle_Crank:
        return "Bicycle Crank";
    case SC_Handle_Bars:
        return "Handle Bars";
    case SC_Front_Brake:
        return "Front Brake";
    case SC_Rear_Brake:
        return "Rear Brake";
    default:
        return "Unkonwn";
    }
}

int8_t *ri_VRControls(int32_t usage)
{
    switch(usage)
    {
    case VR_Belt:
        return "Belt";
    case VR_Body_Suit:
        return "Body Suit";
    case VR_Flexor:
        return "Flexor";
    case VR_Glove:
        return "Glove";
    case VR_Head_Tracker:
        return "Head Tracker";
    case VR_Head_Mounted_Display:
        return "Head Mounted Display";
    case VR_Hand_Tracker:
        return "Hand Tracker";
    case VR_Oculometer:
        return "Oculometer";
    case VR_Vest:
        return "Vest";
    case VR_Animatronic_Device:
        return "Animatronic Device";
    case VR_Stereo_Enable:
        return "Stereo Enable";
    case VR_Display_Enable:
        return "Display Enable";
    default:
        return "Unknown";
    }
}

int8_t *ri_SportControls(int32_t usage)
{
    switch(usage)
    {
    case SpC_Baseball_Bat:
        return "Baseball Bat";
    case SpC_Golf_Club:
        return "Golf Club";
    case SpC_Rowing_Machine:
        return "Rowing Machine";
    case SpC_Treadmill:
        return "Treadmill";
    case SpC_Oar:
        return "Oar";
    case SpC_Slope:
        return "Slope";
    case SpC_Rate:
        return "Rate";
    case SpC_Stick_Speed:
        return "Stick Speed";
    case SpC_Stick_Face_Angle:
        return "Stick Face Angle";
    case SpC_Stick_HeelorToe:
        return "Stick HeelorToe";
    case SpC_Stick_Follow_Through:
        return "Stick Follow Through";
    case SpC_Stick_Tempo:
        return "Stick Tempo";
    case SpC_Stick_Type:
        return "Stick Type";
    case SpC_Stick_Height:
        return "Stick Height";
    case SpC_Putter:
        return "Putter";
    case SpC_Iron_1:
    case SpC_Iron_2:
    case SpC_Iron_3:
    case SpC_Iron_4:
    case SpC_Iron_5:
    case SpC_Iron_6:
    case SpC_Iron_7:
    case SpC_Iron_8:
    case SpC_Iron_9:
    case SpC_Iron_10:
    case SpC_Iron_11:
        return "Iron";
    case SpC_Sand_Wedge:
        return "Sand Wedge";
    case SpC_Loft_Wedge:
        return "Loft Wedge";
    case SpC_Power_Wedge:
        return "Power Wedge";
    case SpC_Wood_1:
    case SpC_Wood_3:
    case SpC_Wood_5:
    case SpC_Wood_7:
    case SpC_Wood_9:
        return "Wood";
    default:
        return "Unknown";
    }
}

int8_t *ri_GameControls(int32_t usage)
{
    switch(usage)
    {
    case GC_3D_Game_Controller:
        return "3D Game Controller ";
    case GC_Pinball_Device:
        return "Pinball Device ";
    case GC_Gun_Device:
        return "Gun Device";
    case GC_Point_of_View:
        return "Point of View";
    case GC_Turn_Right_Left:
        return "Turn Right/Left";
    case GC_Pitch_Forward_Backward:
        return "Pitch Forward/Backward";
    case GC_Roll_Right_Left:
        return "Roll Right/Left";
    case GC_Move_Right_Left:
        return "Move Right/Left";
    case GC_Move_Forward_Backward:
        return "Move Forward/Backward";
    case GC_Move_Up_Down:
        return "Move Up/Down";
    case GC_Lean_Right_Left:
        return "Lean Right/Left";
    case GC_Lean_Forward_Backward:
        return "Lean Forward/Backward";
    case GC_Height_of_POV:
        return "Height of POV";
    case GC_Flipper:
        return "Flipper";
    case GC_Secondary_Flipper:
        return "Secondary Flipper";
    case GC_Bump:
        return "Bump";
    case GC_New_Game:
        return "New Game";
    case GC_Shoot_Ball:
        return "Shoot Ball";
    case GC_Player:
        return "Player";
    case GC_Gun_Bolt:
        return "Gun Bolt";
    case GC_Gun_Clip:
        return "Gun Clip";
    case GC_Gun_Selector:
        return "Gun Selector";
    case GC_Gun_Single_Shot:
        return "Gun Single Shot";
    case GC_Gun_Burst:
        return "Gun Burst";
    case GC_Gun_Automatic:
        return "Gun Automatic";
    case GC_Gun_Safety:
        return "Gun Safety";
    case GC_Gamepad_Fire_Jump:
        return "Gamepad Fire/Jump";
    case GC_Gamepad_Trigger:
        return "Gamepad Trigger";
    default:
        return "Unknown";
    }
}

int8_t *ri_GenericDeviceControls(int32_t usage)
{
    switch(usage)
    {
    case GDC_Battery_Strength:
	    return "Battery Strength";
    case GDC_Wireless_Channel:
        return "Wireless Channel";
    case GDC_Wireless_ID:
        return "Wireless ID";
    case GDC_Discover_Wireless_Ctrl:
        return "Discover Wireless Ctrl";
    case GDC_SC_Character_Entered:
        return "Security Code Character Entered";
    case GDC_SC_Character_Cleared:
        return "Security Code Character Cleared";
    case GDC_SC_Cleared:
        return "Security Code Cleared";
    default:
        return "Unknown";
    }
}

int8_t *ri_KeyboardOrKeypad(int32_t usage)
{
    switch(usage)
    {
    //TODO:
    default:
        return "Unknown";
    }
}

int8_t *ri_LEDs(int32_t usage)
{
    switch(usage)
    {
    case LED_Num_Lock:
        return "Num Lock";
    case LED_Caps_Lock:
        return "Caps Lock";
    case LED_Scroll_Lock:
        return "Scroll Lock";
    case LED_Compose:
        return "Compose";
    case LED_Kana:
        return "Kana";
    case LED_Power:
        return "Power";
    case LED_Shift:
        return "Shift";
    case LED_Donot_Disturb:
        return "Donot Disturb";
    case LED_Mute:
        return "Mute";
    case LED_Tone_Enable:
        return "Tone Enable";
    case LED_High_Cut_Filter:
        return "High Cut Filter";
    case LED_Low_Cut_Filter:
        return "Low Cut Filter";
    case LED_Equalizer_Enable:
        return "Equalizer Enable";
    case LED_Sound_Field_On:
        return "Sound Field On";
    case LED_Surround_On:
        return "Surround On";
    case LED_Repeat:
        return "Repeat";
    case LED_Stereo:
        return "Stereo";
    case LED_Sampling_Rate_Detect:
        return "Sampling Rate Detect";
    case LED_Spinning:
        return "Spinning";
    case LED_CAV:
        return "CAV";
    case LED_CLV:
        return "CLV";
    case LED_Recording_Format_Detect:
        return "Recording Format Detect";
    case LED_Off_Hook:
        return "Off-Hook";
    case LED_Ring:
        return "Ring";
    case LED_Message_Waiting:
        return "Message Waiting";
    case LED_Data_Mode:
        return "Data Mode";
    case LED_Battery_Operation:
        return "Battery Operation";
    case LED_Battery_OK:
        return "Battery OK";
    case LED_Battery_Low:
        return "Battery LOW";
    case LED_Speaker:
        return "Speaker";
    case LED_Head_Set:
        return "Head Set";
    case LED_Hold:
        return "Hold";
    case LED_Microphone:
        return "Microphone";
    case LED_Coverage:
        return "Coverage";
    case LED_Night_Mode:
        return "Night Mode";
    case LED_Send_Calls:
        return "Send Calls";
    case LED_Call_Pickup:
        return "Call Pickup";
    case LED_Conference:
        return "Conference";
    case LED_Standby:
        return "Standby";
    case LED_Camera_On:
        return "Camera On";
    case LED_Camera_Off:
        return "Camera Off";
    case LED_On_Line:
        return "On Line";
    case LED_Off_Line:
        return "Off Line";
    case LED_Busy:
        return "Busy";
    case LED_Ready:
        return "Ready";
    case LED_Paper_Out:
        return "Paper Out";
    case LED_Paper_Jam:
        return "Paper Jam";
    case LED_Remote:
        return "Remote";
    case LED_Forward:
        return "Forward";
    case LED_Reverse:
        return "Reverse";
    case LED_Stop:
        return "Stop";
    case LED_Rewind:
        return "Rewind";
    case LED_Fast_Forward:
        return "Fast Forward";
    case LED_Play:
        return "Play";
    case LED_Pause:
        return "Pause";
    case LED_Record:
        return "Record";
    case LED_Error:
        return "Error";
    case LED_Selected_Indicator:
        return "Selected Indicator";
    case LED_In_Use_Indicator:
        return "In Use Indicator";
    case LED_Multi_Mode_Indicator:
        return "Multi Mode Indicator";
    case LED_Indicator_On:
        return "Indicator On";
    case LED_Indicator_Flash:
        return "Indicator Flash";
    case LED_Indicator_Slow_Blink:
        return "Indicator Slow Blink";
    case LED_Indicator_Fast_Blink:
        return "Indicator Fast Blink";
    case LED_Indicator_Off:
        return "Indicator Off";
    case LED_Flash_On_Time:
        return "Flash On Time";
    case LED_Slow_Blink_On_Time:
        return "Slow Blink On Time";
    case LED_Slow_Blink_Off_Time:
        return "Slow Blink Off Time";
    case LED_Fast_Blink_On_Time:
        return "Fast Blink On Time";
    case LED_Fast_Blink_Off_Time:
        return "Fast Blink Off Time";
    case LED_Usage_Indicator_Color:
        return "Usage Indicator Color";
    case LED_Indicator_Red:
        return "Indicator Red";
    case LED_Indicator_Green:
        return "Indicator Green";
    case LED_Indicator_Amber:
        return "Indicator Amber";
    case LED_Generic_Indicator:
        return "Generic Indicator";
    case LED_Sys_Suspend:
        return "System Suspend";
    case LED_External_Power_Connected:
        return "External Power Connected";
    default:
        return "Unknown";
    }
}

int8_t *ri_Button(int32_t usage)
{
    static int8_t str[16];

    sprintf(str,"Button %d", usage);

    return str;
}

int8_t *ri_Ordinal(int32_t usage)
{
    static int8_t str[16];

    sprintf(str,"Instance %d", usage);

    return str;
}

int8_t *ri_Telephony(int32_t usage)
{
    switch(usage)
    {
	case TD_Phone:	
    	return "Phone";
	case TD_Answering_Machine:	
		return "Answering Machine";
	case TD_Message_Controls:	
		return "Message Controls";
	case TD_Handset:	
		return "Handset";
	case TD_Headset:	
		return "Headset";
	case TD_Telephony_Key_Pad:	
		return "Telephony Key Pad";
	case TD_Programmable_Button:	
		return "Programmable Button";
	case TD_Hook_Switch:	
		return "Hook Switch";
	case TD_Flash:	
		return "Flash";
	case TD_Feature:	
		return "Feature";
	case TD_Hold:	
		return "Hold";
	case TD_Redial:	
		return "Redial";
	case TD_Transfer:	
		return "Transfer";
	case TD_Drop:	
		return "Drop";
	case TD_Park:	
		return "Park";
	case TD_Forward_Calls:	
		return "Forward Calls";
	case TD_Alternate_Function:	
		return "Alternate Function";
	case TD_Line:	
		return "Line";
	case TD_Speaker_Phone:	
		return "Speaker Phone";
	case TD_Conference:	
		return "Conference";
	case TD_Ring_Enable:	
		return "Ring Enable";
	case TD_Ring_Select:	
		return "Ring Select";
	case TD_Phone_Mute:	
		return "Phone Mute";
	case TD_Caller_ID:	
		return "Caller ID";
	case TD_Send:	
		return "Send";
	case TD_Speed_Dial:	
		return "Speed Dial";
	case TD_Store_Number:	
		return "Store Number";
	case TD_Recall_Number:	
		return "Recall Number";
	case TD_Phone_Directory:	
		return "Phone Directory";
	case TD_Voice_Mail:	
		return "Voice Mail";
	case TD_Screen_Calls:	
		return "Screen Calls";
	case TD_Do_Not_Disturb:	
		return "Do Not Disturb";
	case TD_Message:	
		return "Message";
	case TD_Answer_On_Off:	
		return "Answer On/Off";
	case TD_Inside_Dial_Tone:	
		return "Inside Dial Tone";
	case TD_Outside_Dial_Tone:	
		return "Outside Dial Tone";
	case TD_Inside_Ring_Tone:	
		return "Inside Ring Tone";
	case TD_Outside_Ring_Tone:	
		return "Outside Ring Tone";
	case TD_Priority_Ring_Tone:	
		return "Priority Ring Tone";
	case TD_Inside_Ringback:	
		return "Inside Ringback";
	case TD_Priority_Ringback:	
		return "Priority Ringback";
	case TD_Line_Busy_Tone:	
		return "Line Busy Tone";
	case TD_Reorder_Tone:	
		return "Reorder Tone";
	case TD_Call_Waiting_Tone:	
		return "Call Waiting Tone";
	case TD_Confirmation_Tone_1:	
		return "Confirmation Tone 1";
	case TD_Confirmation_Tone_2:	
		return "Confirmation Tone 2";
	case TD_Tones_Off:	
		return "Tones Off";
	case TD_Outside_Ringback:	
		return "Outside Ringback";
	case TD_Ringer:
		return "Ringer";
    default:
        return "Unknown";
    }
}

int8_t *ri_Consumer(int32_t usage)
{
    switch(usage)
    {
    case UC_Consumer_Ctrl:
        return "Consumer Control";
    case UC_Numeric_Keypad:
        return "Numeric Key Pad";
    case UC_Prog_Btns:
        return "Programmable Buttons";
    case UC_Mic:
        return "Microphone";
    case UC_Headphone:
        return "Headphone";
    case UC_Graphic_Equalizer:
        return "Graphic Equalizer";
    case UC_Add_10:
        return "+10";
    case UC_Add_100:
        return "+100";
    case UC_AM_PM:
        return "AM/PM";
    case UC_Power:
        return "Power";
    case UC_Reset:
        return "Reset";
    case UC_Sleep:
        return "Sleep";
    case UC_Sleep_After:
        return "Sleep After";
    case UC_Sleep_Mode:
        return "Sleep Mode";
    case UC_ILL:
        return "Illumination";
    case UC_Function_Buttons:
        return "Function Buttons";
    case UC_Menu:
        return "Menu";
    case UC_Menu_Pick:
        return "Menu Pick";
    case UC_Menu_Up:
        return "Menu Up";
    case UC_Menu_Down:
        return "Menu Down";
    case UC_Menu_Left:
        return "Menu Left";
    case UC_Menu_Right:
        return "Menu Right";
    case UC_Menu_Escape:
        return "Menu Escape";
    case UC_Menu_Value_Incr:
        return "Menu Value Increase";
    case UC_Menu_Value_Decr:
        return "Menu Value Decrease";
    case UC_Data_On_Screen:
        return "Data On Screen";
    case UC_Closed_Caption:
        return "Closed Caption";
    case UC_Closed_Caption_Sel:
        return "Closed Caption Select";
    case UC_VCR_TV:
        return "VCR/TV";
    case UC_Broadcast_Mode:
        return "Broadcast Mode";
    case UC_Snapshot:
        return "Snapshot";
    case UC_Still:
        return "Still";
    case UC_Selion:
        return "Selection";
    case UC_Assign_Selion:
        return "Assign Selection";
    case UC_Mode_Step:
        return "Mode Step";
    case UC_Recall_Last:
        return "Recall Last";
    case UC_Enter_Channel:
        return "Enter Channel";
    case UC_Order_Movie:
        return "Order Movie";
    case UC_Channel:
        return "Channel";
    case UC_Media_Selion:
        return "Media Selection";
    case UC_Media_Sel_Computer:
        return "Media Select Computer";
    case UC_Media_Sel_TV:
        return "Media Select TV";
    case UC_Media_Sel_WWW:
        return "Media Select WWW";
    case UC_Media_Sel_DVD:
        return "Media Select DVD";
    case UC_Media_Sel_Telephone:
        return "Media Select Telephone";
    case UC_Media_Sel_Program_Guide:
        return "Media Select Program Guide";
    case UC_Media_Sel_Video_Phone:
        return "Media Select Video Phone";
    case UC_Media_Sel_Games:
        return "Media Select Games";
    case UC_Media_Sel_Messages:
        return "Media Select Messages";
    case UC_Media_Sel_CD:
        return "Media Select CD";
    case UC_Media_Sel_VCR:
        return "Media Select VCR";
    case UC_Media_Sel_Tuner:
        return "Media Select Tuner";
    case UC_Quit:
        return "Quit";
    case UC_Help:
        return "Help";
    case UC_Media_Sel_Tape:
        return "Media Select Tape";
    case UC_Media_Sel_Cable:
        return "Media Select Cable";
    case UC_Media_Sel_Satellite:
        return "Media Select Satellite";
    case UC_Media_Sel_Security:
        return "Media Select Security";
    case UC_Media_Sel_Home:
        return "Media Select Home";
    case UC_Media_Sel_Call:
        return "Media Select Call";
    case UC_Channel_Incr:
        return "Channel Increment";
    case UC_Channel_Decr:
        return "Channel Decrement";
    case UC_Media_Sel_SAP:
        return "Media Select SAP";
    case UC_VCR_Plus:
        return "VCR Plus";
    case UC_Once:
        return "Once";
    case UC_Daily:
        return "Daily";
    case UC_Weekly:
        return "Weekly";
    case UC_Monthly:
        return "Monthly";
    case UC_Play:
        return "Play";
    case UC_Pause:
        return "Pause";
    case UC_Record:
        return "Record";
    case UC_Fast_Forward:
        return "Fast Forward";
    case UC_Rewind:
        return "Rewind";
    case UC_Scan_Next_Track:
        return "Scan Next Track";
    case UC_Scan_Previous_Track:
        return "Scan Previous Track";
    case UC_Stop:
        return "Stop";
    case UC_Eject:
        return "Eject";
    case UC_Random_Play:
        return "Random Play";
    case UC_Sel_Disc:
        return "Select Disc";
    case UC_Enter_Disc:
        return "Enter Disc";
    case UC_Repeat:
        return "Repeat";
    case UC_Tracking:
        return "Tracking";
    case UC_Track_Normal:
        return "Track Normal";
    case UC_Slow_Tracking:
        return "Slow Tracking";
    case UC_Frame_Forward:
        return "Frame Forward";
    case UC_Frame_Back:
        return "Frame Back";
    case UC_Mark:
        return "Mark";
    case UC_Clear_Mark:
        return "Clear Mark";
    case UC_Repeat_From_Mark:
        return "Repeat From Mark";
    case UC_Return_To_Mark:
        return "Return To Mark";
    case UC_Search_Mark_Forward:
        return "Search Mark Forward";
    case UC_Search_Mark_Backward:
        return "Search Mark Backwards";
    case UC_Counter_Reset:
        return "Counter Reset";
    case UC_Show_Counter:
        return "Show Counter";
    case UC_Tracking_Incr:
        return "Tracking Increment";
    case UC_Tracking_Decr:
        return "Tracking Decrement";
    case UC_Stop_Eject:
        return "Stop/Eject";
    case UC_Play_Pause:
        return "Play/Pause";
    case UC_Play_Skip:
        return "Play/Skip";
    case UC_Volume:
        return "Volume";
    case UC_Balance:
        return "Balance";
    case UC_Mute:
        return "Mute";
    case UC_Bass:
        return "Bass";
    case UC_Treble:
        return "Treble";
    case UC_Bass_Boost:
        return "Bass Boost";
    case UC_Surround_Mode:
        return "Surround Mode";
    case UC_Loudness:
        return "Loudness";
    case UC_MPX:
        return "MPX";
    case UC_Volume_Incr:
        return "Volume Increment";
    case UC_Volume_Decr:
        return "Volume Decrement";
    case UC_Speed_Sel:
        return "Speed Select";
    case UC_Playback_Speed:
        return "Playback Speed";
    case UC_Standard_Play:
        return "Standard Play";
    case UC_Long_Play:
        return "Long Play";
    case UC_Extended_Play:
        return "Extended Play";
    case UC_Slow:
        return "Slow";
    case UC_Fan_Enable:
        return "Fan Enable";
    case UC_Fan_Speed:
        return "Fan Speed";
    case UC_Light_Enable:
        return "Light Enable";
    case UC_Light_ILL_Level:
        return "Light Illumination Level";
    case UC_Climate_Ctrl_Enable:
        return "Climate Control Enable";
    case UC_Room_Temperature:
        return "Room Temperature";
    case UC_Security_Enable:
        return "Security Enable";
    case UC_Fire_Alarm:
        return "Fire Alarm";
    case UC_Police_Alarm:
        return "Police Alarm";
    case UC_Proximity:
        return "Proximity";
    case UC_Motion:
        return "Motion";
    case UC_Duress_Alarm:
        return "Duress Alarm";
    case UC_Holdup_Alarm:
        return "Holdup Alarm";
    case UC_Medical_Alarm:
        return "Medical Alarm";
    case UC_Balance_Right:
        return "Balance Right";
    case UC_Balance_Left:
        return "Balance Left";
    case UC_Bass_Incr:
        return "Bass Increment";
    case UC_Bass_Decr:
        return "Bass Decrement";
    case UC_Treble_Incr:
        return "Treble Increment";
    case UC_Treble_Decr:
        return "Treble Decrement";
    case UC_Speaker_Sys:
        return "Speaker System";
    case UC_Channel_Left:
        return "Channel Left";
    case UC_Channel_Right:
        return "Channel Right";
    case UC_Channel_Center:
        return "Channel Center";
    case UC_Channel_Front:
        return "Channel Front";
    case UC_Channel_Center_Front:
        return "Channel Center Front";
    case UC_Channel_Side:
        return "Channel Side";
    case UC_Channel_Surround:
        return "Channel Surround";
    case UC_Channel_Low_Frequency_Enhancement:
        return "Channel Low Frequency Enhancement";
    case UC_Channel_Top:
        return "Channel Top";
    case UC_Channel_Unknown:
        return "Channel Unknown";
    case UC_Subchannel:
        return "Sub-channel";
    case UC_Subchannel_Incr:
        return "Sub-channel Increment";
    case UC_Subchannel_Decr:
        return "Sub-channel Decrement";
    case UC_Alternate_Audio_Incr:
        return "Alternate Audio Increment";
    case UC_Alternate_Audio_Decr:
        return "Alternate Audio Decrement";
    case UC_App_Launch_Btns:
        return "Application Launch Buttons";
    case UC_AL_Launch_Btn_Config_Tool:
        return "AL Launch Button Configuration Tool";
    case UC_AL_Prog_Btn_Config:
        return "AL Programmable Button Configuration";
    case UC_AL_Consumer_Ctrl_Config:
        return "AL Consumer Control Configuration";
    case UC_AL_Word_Processor:
        return "AL Word Processor";
    case UC_AL_Text_Editor:
        return "AL Text Editor";
    case UC_AL_Spreadsheet:
        return "AL Spreadsheet";
    case UC_AL_Graphics_Editor:
        return "AL Graphics Editor";
    case UC_AL_Presentation_App:
        return "AL Presentation App";
    case UC_AL_Database_App:
        return "AL Database App";
    case UC_AL_Email_Reader:
        return "AL Email Reader";
    case UC_AL_Newsreader:
        return "AL Newsreader";
    case UC_AL_Voicemail:
        return "AL Voicemail";
    case UC_AL_Contacts_Address_Book:
        return "AL Contacts/Address Book";
    case UC_AL_Calendar_Schedule:
        return "AL Calendar/Schedule";
    case UC_AL_Task_Project_Manager:
        return "AL Task/Project Manager";
    case UC_AL_Log_Journal_Timecard:
        return "AL Log/Journal/Timecard";
    case UC_AL_Checkbook_Finance:
        return "AL Checkbook/Finance";
    case UC_AL_Calculator:
        return "AL Calculator";
    case UC_AL_AV_Capture_Playback:
        return "AL A/V Capture/Playback";
    case UC_AL_Local_Machine_Browser:
        return "AL Local Machine Browser";
    case UC_AL_LAN_WAN_Browser:
        return "AL LAN/WAN Browser";
    case UC_AL_Internet_Browser:
        return "AL Internet Browser";
    case UC_AL_RemoteNet_ISP_Connect:
        return "AL Remote Networking/ISP Connect";
    case UC_AL_Net_Conference:
        return "AL Network Conference";
    case UC_AL_Net_Chat:
        return "AL Network Chat";
    case UC_AL_Telephony_Dialer:
        return "AL Telephony/Dialer";
    case UC_AL_Logon:
        return "AL Logon";
    case UC_AL_Logoff:
        return "AL Logoff";
    case UC_AL_Logon_Logoff:
        return "AL Logon/Logoff";
    case UC_AL_Terminal_Lock_Screensaver:
        return "AL Terminal Lock/Screensaver";
    case UC_AL_Ctrl_Panel:
        return "AL Control Panel";
    case UC_AL_Command_Line_Processor_Run:
        return "AL Command Line Processor/Run";
    case UC_AL_Process_Task_Manager:
        return "AL Process/Task Manager";
    case UC_AL_Sel_Task_App:
        return "AL Select Task/Application";
    case UC_AL_Next_Task_App:
        return "AL Next Task/Application";
    case UC_AL_Previous_Task_App:
        return "AL Previous Task/Application";
    case UC_AL_Preemptive_Halt_Task_App:
        return "AL Preemptive Halt Task/Application";
    case UC_AL_Integrated_Help_Center:
        return "AL Integrated Help Center";
    case UC_AL_Documents:
        return "AL Documents";
    case UC_AL_Thesaurus:
        return "AL Thesaurus";
    case UC_AL_Dictionary:
        return "AL Dictionary";
    case UC_AL_Desktop:
        return "AL Desktop";
    case UC_AL_Spell_Check:
        return "AL Spell Check";
    case UC_AL_Grammar_Check:
        return "AL Grammar Check";
    case UC_AL_Wireless_Status:
        return "AL Wireless Status";
    case UC_AL_Keyboard_Layout:
        return "AL Keyboard Layout";
    case UC_AL_Virus_Protection:
        return "AL Virus Protection";
    case UC_AL_Encryption:
        return "AL Encryption";
    case UC_AL_Screen_Saver:
        return "AL Screen Saver";
    case UC_AL_Alarms:
        return "AL Alarms";
    case UC_AL_Clock:
        return "AL Clock";
    case UC_AL_File_Browser:
        return "AL File Browser";
    case UC_AL_Power_Status:
        return "AL Power Status";
    case UC_AL_Image_Browser:
        return "AL Image Browser";
    case UC_AL_Audio_Browser:
        return "AL Audio Browser";
    case UC_AL_Movie_Browser:
        return "AL Movie Browser";
    case UC_AL_Digital_Rights_Manager:
        return "AL Digital Rights Manager";
    case UC_AL_Digital_Wallet:
        return "AL Digital Wallet";
    case UC_AL_Instant_Messaging:
        return "AL Instant Messaging";
    case UC_AL_OEM_Features_Tips_Tutorial_Browser:
        return "AL OEM Features/Tips/Tutorial Browser";
    case UC_AL_OEM_Help:
        return "AL OEM Help";
    case UC_AL_Online_Community:
        return "AL Online Community";
    case UC_AL_Entertainment_Content_Browser:
        return "AL Entertainment Content Browser";
    case UC_AL_Online_Shopping_Browser:
        return "AL Online Shopping Browser";
    case UC_AL_SmartCard_Information_Help:
        return "AL SmartCard Information/Help";
    case UC_AL_Market_Monitoror_Finance_Browser:
        return "AL Market Monitor/Finance Browser";
    case UC_AL_Customized_Corporate_News_Browser:
        return "AL Customized Corporate News Browser";
    case UC_AL_Online_Activity_Browser:
        return "AL Online Activity Browser";
    case UC_AL_Research_Search_Browser:
        return "AL Research/Search Browser";
    case UC_AL_Audio_Player:
        return "AL Audio Player";
    case UC_Generic_GUI_App_Ctrls:
        return "Generic GUI Application Controls";
    case UC_AC_New:
        return "AC New";
    case UC_AC_Open:
        return "AC Open";
    case UC_AC_Close:
        return "AC Close";
    case UC_AC_Exit:
        return "AC Exit";
    case UC_AC_Maximize:
        return "AC Maximize";
    case UC_AC_Minimize:
        return "AC Minimize";
    case UC_AC_Save:
        return "AC Save";
    case UC_AC_Print:
        return "AC Print";
    case UC_AC_Properties:
        return "AC Properties";
    case UC_AC_Undo:
        return "AC Undo";
    case UC_AC_Copy:
        return "AC Copy";
    case UC_AC_Cut:
        return "AC Cut";
    case UC_AC_Paste:
        return "AC Paste";
    case UC_AC_Sel_All:
        return "AC Select All";
    case UC_AC_Find:
        return "AC Find";
    case UC_AC_Find_and_Replace:
        return "AC Find and Replace";
    case UC_AC_Search:
        return "AC Search";
    case UC_AC_Go_To:
        return "AC Go To";
    case UC_AC_Home:
        return "AC Home";
    case UC_AC_Back:
        return "AC Back";
    case UC_AC_Forward:
        return "AC Forward";
    case UC_AC_Stop:
        return "AC Stop";
    case UC_AC_Refresh:
        return "AC Refresh";
    case UC_AC_Previous_Link:
        return "AC Previous Link";
    case UC_AC_Next_Link:
        return "AC Next Link";
    case UC_AC_Bookmarks:
        return "AC Bookmarks";
    case UC_AC_History:
        return "AC History";
    case UC_AC_Subscriptions:
        return "AC Subscriptions";
    case UC_AC_Zoom_In:
        return "AC Zoom In";
    case UC_AC_Zoom_Out:
        return "AC Zoom Out";
    case UC_AC_Zoom:
        return "AC Zoom";
    case UC_AC_Full_Screen_View:
        return "AC Full Screen View";
    case UC_AC_Normal_View:
        return "AC Normal View";
    case UC_AC_View_Toggle:
        return "AC View Toggle";
    case UC_AC_Scroll_Up:
        return "AC Scroll Up";
    case UC_AC_Scroll_Down:
        return "AC Scroll Down";
    case UC_AC_Scroll:
        return "AC Scroll";
    case UC_AC_Pan_Left:
        return "AC Pan Left";
    case UC_AC_Pan_Right:
        return "AC Pan Right";
    case UC_AC_Pan:
        return "AC Pan";
    case UC_AC_New_Window:
        return "AC New Window";
    case UC_AC_Tile_Horizontally:
        return "AC Tile Horizontally";
    case UC_AC_Tile_Vertically:
        return "AC Tile Vertically";
    case UC_AC_Format:
        return "AC Format";
    case UC_AC_Edit:
        return "AC Edit";
    case UC_AC_Bold:
        return "AC Bold";
    case UC_AC_Italics:
        return "AC Italics";
    case UC_AC_Underline:
        return "AC Underline";
    case UC_AC_Strikethrough:
        return "AC Strikethrough";
    case UC_AC_Subscript:
        return "AC Subscript";
    case UC_AC_Superscript:
        return "AC Superscript";
    case UC_AC_All_Caps:
        return "AC All Caps";
    case UC_AC_Rotate:
        return "AC Rotate";
    case UC_AC_Resize:
        return "AC Resize";
    case UC_AC_Flip_Horiz:
        return "AC Flip horizontal";
    case UC_AC_Flip_Verti:
        return "AC Flip Vertical";
    case UC_AC_Mirror_Horizontal:
        return "AC Mirror Horizontal";
    case UC_AC_Mirror_Vertical:
        return "AC Mirror Vertical";
    case UC_AC_Font_Sel:
        return "AC Font Select";
    case UC_AC_Font_Color:
        return "AC Font Color";
    case UC_AC_Font_Size:
        return "AC Font Size";
    case UC_AC_Justify_Left:
        return "AC Justify Left";
    case UC_AC_Justify_Center_H:
        return "AC Justify Center H";
    case UC_AC_Justify_Right:
        return "AC Justify Right";
    case UC_AC_Justify_Block_H:
        return "AC Justify Block H";
    case UC_AC_Justify_Top:
        return "AC Justify Top";
    case UC_AC_Justify_Center_V:
        return "AC Justify Center V";
    case UC_AC_Justify_Bottom:
        return "AC Justify Bottom";
    case UC_AC_Justify_Block_V:
        return "AC Justify Block V";
    case UC_AC_Indent_Decr:
        return "AC Indent Decrease";
    case UC_AC_Indent_Incr:
        return "AC Indent Increase";
    case UC_AC_Numbered_List:
        return "AC Numbered List";
    case UC_AC_Restart_Numbering:
        return "AC Restart Numbering";
    case UC_AC_Bulleted_List:
        return "AC Bulleted List";
    case UC_AC_Promote:
        return "AC Promote";
    case UC_AC_Demote:
        return "AC Demote";
    case UC_AC_Yes:
        return "AC Yes";
    case UC_AC_No:
        return "AC No";
    case UC_AC_Cancel:
        return "AC Cancel";
    case UC_AC_Catalog:
        return "AC Catalog";
    case UC_AC_BuyorCheckout:
        return "AC Buy/Checkout";
    case UC_AC_Add_to_Cart:
        return "AC Add to Cart";
    case UC_AC_Expand:
        return "AC Expand";
    case UC_AC_Expand_All:
        return "AC Expand All";
    case UC_AC_Collapse:
        return "AC Collapse";
    case UC_AC_Collapse_All:
        return "AC Collapse All";
    case UC_AC_Print_Preview:
        return "AC Print Preview";
    case UC_AC_Paste_Special:
        return "AC Paste Special";
    case UC_AC_Insert_Mode:
        return "AC Insert Mode";
    case UC_AC_Delete:
        return "AC Delete";
    case UC_AC_Lock:
        return "AC Lock";
    case UC_AC_Unlock:
        return "AC Unlock";
    case UC_AC_Protect:
        return "AC Protect";
    case UC_AC_Unprotect:
        return "AC Unprotect";
    case UC_AC_Attach_Comment:
        return "AC Attach Comment";
    case UC_AC_Delete_Comment:
        return "AC Delete Comment";
    case UC_AC_View_Comment:
        return "AC View Comment";
    case UC_AC_Sel_Word:
        return "AC Select Word";
    case UC_AC_Sel_Sentence:
        return "AC Select Sentence";
    case UC_AC_Sel_Paragraph:
        return "AC Select Paragraph";
    case UC_AC_Sel_Column:
        return "AC Select Column";
    case UC_AC_Sel_Row:
        return "AC Select Row";
    case UC_AC_Sel_Table:
        return "AC Select Table";
    case UC_AC_Sel_Object:
        return "AC Select Object";
    case UC_AC_Redo_Repeat:
        return "AC Redo/Repeat";
    case UC_AC_Sort:
        return "AC Sort";
    case UC_AC_Sort_Ascending:
        return "AC Sort Ascending";
    case UC_AC_Sort_Descending:
        return "AC Sort Descending";
    case UC_AC_Filter:
        return "AC Filter";
    case UC_AC_Set_Clock:
        return "AC Set Clock";
    case UC_AC_View_Clock:
        return "AC View Clock";
    case UC_AC_Sel_Time_Zone:
        return "AC Select Time Zone";
    case UC_AC_Edit_Time_Zones:
        return "AC Edit Time Zones";
    case UC_AC_Set_Alarm:
        return "AC Set Alarm";
    case UC_AC_Clear_Alarm:
        return "AC Clear Alarm";
    case UC_AC_Snooze_Alarm:
        return "AC Snooze Alarm";
    case UC_AC_Reset_Alarm:
        return "AC Reset Alarm";
    case UC_AC_Synchronize:
        return "AC Synchronize";
    case UC_AC_Send_or_Recv:
        return "AC Send/Receive";
    case UC_AC_Send_To:
        return "AC Send To";
    case UC_AC_Reply:
        return "AC Reply";
    case UC_AC_Reply_All:
        return "AC Reply All";
    case UC_AC_Forward_Msg:
        return "AC Forward Msg";
    case UC_AC_Send:
        return "AC Send";
    case UC_AC_Attach_File:
        return "AC Attach File";
    case UC_AC_Upload:
        return "AC Upload";
    case UC_AC_Download_Save_As:
        return "AC Download (Save Target As)";
    case UC_AC_Set_Borders:
        return "AC Set Borders";
    case UC_AC_Insert_Row:
        return "AC Insert Row";
    case UC_AC_Insert_Column:
        return "AC Insert Column";
    case UC_AC_Insert_File:
        return "AC Insert File";
    case UC_AC_Insert_Picture:
        return "AC Insert Picture";
    case UC_AC_Insert_Object:
        return "AC Insert Object";
    case UC_AC_Insert_Symbol:
        return "AC Insert Symbol";
    case UC_AC_Save_and_Close:
        return "AC Save and Close";
    case UC_AC_Rename:
        return "AC Rename";
    case UC_AC_Merge:
        return "AC Merge";
    case UC_AC_Split:
        return "AC Split";
    case UC_AC_Distribute_Horiz:
        return "AC Distribute Horizontally";
    case UC_AC_Distribute_Verti:
        return "AC Distribute Vertically";
    default:
        return "Unknown";
    }
}

int8_t *ri_Digitizer(int32_t usage)
{
    switch(usage)
    {
    case D_Digitizer:
        return "Digitizer";
    case D_Pen:
        return "Pen";
    case D_Light_Pen:
        return "Light Pen";
    case D_Touch_Screen:
        return "Touch Screen";
    case D_Touch_Pad:
        return "Touch Pad";
    case D_White_Board:
        return "White Board";
    case D_Coordinate_Measuring_Machine:
        return "Coordinate Measuring Machine";
    case D_4D_Digitizer:
        return "3D Digitizer";
    case D_Stereo_Plotter:
        return "Stereo Plotter";
    case D_Articulated_Arm:
        return "Articulated Arm";
    case D_Armature:
        return "Armature";
    case D_Multiple_Point_Digitizer:
        return "Multiple Point Digitizer ";
    case D_Free_Space_Wand:
        return "Free Space Wand";
    case D_Stylus:
        return "Stylus";
    case D_Puck:
        return "Puck";
    case D_Finger:
        return "Finger";
    case D_Tip_Pressure:
        return "Tip Pressure";
    case D_Barrel_Pressure:
        return "Barrel Pressure";
    case D_In_Range:
        return "In Range";
    case D_Touch:
        return "Touch";
    case D_Untouch:
        return "Untouch";
    case D_Tap:
        return "Tap";
    case D_Quality:
        return "Quality";
    case D_Data_Valid:
        return "Data Valid";
    case D_Transducer_Index:
        return "Transducer Index";
    case D_Tablet_Function_Keys:
        return "Tablet Function Keys";
    case D_Program_Change_Keys:
        return "Program Change Keys";
    case D_Battery_Strength:
        return "Battery Strength";
    case D_Invert:
        return "Invert";
    case D_X_Tilt:
        return "X Tilt";
    case D_Y_Tilt:
        return "Y Tilt";
    case D_Azimuth:
        return "Azimuth";
    case D_Altitude:
        return "Altitude ";
    case D_Twist:
        return "Twist ";
    case D_Tip_Switch:
        return "Tip Switch";
    case D_Secondary_Tip_Switch:
        return "Secondary Tip Switch ";
    case D_Barrel_Switch:
        return "Barrel Switch ";
    case D_Eraser:
        return "Eraser";
    case D_Tablet_Pick:
        return "Tablet Pick";
    default:
        return "Unknown";
    }
}

int8_t *ri_PIDPage(int32_t usage)
{
    switch(usage)
    {
    /* HID 1.11 Chapter 3 Table 1 says that
    ** USB Physical Interface Device definitions
    ** for force feedback and related decvices.
    ** This document didn't describe details.
    */
    default:
        return "Unknown";
    }
}

int8_t *ri_Unicode(int32_t usage)
{
    switch(usage)
    {
        /* see HID 1.11 Chapter 17
        */
    default:
        return "Unknown";
    }
}

int8_t *ri_AlphanumericDisplay(int32_t usage)
{
    switch(usage)
    {
    case AD_Alphanumeric_Display:
        return "Alphanumeric Display";
    case AD_Bitmapped_Display:
        return "Bitmapped Display";
    case AD_Display_Attributes_Report:
        return "Display Attributes Report";
    case AD_ASCII_Character_Set:
        return "ASCII Character Set";
    case AD_Data_Read_Back:
        return "Data Read Back";
    case AD_Font_Read_Back:
        return "Font Read Back";
    case AD_Display_Control_Report:
        return "Display Control Report";
    case AD_Clear_Display:
        return "Clear Display";
    case AD_Display_Enable:
        return "Display Enable";
    case AD_Screen_Saver_Delay:
        return "Screen Saver Delay";
    case AD_Screen_Saver_Enable:
        return "Screen Saver Enable";
    case AD_Vertical_Scroll:
        return "Vertical Scroll";
    case AD_Horizontal_Scroll:
        return "Horizontal Scroll";
    case AD_Character_Report:
        return "Character Report";
    case AD_Display_Data:
        return "Display Data";
    case AD_Display_Status:
        return "Display Status";
    case AD_Stat_Not_Ready:
        return "Stat Not Ready";
    case AD_Stat_Ready:
        return "Stat Ready";
    case AD_Err_Not_a_loadable_character:
        return "Err Not a loadable character";
    case AD_Err_Font_data_cannot_be_read:
        return "Err Font data cannot be read";
    case AD_Cursor_Position_Report:
        return "Cursor Position Report";
    case AD_Row:
        return "Row";
    case AD_Column:
        return "Column";
    case AD_Rows:
        return "Rows";
    case AD_Columns:
        return "Columns";
    case AD_Cursor_Pixel_Positioning:
        return "Cursor Pixel Positioning";
    case AD_Cursor_Mode:
        return "Cursor Mode";
    case AD_Cursor_Enable:
        return "Cursor Enable";
    case AD_Cursor_Blink:
        return "Cursor Blink";
    case AD_Font_Report:
        return "Font Report";
    case AD_Font_Data:
        return "Font Data";
    case AD_Character_Width:
        return "Character Width";
    case AD_Character_Height:
        return "Character Height";
    case AD_Character_Spacing_Horizontal:
        return "Character Spacing Horizontal";
    case AD_Character_Spacing_Vertical:
        return "Character Spacing Vertical";
    case AD_Unicode_Character_Set:
        return "Unicode Character Set";
    case AD_Font_7_Segment:
        return "Font 7-Segment";
    case AD_7_Segment_Direct_Map:
        return "7-Segment Direct Map";
    case AD_Font_14_Segment:
        return "Font 14-Segment";
    case AD_14_Segment_Direct_Map:
        return "14-Segment Direct Map";
    case AD_Display_Brightness:
        return "Display Brightness";
    case AD_Display_Contrast:
        return "Display Contrast";
    case AD_Character_Attribute:
        return "Character Attribute";
    case AD_Attribute_Readback:
        return "Attribute Readback";
    case AD_Attribute_Data:
        return "Attribute Data";
    case AD_Char_Attr_Enhance:
        return "Char Attr Enhance";
    case AD_Char_Attr_Underline:
        return "Char Attr Underline";
    case AD_Char_Attr_Blink:
        return "Char Attr Blink";
    case AD_Bitmap_Size_X:
        return "Bitmap Size X";
    case AD_Bitmap_Size_Y:
        return "Bitmap Size Y";
    case AD_Bit_Depth_Format:
        return "Bit Depth Format";
    case AD_Display_Orientation:
        return "Display Orientation";
    case AD_Palette_Report:
        return "Palette Report";
    case AD_Palette_Data_Size:
        return "Palette Data Size";
    case AD_Palette_Data_Offset:
        return "Palette Data Offset";
    case AD_Palette_Data:
        return "Palette Data";
    case AD_Blit_Report:
        return "Blit Report";
    case AD_Blit_Rectangle_X1:
        return "Blit Rectangle X1";
    case AD_Blit_Rectangle_Y1:
        return "Blit Rectangle Y1";
    case AD_Blit_Rectangle_X2:
        return "Blit Rectangle X2";
    case AD_Blit_Rectangle_Y2:
        return "Blit Rectangle Y2";
    case AD_Blit_Data:
        return "Blit Data";
    case AD_Soft_Button:
        return "Soft Button";
    case AD_Soft_Button_ID:
        return "Soft Button ID";
    case AD_Soft_Button_Side:
        return "Soft Button Side";
    case AD_Soft_Button_Offset_1:
        return "Soft Button Offset 1";
    case AD_Soft_Button_Offset_2:
        return "Soft Button Offset 2";
    case AD_Soft_Button_Report:
        return "Soft Button Report";
    default:
        return "Unknown";
    }
}

int8_t *ri_MedicalInstruments(int32_t usage)
{
    switch(usage)
    {
    case MI_Medical_Ultrasound:
        return "Medical Ultrasound";
    case MI_VCR_Acquisition:
        return "VCR/Acquisition";
    case MI_Freeze_Thaw:
        return "Freeze/Thaw";
    case MI_Clip_Store:
        return "Clip Store";
    case MI_Update:
        return "Update";
    case MI_Next:
        return "Next";
    case MI_Save:
        return "Save";
    case MI_Print:
        return "Print";
    case MI_Microphone_Enable:
        return "Microphone Enable";
    case MI_Cine:
        return "Cine";
    case MI_Transmit_Power:
        return "Transmit Power";
    case MI_Volume:
        return "Volume";
    case MI_Focus:
        return "Focus";
    case MI_Depth:
        return "Depth";
    case MI_Soft_Step_Primary:
        return "Soft Step - Primary";
    case MI_Soft_Step_Secondary:
        return "Soft Step - Secondary";
    case MI_Depth_Gain_Compensation:
        return "Depth Gain Compensation";
    case MI_Zoom_Select:
        return "Zoom Select";
    case MI_Zoom_Adjust:
        return "Zoom Adjust";
    case MI_Spectral_Doppler_Mode_Select:
        return "Spectral Doppler Mode Select";
    case MI_Spectral_Doppler_Adjust:
        return "Spectral Doppler Adjust";
    case MI_Color_Doppler_Mode_Select:
        return "Color Doppler Mode Select";
    case MI_Color_Doppler_Adjust:
        return "Color Doppler Adjust";
    case MI_Motion_Mode_Select:
        return "Motion Mode Select";
    case MI_Motion_Mode_Adjust:
        return "Motion Mode Adjust";
    case MI_2D_Mode_Select:
        return "2-D Mode Select";
    case MI_2D_Mode_Adjust:
        return "2-D Mode Adjust";
    case MI_Soft_Control_Select:
        return "Soft Control Select";
    case MI_Soft_Control_Adjust:
        return "Soft Control Adjust";
    default:
        return "Unknown";
    }
}

int8_t *ri_Monitor(int32_t usage)
{
    switch(usage)
    {
    /* HID 1.11 Chapter 3 Table 1 says that
    ** USB Device Class Definitrion for Monitor Device
    ** This document didn't describe details.
    */
    default:
        return "Unknown";
    }
}

int8_t *ri_Power(int32_t usage)
{
    switch(usage)
    {
    /* HID 1.11 Chapter 3 Table 1 says that
    ** USB Device Class Definitrion for Power Device
    ** This document didn't describe details.
    */
    default:
        return "Unknown";
    }
}

int8_t *ri_BarCodeScanner(int32_t usage)
{
    switch(usage)
    {
    /* HID 1.11 Chapter 3 Table 1 says that
    ** USB Device Class Definitrion for Point of Sale Device
    ** This document didn't describe details.
    */
    default:
        return "Unknown";
    }
}

int8_t *ri_Scale(int32_t usage)
{
    switch(usage)
    {
    /* HID 1.11 Chapter 3 Table 1 says that
    ** USB Device Class Definitrion for Point of Sale Device
    ** This document didn't describe details.
    */
    default:
        return "Unknown";
    }
}

int8_t *ri_MSRDevices(int32_t usage)
{
    /* Megnetic Stripe Reading Device */
    switch(usage)
    {
    /* HID 1.11 Chapter 3 Table 1 says that
    ** USB Device Class Definitrion for Point of Sale Device
    ** This document didn't describe details.
    */
    default:
        return "Unknown";
    }
}

int8_t *ri_CameraControl(int32_t usage)
{
    switch(usage)
    {
    /* HID 1.11 Chapter 3 Table 1 says that
    ** USB Device Class Definitrion for Image Class Device
    ** This document didn't describe details.
    */
    default:
        return "Unknown";
    }
}

int8_t *ri_Arcade(int32_t usage)
{
    switch(usage)
    {
    /* HID 1.11 Chapter 3 Table 1 says that
    ** OAAF Definitrion for arcade and coinop related Devices
    ** This document didn't describe details.
    */
    default:
        return "Unknown";
    }
}

int8_t *ri_Usage(int32_t usagePage, int32_t usage)
{
    switch(usagePage)
    {
    case UP_Generic_Desktop:
        return ri_GenericDesktop(usage);
    case UP_Simulation_Controls:
        return ri_SimulationControls(usage);
    case UP_VR_Controls:
        return ri_VRControls(usage);
    case UP_Sport_Controls:
        return ri_SportControls(usage);
    case UP_Game_Controls:
        return ri_GameControls(usage);
    case UP_Generic_Device_Controls:
        return ri_GenericDeviceControls(usage);
    case UP_Keyboard_or_Keypad:
        return ri_KeyboardOrKeypad(usage);
    case UP_LEDs:
        return ri_LEDs(usage);
    case UP_Button:
        return ri_Button(usage);
    case UP_Ordinal:
        return ri_Ordinal(usage);
    case UP_Telephony:
        return ri_Telephony(usage);
    case UP_Consumer:
        return ri_Consumer(usage);
    case UP_Digitizer:
        return ri_Digitizer(usage);
    case UP_PID_Page:
        return ri_PIDPage(usage);
    case UP_Unicode:
        return ri_Unicode(usage);
    case UP_Alphanumeric_Display:
        return ri_AlphanumericDisplay(usage);
    case UP_Medical_Instruments:
        return ri_MedicalInstruments(usage);
    // case UP_Monitor_pages_1:
    // case UP_Monitor_pages_2:
    // case UP_Monitor_pages_3:
    // case UP_Monitor_pages_4:
    //     return ri_Monitor(usage);
    // case UP_Power_pages_1:
    // case UP_Power_pages_2:
    // case UP_Power_pages_3:
    // case UP_Power_pages_4:
    //     return ri_Power(usage);
    // case UP_Bar_Code_Scanner_page:
    //     return ri_BarCodeScanner(usage);
    // case UP_Scale_page:
    //     return ri_Scale(usage);
    // case UP_MSR_Devices:
    //     return ri_MSRDevices(usage);
    // case UP_Camera_Control_Page:
    //     return ri_CameraControl(usage);
    // case UP_Arcade_Page:
    //     return ri_Arcade(usage);
    default:
        return "Unknown";
    }
}
