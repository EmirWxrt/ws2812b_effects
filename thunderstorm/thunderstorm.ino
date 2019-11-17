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
  thunderstorm();
}

void thunderstorm() {
  //Number of flashes for each loop
  int flashCnt = random(3, 15);

  //Brightness range for each individuell flash
  int minBrightness = 10;
  int maxBrightness = 255;

  //Duration range for each individuell flash
  int minDuration = 1;
  int maxDuration = 50;

  //Delay between each flash in one loop
  int minDelay = 1;
  int maxDelay = 150;

  int loopDelay = random(3000, 30000 / 2);  //Delay after one loop

  for (int flash = 0; flash <= flashCnt; flash++) {
    int brightness = random(minBrightness, maxBrightness);
    strip.fill(strip.Color(brightness, brightness, brightness), 0, LED_CNT);
    strip.show();
    delay(random(minDelay, maxDelay));
    strip.clear();
    strip.show();
    delay(random(minDelay, maxDelay));
  }
  delay(loopDelay);
}
