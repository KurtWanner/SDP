#include <FEHLCD.h>

#include "Graphics.h"



void Sprite::draw(int x, int y) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (pixels[i * width + j] != 0xff)
                LCD.DrawPixel(x + j, y + i);
        }
    }
}