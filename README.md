# DigitalTube
Library for 4-Bit Digital Tube Module, show text or number to display

![](https://image.ibb.co/ghk1qv/IMG20170605224159_Medium.jpg)

## Support device
 * Arduino Uno R3
 * Arduino Mega 2560
 * Arduino Nano
 * Arduino Pro Mini 5V and 3.3V
 * ESP8266
 * ESP32
 
 ## Example
 
 ```Arduino
 /*
 * Written by IOXhop : www.ioxhop.com
 * Author : Sonthaya Nongnuch (www.fb.me/maxthai)
 */

#include <DigitalTube.h>

// DigitalTube::DigitalTube(int sclk, int rclk, int dio)
DigitalTube dis(4, 5, 6);

void setup() {
  dis.begin();
}

void loop() {
  // Show text
  dis.show(' ', ' ', ' ', ' ');
  delay(500);
  dis.show(' ', ' ', ' ', 'H');
  delay(500);
  dis.show(' ', ' ', 'H', 'e');
  delay(500);
  dis.show(' ', 'H', 'e', 'l');
  delay(500);
  dis.show('H', 'e', 'l', 'l');
  delay(500);
  dis.show('e', 'l', 'l', 'o');
  delay(500);
  dis.show('l', 'l', 'o', ' ');
  delay(500);
  dis.show('l', 'o', ' ', ' ');
  delay(500);
  dis.show('o', ' ', ' ', ' ');
  delay(500);
  dis.show(' ', ' ', ' ', ' ');
  delay(500);

  for (int i=9;i>0;i--) {
    dis.print(i); // Show 'i' to display
    delay(500);
  }

  dis.show('S', 'T', 'O', 'P');
  delay(2000);
}
```
 
 ## License
This library open source. Copied, distributed for free
 * http://www.ioxhop.com/
