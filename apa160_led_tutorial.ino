#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN            6
#define NUMPIXELS      1
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  pixels.begin();
}

void loop() {

  //hue from 0 to 360 degrees
  for(int hue = 0; hue < 360; hue++) {

    // saturation and value = 1
    setLedColorHSV(hue, 1, 1); 
    delay(50);
  }
}

// thanks to http://forum.arduino.cc/index.php?topic=307655.5
void setLedColorHSV(int h, double s, double v) {

  double r=0; 
  double g=0; 
  double b=0;
  double hf=h/60.0;

  int i=(int)floor(h/60.0);
  double f = h/60.0 - i;
  double pv = v * (1 - s);
  double qv = v * (1 - s*f);
  double tv = v * (1 - s * (1 - f));

  switch (i)
  {
  case 0:
    r = v;
    g = tv;
    b = pv;
    break;
  case 1:
    r = qv;
    g = v;
    b = pv;
    break;
  case 2: 
    r = pv;
    g = v;
    b = tv;
    break;
  case 3:
    r = pv;
    g = qv;
    b = v;
    break;
  case 4:
    r = tv;
    g = pv;
    b = v;
    break;
  case 5:
    r = v;
    g = pv;
    b = qv;
    break;
  }

  //set each component to a integer value between 0 and 255
  int red = constrain((int)255*r,0,255);
  int green = constrain((int)255*g,0,255);
  int blue = constrain((int)255*b,0,255);

  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.show();
}
