# USB-HID-Report-Parser  
如果我们希望了解一个HID设备的功能，就必须解析它的报告描述符。  
Windows下，使用USBView工具可以查看所有USB设备的描述符集，使用Bus Hound工具可以抓取枚举过程的数据（包括报告描述符）。  
USB HID设备的报告描述符（Report Descriptor）由短条目（Short Item）组成。  
拿到USB HID设备的报告描述符后，一个字节一个字节组成短条目来解析报告描述符太累了，我用Excel协助生成了一套代码（按照HID1.11+Usage Table 1.12v2的标准），用于将报告描述符数组翻译成文字描述。 同时，也可以用header文件中的宏自己写一套报告描述符。  
  
例子：  
  
uint8_t Report[] =  
{  
  0x05, 0x01,  0x09, 0x06,  0xA1, 0x01,  0x85, 0x01,  
  0x05, 0x07,  0x19, 0xE0,  0x29, 0xE7,  0x15, 0x00,  
  0x25, 0x01,  0x95, 0x08,  0x75, 0x01,  0x81, 0x02,  
  0x95, 0x01,  0x75, 0x08,  0x81, 0x03,  0x05, 0x07,  
  0x19, 0x00,  0x29, 0x68,  0x15, 0x00,  0x25, 0x68,  
  0x95, 0x06,  0x75, 0x08,  0x81, 0x00,  0x05, 0x08,  
  0x19, 0x01,  0x29, 0x05,  0x95, 0x05,  0x75, 0x01,  
  0x91, 0x02,  0x95, 0x01,  0x75, 0x03,  0x91, 0x01,  
  0xC0  
};  
  
输出：  
Report Item Parse:  
Usage Page (Generic Desktop)  
Usage (Keyboard)  
Collection (App)  
  Report ID (1)  
  Usage Page (Keyboard)  
  Usage Min (224)  
  Usage Max (231)  
  Logical Min (0)  
  Logical Max (1)  
  Report Count (8)  
  Report Size (1)  
    Input (Data, Var, Abs)  
  Report Count (1)  
  Report Size (8)  
    Input (Cnst, Var, Abs)  
  Usage Page (Keyboard)  
  Usage Min (0)  
  Usage Max (104)  
  Logical Min (0)  
  Logical Max (104)  
  Report Count (6)  
  Report Size (8)  
    Input (Data, Array, Abs)  
  Usage Page (LEDs)  
  Usage Min (1)  
  Usage Max (5)  
  Report Count (5)  
  Report Size (1)  
    Output (Data, Var, Abs)  
  Report Count (1)  
  Report Size (3)  
    Output (Cnst, Array, Abs)  
End Collection  
  
