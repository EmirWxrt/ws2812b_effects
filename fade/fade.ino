#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_CNT 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_CNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  //red
  fade(0, 255, 0, 0);
  //green
  fade(0, 0, 255, 0);
  //blue
  fade(0, 0, 0, 255);
  //purple
  fade(0, 255, 0, 255);
  //turquise
  fade(0, 0, 255, 255);
  //yellow
  fade(0, 255, 255, 0);
  //white
  fade(0, 255, 255, 255);
  //random
  fade(0, random(2, 255), random(2, 255), random(2, 255));
}

/*
   Passing 1 for red, green or blue may produce unexspected results,
   use 2 or 0 instead. The result should look the same.
*/
void fade(int wait, int red, int green, int blue) {
  float r, g, b;
  for (int i = 0; i < 255; i++) {
    /*
       Normalize the current value and multiple them by the given
       colorvalue to keep the ratio.
    */
    r = (i / 255.0) * red;
    g = (i / 255.0) * green;
    b = (i / 255.0) * blue;

    uint32_t color = strip.Color(r, g, b);
    strip.fill(color, 0, LED_CNT);
    strip.show();
    delay(wait);

    /*
       If a channel reaches 255 the loop breaks, because 255 is
       the max value and the ratio can't keep beyond this point.
    */
    if (r == 255 || b == 255 || b == 255) {
      break;
    }
  }
  for (int i = 255; i > 0; i--) {
    r = (i / 255.0) * red;
    g = (i / 255.0) * green;
    b = (i / 255.0) * blue;

    uint32_t color = strip.Color(r, g, b);
    strip.fill(color, 0, LED_CNT);
    strip.show();
    delay(wait);

    /*
       Checking for 1 is a workarround to make this work.
       Checking for 0 will produce a break everytime this loop is called
       when one channel of the color is 0. In this case reducing the
       brighness will be skipped. 1 is also not visible and pretty uncommon
       to use for color values.
    */
    if (r == 1 || b == 1 || b == 1) {
      break;
    }
  }
}
