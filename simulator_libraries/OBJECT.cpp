#include "object.h"

Object::Object(){
    //Constructor
    PosX = 0;
    PosY = 0;

    Width = 0;
    Height = 0;
}

/* Top left pixel is (0, 0) */
int Object :: getLeftBound(){
    return PosX;
}

int Object :: getRightBound(){
    return PosX + Width;
}

int Object :: getUpperBound(){
    return PosY;
}

int Object :: getLowerBound(){
    return PosY + Height;
}

int Object :: getWidth(){
    return Width;
}

int Object :: getHeight(){
    return Height;
}

void Object :: setWidth(int w){
    Width = w;
}

void Object :: setHeight(int h){
    Height = h;
}

int Object :: getX(){
    return PosX;
}


int Object :: getY(){
    return PosY;
}

void Object :: setX(int x){
    PosX = x;
}

void Object :: setY(int y){
    PosY = y;
}
