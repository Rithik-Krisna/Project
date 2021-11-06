/* need to set the rst, cs, pkt pin manually with any digital i/o pins
 *  if hardware serial use the default pins
 *  if software serial use the defined pins
 *  compactable with esp8266,arduino
 *  
 *  checked with nodemcu-esp8266
*/
#include <SPI.h>
#include "LT8920.h"

const uint8_t PIN_NRF_RST = D1;
const uint8_t PIN_NRF_CS = D8;
const uint8_t PIN_NRF_PKT = D2;

// see nodemcu pinout for the spi pins to connect - MISO,MOSI,CLK

LT8920 lt(PIN_NRF_CS, PIN_NRF_PKT, PIN_NRF_RST);

uint8_t number = 0;
uint8_t a = 0;   //+1 with every packet recieved
uint8_t b = 105;    //Change from 0 to 255 in receiver and put other numbers
uint8_t c = 218;   //Check signal
uint8_t d = 53;   //reception / transmission
uint8_t e = 95;
void setup()
{
 Serial.begin(9600);
  SPI.begin();
  SPI.beginTransaction(SPISettings(12000000, MSBFIRST, SPI_MODE1));
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  lt.begin();
//  lt.writeRegister(35, 0x0F00);  //Setting the number of repeated dispatches to 255
  lt.setCurrentControl(15,15);  //Setting the power and gain of antenna signal,4bit value-0xf
  lt.setDataRate(LT8920::LT8920_1MBPS); // default baud Rate was 1MBPSa
  lt.setChannel(0x6d);  // Setting the Channel
  lt.setSyncWord(0x123A123B123C123D); 
}

void loop()
{
	delay(100);
	 uint8_t data[] = { a,b,c,d,e };
    lt.sendPacket(data,5);  //Sending the second digit in the number of words in the packet
    Serial.print("Packet send:");  // Printing “Packet send”
    Serial.println(a);
    a=a+1;
    if (a>=256)
    {
      a=0;
    }
}
