#include "object.h"
#include <stdio.h>
#include <iostream>

using namespace std;

/* Made by Kurt */
/* Object class constructor */
Object::Object(int width, int height, float posX, float posY){

    PosX = posX;
    PosY = posY;

    Width = width;
    Height = height;
}

/* Made by Kurt */
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

/* Made by Kurt */
/* Returns left bound of object */
int Object :: getLeftBound(){
    return PosX;
}

/* Made by Kurt */
/* Returns right bound of object */
int Object :: getRightBound(){
    return PosX + Width;
}

/* Made by Kurt */
/* Returns upper bound of object */
int Object :: getUpperBound(){
    return PosY;
}

/* Made by Kurt */
/* Returns lower bound of object */
int Object :: getLowerBound(){
    return PosY + Height;
}

/* Made by Kurt */
/* Returns width of object */
int Object :: getWidth(){
    return Width;
}

/* Made by Kurt */
/* Returns height of object */
int Object :: getHeight(){
    return Height;
}

/* Made by Kurt */
/* Sets the width of the object */
void Object :: setWidth(int w){
    Width = w;
}

/* Made by Kurt */
/* Sets the height of the object */
void Object :: setHeight(int h){
    Height = h;
}

/* Made by Kurt */
/* Returns the x value of the object */
float Object :: getX(){
    return PosX;
}

/* Made by Kurt */
/* Returns the y value of the object */
float Object :: getY(){
    return PosY;
}

/* Made by Kurt */
/* Sets the x value of the object */
void Object :: setX(float x){
    PosX = x;
}

/* Made by Kurt */
/* Sets the y value of the object */
void Object :: setY(float y){
    PosY = y;
}
