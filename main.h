#ifndef MAIN_H_
#define MAIN_H_

#include "stdint.h"

typedef struct color_t color_t;

struct color_t{
    uint8_t red;
    uint8_t blue;
    uint8_t green;
   
    uint32_t (*getRGB)(color_t*);
    void (*Build)(color_t*, uint8_t, uint8_t, uint8_t);
};

static color_t colorInit(void);
static uint32_t colorGetRGB(color_t*);
static void colorBuild(color_t*, uint8_t, uint8_t, uint8_t);

color_t colorInit(){
    color_t color;

    color.red = 127;
    color.blue = 127;
    color.green = 127;
    color.getRGB = &colorGetRGB;
    color.Build = &colorBuild;
    
    return color;
}

uint32_t colorGetRGB(color_t* color){
    uint32_t RGB_value = color->red;
    RGB_value = RGB_value << 8;
    RGB_value = RGB_value | color->green;
    RGB_value = RGB_value << 8;
    RGB_value = RGB_value | color->blue;

    return RGB_value;
}

void colorBuild(color_t* color, uint8_t red, uint8_t green, uint8_t blue){
    color->red = red;
    color->green = green;
    color->blue = blue;
}


#endif