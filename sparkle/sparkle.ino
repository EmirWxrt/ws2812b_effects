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
  sparkle(strip.Color(255, 50, 50), 50);

}

void sparkle(uint32_t color, int wait){
  strip.setPixelColor(random(0, LED_CNT), color);
  strip.show();
  delay(wait);
  strip.clear();
  strip.show();
  delay(wait);
}
