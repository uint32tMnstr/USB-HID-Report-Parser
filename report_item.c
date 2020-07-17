
/* HID 1.11: https://www.usb.org/document-library/device-class-definition-hid-11
** HID Usage Tables 1.12: https://www.usb.org/document-library/hid-usage-tables-112
*/

#if defined(_WIN32) || defined(_WIN64)
#pragma warning(disable:4996)
#endif

#include <stdio.h>
#include <string.h>

#include "report_item.h"
#include "report_usage.h"

#define ri_StringGet        sprintf

#define ri_ItemSize(sizeMask)      ((uint8_t)(sizeMask) == Size_4B?4:(uint8_t)(sizeMask))

uint8_t *ri_ColletionType(uint8_t itemData)
{
    static uint8_t *colType[] = {
        "Physical",
        "App",
        "Logical",
        "Report",
        "Named Array",
        "Usage Switch",
        "Usage Modifier"
    };

    if(itemData <= Col_Usage_Modifier)
        return colType[itemData];

    /* 0x07-0x7F RFU.
    ** 0x80-0xFF Vendor defined.
    */
    return "Unknown";
}

uint8_t *ri_dataType(uint8_t itemTag, int32_t itemData)
{
#define STR_BUFFER_SIZE     (128U)
    static uint8_t str[STR_BUFFER_SIZE];

    int32_t index = 0;

    memset(str, 0, STR_BUFFER_SIZE);
    /* Only data byte 0 is used now. */
    index += ri_StringGet(str + index, "%s", (itemData & Constant)?"Cnst":"Data");
    index += ri_StringGet(str + index, "%s", (itemData & Variable)?", Var":", Array");
    index += ri_StringGet(str + index, "%s", (itemData & Relative)?", Rel":", Abs");
    if(itemData & Wrap)
        index += ri_StringGet(str + index, ", Wrap");
    if(itemData & NonLinear)
        index += ri_StringGet(str + index, ", NonLinear");
    if(itemData & No_Prefered)
        index += ri_StringGet(str + index, ", No Preferred");
    if(itemData & Null_State)
        index += ri_StringGet(str + index, ", Null State");

    /* Input Items Data bit 7 is undefined and is RFU. */
    if((itemTag & TAG_MASK) != Input(0) && (itemData & Volatile))
        index += ri_StringGet(str + index, ", Volatile");

    /* Data byte 1~3 is RFU. */
    if(itemData & 0xFFFFFF00)
        index += ri_StringGet(str + index, ", ???");

    str[index] = 0;
    return (uint8_t *)str;
}

void  ri_MainItem(uint8_t itemTag, int32_t itemData, uint8_t *pspace)
{
    uint8_t str[256] = {0};
    int32_t index = 0;

    for (; index < *pspace; index++)
        str[index] = ' ';

    switch(itemTag)
    {
    case Input(0):
        index += ri_StringGet(str + index, "  Input (%s)", ri_dataType(Input(0), itemData));
        break;
    case Output(0):
        index += ri_StringGet(str + index, "  Output (%s)", ri_dataType(Output(0), itemData));
        break;
    case Feature(0):
        index += ri_StringGet(str + index, "  Feature (%s)", ri_dataType(Feature(0), itemData));
        break;
    case Collection(0):
        *pspace += 2;
        index += ri_StringGet(str + index, "Collection (%s)", ri_ColletionType((uint8_t)itemData));
        if(itemData & 0xFFFFFF00U)
            index += ri_StringGet(str + index, " ???");
        break;
    case End_Colletion(0):
        *pspace -= 2;
        index -= 2;
        index += ri_StringGet(str + index, "End Collection");
        break;
    default:
        index += ri_StringGet(str + index, "Unknown Item: %02X", itemTag);
        break;
    }
    LOG("%s\r\n", str);
}

uint8_t *ri_UsagePage(int32_t itemData)
{
    switch(itemData)
    {
    case UP_Generic_Desktop:
        return "Generic Desktop";
    case UP_Simulation_Controls:
        return "Simulation";
    case UP_VR_Controls:
        return "VR Controls";
    case UP_Sport_Controls:
        return "Sport Controls";
    case UP_Game_Controls:
        return "Game Controls";
    case UP_Generic_Device_Controls:
        return "Generic Device";
    case UP_Keyboard_or_Keypad:
        return "Keyboard";
    case UP_LEDs:
        return "LEDs";
    case UP_Button:
        return "Buttons";
    case UP_Ordinal:
        return "Ordinal";
    case UP_Telephony:
        return "Telephony";
    case UP_Consumer:
        return "Consumer";
    case UP_Digitizer:
        return "Digitizer";
    case UP_PID_Page:
        return "PID Page";
    case UP_Unicode:
        return "Unicode";
    case UP_Alphanumeric_Display:
        return "Alphanumeric Display";
    case UP_Medical_Instruments:
        return "Medical Instruments";
    case UP_Monitor_pages_1:
    case UP_Monitor_pages_2:
    case UP_Monitor_pages_3:
    case UP_Monitor_pages_4:
        return "Monitor";
    case UP_Power_pages_1:
    case UP_Power_pages_2:
    case UP_Power_pages_3:
    case UP_Power_pages_4:
        return "Power";
    case UP_Bar_Code_Scanner_page:
        return "Bar Code Scanner";
    case UP_Scale_page:
        return "Scale";
    case UP_MSR_Devices:
        return "MSR Device";
    case UP_Camera_Control_Page:
        return "Camera";
    case UP_Arcade_Page:
        return "Arcade";
    default:
        return "Unknown";
    }
}

int32_t ri_GetItemData(uint8_t *itemData, uint8_t size)
{
    if(size == 1)
        return *itemData;
    else if(size == 2)
        return *((int16_t *)itemData);
    else if(size == 4)
        return *((int32_t *)itemData);

    return 0;
}

int8_t *ri_Exponent(int32_t itemData)
{
    static int8_t *str[] = {"5","6","7","-8","-7","-6","-5","-4","-3","-2","-1"};

    uint8_t code = (uint8_t)itemData;

    if(code < 0x10U && code > 0x04U)
        return str[code - 5];

    return "Unknown";
}

#define NibbleToByte(nibble)    (((int8_t)nibble & 0x08)?((int8_t)nibble | 0xF0):(int8_t)nibble)

int8_t *ri_Unit(uint32_t itemData)
{
    static uint8_t str[128] = {0};

    int8_t *strUnit_SI_Linear[] = {"SI Linear","cm","Gram","Seconds","Kelvin","Ampere","Candela"};
    int8_t *strUnit_SI_Rotation[] = {"SI Rotation","rad","Gram","Seconds","Kelvin","Ampere","Candela"};
    int8_t *strUnit_English_Linear[] = {"English Linear","Inch","Slug","Seconds","Fahrenheit","Ampere","Candela"};
    int8_t *strUnit_English_Rotation[] = {"English Rotation","Degrees","Slug","Seconds","Fahrenheit","Ampere","Candela"};
    int8_t **strUnit = NULL;

    int32_t index = 0;
    int8_t nibble = itemData & 0xF;
    int8_t nibbleNo = 0;    /* 7 is reserved. */

    /* System */
    switch(nibble)
    {
    case System_None:
        return "None";
    case System_SI_Linear:
        strUnit = strUnit_SI_Linear;
        break;
    case System_SI_Rotation:
        strUnit = strUnit_SI_Rotation;
        break;
    case System_English_Linear:
        strUnit = strUnit_English_Linear;
        break;
    case System_English_Rotation:
        strUnit = strUnit_English_Rotation;
        break;
    default:
        return "Unknown";
    }

    index = ri_StringGet(str + index, "%s:", strUnit[0]);
    itemData >>= 4; /* 跳过首个nibble */
    nibbleNo++;

    for(; itemData && nibbleNo < 7; itemData >>= 4)
    {
        nibble = itemData & 0xF;
        if(nibble)
            index += ri_StringGet(str + index, " %s[%d]", strUnit[nibbleNo], NibbleToByte(nibble));
        nibbleNo++;
    }

    return str;
}

void ri_GlobalItem(uint8_t itemTag, int32_t itemData, uint8_t space, int32_t *pUsagePage)
{
    uint8_t str[256] = {0};
    int32_t index = 0;

    for (; index < space; index++)
        str[index] = ' ';

    switch(itemTag)
    {
    case Usage_Page(0):
        *pUsagePage = itemData;
        index += ri_StringGet(str + index, "Usage Page (%s)", ri_UsagePage(itemData));
        break;
    case Logical_Minimum(0):
        index += ri_StringGet(str + index, "Logical Min (%d)", itemData);
        break;
    case Logical_Maximum(0):
        index += ri_StringGet(str + index, "Logical Max (%d)", itemData);
        break;
    case Physical_Minimum(0):
        index += ri_StringGet(str + index, "Physical Min (%d)", itemData);
        break;
    case Physical_Maximum(0):
        index += ri_StringGet(str + index, "Physical Max (%d)", itemData);
        break;
    case Unit_Exponent(0):
        index += ri_StringGet(str + index, "Unit Exponent (%s)", ri_Exponent(itemData));
        break;
    case Unit(0):
        index += ri_StringGet(str + index, "Unit (%s)", ri_Unit((uint32_t)itemData));
        break;
    case Report_Size(0):
        index += ri_StringGet(str + index, "Report Size (%d)", itemData);
        break;
    case Report_ID(0):
        index += ri_StringGet(str + index, "Report ID (%d)", itemData);
        break;
    case Report_Count(0):
        index += ri_StringGet(str + index, "Report Count (%d)", itemData);
        break;
    case Push(0):
        index += ri_StringGet(str + index, "Push");
        break;
    case Pop(0):
        index += ri_StringGet(str + index, "Pop");
        break;
    default:
        index += ri_StringGet(str + index, "Unknown Item: %02X", itemTag);
        break;
    }

    LOG("%s\r\n", str);
}

#define ri_DelimiterItem(itemData)  (((int32_t)itemData)? \
                                     (((int32_t)itemData == 1)?"Open Set":"Unknown Setting"): \
                                     "Close Set")

void ri_LocalItem(uint8_t itemTag, int32_t itemData, uint8_t space, int32_t usagePage)
{
    uint8_t str[256] = {0};
    int32_t index = 0;

    for (; index < space; index++)
        str[index] = ' ';

    switch(itemTag)
    {
    case Usage(0):
        /* TODO: 根据Usage Page查表 */
        index += ri_StringGet(str + index, "Usage (%s)", ri_Usage(usagePage, itemData));
        break;
    case Usage_Minimum(0):
        index += ri_StringGet(str + index, "Usage Min (%d)", itemData);
        break;
    case Usage_Maximum(0):
        index += ri_StringGet(str + index, "Usage Max (%d)", itemData);
        break;
    case Designator_Index(0):
        index += ri_StringGet(str + index, "Designator Index (%d)", itemData);
        break;
    case Designator_Minimum(0):
        index += ri_StringGet(str + index, "Designator Min (%d)", itemData);
        break;
    case Designator_Maximum(0):
        index += ri_StringGet(str + index, "Designator Max (%d)", itemData);
        break;
    case String_Index(0):
        index += ri_StringGet(str + index, "String Index (%d)", itemData);
        break;
    case String_Minimum(0):
        index += ri_StringGet(str + index, "String Min (%d)", itemData);
        break;
    case String_Maximum(0):
        index += ri_StringGet(str + index, "String Max (%d)", itemData);
        break;
    case Delimiter(0):
        /* defines the deginning or end of a set of local items. 
        ** 1 = open set, 0 = close set. 
        */
        index += ri_StringGet(str + index, "Delimiter (%s)", ri_DelimiterItem(itemData));
    default:
        index += ri_StringGet(str + index, "Unknown Item: %02X", itemTag);
        break;
    }

    LOG("%s\r\n", str);
}

int ri_Parse(uint8_t *buf, uint16_t len)
{
    uint8_t space = 0;
    uint16_t index = 0;
    LOGD("Report Item Parse:\r\n");
    while(index < len)
    {
        static int32_t sUsagePage = -1;

        uint8_t itemTag = buf[index] & TAG_MASK;
        uint8_t itemSize = ri_ItemSize(buf[index] & SIZE_MASK);
        int32_t itemData = 0;

        if(index + itemSize >= len)
        {
            LOGE("out of buffer.\r\n");
            break;
        }
        
        itemData = ri_GetItemData(&buf[index + 1], itemSize);
        switch(itemTag & TYPE_MASK)
        {
        case MAIN_ITEM:
            ri_MainItem(itemTag, itemData, &space);
            break;
        case GLOBAL_ITEM:
            ri_GlobalItem(itemTag, itemData, space, &sUsagePage);
            break;
        case LOCAL_ITEM:
            ri_LocalItem(itemTag, itemData, space, sUsagePage);
            break;
        default:
            LOG("Unknown Type: %02X, index: %d\r\n", itemTag, index);
            break;
        }
        index += (itemSize + 1);
    }

    return (index < len);
}

uint8_t USBD_KeyBoardReportDesc[] =
{
  /* 键盘定义了8B长度的消息：
  ** 第一个Byte表示8个特殊按键是否按下
  ** 第二个Byte为常量，自定义数据
  ** 后六个Byte代表普通按键是否被按下，最多同时识别六个，超出则应输出按键无效(FF)
  */
  0x05, 0x01,  /* Usage Page (Generic Desktop) */
  0x09, 0x06,  /* Usage (Keyboard) */
  0xA1, 0x01,  /* Collection (Application) */
  0x85, 0x01,  /* Report ID 只有一个报告，可以忽略该字段 */
  0x05, 0x07,  /*   Usage (Keypad) */

  /* 特殊按键的输入报告 */
  0x19, 0xE0,  /*   Usage Minimum (Left Control) */
  0x29, 0xE7,  /*   Usage Maximum (Right GUI) */
  0x15, 0x00,  /*   Logical Minimum (0) */
  0x25, 0x01,  /*   Logical Maximum (1) */
  0x95, 0x08,  /*   Report Count (8) */
  0x75, 0x01,  /*   Report Size Bit(s) (1) */
  0x81, 0x02,  /*     Input (Data, Var, Abs) 8bit分别对应E0~E7键值 */
  0x95, 0x01,  /*   Report Count (1) */
  0x75, 0x08,  /*   Report Size Bit(s) (8) */
  0x81, 0x03,  /*     Input (Const, Var, Abs) 固定为常量0，保留字节OEM使用 */

  /* 普通按键的输入报告 */
  0x05, 0x07,  /*   Usage (Keypad) */
  0x19, 0x00,  /*   Usage Minimum (0)：没有键按下 */
  0x29, 0x68,  /*   Usage Maximum (104)：最大键值 */
  0x15, 0x00,  /*   Logical Minimum (0) */
  0x25, 0x68,  /*   Logical Maximum (104) */
  0x95, 0x06,  /*   Report Count (6)：最多同时识别6个普通键按下 */
  0x75, 0x08,  /*   Report Size Bit(s) (8) */
  0x81, 0x00,  /*     Input (Data, Array, Abs) */
    
  /* 指示灯的输出报告 */
  0x05, 0x08,  /*   Usage (LEDs) */
  0x19, 0x01,  /*   Usage Minimum (NumLock) */
  0x29, 0x05,  /*   Usage Maximum (Kana)  */
  0x95, 0x05,  /*   Report Count (5) */
  0x75, 0x01,  /*   Report Size Bit(s) (1) */
  0x91, 0x02,  /*     Output (Data, Var, Abs) */
  0x95, 0x01,  /*   Report Count (1) */
  0x75, 0x03,  /*   Report Size Bit(s) (3) */
  0x91, 0x01,  /*     Output(Const, Array, Abs) 补充3bit对齐到Byte */

    0x05, 0x0c,  /*   Usage (Consumer) */
    0x09, 0x00,  /*   Usage (Unassigned) */
    0x15, 0x80,  /*   Logical Minimum (-127) */
    0x25, 0x7f,  /*   Logical Minimum (127) */
    0x75, 0x08,  /*   Report Size Bit(s) (8) */
    0x95, 0x40,  /*   Report Count (64) */
    0xb1, 0x02,  /*   Feature (Data, Var, Abs) */
  0xC0         /* End Collection */
};

uint8_t USBD_MouseReportDesc[] =
{
  /* 鼠标定义了4B长度的消息：
  ** 第一个字节的低3bit指示左/右/中键是否被按下
  ** 后三个字节分别指示（X偏移量，Y偏移量，滑轮偏移量）
  */
  /* Ref: 
  ** 条目对照表：https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
  ** Report结构：https://www.usb.org/sites/default/files/documents/hid1_11.pdf
  ** Short Items(1Byte): [7  ~  4] [3   2] [1   0] bit
  **                     [ bTag  ] [bType] [bSize]
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

  /* Report ID: 0x01U, Size: 5B, {0x01, Button，ΔX，ΔY，ΔWheel}.
  ** Desc: 鼠标报告（相对坐标），参考sm_report.c - SM_MouseCollection().
  */
  0x05, 0x01,         /* Usage Page (Generic Desktop) */
  0x09, 0x02,         /* Usage (Mouse) */
  0xA1, 0x01,         /* Collection (Application) */
  0x85, 0x01,  /*   Report ID */
  0x09, 0x01,         /*   Usage (Pointer) */
  0xA1, 0x00,         /*   Collection (Physical) */
  0x05, 0x09,         /*     Usage Page (Buttons) */
  0x19, 0x01,         /*     Usage Minimum (01) */
  0x29, 0x03,         /*     Usage Maximum (03) */
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x25, 0x01,         /*     Logical Maximum (1) */
  0x95, 0x03,         /*     Report Count (3) */
  0x75, 0x01,         /*     Report Size Bit(s) (1) */
  0x81, 0x02,         /*       Input (Data, Variable, Absolute) */
  0x95, 0x01,         /*     Report Count (1) */
  0x75, 0x05,         /*     Report Size (5) */
  0x81, 0x01,         /*       Input (Constant)：补充前面3bit到一个字节 */
  0x05, 0x01,         /*     Usage Page (Generic Desktop) */
  0x09, 0x30,         /*     Usage (X) */
  0x09, 0x31,         /*     Usage (Y) */
  0x09, 0x38,         /*     Usage (Wheel) */
  0x15, 0x81,         /*     Logical Minimum (-127) */
  0x25, 0x7F,         /*     Logical Maximum (127) */
  0x75, 0x08,         /*     Report Size (8) */
  0x95, 0x03,         /*     Report Count (3) */
  0x81, 0x06,         /*       Input (Data, Variable, Relative) */
  0xC0,               /*   End Collection */
  0xC0,               /* End Collection */
  
  /* Report ID: 0x02U, Size: 30B, {0x02, Finger1(5B)...Finger5(5B), Scan Time(2B), Finger Num, Button}.
  ** Desc: 多触点报告，Win10专用
  ** REF：https://docs.microsoft.com/en-us/windows-hardware/design/component-guidelines/supporting-usages-in-digitizer-report-descriptors
  **      https://docs.microsoft.com/en-us/windows-hardware/design/component-guidelines/touchpad-configuration-collection
  */
  0x05, 0x0D,         /* Usage Page (Digitizers) */
  0x09, 0x05,         /* Usage (Touchpad) */
  0xA1, 0x01,         /* Collection (Application) */
  0x85, 0x02,  /*   Report ID: 2 */
  0x09, 0x22,         /*   Usage (Finger) */
  0xA1, 0x02,         /*   Collection (Logical) */
  0x09, 0x47,         /*     Usage (Confidence): Set when contact is a finger (not a palm or any other part of the hand that should not trigger finger input). */
  0x09, 0x42,         /*     Usage (Tip Switch): 触碰置1，松开置0 */
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x25, 0x01,         /*     Logical Maximum (1) */
  0x75, 0x01,         /*     Bits (1) */
  0x95, 0x02,         /*     Count (2) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x51,         /*     Usage (Contact ID) */
  0x25, 0x07,         /*     Logical Maximum (7) */
  0x75, 0x03,         /*     Bits (3) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x81, 0x03,         /*       Input(Const, Var, Abs) */
  0x05, 0x01,         /*     Usage Page (Generic Desktop) */
  0x09, 0x30,         /*     Usage (X) */
  0x55, 0x0E,         /*     Unit Exponent (-2): Ref hid1_11.pdf page 38 */
  /* Unit(Nibble): (System, Length, Mass, Time, Temperature, Current, Luminous intensity, Reversed) */
  0x65, 0x13,         /*     Unit (English Linear, Inch)*/
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x35, 0x00,         /*     Physical Minimum (0) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x75, 0x10,         /*     Bits (16) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x31,         /*     Usage (Y) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0xC0,               /*   End Collection */
  0x05, 0x0D,         /*   Usage Page (Digitizers) */
  0x09, 0x22,         /*   Usage (Finger) */
  0xA1, 0x02,         /*   Collection (Logical) */
  0x09, 0x47,         /*     Usage (Confidence): need in Finger */
  0x09, 0x42,         /*     Usage (Tip Switch) */
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x25, 0x01,         /*     Logical Maximum (1) */
  0x75, 0x01,         /*     Bits (1) */
  0x95, 0x02,         /*     Count (2) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x51,         /*     Usage (Contact ID) */
  0x25, 0x07,         /*     Logical Maximum (7) */
  0x75, 0x03,         /*     Bits (3) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x81, 0x03,         /*       Input(Const, Var, Abs) */
  0x05, 0x01,         /*     Usage Page (Generic Desktop) */
  0x09, 0x30,         /*     Usage (X) */
  0x55, 0x0E,         /*     Unit Exponent (-2) */
  0x65, 0x13,         /*     Unit (English Linear, Inch)*/
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x35, 0x00,         /*     Physical Minimum (0) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x75, 0x10,         /*     Bits (16) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x31,         /*     Usage (Y) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0xC0,               /*   End Collection */
  0x05, 0x0D,         /*   Usage Page (Digitizers) */
  0x09, 0x22,         /*   Usage (Finger) */
  0xA1, 0x02,         /*   Collection (Logical) */
  0x09, 0x47,         /*     Usage (Confidence): need in Finger */
  0x09, 0x42,         /*     Usage (Tip Switch) */
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x25, 0x01,         /*     Logical Maximum (1) */
  0x75, 0x01,         /*     Bits (1) */
  0x95, 0x02,         /*     Count (2) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x51,         /*     Usage (Contact ID) */
  0x25, 0x07,         /*     Logical Maximum (7) */
  0x75, 0x03,         /*     Bits (3) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x81, 0x03,         /*       Input(Const, Var, Abs) */
  0x05, 0x01,         /*     Usage Page (Generic Desktop) */
  0x09, 0x30,         /*     Usage (X) */
  0x55, 0x0E,         /*     Unit Exponent (14) */
  0x65, 0x13,         /*     Unit (English Linear, Inch) */
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x35, 0x00,         /*     Physical Minimum (0) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x75, 0x10,         /*     Bits (16) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x31,         /*     Usage (Y) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0xC0,               /*   End Collection */
  0x05, 0x0D,         /*   Usage Page (Digitizers) */
  0x09, 0x22,         /*   Usage (Finger) */
  0xA1, 0x02,         /*   Collection (Logical) */
  0x09, 0x47,         /*     Usage (Confidence): need in Finger */
  0x09, 0x42,         /*     Usage (Tip Switch) */
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x25, 0x01,         /*     Logical Maximum (1) */
  0x75, 0x01,         /*     Bits (1) */
  0x95, 0x02,         /*     Count (2) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x51,         /*     Usage (Contact ID) */
  0x25, 0x07,         /*     Logical Maximum (7) */
  0x75, 0x03,         /*     Bits (3) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x81, 0x03,         /*       Input(Const, Var, Abs) */
  0x05, 0x01,         /*     Usage Page (Generic Desktop) */
  0x09, 0x30,         /*     Usage (X) */
  0x55, 0x0E,         /*     Unit Exponent (14) */
  0x65, 0x13,         /*     Unit (English Linear, Inch) */
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x35, 0x00,         /*     Physical Minimum (0) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x75, 0x10,         /*     Bits (16) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x31,         /*     Usage (Y) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0xC0,               /*   End Collection */
  0x05, 0x0D,         /*   Usage Page (Digitizers) */
  0x09, 0x22,         /*   Usage (Finger) */
  0xA1, 0x02,         /*   Collection (Logical) */
  0x09, 0x47,         /*     Usage (Confidence): need in Finger */
  0x09, 0x42,         /*     Usage (Tip Switch) */
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x25, 0x01,         /*     Logical Maximum (1) */
  0x75, 0x01,         /*     Bits (1) */
  0x95, 0x02,         /*     Count (2) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x51,         /*     Usage (Contact ID) */
  0x25, 0x07,         /*     Logical Maximum (7) */
  0x75, 0x03,         /*     Bits (3) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x81, 0x03,         /*       Input(Const, Var, Abs) */
  0x05, 0x01,         /*     Usage Page (Generic Desktop) */
  0x09, 0x30,         /*     Usage (X) */
  0x55, 0x0E,         /*     Unit Exponent (14) */
  0x65, 0x13,         /*     Unit (English Linear, Inch) */
  0x15, 0x00,         /*     Logical Minimum (0) */
  0x35, 0x00,         /*     Physical Minimum (0) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x75, 0x10,         /*     Bits (16) */
  0x95, 0x01,         /*     Count (1) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x09, 0x31,         /*     Usage (Y) */
  0x26, 0xFF, 0x00,   /*     Logical Maximum () */
  0x46, 0xFF, 0x00,   /*     Physical Maximum () */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0xC0,               /*   End Collection */
  0x05, 0x0D,         /*   Usage Page (Digitizers) */
  0x09, 0x56,         /*   Usage (Long Scan Time): touch needed. */
  0x55, 0x0C,         /*   Unit Exponent (-4): Windows规定单位必须为100us */
  0x66, 0x01, 0x10,   /*   Unit (SI Linear(国际线性系统), None, None, Seconds) */
  0x47, 0xFF, 0xFF, 0x00, 0x00, /*   Physical Maximum (0x0FFFF) */
  0x27, 0xFF, 0xFF, 0x00, 0x00, /*   Logical Maximum (0x0FFFF) */
  0x75, 0x10,         /*   Bits (16) */
  0x95, 0x01,         /*   Count (1) */
  0x81, 0x02,         /*     Input(Data, Var, Abs) */
  0x09, 0x54,         /*   Usage (Contact count) */
  0x25, 0x7F,         /*   Logical Maximum (127) */
  0x75, 0x08,         /*   Bits (8) */
  0x95, 0x01,         /*   Count (1) */
  0x81, 0x02,         /*     Input(Data, Var, Abs) */
  0x05, 0x09,         /*   Usage Page (Button) */
  0x09, 0x01,         /*   Usage (Button1) */
  0x25, 0x01,         /*   Logical Maximum (1) */
  0x75, 0x01,         /*   Bits (1) */
  0x95, 0x01,         /*   Count (1) */
  0x81, 0x02,         /*     Input(Data, Var, Abs) */
  0x95, 0x07,         /*   Count (7) */
  0x81, 0x03,         /*     Input(Const, Var, Abs) */
  
  /* Report ID: 0x03U, Size: 2B， {0x03, Contact Max Count}
  ** Desc: 最大触点个数特性报告
  */
  0x05, 0x0D,         /*   USAGE_PAGE (Digitizer) */
  0x85, 0x03, /* REPORT_ID (Feature) */
  0x09, 0x55,         /*   USAGE (Contact Count Maximum) */
  0x09, 0x59,         /*   USAGE (Pad TYpe) */
  0x75, 0x04,         /*   REPORT_SIZE (4) */
  0x95, 0x02,         /*   REPORT_COUNT (2) */
  0x25, 0x0F,         /*   LOGICAL_MAXIMUM (15) */
  0xB1, 0x02,         /*     FEATURE (Data,Var,Abs) */

  /* Report ID: 0x04U, Size: 257B, {0x04, BLOB(256B)}
  ** Desc: 精确式触控板的签名块，用以判断是否经微软验证的精确式设备
  */
  0x06, 0x00, 0xFF,   /*   USAGE_PAGE (Vendor Defined) */
  0x85, 0x04,  /*   REPORT_ID (PTPHQA) */
  0x09, 0xC5,         /*   USAGE (Vendor Usage 0xC5) */
  0x15, 0x00,         /*   LOGICAL_MINIMUM (0) */
  0x26, 0xFF, 0x00,   /*   LOGICAL_MAXIMUM (0xff) */
  0x75, 0x08,         /*   REPORT_SIZE (8) */
  0x96, 0x00, 0x01,   /*   REPORT_COUNT (256) */
  0xB1, 0x02,         /*     FEATURE (Data,Var,Abs) */
  0xC0,               /* End Collection */ 

  /* Report ID: 0x05U, Size: 2B, {0x05, Mode}
  ** Desc: 输入模式特性报告
  ** Input Mode : 0 - 鼠标集合 3 - 触点集合
  */
  0x05, 0x0D,         /* USAGE_PAGE (Digitizer) */
  0x09, 0x0E,         /* USAGE (Configuration) */
  0xA1, 0x01,         /* COLLECTION (Application) */
  0x85, 0x05, /*   REPORT_ID (Feature)*/
  0x09, 0x22,         /*   USAGE (Finger) */
  0xA1, 0x02,         /*   COLLECTION (logical) */
  0x09, 0x52,         /*     USAGE (Input Mode) */
  0x15, 0x00,         /*     LOGICAL_MINIMUM (0) */
  0x25, 0x0A,         /*     LOGICAL_MAXIMUM (10) */
  0x75, 0x08,         /*     REPORT_SIZE (8) */
  0x95, 0x01,         /*     REPORT_COUNT (1) */
  0xB1, 0x02,         /*       FEATURE (Data,Var,Abs) */
  0xC0,               /*   END_COLLECTION */

  /* Report ID: 0x06U, Size: 2B, {0x06, switch}
  ** Desc: 
  */   
  0x09, 0x22,         /*   USAGE (Finger) */
  0xA1, 0x00,         /*   COLLECTION (Physical) */
  0x85, 0x06, /*     REPORT_ID (Feature) */
  0x09, 0x57,         /*     USAGE(Surface switch) */
  0x09, 0x58,         /*     USAGE(Button switch) */
  0x75, 0x01,         /*     REPORT_SIZE (1) */
  0x95, 0x02,         /*     REPORT_COUNT (2) */
  0x25, 0x01,         /*     LOGICAL_MAXIMUM (1) */
  0xB1, 0x02,         /*       FEATURE (Data,Var,Abs) */
  0x95, 0x06,         /*     REPORT_COUNT (6) */
  0xB1, 0x03,         /*       FEATURE (Cnst,Var,Abs) */
  0xC0,               /*   END_COLLECTION */
  0xC0,               /* END_COLLECTION */

  /* Report ID: 0x08U, Size: 2B, {0x08, option}
  ** Desc: 多媒体控制报告
  **       | Bit |  0   |  1   |  2  |     3     |  4  |   5   |   6   |  7   |
  **       | Opt | 前进 | 后退 | 停止 | 暂停/继续 | 静音 | 音量+ | 音量- | 预留 |
  */
  0x05, 0x0C,         /*   Usage Page (Consumer) */
  0x09, 0x01,         /*   Usage (Consumer Control) */
  0xA1, 0x01,         /*   Collection (Application) */
  0x85, 0x07, /*     REPORT_ID (Media Control) */
  0x09, 0xB5,         /*     Usage (Scan Next Track) */
  0x09, 0xB6,         /*     Usage (Scan Previous Track) */
  0x09, 0xB7,         /*     Usage (Stop) */
  0x09, 0xCD,         /*     Usage (Play/Pause) */
  0x09, 0xE2,         /*     Usage (Mute) */
  0x09, 0xE9,         /*     Usage (Volume Up) */
  0x09, 0xEA,         /*     Usage (Volume Down) */
  0x15, 0x00,         /*     LOGICAL_MINIMUM (0) */
  0x25, 0x01,         /*     LOGICAL_MAXIMUM (1) */
  0x75, 0x01,         /*     REPORT_SIZE (1) */
  0x95, 0x07,         /*     REPORT_COUNT (7) */
  0x81, 0x02,         /*       Input(Data, Var, Abs) */
  0x95, 0x01,         /*     REPORT_COUNT (1) */
  0x81, 0x03,         /*       Input(Cnst, Var, Abs) */
  0xC0                /*   END_COLLECTION */
};

int main()
{
    ri_Parse(USBD_MouseReportDesc, sizeof(USBD_MouseReportDesc));
    return 0;
}