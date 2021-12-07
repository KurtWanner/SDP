#include "object.h"
#include <stdio.h>
#include <iostream>

using namespace std;

/* Object class constructor */
Object::Object(int width, int height, float posX, float posY){

    PosX = posX;
    PosY = posY;

    Width = width;
    Height = height;
}

/* Tests collision between current object and argument */
bool Object :: collision(Object ob){

    /* Tests conditions in which the objects are absolutely not colliding */
    if(getLeftBound() > ob.getRightBound()){
        return false;
    }
    if(getRightBound() < ob.getLeftBound()){
        return false;
    }
    if(getUpperBound() > ob.getLowerBound()){
        return false;
    }
    if(getLowerBound() < ob.getUpperBound()){
        return false;
    }

    /* If none of the previous if statements ran, then the two objects are colliding */
    return true;
}

/* Returns left bound of object */
int Object :: getLeftBound(){
    return PosX;
}

/* Returns right bound of object */
int Object :: getRightBound(){
    return PosX + Width;
}

/* Returns upper bound of object */
int Object :: getUpperBound(){
    return PosY;
}

/* Returns lower bound of object */
int Object :: getLowerBound(){
    return PosY + Height;
}

/* Returns width of object */
int Object :: getWidth(){
    return Width;
}

/* Returns height of object */
int Object :: getHeight(){
    return Height;
}

/* Sets the width of the object */
void Object :: setWidth(int w){
    Width = w;
}

/* Sets the height of the object */
void Object :: setHeight(int h){
    Height = h;
}

/* Returns the x value of the object */
float Object :: getX(){
    return PosX;
}

/* Returns the y value of the object */
float Object :: getY(){
    return PosY;
}

/* Sets the x value of the object */
void Object :: setX(float x){
    PosX = x;
}

/* Sets the y value of the object */
void Object :: setY(float y){
    PosY = y;
}
