#ifndef DINO_H
#define DINO_H

#include "OBJECT.h"
#include <Constants.h>

class Dino : public Object{
    private:
        /* PosY defined in Object parent */
        float vel;
        float acc;

        /* Not in use yet, maybe use with draw function? */
        int animationState;

    public:

        /* Constructor class inheritance */
        Dino(int w, int h, float x, float y) : Object(w, h, x, y) {
            vel = 0;
            acc = DINO_ACC * FPS; //Going downward
        }

        void UpdateVelocity();
        void UpdatePosition();        

        void Draw();
        void Erase();

        void Jump();
};

#endif