#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_CNT 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_CNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}


void loop() {
  kitt(20, 150, 200, 5, 5);
}

void kitt(int red, int green, int blue, int wait, int wide) {
  uint32_t color = strip.Color(red, green, blue);
  for (int i = 0; i < LED_CNT - wide; i++) {
    strip.setPixelColor(i - 2, red / 4, green / 4, blue / 4);
    strip.setPixelColor(i - 1, red / 2, green / 2, blue / 2);
    strip.setPixelColor(i + 1 + wide, red / 4, green / 4, blue / 4);
    strip.setPixelColor(i + wide, red / 2, green / 2, blue / 2);

    for (int j = 0; j < wide; j++) {
      strip.setPixelColor(i + j, color);
    }

    strip.show();
    delay(wait);
    strip.clear();
    delay(wait);
    strip.show();
  }

  for (int i = LED_CNT; i > 0 + wide; i--) {
    strip.setPixelColor(i - 1 - wide, red / 4, green / 4, blue / 4);
    strip.setPixelColor(i - wide, red / 2, green / 2, blue / 2);
    strip.setPixelColor(i + 1, red / 2, green / 2, blue / 2);
    strip.setPixelColor(i + 2, red / 4, green / 4, blue / 4);

    for (int j = 0; j < wide; j++) {
      strip.setPixelColor(i - j, color);
    }
    
    strip.show();
    delay(wait);
    strip.clear();
    delay(wait);
    strip.show();
  }



}
