//Joseph Schwartz-Messing
#include <Adafruit_NeoPixel.h>
#include <Bridge.h>
#include <HttpClient.h>

int btn1_pressed = 0;
int btn2_pressed = 0;
int btn1 = 9;
int btn2 = 10;
int left_button_pin = 0;
int pot_pin = A7;
int num_pixels = 1;
int pixel_pin = 8;

Adafruit_NeoPixel ring = Adafruit_NeoPixel(num_pixels, pixel_pin);

int delay_time = 1000;
int which_color = 0;
int which_site = 0;

struct Color
{
  byte red;
  byte green;
  byte blue;
  
};

Color red = {255, 0, 0};
Color orange = {255, 127, 0};
Color yellow = {255, 255, 0};
Color green = {0, 255, 0};
Color blue = {0, 0, 255};
Color indigo = {75, 0, 130};
Color violet = {139, 0, 255};

Color rainbow[] = {red, orange, yellow, green, blue, indigo, violet};

char * mySites[]={"http://babbage.cs.qc.cuny.edu/courses/cs100/2016_02/", "http://facebook.com", "http://twitter.com",
"http://blackboard.com", "http://qc.cuny.edu",};

char * output[]={" ", " ", " ", " ", " "};

void setup() { 
  pinMode(pot_pin, INPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  ring.begin();
  ring.setPixelColor(0, ring.Color(255, 0, 0));
  Bridge.begin();
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  btn1_pressed = 1 - digitalRead(btn1);
  btn2_pressed = 1 - digitalRead(btn2);
  if (btn1_pressed && btn2_pressed)
  {
    which_color = map(analogRead(pot_pin), 0, 1023, 0, 6);
    which_site = map(analogRead(pot_pin), 0, 1023, 0, sizeof(mySites)/sizeof(char *));
  }
  else if (btn1_pressed)
  {
   output[which_site] = " ";
   HttpClient client;
   client.get(mySites[which_site]); 
   while (client.available()) {
    char c = client.read();
    Serial.print(c);
    output[which_site] += c;
  }
  delay(5000);
}
 
  else if (btn2_pressed)
  {
  Serial.println(output[which_site]);
  }
  ring.setPixelColor(0, ring.Color(rainbow[which_color].red, rainbow[which_color].green, rainbow[which_color].blue));
  ring.show();
}
