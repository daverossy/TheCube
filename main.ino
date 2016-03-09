#include <Adafruit_NeoPixel.h>

// Constants
const int inPin = 4;

// Variables
int val = LOW;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 6, NEO_GRB + NEO_KHZ800);

// Setup
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  pinMode(inPin, INPUT);
}

// Main code to run in loop
void loop() {
  val = digitalRead(inPin); //check input pin
  if (val == HIGH) {
    colourCycle();
  } else {
    strip.setPixelColor(0, 0, 0, 255);
    strip.show();
    delay(1000);
    strip.setPixelColor(0, 0, 0, 0);
    strip.show();
    delay(1000);
  } 
}

void colourCycle() {
  int i = 0;
  for(i=0; i<256; i++) {
    strip.setPixelColor(0, i, (255-i), 0);
    strip.show();
    delay(118);
    }
}

