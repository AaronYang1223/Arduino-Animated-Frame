#include "FastLED.h"
#include <Servo.h>

#define NUM_LEDS 70 //设置灯带的长度

#define DATA_PIN 3 //设置在Arduino上的串口

CRGB leds[NUM_LEDS]; //建立光带leds, 色彩空间为RGB

int ledNum; //记录灯串的数目

//每帧动画
int black[] = {0, 1, 2, 3, 7, 8, 14, 15, 22, 23, 30, 31, 38, 39, 46, 47, 54, 55, 61, 62, 66, 67, 68, 69}; //24
int ROW1[] = {13, 16, 48, 60}; //4
int ROW2[] = {4, 12, 17, 29, 45, 49, 59, 63}; //8
int ROW3[] = {5, 11, 18, 28, 32, 44, 50, 58, 64}; //9
int ROW4[] = {6, 10, 19, 27, 33, 43, 51, 57, 65}; //9
int ROW5[] = {9, 20, 26, 34, 42, 52, 56}; //7
int ROW6[] = {21, 25, 35, 41, 53}; //5
int ROW7[] = {24, 36, 40}; //3
int ROW8[] = {37}; //1

CRGB myRGBcolor(0,0,0); //用来赋值 

//色彩表
int PINK[] = {255, 64, 64};
int DeepSkyBlue2[] = {0, 178, 238};

//得到每个part1的灯串个数
template<class T,size_t N>
int Length(T (&array)[N]){
    // 用于debug
    // Serial.print("A1:");
    // Serial.println(sizeof(array));
    // Serial.print("A2:");
    // Serial.println(sizeof(T));
    // Serial.print("R:");
    // Serial.println(sizeof(array) / sizeof(T));    
    return sizeof(array) / sizeof(T);
}

//点亮对应灯串：
void OnLightsOrder_1(int* array, int ledNum, int* RGB){
      for (int i = 0; i < ledNum; i++){
        leds[array[i]] = myRGBcolor.r = RGB[0];
        Serial.print("R:");
        Serial.println(RGB[0]);
        leds[array[i]] = myRGBcolor.g = RGB[1];
        Serial.print("G:");
        Serial.println(RGB[1]);
        leds[array[i]] = myRGBcolor.b = RGB[2];
        Serial.print("B:");
        Serial.println(RGB[2]);
        leds[array[i]] = myRGBcolor;
        FastLED.show();
        delay(100);
    } 
}

void OnLightsOrder_2(int* array, int ledNum, int* RGB){
      for (int i = ledNum - 1; i >= 0; i--){
        leds[array[i]] = myRGBcolor.r = RGB[0];
        Serial.print("R:");
        Serial.println(RGB[0]);
        leds[array[i]] = myRGBcolor.g = RGB[1];
        Serial.print("G:");
        Serial.println(RGB[1]);
        leds[array[i]] = myRGBcolor.b = RGB[2];
        Serial.print("B:");
        Serial.println(RGB[2]);
        leds[array[i]] = myRGBcolor;
        FastLED.show();
        delay(100);
    } 
}

void setup() {
  Serial.begin(9600); //初始化波特率
  Serial.println("Get Start!");  
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS); //仅有初始化作用，并不会改变上一次编程结果
  FastLED.setBrightness(50); //设置灯的亮度，最大为255
  //FastLED.clear(); //熄灭所有的灯带，目前该library有点小问题，可能是刷新率的原因
  //+=========PART1==========+
  fill_solid(leds, NUM_LEDS, CRGB::Black); //熄灭所有的灯带
  Serial.println("Done!");  
}

void loop() {
  //on black part
  ledNum = ::Length(black);
  OnLightsOrder_2(black, ledNum, DeepSkyBlue2);

  //on red part
  ledNum = ::Length(ROW1);
  OnLightsOrder_2(ROW1, ledNum, PINK);

  ledNum = ::Length(ROW2);
  OnLightsOrder_2(ROW2, ledNum, PINK);

  ledNum = ::Length(ROW3);
  OnLightsOrder_2(ROW3, ledNum, PINK);

  ledNum = ::Length(ROW4);
  OnLightsOrder_2(ROW4, ledNum, PINK);

  ledNum = ::Length(ROW5);
  OnLightsOrder_2(ROW5, ledNum, PINK);

  ledNum = ::Length(ROW6);
  OnLightsOrder_2(ROW6, ledNum, PINK);

  ledNum = ::Length(ROW7);
  OnLightsOrder_2(ROW7, ledNum, PINK);

  ledNum = ::Length(ROW8);
  OnLightsOrder_2(ROW8, ledNum, PINK);
}
