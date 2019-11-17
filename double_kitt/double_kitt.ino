#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_CNT 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_CNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  doubleKitt(200, 0, 120, 5, 5);

}

void doubleKitt(int red, int green, int blue, int wait, int wide) {
  int j = LED_CNT;
  for (int i = 0; i < (LED_CNT / 2) - wide -2; i++) {
    j = LED_CNT - i;

    strip.setPixelColor(i - 2, red / 4, green / 4, blue / 4);
    strip.setPixelColor(i - 1, red / 2, green / 2, blue / 2);
    strip.setPixelColor(i + 1 + wide, red / 4, green / 4, blue / 4);
    strip.setPixelColor(i + wide, red / 2, green / 2, blue / 2);
    strip.setPixelColor(j - 2, red / 4, green / 4, blue / 4);
    strip.setPixelColor(j - 1, red / 2, green / 2, blue / 2);
    strip.setPixelColor(j + 1 + wide, red / 4, green / 4, blue / 4);
    strip.setPixelColor(j + wide, red / 2, green / 2, blue / 2);

    for (int k = 0; k < wide; k++) {
      strip.setPixelColor(i + k, red, green, blue);
      strip.setPixelColor(j + k, red, green, blue);
    }

    strip.show();
    delay(wait);
    strip.clear();
    delay(wait);
    strip.show();
  }
  for (int i = LED_CNT / 2; i > 0 + wide + 2; i--) {
    j = LED_CNT - i;

    strip.setPixelColor(j - 2, red / 4, green / 4, blue / 4);
    strip.setPixelColor(j - 1, red / 2, green / 2, blue / 2);
    strip.setPixelColor(j + 1 + wide, red / 4, green / 4, blue / 4);
    strip.setPixelColor(j + wide, red / 2, green / 2, blue / 2);
    strip.setPixelColor(i - 2, red / 4, green / 4, blue / 4);
    strip.setPixelColor(i - 1, red / 2, green / 2, blue / 2);
    strip.setPixelColor(i + 1 + wide, red / 4, green / 4, blue / 4);
    strip.setPixelColor(i + wide, red / 2, green / 2, blue / 2);

    for (int k = 0; k < wide; k++) {
      strip.setPixelColor(i + k, red, green, blue);
      strip.setPixelColor(j + k, red, green, blue);
    }

    strip.show();
    delay(wait);
    strip.clear();
    delay(wait);
    strip.show();
  }
}
