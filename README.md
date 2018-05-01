These are MicroPython board definition files for the PYFLEX_F401 from kitmatic.com.  Although derived from dhylands/G30TH, they are now a different platform jgriessen/PYFLEX_F401.  To use this repository, first choose a directory where you can put the micropython repo, and the culture shock repo side by side. 
git clone https://github.com/micropython/micropython.git
Next,
cd micropython/ports/stm32/boards
git clone https://github.com/jgriessen/PYFLEX_F401.git
then go back to the base dir above where you cloned micropython and,
git clone https://github.com/kanzure/culture_shock.git

A minimal "howto" follows, more READMEs and documentation can be found among the different directories in the repo, and blog posts on this project can be found here:  http://blog.kitmatic.com/...

The PYFLEX_F401 has the STM32F401CE MCU, voltage converters from USB 5V up to 18VDC and from USB 5V down to lithium iron phosphate battery charging volts between 2.4 and 3.4VDC,2 20 pin flat flex connectors to get to the GPIOs, ADCs, battery and com ports of the MCU, a microUSB C connector for charging, a microUSB AB connector for development and data logging data transfer.  A 2-wire I2C port can be used with OLED and LCD displays.

To build the micropython firmware:
```
cd culture_shock/code_PYFLEX_F401
./make_PYFLEX_F401.py --clean
./make_PYFLEX_F401.py 
```
After the above finishes, it will probably report "Not in DFU mode, no board found"
To get the device in DFU mode, you need to press SW23, at the top of the pyflex_f401 board, (BOOT0 to 3V3), before and during applying power or resetting, (SW22).

Once in DFU mode, you should be able to use the command 
```
dfu-util --list
```
from your computer that is connected by USB cable to the culture_shock, and see something like this:

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

Reboot with BOOT0 unconnected, (SW23 not pressed), and it should boot up MicroPython on the REPL.  Use a terminal program such as screen, or rshell to connect to /dev/tty ACM0.  The rshell program needs the additional command, 
```
repl
```
to get to the python prompt:
```
USB Serial device with vendor 'MicroPython' serial '377A364D3234' connected @/dev/ttyACM0
Use Control-X to exit.
MicroPython v1.8.2-13-g08eac74 on 2016-07-14; G30TH with STM32F401CE
Type "help()" for more information.
>>> 
```

Now that MicroPython is installed and running the REPL, you
can get into DFU mode, (to load a new micropython), by using the command:
```
>>> pyb.bootloader()
```
or using thw switches as above.  To run programs, you won't need to compile again 
until you run into a need for more speed, or use up your code storage space on flash.
