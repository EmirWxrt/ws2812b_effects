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
  multiColorTwinkle(20, 100, 0);
}

void multiColorTwinkle(int twinkleCnt, int twinkleWait, int cycleWait) {
  for (int i = 0; i < twinkleCnt; i++) {
    uint32_t color = strip.Color(random(0, 255), random(0, 255), random(0, 255));
    strip.setPixelColor(random(0, LED_CNT), color);
    strip.show();
    delay(twinkleWait);
  }
  strip.clear();
  strip.show();
  delay(cycleWait);
}
