This is a MicroPython board definition file for the PYFLEX_F401 from kitmatic.com.

The quick version follows, and a more complete blog post can be found here:
http://blog.kitmatic.com/...

The PYFLEX_F401 has the STM32F401CE MCU, voltage converters from USB 5V up to 18VDC and from USB 5Vdown to lithium iron phosphate battery charging volts between 2.4 and 3.4VDC,2 20 pin flat flex connectors to get to the GPIOs, ADCs, and com ports of the MCU, a USB C connector for charging, a microUSB AB connector for development and data logging data transfer, and an SD card slot. 

Build the firmware using:
```
cd micropython/stmhal/boards
git clone https://github.com/jgriessen/PYFLEX_F401
cd ..
make BOARD=PYFLEX_F401
```

To get the device in DFU mode, you need to connect ??B0, which is the test
point located on the bottom right corner of the board (same side and opposite end
to the USB connector), to 3.3v, while powering up or RESETing the device.

Once in DFU mode, you should be able to use the ```dfu-util --list``` command and see
something like this:
```
Found DFU: [0483:df11] ver=2200, devnum=14, cfg=1, intf=0, alt=3, name="@Device Feature/0xFFFF0000/01*004 e", serial="377A364D3234"
Found DFU: [0483:df11] ver=2200, devnum=14, cfg=1, intf=0, alt=2, name="@OTP Memory /0x1FFF7800/01*512 e,01*016 e", serial="377A364D3234"
Found DFU: [0483:df11] ver=2200, devnum=14, cfg=1, intf=0, alt=1, name="@Option Bytes  /0x1FFFC000/01*016 e", serial="377A364D3234"
Found DFU: [0483:df11] ver=2200, devnum=14, cfg=1, intf=0, alt=0, name="@Internal Flash  /0x08000000/04*016Kg,01*064Kg,03*128Kg", serial="377A364D3234"
```

Now you can flash MicroPython using:
```
make BOARD=PYFLEX_F401 deploy
```

Reboot with BOOT0 unconnected, and it should boot up MicroPython on the REPL:
```
USB Serial device with vendor 'MicroPython' serial '377A364D3234' connected @/dev/ttyACM0
Use Control-X to exit.
MicroPython v1.8.2-13-g08eac74 on 2016-07-14; G30TH with STM32F401CE
Type "help()" for more information.
>>> 
```

Now that MicroPython is installed, as long as you can get to the REPL, then you
can get back into DFU mode by using the command:
```
>>> pyb.bootloader()
```
or by connecting B0 to 3.3v.

