#include <Adafruit_NeoPixel.h>

#define PIN 5
#define NUMPIXELS 17

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 500;

void setup() {
  // put your setup code here, to run once:
  Particle.function("flash", flashTopLed);
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(150, 150, 150));
    pixels.show();
    delay(70);
  }
  for (int j=0; j<NUMPIXELS; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 0));
    pixels.show();
    delay(70);
  }
  delay(100);
}

int flashTopLed(String command) {
  //if(command == "red") {
    pixels.setPixelColor(16, pixels.Color(255, 0, 0));
    pixels.show();
    delay(1000);
    return 1;
  //}
}

