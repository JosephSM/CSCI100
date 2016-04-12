//Joseph Schwartz-Messing
//Programming neopixel on flora to run through colors of the rainbow
//include the neopixel library for added functions i.e. "Adafruit_Neopixel()"
#include <Adafruit_NeoPixel.h>
//set global var for number of pixels, in this case theres only one neopixel on the flora
//set pin to 8
int num_pixels = 1;
int pixel_pin  = 8;
Adafruit_NeoPixel ring = Adafruit_NeoPixel(num_pixels, pixel_pin);


void setup() {
  //initialize the ring object, set its color, and show red.
  ring.begin();
  ring.setPixelColor(0, ring.Color(255, 0, 0));
  ring.show();

}

void loop() {
  // delay 1 second, set new color and show.
  //process repeated for 7 colors of the rainbow
  delay(1000);
  ring.setPixelColor(0, ring.Color(255,127,0));
  ring.show();
  delay(1000);
  ring.setPixelColor(0, ring.Color(255,255,0));
  ring.show();
  delay(1000);
  ring.setPixelColor(0, ring.Color(0,255,0));
  ring.show();
  delay(1000);
  ring.setPixelColor(0, ring.Color(0,0,255));
  ring.show();
  delay(1000);
  ring.setPixelColor(0, ring.Color(75,0,130));
  ring.show();
  delay(1000);
  ring.setPixelColor(0, ring.Color(139,0,255));
  ring.show();
  delay(1000);
  ring.setPixelColor(0, ring.Color(255,0,0));
  ring.show();
  

}
