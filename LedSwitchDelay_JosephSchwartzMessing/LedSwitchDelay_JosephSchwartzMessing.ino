// Joseph Schwartz-Messing
//Switching LED on and off with delays.

int led_pin = 7;
int switch_pin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(led_pin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int switch_state = digitalRead(switch_pin);
  if(switch_state)
  {
    delay(1000);
    digitalWrite(led_pin, HIGH);
  }
  else
  {
    delay(2000);
    digitalWrite(led_pin, LOW);
  }
}
