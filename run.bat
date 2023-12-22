@echo off
cls

set ARDUINO_PATH="D:\Code\IoT\HomeOs\untralsonicSensor_19-12-23\UntralsonicSensor\src" 
set ARDUINO_MODEL=9600
set COM_PORT=COM8

%ARDUINO_PATH%\hardware\tools\avr\bin\avrdude -C%ARDUINO_PATH%\hardware\tools\avr\etc\avrdude.conf -v -patmega328p -carduino -P%COM_PORT% -b115200 -D -Uflash:w:%1:i
