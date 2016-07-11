This is a MicroPython board definition file for the G30TH from ghielectronics.

The G30TH is the replacement for the G30HDR. The product page can be found here:
https://www.ghielectronics.com/catalog/product/551

Build the firmware using:
```
cd micropython/stmhal/boards
git clone https://github.com/dhylands/G30TH.git
cd ..
make BOARD=G30TH
```

To get the device in DFU mode, you need to connect B0, which is the test
point located on the bottom right corner of the board (same side and opposite end
to the USB connector), to 3.3v, while powering up or RESETing the device.

Once in DFU mode, you should be able to use the dfu-list command and see
something like this:
```
Found DFU: [0483:df11] ver=2200, devnum=45, cfg=1, intf=0, alt=3, name="@Device Feature/0xFFFF0000/01*004 e", serial="348E37423533"
Found DFU: [0483:df11] ver=2200, devnum=45, cfg=1, intf=0, alt=2, name="@OTP Memory /0x1FFF7800/01*512 e,01*016 e", serial="348E37423533"
Found DFU: [0483:df11] ver=2200, devnum=45, cfg=1, intf=0, alt=1, name="@Option Bytes  /0x1FFFC000/01*016 e", serial="348E37423533"
Found DFU: [0483:df11] ver=2200, devnum=45, cfg=1, intf=0, alt=0, name="@Internal Flash  /0x08000000/04*016Kg,01*064Kg,03*128Kg", serial="348E37423533"
```

The G30TH is read protected (assumed). In order to flash MicroPython on it, you need
to unprotect it, which will in turn erase the part. This is a one-time
operation. Once MicroPython is flashed, the device will remain unprotected.

Unprotect/Erase the device using:
```
dfu-util -s :unprotect:force -a 0 -d 0483:df11 -D build-G30TH/firmware.dfu
```

Now you can flash MicroPython using:
```
make BOARD=G30TH deploy
```

Reboot with BOOT0 unconnected, and it should boot up MicroPython on the REPL:
```
USB Serial device with vendor 'MicroPython' serial '348E37423533' connected @/dev/ttyACM0
Use Control-Y to exit.
MicroPython v1.5.1-184-g7c8c5d8 on 2015-12-27; G30TH with STM32F401CE
Type "help()" for more information.
>>> 
```

Now that MicroPython is installed, as long as you can get to the REPL, then you
can get back into DFU mode by using the command:
```
>>> pyb.bootloader()
```
or by connecting BOOT0 to 3.3v.

