#ifndef DINO_H
#define DINO_H

#include "OBJECT.h"

class Dino : public Object{
    private:
        /* PosY defined in Object parent */
        float vel;
        float acc;

        /* Not in use yet, maybe use with draw function? */
        int animationState;

    public:
        Dino();

        void UpdateVelocity();
        void UpdatePosition();        

        void Draw();
        void Erase();
};

#endif