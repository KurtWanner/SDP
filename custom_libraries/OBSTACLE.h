#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "OBJECT.h"

class Obstacle : public Object{
    private:

    public:
        /* Constructor inhereted from Object */
        Obstacle(int w, int h, float x, float y) : Object(w, h, x, y) {}
};

#endif