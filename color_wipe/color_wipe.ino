#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_CNT 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_CNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  baseColorWipe(10);
}

void colorWipe(int wait, uint32_t color) {
  for (int i = 0; i < LED_CNT; i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

void baseColorWipe(int wait) {
  colorWipe(wait, strip.Color(255, 0, 0));
  colorWipe(wait, strip.Color(0, 255, 0));
  colorWipe(wait, strip.Color(0, 0, 255));
  colorWipe(wait, strip.Color(255, 255, 0));
  colorWipe(wait, strip.Color(0, 255, 255));
  colorWipe(wait, strip.Color(255, 0, 255));
}
