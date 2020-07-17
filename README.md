# USB-HID-Report-Parser
如果我们希望了解一个HID设备的功能，就必须解析它的报告描述符。 Windows下，使用USBView工具可以查看所有USB设备的描述符集，使用Bus Hound工具可以抓取枚举过程的数据（包括报告描述符）。 USB HID设备的报告描述符（Report Descriptor）由短条目（Short Item）组成。 拿到USB HID设备的报告描述符后，一个字节一个字节组成短条目来解析报告描述符太累了，我用Excel协助生成了一套代码（按照HID1.11+Usage Table 1.12v2的标准），用于将报告描述符数组翻译成文字描述。 同时，也可以用header文件中的宏自己写一套报告描述符。
