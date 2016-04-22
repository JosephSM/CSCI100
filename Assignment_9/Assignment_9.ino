//Joseph Schwartz-Messing
//include neopixel library
#include <Adafruit_NeoPixel.h>
int btn1_pressed = 0;
int btn2_pressed = 0;
int btn1 = 9;
int btn2 = 10;
int left_button_pin = 0;
int pot_pin = A7;
int num_pixels = 1;
int pixel_pin = 8;
//define a new neopixel by by specifying the pin number and number of pixels.
//in this case its only one pixel which is on the flora on pin 8.  We name this var "ring"
Adafruit_NeoPixel ring = Adafruit_NeoPixel(num_pixels, pixel_pin);
//delay_time will represent the amount of delay in milliseconds.
int delay_time = 1000;
//intensity will represent the intensity(brightness) of the color by displaying 0-100% of the values defined in our Color objects.
float intensity = 1.0;
//which_color represents an index in the rainbow array from 0-6.
int which_color = 0;

//struct is a constructor which allows us to easily create new objects.
// our Color object contains three byte variables with the names red, green, and blue.
struct Color
{
  byte red;
  byte green;
  byte blue;
};
//below are a list of new color objects with numbers assigned to red, green and blue.  
Color red = {255, 0, 0};
Color orange = {255, 127, 0};
Color yellow = {255, 255, 0};
Color green = {0, 255, 0};
Color blue = {0, 0, 255};
Color indigo = {75, 0, 130};
Color violet = {139, 0, 255};
//rainbow is a 7 index array that contains the above colors.
Color rainbow[] = {red, orange, yellow, green, blue, indigo, violet};
void setup() {
  //pins are described here as inputs, outputs or input pullups.
  pinMode(pot_pin, INPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  //begin must be called to initiate the ring
  ring.begin();
  // We want the pixel color to begin as red until being changed in the loop
  ring.setPixelColor(0, ring.Color(255, 0, 0));
}

void loop() {
  //Because 1 represents true and 0 represents false, we want the buttons to respond accordingly however input pullups are on at 0 and off at not-0. The following statements correct this issue.
  btn1_pressed = 1 - digitalRead(btn1);
  btn2_pressed = 1 - digitalRead(btn2);
  //if both buttons are pressed...
  if (btn1_pressed && btn2_pressed)
  {
    //...which_color will be assigned a value from 0-6 depending on our potentiometer value.  
    //The map function allows us to map a range of values, in this case 0-1023 to another range of values 0-6.
    //The first argument(analogRead(pot_pin)) represents a value in the first range being scaled to the second range.
    which_color = map(analogRead(pot_pin), 0, 1023, 0, 6);
  }
  //if button 1 is pressed then delay_time will be changed to a value ranging from 0-1023
  else if (btn1_pressed)
  {
    delay_time = analogRead(pot_pin);
  }
  //if button 2 is pressed then intensity will be changed from some x between 0-1023 inclusive depending on the change in the pot movement such that intensity = x/1024.
  else if (btn2_pressed)
  {
    intensity = analogRead(pot_pin) / 1024.0;
  }
  //setPixelColor will display on our only neopixel i.e. index 0, red, green, and blue values of a Color in the rainbow array whose index is specified by the value of which_color. 
  //These values will be shown at an intensity from 0-100%.
  //Starting value will be red as shown in the setup function i.e. (ring.setPixelColor(0, ring.Color(255, 0, 0)). Starting intensity will be 1 or 100%.  
  ring.setPixelColor(0, ring.Color(rainbow[which_color].red * intensity, rainbow[which_color].green * intensity, rainbow[which_color].blue * intensity));
  ring.show();
  //delay for the number of milliseconds that the variable "delay_time" represents.  Starting value is 1000.
  delay(delay_time);
  ring.setPixelColor(0, ring.Color(0, 0, 0));
  ring.show();
  delay(delay_time);
}
