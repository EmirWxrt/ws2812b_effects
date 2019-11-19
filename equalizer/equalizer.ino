#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_CNT 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_CNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  rainbowEqualizer(random(0,LED_CNT));
}

void equalizer(int pos, uint32_t color) {
  strip.fill(color, 0, pos - 1);
  strip.show();
  for (int i = pos; i > 0; i--) {
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
  strip.clear();
}

void rainbowEqualizer(int pos) {
  for (int i = 0; i < pos; i++) {
    strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(i * 65536 / LED_CNT, 255, 100)));
  }
  strip.show();
  for (int i = pos; i > 0; i--) {
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
  strip.clear();
}
