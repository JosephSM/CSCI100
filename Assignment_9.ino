//Joseph Schwartz- Messing
#include <Adafruit_NeoPixel.h>
int btn1_pressed = 0;
int btn1 = 9;
int btn2 = 10;
int pot_pin = A7;
int num_pixels = 1;
int pixel_pin = 8;
Adafruit_NeoPixel ring = Adafruit_NeoPixel(num_pixels, pixel_pin);
int delay_time = 1000;
struct Color
{
  byte red;
  byte green;
  byte blue;
};

Color red;

void setup() {
  pinMode(pot_pin, INPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  ring.begin();
}

void loop() {
  btn1_pressed = 1 - digitalRead(btn1);
  if (btn1_pressed)
  {
    delay_time = analogRead(pot_pin);
  }
  ring.setPixelColor(0, ring.Color(255, 0, 0));
  ring.show();
  delay(delay_time);
  ring.setPixelColor(0, ring.Color(0, 0, 0));
  ring.show();
  delay(delay_time);
}
