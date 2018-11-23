
#include <Adafruit_NeoPixel.h>
//#include "NewYearTree.h"
#include <PinChangeInt.h>

#define   SIDE_1_LED_PIN       10
#define   SIDE_STAR_LED_PIN    7
#define   LED_1_PIN            3
#define   LED_2_PIN            5
#define   LED_3_PIN            6
#define   LED_4_PIN            9
#define   LED_5_PIN            13

#define   KEY_PIN              A2

#define   SIDE_1_PIXEL_NUM         24 
#define   SIDE_STAR_PIXEL_NUM      26
#define   PICTURE_NUM              60

#define   BOTTOM_LEDS_START_INDEX    26

#define   RainbowDelay         1
#define   BRIGHTNESS           25//255
#define   SHOW_PIC_DELAY       300


Adafruit_NeoPixel SIDE_1 = Adafruit_NeoPixel(SIDE_1_PIXEL_NUM, SIDE_1_LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel SIDE_STAR = Adafruit_NeoPixel(SIDE_STAR_PIXEL_NUM, SIDE_STAR_LED_PIN, NEO_GRB + NEO_KHZ800);

const uint32_t Picture_1[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000,
             
};

const uint32_t Picture_2[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000,
};

const uint32_t Picture_3[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
  0x000000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000,
              
};

const uint32_t Picture_4[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
  0x000000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000,
              
};

const uint32_t Picture_5[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
  0x000000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000,
              
};

const uint32_t Picture_6[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
  0x000000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000,
};

const uint32_t Picture_7[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
  0x000000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000,
};

const uint32_t Picture_8[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
  0x000000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000,
};

const uint32_t Picture_9[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
  0x000000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x000000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000,
};

const uint32_t Picture_10[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
  0x000000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0x000000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000,
};

const uint32_t Picture_11[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
  0x000000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0x000000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000,
};

const uint32_t Picture_12[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0x000000, 0xFF0000, 0xFF0000, 0x000000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
  0x000000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0x000000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000,
};

const uint32_t Picture_13[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
  0x000000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0x000000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000,
};

const uint32_t Picture_14[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
  0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000,
};

const uint32_t Picture_15[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
  0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000,
};

const uint32_t Picture_16[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
  0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000,
};

const uint32_t Picture_17[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
  0xFF0000, 0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000,
};

const uint32_t Picture_18[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
  0xFF0000, 0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000,
};

const uint32_t Picture_19[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
  0xFF0000, 0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000,
};

const uint32_t Picture_20[] PROGMEM = 
{
                        0xFF0000, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
  0xFF0000, 0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000,
};

const uint32_t Picture_21[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
  0xFF0000, 0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000,
};

const uint32_t Picture_22[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
  0xFF0000, 0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 0xFF0000, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00,
};

const uint32_t Picture_23[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
  0xFF0000, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00,
};

const uint32_t Picture_24[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
  0xFF0000, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00,
};

const uint32_t Picture_25[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFF0000, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
  0xFF0000, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00,
};

const uint32_t Picture_26[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
  0xFF0000, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFF0000, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00,
};

const uint32_t Picture_27[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
  0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00,
};
//------------------------------------------------------------------------------- добавили синий
const uint32_t Picture_28[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
  0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00,
};

const uint32_t Picture_29[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
  0xFFFF00, 0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00,
};

const uint32_t Picture_30[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
  0xFFFF00, 0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00,
};

const uint32_t Picture_31[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
  0xFFFF00, 0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00,  
};

const uint32_t Picture_32[] PROGMEM = 
{
                        0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
  0xFFFF00, 0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00,
};

const uint32_t Picture_33[] PROGMEM = 
{
                        0xFFFFFF, 0xFFFFFF, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
  0xFFFF00, 0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00,
};

const uint32_t Picture_34[] PROGMEM = 
{
                        0xFFFFFF, 0xFFFFFF, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
  0xFFFF00, 0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 0xFFFF00, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_35[] PROGMEM = 
{
                        0xFFFFFF, 0xFFFFFF, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
  0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_36[] PROGMEM = 
{
                        0xFFFFFF, 0xFFFFFF, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_37[] PROGMEM = 
{
                        0xFFFFFF, 0xFFFFFF, 
              0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_38[] PROGMEM = 
{
                        0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_39[] PROGMEM = 
{
                        0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_40[] PROGMEM = 
{
                          0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_41[] PROGMEM = 
{
                        0xFFFFFF, 0x000000, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_42[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_43[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_44[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_45[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_46[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_47[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_48[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_49[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0x000000, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_50[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000, 0x000000, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_51[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF,
};

const uint32_t Picture_52[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000,
};

const uint32_t Picture_53[] PROGMEM = 
{
                        0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0xFFFFFF, 0x000000,
};

const uint32_t Picture_54[] PROGMEM = 
{
                        0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
  0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000,
};

const uint32_t Picture_55[] PROGMEM = 
{
                        0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
  0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000,
};

const uint32_t Picture_56[] PROGMEM = 
{
                        0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
  0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000,
};

const uint32_t Picture_57[] PROGMEM = 
{
                        0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
  0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000,
};

const uint32_t Picture_58[] PROGMEM = 
{
                        0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
  0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000,
};

const uint32_t Picture_59[] PROGMEM = 
{
                        0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
  0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000,
};

const uint32_t Picture_60[] PROGMEM = 
{
                         0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000, 
  0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 0x001000, 
              0x001000, 0x001000, 0x001000, 0x001000,
};
//__________________________________________________________________________________________________________________________________
const uint32_t Picture_star_1[] PROGMEM = 
{                               0x200000,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              0, 0, 0, 0, 
};

const uint32_t Picture_star_2[] PROGMEM = 
{
                                0x202000,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              8, 8, 8, 8,
};

const uint32_t Picture_star_3[] PROGMEM = 
{
                                0x202020,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              16, 16, 16, 16,
};

const uint32_t Picture_star_4[] PROGMEM = 
{
                                0x202040,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              24, 24, 24, 24,
};

const uint32_t Picture_star_5[] PROGMEM = 
{
                                0x204040,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              32, 32, 32, 32,
};

const uint32_t Picture_star_6[] PROGMEM = 
{
                                0x404040,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              40, 40, 40, 40, 
};

const uint32_t Picture_star_7[] PROGMEM = 
{
                                0x604040,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              48, 48, 48, 48,
};

const uint32_t Picture_star_8[] PROGMEM = 
{
                                0x606040,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              56, 56, 56, 56,
};

const uint32_t Picture_star_9[] PROGMEM = 
{
                                0x606060,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              64, 64, 64, 64,
};

const uint32_t Picture_star_10[] PROGMEM = 
{
                                0x606080,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              72, 72, 72, 72,
};

const uint32_t Picture_star_11[] PROGMEM = 
{
                                0x608080,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              80, 80, 80, 80,
};

const uint32_t Picture_star_12[] PROGMEM = 
{
                                0x808080,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              88, 88, 88, 88,
};

const uint32_t Picture_star_13[] PROGMEM = 
{
                                0x908080,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              96, 96, 96, 96,
};

const uint32_t Picture_star_14[] PROGMEM = 
{
                                0x909080,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              104, 104, 104, 104,
};

const uint32_t Picture_star_15[] PROGMEM = 
{
                                0x909090,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              112, 112, 112, 112,
};

const uint32_t Picture_star_16[] PROGMEM = 
{
                                0xA09090,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              120, 120, 120, 120, 
};

const uint32_t Picture_star_17[] PROGMEM = 
{
                                0xA0A090,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              128, 128, 128, 128,
};

const uint32_t Picture_star_18[] PROGMEM = 
{
                                0xA0A0A0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              136, 136, 136, 136,
};

const uint32_t Picture_star_19[] PROGMEM = 
{
                                0xA0A0B0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              144, 144, 144, 144,
};


const uint32_t Picture_star_20[] PROGMEM = 
{
                                0xA0B0B0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              152, 152, 152, 152,
};

const uint32_t Picture_star_21[] PROGMEM = 
{
                                0xB0B0B0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              160, 160, 160, 160,
};

const uint32_t Picture_star_22[] PROGMEM = 
{
                                0xC0B0B0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              168, 168, 168, 168,
};

const uint32_t Picture_star_23[] PROGMEM = 
{
                                0xC0C0B0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              176, 176, 176, 176,
};

const uint32_t Picture_star_24[] PROGMEM = 
{
                                0xC0C0C0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              184, 184, 184, 184, 
};

const uint32_t Picture_star_25[] PROGMEM = 
{
                                0xC0C0E0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              192, 192, 192, 192,
};

const uint32_t Picture_star_26[] PROGMEM = 
{
                                0xC0E0E0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              200, 200, 200, 200,
};

const uint32_t Picture_star_27[] PROGMEM = 
{
                                0xE0E0E0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              210, 210, 210, 210,
};

const uint32_t Picture_star_28[] PROGMEM = 
{
                                0xF1E0E0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              220, 220, 220, 220,
};

const uint32_t Picture_star_29[] PROGMEM = 
{
                                0xF1F1E0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              230, 230, 230, 230,
};

const uint32_t Picture_star_30[] PROGMEM = 
{
                                0xF1F1F1,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              255, 255, 255, 255,
};

const uint32_t Picture_star_31[] PROGMEM = 
{
                                0xF1F1F5,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              255, 230, 255, 230,
};
const uint32_t Picture_star_32[] PROGMEM = 
{
                                0xF1F5F5,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              255, 223, 255, 223,
};

const uint32_t Picture_star_33[] PROGMEM = 
{
                                0xF5F5F5,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              255, 207, 255, 207,
};

const uint32_t Picture_star_34[] PROGMEM = 
{
                                0xFAF5F5,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              255, 191, 255, 191,
};

const uint32_t Picture_star_35[] PROGMEM = 
{
                                0xFAFAF5,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              255, 175, 255, 175,
};

const uint32_t Picture_star_36[] PROGMEM = 
{
                                0xFAFAFA,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              255, 159, 255, 159, 
};

const uint32_t Picture_star_37[] PROGMEM = 
{
                                0xFAFAFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              255, 143, 255, 143, 
};

const uint32_t Picture_star_38[] PROGMEM = 
{
                                0xFAFCFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              255, 127, 255, 127,
};

const uint32_t Picture_star_39[] PROGMEM = 
{
                                0xFCFCFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              255, 111, 255, 111,
};

const uint32_t Picture_star_40[] PROGMEM = 
{
                                0xFFFCFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              255, 95, 255, 95, 
};

const uint32_t Picture_star_41[] PROGMEM = 
{
                                0xFFFFFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              255, 79, 255, 79,
};

const uint32_t Picture_star_42[] PROGMEM = 
{
                                0xFFFFFF,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              255, 63, 255, 63, 
};

const uint32_t Picture_star_43[] PROGMEM = 
{
                                0xFFFFFF,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              255, 47, 255, 47, 
};

const uint32_t Picture_star_44[] PROGMEM = 
{
                                0xFFFFFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              255, 31, 255, 31, 
};

const uint32_t Picture_star_45[] PROGMEM = 
{
                                0xFFFCFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              255, 15, 255, 15, 
};

const uint32_t Picture_star_46[] PROGMEM = 
{
                                0xFCFCFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              240, 0, 240, 0,
};

const uint32_t Picture_star_47[] PROGMEM = 
{
                                0xFAFCFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              230, 0, 230, 0,
};

const uint32_t Picture_star_48[] PROGMEM = 
{
                                0xFAFAFC,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              210, 0, 210, 0,
};

const uint32_t Picture_star_49[] PROGMEM = 
{
                                0xFAFAFA,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              194, 0, 194, 0,
};

const uint32_t Picture_star_50[] PROGMEM = 
{
                                0xFAFAF2,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              178, 0, 178, 0,
};

const uint32_t Picture_star_51[] PROGMEM = 
{
                                0xFAF2F2,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              162, 0, 162, 0,
};

const uint32_t Picture_star_52[] PROGMEM = 
{
                                0xF2F2F2,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              146, 0, 146, 0,
};

const uint32_t Picture_star_53[] PROGMEM = 
{
                                0xC0F2F2,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              130, 0, 130, 0,
};

const uint32_t Picture_star_54[] PROGMEM = 
{
                                0xC0C0F2,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              114, 0, 114, 0,
};

const uint32_t Picture_star_55[] PROGMEM = 
{
                                0xC0C0C0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              98, 0, 98, 0,
};

const uint32_t Picture_star_56[] PROGMEM = 
{
                                0x90C0C0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              80, 0, 80, 0,
};

const uint32_t Picture_star_57[] PROGMEM = 
{
                                0x9090C0,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              60, 0, 60, 0,
};

const uint32_t Picture_star_58[] PROGMEM = 
{
                                0x909090,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              40, 0, 40, 0,
};

const uint32_t Picture_star_59[] PROGMEM = 
{
                                0x909050,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              30, 0, 30, 0,
};

const uint32_t Picture_star_60[] PROGMEM = 
{
                                0x505050,
                                0x000000,
                          0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000, 
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
              0x000000, 0x000000, 0x000000, 0x000000,
              10, 10, 10, 10,
};
const uint32_t *SIDE_1_Pictures[] =
{
  Picture_1, Picture_2, Picture_3, Picture_4,  Picture_5,  Picture_6,  Picture_7,  Picture_8, Picture_9, Picture_10, Picture_11, Picture_12, Picture_13, Picture_14, Picture_15, Picture_16, Picture_17, Picture_18, Picture_19, 
  Picture_20, Picture_21, Picture_22, Picture_23, Picture_24, Picture_25, Picture_26, Picture_27, Picture_28, Picture_29, Picture_30, Picture_31, Picture_32, Picture_33, Picture_34, Picture_35, Picture_36, Picture_37, Picture_38,
  Picture_39, Picture_40, Picture_41, Picture_42, Picture_43, Picture_44, Picture_45, Picture_46, Picture_47, Picture_48, Picture_49, Picture_50, Picture_51, Picture_52, Picture_53, Picture_54, Picture_55, Picture_56, Picture_57,
  Picture_58, Picture_59, Picture_60
};

const uint32_t *SIDE_STAR_Pictures[] =
{
  Picture_star_1, Picture_star_2, Picture_star_3, Picture_star_4, Picture_star_5, Picture_star_6, Picture_star_7, Picture_star_8, Picture_star_9, Picture_star_10, Picture_star_11, Picture_star_12, Picture_star_13, Picture_star_14,
  Picture_star_15, Picture_star_16, Picture_star_17, Picture_star_18, Picture_star_19, Picture_star_20, Picture_star_21, Picture_star_22, Picture_star_23, Picture_star_24, Picture_star_25, Picture_star_26, Picture_star_27,
  Picture_star_28, Picture_star_29, Picture_star_30, Picture_star_31, Picture_star_32, Picture_star_33, Picture_star_34, Picture_star_35, Picture_star_36, Picture_star_37, Picture_star_38, Picture_star_39, Picture_star_40,
  Picture_star_41, Picture_star_42, Picture_star_43, Picture_star_44, Picture_star_45, Picture_star_46, Picture_star_47, Picture_star_48, Picture_star_49, Picture_star_50, Picture_star_51, Picture_star_52, Picture_star_53, 
  Picture_star_54,  Picture_star_55, Picture_star_56, Picture_star_57, Picture_star_58, Picture_star_59, Picture_star_60
};

uint8_t Mode = 0; //1
uint8_t ActivePic = 0;
uint8_t State = 0;


void setup()
{
  pinMode(KEY_PIN, INPUT);
  digitalWrite(KEY_PIN, HIGH);
  PCintPort::attachInterrupt(KEY_PIN, &Key_ISR, FALLING);
  
  SIDE_1.begin();
  SIDE_1.setBrightness(BRIGHTNESS);
  SIDE_STAR.begin();
  SIDE_STAR.setBrightness(BRIGHTNESS);

  randomSeed(analogRead(0));
  for (uint8_t i = 0; i < 30; i++)
  {    
    uint32_t RandomColor = random(0xFFFFFF);
    uint8_t RandomLed = random(SIDE_1_PIXEL_NUM + 1);
    SIDE_1.setPixelColor(RandomLed, RandomColor);
    RandomColor = random(0xFFFFFF);
    RandomLed = random(SIDE_STAR_PIXEL_NUM - 1);
    SIDE_1.setPixelColor(RandomLed, RandomColor);
    SIDE_STAR.setPixelColor(RandomLed, RandomColor);
    SIDE_1.show();
    SIDE_STAR.show();
    delay(100);

    SIDE_1.clear();
    SIDE_STAR.clear();    
  }
  
  SIDE_1.show();
  SIDE_STAR.show();
  delay(100);

  uint8_t LED_PINS[] = {LED_1_PIN, LED_2_PIN, LED_3_PIN, LED_4_PIN,};
  for (uint8_t led = 0; led < 4; led++)
    pinMode(LED_PINS[led], OUTPUT);
  for (uint8_t brightness = 0; brightness < 250; brightness+= 5)
  {
    for (uint8_t led = 0; led < 4; led++)
      analogWrite(LED_PINS[led], brightness);

    delay(25);
  }

  for (uint8_t led = 0; led < 4; led++)
    digitalWrite(LED_PINS[led], HIGH);
  digitalWrite(LED_5_PIN, HIGH);
  
  for (uint8_t ledNum = 0; ledNum < SIDE_1_PIXEL_NUM; ledNum++)
  {
    SIDE_1.setPixelColor(ledNum, (uint32_t)0xF00000);
    SIDE_STAR.setPixelColor(ledNum, (uint32_t)0xF00000);
    SIDE_1.show();
    SIDE_STAR.show();
    delay(100);
    SIDE_1.clear();
    SIDE_STAR.clear();    
  }

  SIDE_STAR.setPixelColor(SIDE_STAR_PIXEL_NUM - 2, (uint32_t)0xF00000);   
  SIDE_STAR.show();
  delay(100);
  SIDE_STAR.clear();  
  SIDE_1.show();
  SIDE_STAR.show();
  delay(100);

  for (uint32_t LedBrightness = 0; LedBrightness < 255; LedBrightness++)
  {
    SIDE_STAR.setPixelColor(SIDE_STAR_PIXEL_NUM - 1, (uint32_t)(LedBrightness << 16));
    SIDE_STAR.show();
    delay(20);
  } 
  }
//-----------------------------------------------------------
void loop()
{
  if (Mode == 0)
  {
    SIDE_1_Rainbow(RainbowDelay);
    SIDE_STAR_Rainbow(RainbowDelay);
  }

  else
  {
    SIDE_1_ChangePicture(SIDE_1_Pictures[ActivePic]);
    SIDE_STAR_ChangePicture(SIDE_STAR_Pictures[ActivePic]);
    SIDE_1.show();
    SIDE_STAR.show();
    delay(SHOW_PIC_DELAY);

    ActivePic++;
    if (ActivePic == PICTURE_NUM)
      ActivePic = 0;
  }

  if (State)
  {
    PCintPort::detachInterrupt(KEY_PIN);
    if (Mode == 0)
      Mode = 1;
    else
      Mode = 0;

    State = 0;

    while(!digitalRead(KEY_PIN));
    PCintPort::attachInterrupt(KEY_PIN, &Key_ISR, FALLING);
  }  
}
//-----------------------------------------------------------
void SIDE_1_Rainbow(uint8_t wait)
{
  uint16_t i, j;

  for(j=0; j<256*1; j++)
  { 
    if (State)
      break;
    
    for(i=0; i< SIDE_1.numPixels(); i++)
    {
      SIDE_1.setPixelColor(i, SIDE_1_Wheel(((i * 256 / SIDE_1.numPixels()) + j) & 255));
    }
    SIDE_1.show();
    delay(wait);
  }
}
//-----------------------------------------------------------
uint32_t SIDE_1_Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85)
  {
    return SIDE_1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170)
  {
    WheelPos -= 85;
    return SIDE_1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return SIDE_1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
//-----------------------------------------------------------
void SIDE_STAR_Rainbow(uint8_t wait)
{
  uint16_t i, j;

  for(j=0; j<256*5; j++)
  { 
    if (State)
      break;
      
    for(i=0; i< (SIDE_STAR.numPixels() - 1); i++)
    {
      SIDE_STAR.setPixelColor(i, SIDE_STAR_Wheel(((i * 256 / (SIDE_STAR.numPixels() - 1)) + j) & 255));
    }
    SIDE_STAR.show();
    delay(wait);
  }
}
//-----------------------------------------------------------
uint32_t SIDE_STAR_Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85)
  {
    return SIDE_STAR.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170)
  {
    WheelPos -= 85;
    return SIDE_STAR.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return SIDE_STAR.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
//-----------------------------------------------------------
void SIDE_1_ChangePicture(const uint32_t *Picture)
{  
  uint8_t StartIndex = (SIDE_1_PIXEL_NUM - 1);
 
  //ряд 0 сверху
  for (uint8_t ledNum = StartIndex; ledNum > (StartIndex - 2); ledNum--)
    SIDE_1.setPixelColor(ledNum, pgm_read_dword(&Picture[SIDE_1_PIXEL_NUM - 1 - ledNum]));
  
  StartIndex -= 2;
  for (uint8_t row = 0; row < 3; row++)
  {    
    for (uint8_t ledNum = StartIndex; ledNum > (StartIndex - 4); ledNum--)
      SIDE_1.setPixelColor(ledNum, pgm_read_dword(&Picture[SIDE_1_PIXEL_NUM - 1 - ledNum]));
    
    StartIndex -= 4;
  }

  for (uint8_t ledNum = StartIndex; ledNum > (StartIndex - 6); ledNum--)
    SIDE_1.setPixelColor(ledNum, pgm_read_dword(&Picture[SIDE_1_PIXEL_NUM - 1 - ledNum]));

  StartIndex -= 6;
  for (int8_t ledNum = StartIndex; ledNum > (StartIndex - 4); ledNum--)
    SIDE_1.setPixelColor(ledNum, pgm_read_dword(&Picture[SIDE_1_PIXEL_NUM - 1 - ledNum]));
}
//-----------------------------------------------------------
void SIDE_STAR_ChangePicture(const uint32_t *Picture)
{  
  uint8_t StartIndex = (SIDE_STAR_PIXEL_NUM - 1);
 
  //ряд 0 сверху
  for (uint8_t row = 0; row < 2; row++)
  {    
    for (uint8_t ledNum = StartIndex; ledNum > (StartIndex - 1); ledNum--)
      SIDE_STAR.setPixelColor(ledNum, pgm_read_dword(&Picture[SIDE_STAR_PIXEL_NUM - 1 - ledNum]));
    
    StartIndex -= 1;
  }
  
  for (uint8_t ledNum = StartIndex; ledNum > (StartIndex - 2); ledNum--)
    SIDE_STAR.setPixelColor(ledNum, pgm_read_dword(&Picture[SIDE_STAR_PIXEL_NUM - 1 - ledNum]));
  
  StartIndex -= 2;
  for (uint8_t row = 0; row < 3; row++)
  {    
    for (uint8_t ledNum = StartIndex; ledNum > (StartIndex - 4); ledNum--)
      SIDE_STAR.setPixelColor(ledNum, pgm_read_dword(&Picture[SIDE_STAR_PIXEL_NUM - 1 - ledNum]));
    
    StartIndex -= 4;
  }

  for (uint8_t ledNum = StartIndex; ledNum > (StartIndex - 6); ledNum--)
    SIDE_STAR.setPixelColor(ledNum, pgm_read_dword(&Picture[SIDE_STAR_PIXEL_NUM - 1 - ledNum]));

  StartIndex -= 6;
  for (int8_t ledNum = StartIndex; ledNum > (StartIndex - 4); ledNum--)
    SIDE_STAR.setPixelColor(ledNum, pgm_read_dword(&Picture[SIDE_STAR_PIXEL_NUM - 1 - ledNum]));
  
  
  uint8_t LED_PINS[] = {LED_1_PIN, LED_2_PIN, LED_3_PIN, LED_4_PIN,};  
  for (uint8_t led = 0; led < 4; led++)
    analogWrite(LED_PINS[led], pgm_read_dword(&Picture[BOTTOM_LEDS_START_INDEX + led]));
}
//----------------------------------------
void Key_ISR()
{
  State = true;
}

