#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_CNT 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_CNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  runningLight(200, 0, 100, 0);
}

void runningLight(int red, int green, int blue, int waveDelay) {
  int pos = 0;

  for (int i = 0; i < LED_CNT * 2; i++)
  {
    pos++;
    for (int j = 0; j < LED_CNT; j++) {
      strip.setPixelColor(j, ((sin(j + pos) * 127 + 128) / 255) * red,
                          ((sin(j + pos) * 127 + 128) / 255) * green,
                          ((sin(j + pos) * 127 + 128) / 255) * blue);
    }
    strip.show();
    delay(waveDelay);
  }
}
