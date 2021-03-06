# USB-HID-Report-Parser  
如果我们希望了解一个HID设备的功能，就必须解析它的报告描述符。  
Windows下，使用USBView工具可以查看所有USB设备的描述符集，使用Bus Hound工具可以抓取枚举过程的数据（包括报告描述符）。  
USB HID设备的报告描述符（Report Descriptor）由短条目（Short Item）组成。  
拿到USB HID设备的报告描述符后，一个字节一个字节组成短条目来解析报告描述符太累了，我用Excel协助生成了一套代码（按照HID1.11+Usage Table 1.12v2的标准），用于将报告描述符数组翻译成文字描述。 同时，也可以用header文件中的宏自己写一套报告描述符。  
  
例子：  
```c
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
```
输出：  
Report Item Parse:  
Usage Page (Generic Desktop)  
Usage (Keyboard)  
Collection (App)  
&ensp;&ensp;Report ID (1)  
&ensp;&ensp;Usage Page (Keyboard)  
&ensp;&ensp;Usage Min (224)  
&ensp;&ensp;Usage Max (231)  
&ensp;&ensp;Logical Min (0)  
&ensp;&ensp;Logical Max (1)  
&ensp;&ensp;Report Count (8)  
&ensp;&ensp;Report Size (1)  
&ensp;&ensp;&ensp;&ensp;Input (Data, Var, Abs)  
&ensp;&ensp;Report Count (1)  
&ensp;&ensp;Report Size (8)  
&ensp;&ensp;&ensp;&ensp;Input (Cnst, Var, Abs)  
&ensp;&ensp;Usage Page (Keyboard)  
&ensp;&ensp;Usage Min (0)  
&ensp;&ensp;Usage Max (104)  
&ensp;&ensp;Logical Min (0)  
&ensp;&ensp;Logical Max (104)  
&ensp;&ensp;Report Count (6)  
&ensp;&ensp;Report Size (8)  
&ensp;&ensp;&ensp;&ensp;Input (Data, Array, Abs)  
&ensp;&ensp;Usage Page (LEDs)  
&ensp;&ensp;Usage Min (1)  
&ensp;&ensp;Usage Max (5)  
&ensp;&ensp;Report Count (5)  
&ensp;&ensp;Report Size (1)  
&ensp;&ensp;&ensp;&ensp;Output (Data, Var, Abs)  
&ensp;&ensp;Report Count (1)  
&ensp;&ensp;Report Size (3)  
&ensp;&ensp;&ensp;&ensp;Output (Cnst, Array, Abs)  
End Collection  
  
