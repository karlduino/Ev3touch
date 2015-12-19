// Use lego EV3 touch sensor as toggle for LED
//
// Using bricktronics ev3 breakout
// connect 6 to arduino pin 12
// connect 4 to ground
// (this is backwards from what I expected)

const int button = 12;
const int led = 8;
int led_state = 0;
int but_state = 1;
int prev_but_state = 1;

void setup() {
  pinMode(13, OUTPUT); digitalWrite(13, LOW);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(115200);
}

void loop() {
  but_state = digitalRead(button);
  if(but_state==LOW & but_state != prev_but_state) {
    delay(50);
    but_state = digitalRead(button);
    if(but_state==LOW) led_state = 1 - led_state;
  }
  prev_but_state = but_state;

  digitalWrite(led, led_state);
}
