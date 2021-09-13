#include "FastLED.h"

#define NUM_LEDS 70 //设置灯带的长度

#define DATA_PIN 3 

CRGB leds[NUM_LEDS]; //建立光带leds, 色彩空间为RGB

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS); //仅有初始化作用，并不会改变上一次编程结果
  FastLED.setBrightness(50); //设置灯的亮度，最大为255
  fill_solid(leds, 70, CRGB::CadetBlue); //设置所有灯泡为红色
  FastLED.show(); //同步更新
}

void loop() {

}