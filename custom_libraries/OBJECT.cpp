#include "object.h"

Object::Object(int width, int height, float posX, float posY){
    //Constructor
    PosX = posX;
    PosY = posY;

    Width = width;
    Height = height;
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

float Object :: getX(){
    return PosX;
}

float Object :: getY(){
    return PosY;
}

void Object :: setX(float x){
    PosX = x;
}

void Object :: setY(float y){
    PosY = y;
}