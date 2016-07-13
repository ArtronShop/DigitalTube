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

