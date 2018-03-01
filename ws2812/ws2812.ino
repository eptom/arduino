#include <Adafruit_NeoPixel.h>

#define PIN 10

#define NUM_LEDS 16

#define BRIGHTNESS 10

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

int delayval = 70; // delay for half a second

void setup() {
  pixels.setBrightness(BRIGHTNESS);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for (int i = 0; i < NUM_LEDS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255, 100, 0)); //yellow

    loopLeds(i,6);



    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }

  //brighten();
  //darker();

  //  pixels.clear();
  //  pixels.show();

  //  delay(2000);
  //  pixels.setBrightness(BRIGHTNESS);
}

void loopLeds(int i,int numLedsOn) {
  if ( i > numLedsOn - 1 ) {
    pixels.setPixelColor(i - numLedsOn, 0); //turn off led
  } else {
    pixels.setPixelColor(NUM_LEDS - numLedsOn + i, 0); //turn off led
  }
}
void brighten() {
  int brightness = pixels.getBrightness();
  for (int i = brightness; i < 100; i++) {
    // always call setPixelColor before update brightness
    for (int j = 0; j < pixels.numPixels(); j++) {
      pixels.setPixelColor(j, pixels.Color(255, 100, 0)); //yellow
    }
    pixels.setBrightness(i);
    pixels.show();
    delay(20);
  }
}


void darker() {
  for (int i = 99; i > BRIGHTNESS; --i) {
    for (int j = 0; j < pixels.numPixels(); j++) {
      pixels.setPixelColor(j, pixels.Color(255, 100, 0)); //yellow
    }
    pixels.setBrightness(i);
    pixels.show();
    delay(20);
  }
}



