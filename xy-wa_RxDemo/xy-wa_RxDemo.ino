/* need to set the rst, cs, pkt pin manually with any digital i/o pins
 *  if hardware serial use the default pins
 *  if software serial use the defined pins
 *  compactable with esp8266,arduino
 *  
 *  checked with arduino uno
*/
#include <SPI.h>
#include "LT8920.h"
const uint8_t PIN_NRF_RST = 6;  // Arduino Uno Pin = 6
const uint8_t PIN_NRF_CS = 5;  //Arduino Uno Pin = 5
const uint8_t PIN_NRF_PKT = 4; //Arduino Uno Pin = 4

// see arduino uno pinout for the spi pins to connect - MISO,MOSI,CLK

char sbuf[32];                                      
LT8920 lt(PIN_NRF_CS, PIN_NRF_PKT, PIN_NRF_RST);
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
  lt.writeRegister(35, 0x0F00);  //Setting the number of repeated dispatches to 255
  lt.setCurrentControl(15,15);  //Setting the power and gain of antenna signal,4bit value-0xf
  lt.setDataRate(LT8920::LT8920_1MBPS);// default baud Rate was 1MBPS
  lt.setChannel(0x6d);  // Setting the Channel (any 7bit number, transmitter and reciever should have the same)
  lt.setSyncWord(0x123A123B123C123D);  //The receiver and transmitter must be on the same channel
} 
void loop()
{
//    uint8_t data[] = { a,b,c,d,e };
//    lt.sendPacket(data,5);  //Sending the second digit in the number of words in the packet
//    Serial.print("Packet send:");  // Printing “Packet send”
//    Serial.println(a);
//    a=a+1;
//    if (a>=256)
//    {
//      a=0;
//    }
      lt.startListening();  //We switch to the reception part
      delay(1000);
//      Serial.println(lt.available());
   if (lt.available())
    {
      uint8_t buf[32];
      int packetSize = lt.read(buf, 32);
      if (packetSize > 0)
      {
        Serial.println(F("Packet read OK")); // If packet received print “Packet read OK”
        for(int i = 0; i < packetSize; i++)
        {
          Serial.print(i);
          Serial.print("=");
          Serial.println(buf[i]);
        }
      }
   }
     else
      {
        Serial.println(F("Packet read --"));
      }
}
