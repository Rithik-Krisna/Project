# XY_WA-2.4G-Type-A---Wireless-Transceiver-Module
Contains the source code of all projects done by me...

I used Node Mcu For transmitting data and anduino uno for recieving the data.

You can test your XY-WA 2.4G Type A - Wireless Transceiver Modules with these code

For More details Go to saiinnovation.com

First install the lt8910 library in your arduino ide
https://github.com/MINI-Qiang/LT8910


Pin connections

Transmitter ( Connection between NodeMCU, XY-WA 2.4G Type A - Wireless Transceiver Modules )
XY-WA     NodeMCU

RST       D1
SPI_CLK   D5
SPI_SS    D8
SPI_MOSI  D7

SPI_MISO  D6
PKT       D2
GND       GND
3.3v      3.3v



Reciever ( Connection between Arduino UNO, XY-WA 2.4G Type A - Wireless Transceiver Modules )
XY-WA     Arduino Uno

RST       6
SPI_CLK   13
SPI_SS    5
SPI_MOSI  11

SPI_MISO  12
PKT       4
GND       GND
3.3v      3.3v


Note: Rf module Pins are not 5v Tolerance so for safety use logic level shifter while using with arduino uno or any simple voltage divider

Reference :
Datasheet - https://components101.com/sites/default/files/component_datasheet/XY-WA-Module-Datasheet.pdf
Coding - https://circuitdigest.com/microcontroller-projects/small-size-radio-frequency-module-for-long-range-communication-xy-wa-interface-with-arduino
Module reference - https://components101.com/modules/xy-wa-wireless-transceiver-module-pinout-features-datasheet
Buying Link - https://robu.in/product/xy-wa-2-4g-wireless-transceiver-module-anti-interference-3-3v-low-power-ultra-24l01-type-a/
