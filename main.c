#include "stdint.h"
#include "stdio.h"
#include "main.h"

int main(void){
    color_t color = colorInit();

    color.Build(&color, 12, 23, 42);

    printf("RGB: %d", color.getRGB(&color));

    return 0;
}