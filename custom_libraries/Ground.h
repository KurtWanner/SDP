#ifndef GROUND_H
#define GROUND_H

#include "Graphics.h"
#include "Constants.h"
#include "Object.h"

class Ground : public Object {
    int offset = 0;
    Sprite sprite;
    public:
        Ground() : Object(GROUND_WIDTH, GROUND_HEIGHT, 0, FLOOR_HEIGHT) {
            sprite.Init(ground_sprite, GROUND_WIDTH, GROUND_HEIGHT);
        }

        void UpdateGround(int speed);
        void DrawGround();
};

#endif