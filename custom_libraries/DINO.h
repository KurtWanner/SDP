#ifndef DINO_H
#define DINO_H

#include "OBJECT.h"
#include "Graphics.h"
#include <Constants.h>

enum DinoFrame {
    DF_IDLE,
    DF_DEAD,
    DF_RUN_1,
    DF_RUN_2,
    DF_DUCK_1,
    DF_DUCK_2,
    NUM_DF
};

class Dino : public Object{
    private:
        /* PosY defined in Object parent */
        float vel;
        float acc;

        /* Not in use yet, maybe use with draw function? */
        DinoFrame animationState;
        Sprite animationFrames[NUM_DF];

    public:

        Dino(int w, int h, float x, float y);
        void UpdateVelocity();
        void UpdatePosition();        

        void Draw();
        void Erase();

        void Jump();
};

#endif