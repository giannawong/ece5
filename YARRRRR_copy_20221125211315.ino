#include <FastLED_NeoPixel.h>

#include <Adafruit_NeoPixel.h>


int analogPin=10;
int strobePin=2;
int resetPin=4;
int spectrumValue[7];
int filter=80;

#include <Adafruit_NeoPixel.h>
#define PIN 8
#define NO_OF_LEDS 140
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NO_OF_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  
  Serial.begin(9600);
  pinMode(analogPin, INPUT);
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'  
}

void loop(){
  
  digitalWrite(resetPin, HIGH);
  digitalWrite(resetPin, LOW);
  for (int i=0;i<7;i++){
    digitalWrite(strobePin, LOW);
    delay(30);
    spectrumValue[i]=analogRead(analogPin);
    spectrumValue[i]=constrain(spectrumValue[i], filter, 1023);
    spectrumValue[i]=map(spectrumValue[i], filter,1023,0,255);
    digitalWrite(strobePin, HIGH);
  }

  
  for (int i=0;i<7;i++)
  {
    int red = 0.5*min(85,max((spectrumValue[i]-85),0));
    int green = 0.5*min(85,max((spectrumValue[i]-170),0));
    int blue = 0.5*min(85,max((spectrumValue[i]-0),0));
    Serial.print(spectrumValue[i]);
    Serial.print(" ");/*
    Serial.print("(");
    Serial.print(red);
    Serial.print(", ");    
    Serial.print(green);
    Serial.print(", ");    
    Serial.print(blue);    
    Serial.print(")");*/
    //strip.setPixelColor(3*i, strip.Color(0, 0, 0));
    //strip.setPixelColor(3*i+1, strip.Color(red, green, blue));
    //strip.setPixelColor(3*i+2, strip.Color(red, green, blue));
    //strip.setPixelColor(2*i, strip.Color(red, green, blue));
    //strip.setPixelColor(2*i+1, strip.Color(red, green, blue));
    //strip.setPixelColor(i, strip.Color(red, green, blue));
    for (int j=0;j<20;j++) {
       strip.setPixelColor(20*i+j, strip.Color(red, green, blue));
    }
  }
    Serial.println();
    strip.show();
 
}