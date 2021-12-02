#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "OBJECT.h"
#include <Constants.h>

class Obstacle : public Object{
    private:
        int type;
        int vel = 4 * FPS;
    public:
        /* Constructor inhereted from Object */
        Obstacle(int w, int h, float x, float y) : Object(w, h, x, y) {}
        
        void UpdatePosition();
        void Draw();
};

#endif