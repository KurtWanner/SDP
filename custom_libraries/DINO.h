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

enum DinoState {
    DS_IDLE,
    DS_JUMP,
    DS_RUN,
    DS_DUCK,
    DS_DEAD
};

class Dino : public Object{
    private:
        /* PosY defined in Object parent */
        float vel;
        float acc;

        /* Not in use yet, maybe use with draw function? */
        DinoFrame animationState;
        DinoState dinoState;
        Sprite animationFrames[NUM_DF];

    public:

        Dino(int w, int h, float x, float y);
        void UpdateVelocity();
        void UpdatePosition();   
        void UpdateAnimation(int tic);     

        void Draw();

        void Jump();
        void Duck();

        /* For when input is removed */
        void Settle();

        void IncreaseGravity();
        void DecreaseGravity();

        void Kill();
};

#endif