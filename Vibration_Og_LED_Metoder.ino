#include <FastLED.h>
#define NUM_LEDS 7
#define DATA_PIN 6

int vibPin1 = 8;
int vibPin2 = A2;

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(vibPin1, OUTPUT);
  pinMode(vibPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  heartBeat();
  delay(1000);
  left();
  delay(1000);
  right();
  delay(1000);
  friendLED();
  delay(1000);
}

void heartBeat() {
    // leds[0] = CRGB::Red;
    turnLEDOn(3, 255, 0, 0);
    FastLED.show();
    delay(10);    
    vibrateHigh(vibPin1, vibPin2);
    delay(200);
    // leds[0] = CRGB(0,0,0);
    FastLED.show();
    delay(10);
    vibrateLow(vibPin1, vibPin2);
    delay(100);
    // leds[0] = CRGB::Red;
    turnLEDOn(7, 255, 0, 0);
    FastLED.show();
    delay(10);
    vibrateHigh(vibPin1, vibPin2);
    delay(200);
    // leds[0] = CRGB(0,0,0);
    turnLEDOn(7, 0, 0, 0);
    FastLED.show();
    vibrateLow(vibPin1, vibPin2);
    delay(1000);
    delay(10);
  }

void right() {
    vibrateHigh(vibPin1, vibPin2);
    // leds[0] = CRGB::Red;
    for(int i = 0; i < 1; i++) {
        leds[i] = CRGB::Red;
      }
    FastLED.show();
    delay(10); 
    delay(1000);
    vibrateLow(vibPin1, vibPin2);
    for(int i = 0; i < 1; i++) {
        leds[i] = CRGB::Black;
      }
    FastLED.show();
    delay(10); 
  }

void left() {
    // leds[0] = CRGB::Red;
    turnLEDOn(2, 255, 0, 0);
    FastLED.show();
    delay(10); 
    vibrateHigh(vibPin1, vibPin2);
    delay(1000);
    // leds[0] = CRGB::Black;
    turnLEDOn(2, 0, 0, 0);
    FastLED.show();
    delay(10); 
    vibrateLow(vibPin1, vibPin2);
    delay(500);
    // leds[0] = CRGB::Red;
    turnLEDOn(2, 255, 0, 0);
    FastLED.show();
    delay(10); 
    vibrateHigh(vibPin1, vibPin2);
    delay(1000);
    // leds[0] = CRGB::Black;
    turnLEDOn(2, 0, 0, 0);
    FastLED.show();
    delay(10); 
    vibrateLow(vibPin1, vibPin2);
  }

void behind() {
    int delayTime = /*getDistance*/ 1 * 100;
    leds[0] = CRGB::Red;
    FastLED.show();
    delay(10); 
    vibrateHigh(vibPin1, vibPin2);
    delay(delayTime);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(10); 
    vibrateLow(vibPin1, vibPin2);
    delay(delayTime);
  }


void friendLED() {
    leds[0] = CRGB(255, 0, 0);
    FastLED.show();
    delay(500);
    leds[1] = CRGB(255, 5, 40);
    FastLED.show();
    delay(500);
    leds[2] = CRGB(255, 10, 80);
    FastLED.show();
    delay(500);
    leds[3] = CRGB(255, 15, 120);
    FastLED.show();
    delay(500);
    leds[4] = CRGB(255, 20, 160);
    FastLED.show();
    delay(500);
    leds[5] = CRGB(255, 25, 200);
    FastLED.show();
    delay(500);
    leds[6] = CRGB(255, 30, 240);
    FastLED.show();
    delay(500);
    turnLEDOn(7, 0, 0, 0);
  }

void turnLEDOn(int numOfLED, int r, int g, int b) {
    for(int i = 0; i < numOfLED; i++) {
        leds[i] = CRGB(r, g, b);
      }

}
void LEDSlow(int delayTime, int numOfLED, int r, int g, int b) {
    for(int i = 0; i < numOfLED; i++) {
        leds[i] = CRGB(r, g, b);
        delay(delayTime);
      }
  }



void vibrateHigh(int vib1, int vib2) {
    digitalWrite(vib1, HIGH);
    digitalWrite(vib2, HIGH);
  }

void vibrateLow(int vib1, int vib2) {
    digitalWrite(vib1, LOW);
    digitalWrite(vib2, LOW);
  }
