#ifndef _REPORT_ITEM_H
#define _REPORT_ITEM_H

/* 注意：只对短条目进行解析（Short Item）
*/

/* 条目对照表：https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
** Report结构：https://www.usb.org/sites/default/files/documents/hid1_11.pdf
** Short Items Header(1Byte): [7  ~  4] [3   2] [1   0] bit
**                            [ bTag  ] [bType] [bSize]
**        bTag: 参考hid1_11.pdf 6.2.2.1 (28页)
**        bType: 00 - main item   Ref: 6.2.2.4 
**               01 - global item Ref: 6.2.2.7
**               10 - local item  Ref: 6.2.2.8
**               11 - Reversed
**        bSize: 00 - 0 Byte
**               01 - 1 Byte
**               10 - 2 Byte
**               11 - 4 Byte 
*/

#define TAG_OFFSET                     (4U)
#define TYPE_OFFSET                    (2U)
#define SIZE_OFFSET                    (0U)

#define TYPE_MASK                      (0x03U<<TYPE_OFFSET)
#define TAG_MASK                       ((0x0FU<<TAG_OFFSET)|TYPE_MASK)
/* size(2bit): 00 - 0B, 01 - 1B, 10 - 2B, 11 - 4B *      /
#define SIZE_MASK                      (0x03U<<SIZE_OFFSET)

/* Short Item Size
*/
#define Size_0B                          (0U)
#define Size_1B                          (1U)
#define Size_2B                          (2U)
#define Size_4B                          (3U)

/* Short Item Type
*/
#define MAIN_ITEM                           (0x00U<<TYPE_OFFSET)
#define GLOBAL_ITEM                         (0x01U<<TYPE_OFFSET)
#define LOCAL_ITEM                          (0x02U<<TYPE_OFFSET)

/* Main Item Tag
*/
#define Input(size)                      (MAIN_ITEM|(0x08U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Output(size)                     (MAIN_ITEM|(0x09U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Feature(size)                    (MAIN_ITEM|(0x0BU<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Collection(size)                 (MAIN_ITEM|(0x0AU<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define End_Colletion(size)              (MAIN_ITEM|(0x0CU<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))

/* Input, Output and Feature Items(1B) Data bit
*/
#define Data                             (0U)
#define Constant                         (1U)
#define Array                            (0U)
#define Variable                         (1U<<1)
#define Absolute                         (0U)
#define Relative                         (1U<<2)
#define No_Wrap                          (0U)
#define Wrap                             (1U<<3)
#define Linear                           (0U)
#define NonLinear                        (1U<<4)
#define Preferred_State                  (0U)
#define No_Prefered                      (1U<<5)
#define No_Null_Position                 (0U)
#define Null_State                       (1U<<6)
#define Nonvolatile                      (0U)
#define Volatile                         (1U<<7)

/* Collection, End Collection Items Data Byte
*/
#define Col_Physical                     (0x00U)
#define Col_Application                  (0x01U)
#define Col_Logical                      (0x02U)
#define Col_Report                       (0x03U)
#define Col_Named_Array                  (0x04U)
#define Col_Usage_Switch                 (0x05U)
#define Col_Usage_Modifier               (0x06U)

/* Global Item Tag
*/
#define Usage_Page(size)                 (GLOBAL_ITEM|(0x00U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Logical_Minimum(size)            (GLOBAL_ITEM|(0x01U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Logical_Maximum(size)            (GLOBAL_ITEM|(0x02U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Physical_Minimum(size)           (GLOBAL_ITEM|(0x03U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Physical_Maximum(size)           (GLOBAL_ITEM|(0x04U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
  /* Unit Exponent: |   Code   | 0x5 | 0x6 | 0x7 | 0x8 | 0x9 | 0xA | 0xB | 0xC | 0xD | 0xE | 0xF |
  **                | Exponent |  5  |  6  |  7  | -8  | -7  | -6  | -5  | -4  | -3  | -2  | -1  |
  */
#define Unit_Exponent(size)              (GLOBAL_ITEM|(0x05U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
  /* Unit: 按半字节(Nibble)拆分，最低位半字节声明使用的计量系统，其余每个半字节声明对应单位的指数(-7~7)
  **  | Nibble |   0    |    1   |  2   |  3   |      4      |    5    |         6          |    7     |
  **  | Parts  | System | Length | Mass | Time | Temperature | Current | Luminous intensity | Reversed |
  **
  **  | Value  | 0x0  |    0x1    |     0x2     |      0x3       |        0x4       |  Other   |
  **  | System | None | SI Linear | SI Rotation | English Linear | English Rotation | Reversed |
  */
#define Unit(size)                       (GLOBAL_ITEM|(0x06U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Report_Size(size)                (GLOBAL_ITEM|(0x07U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Report_ID(size)                  (GLOBAL_ITEM|(0x08U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Report_Count(size)               (GLOBAL_ITEM|(0x09U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Push(size)                       (GLOBAL_ITEM|(0x0AU<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Pop(size)                        (GLOBAL_ITEM|(0x0BU<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))

#define System_None                      (0)
#define System_SI_Linear                 (1)
#define System_SI_Rotation               (2)
#define System_English_Linear            (3)
#define System_English_Rotation          (4)

/* Local Item Tag
*/
#define Usage(size)                      (LOCAL_ITEM|(0x00U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Usage_Minimum(size)              (LOCAL_ITEM|(0x01U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Usage_Maximum(size)              (LOCAL_ITEM|(0x02U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Designator_Index(size)           (LOCAL_ITEM|(0x03U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Designator_Minimum(size)         (LOCAL_ITEM|(0x04U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Designator_Maximum(size)         (LOCAL_ITEM|(0x05U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define String_Index(size)               (LOCAL_ITEM|(0x07U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define String_Minimum(size)             (LOCAL_ITEM|(0x08U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define String_Maximum(size)             (LOCAL_ITEM|(0x09U<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))
#define Delimiter(size)                  (LOCAL_ITEM|(0x0AU<<TAG_OFFSET)|((uint8_t)size&SIZE_MASK))

/* Usage Page Table
*/
//Undefined 0x00U
#define UP_Generic_Desktop               0x01U
#define UP_Simulation_Controls           0x02U
#define UP_VR_Controls                   0x03U
#define UP_Sport_Controls                0x04U
#define UP_Game_Controls                 0x05U
#define UP_Generic_Device_Controls       0x06U
#define UP_Keyboard_or_Keypad            0x07U
#define UP_LEDs                          0x08U
#define UP_Button                        0x09U
#define UP_Ordinal                       0x0AU
#define UP_Telephony                     0x0BU
#define UP_Consumer                      0x0CU
#define UP_Digitizer                     0x0DU
//Reversed 0x0EU
#define UP_PID_Page                      0x0FU
#define UP_Unicode                       0x10U
//Reversed 0x11U~0x13U
#define UP_Alphanumeric_Display          0x14U
//Reversed 0x15U~0x3FU
#define UP_Medical_Instruments           0x40U
//Reversed 0x41U~0x7FU
#define UP_Monitor_pages_1               0x80U
#define UP_Monitor_pages_2               0x81U
#define UP_Monitor_pages_3               0x82U
#define UP_Monitor_pages_4               0x83U
#define UP_Power_pages_1                 0x84U
#define UP_Power_pages_1                 0x84U
#define UP_Power_pages_2                 0x85U
#define UP_Power_pages_3                 0x86U
#define UP_Power_pages_4                 0x87U
//Reversed 0x88U~0x8BU
#define UP_Bar_Code_Scanner_page         0x8CU
#define UP_Scale_page                    0x8DU
#define UP_MSR_Devices                   0x8EU /* Magnetic Stripe Reading */
//Reversed point for sale pages 0x8FU
#define UP_Camera_Control_Page           0x90U
#define UP_Arcade_Page                   0x91U
//Reversed 0x92U~0xFEFFU
//Vendor-defined 0xFF00U~0xFFFFU

#define LOG         printf
#define LOGD        printf
#define LOGW        printf
#define LOGE        printf

#ifndef uint8_t
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef char                int8_t;
typedef short               int16_t;
typedef int                 int32_t;
typedef long long           int64_t;
#endif

#endif //_REPORT_ITEM_H