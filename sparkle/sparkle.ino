#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_CNT 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_CNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  randomSeed(42);
}

void loop() {
  multiColorSparkle(25, 100);
}

void sparkle(uint32_t color, int wait, int cycle) {
  for (int i = 0; i < cycle; i++) {
    strip.setPixelColor(random(0, LED_CNT), color);
    strip.show();
    delay(wait);
    strip.clear();
    strip.show();
    delay(wait);
  }
}

void multiColorSparkle(int wait, int cycle) {
  for (int i = 0; i < cycle; i++) {
    uint32_t color = strip.Color(random(0, 255), random(0, 255), random(0, 255));
    sparkle(color, 25, 1);
  }
}
