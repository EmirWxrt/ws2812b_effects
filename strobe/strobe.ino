#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_CNT 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_CNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {

  strobe(strip.Color(255, 0, 0), 10, 25, 1000);

}

void strobe(uint32_t color, int flashCnt, int flashWait, int cycleWait) {

  for (int i = 0; i < flashCnt; i++) {
    strip.fill(color, 0, LED_CNT);
    strip.show();
    delay(flashWait);
    strip.clear();
    strip.show();
    delay(flashWait);
  }
  delay(cycleWait);

}
