#include "FastLED.h"            // 此示例程序需要使用FastLED库
 
#define NUM_LEDS 70             // LED灯珠数量
#define LED_DT 3                // Arduino输出控制信号引脚
#define LED_TYPE WS2811         // LED灯带型号
#define COLOR_ORDER RGB         // RGB灯珠中红色、绿色、蓝色LED的排列顺序
 
uint8_t max_bright = 30;       // LED亮度控制变量，可使用数值为 0 ～ 255， 数值越大则光带亮度越高
 
CRGB leds[NUM_LEDS];     // 建立光带leds
   
CHSV myHSVcolor(80,255,200);    //HSV方法定义颜色  myHSVcolor（色调，饱和度，明亮度）
CRGB myRGBcolor(0,0,0);         //RGB方法定义颜色  myRGBcolor（红色，绿色，蓝色）

void setup() { 
 
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);  // 初始化光带
  
  FastLED.setBrightness(max_bright);                            // 设置光带亮度
}
 
void loop () { 
//  演示如何使用方法改变CHSV颜色的某一个数值
//  myHSVcolor.h++;  // 修改HSV定义颜色的单一数值
//                   // myHSVcolor.h为myHSVcolor的色调数值

//  myHSVcolor.s++;  // 修改HSV定义颜色的单一数值
//                   // myHSVcolor.h为myHSVcolor的饱和度数值

//  myHSVcolor.v++;   // 修改HSV定义颜色的单一数值
                    // myHSVcolor.h为myHSVcolor的明亮度数值

//  演示如何使用方法改变CRGB颜色的某一个数值
 myRGBcolor.r++;  // 修改HSV定义颜色的单一数值
                  // myHSVcolor.h为myHSVcolor的色调数值

 myRGBcolor.g++;  // 修改HSV定义颜色的单一数值
                  // myHSVcolor.h为myHSVcolor的饱和度数值

 myRGBcolor.b++;   // 修改HSV定义颜色的单一数值
                    // myHSVcolor.h为myHSVcolor的明亮度数值
                    
//HSV颜色对应
  myHSVcolor.h = 0.577 * 255;
  myHSVcolor.s = 0.0588 * 255;
  myHSVcolor.v = 1.0000 * 255;

//RGB颜色对应
//  myRGBcolor.r = 240; 
//  myRGBcolor.g = 248;
//  myRGBcolor.b = 255;
    
//  fill_solid(leds, NUM_LEDS, myHSVcolor);
  fill_solid(leds, NUM_LEDS, myRGBcolor);     
  FastLED.show();          
  delay(10);       
} 

