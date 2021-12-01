#include "DINO.h"
#include <FEHLCD.h>
#include <iostream>
#include <Constants.h>

void Dino :: UpdatePosition(){

    /* Change y position based on velocity and FPS */
    setY(getY() + (vel / FPS));
    //std::cout << "Position: " << getY() << std::endl;

    /* Ensures dino doesn't go below floor */
    if(getY() + getHeight() > FLOOR_HEIGHT){
        vel = 0;
        setY(FLOOR_HEIGHT - getHeight());
    }
}

void Dino :: UpdateVelocity(){
    vel += (acc / FPS);
    //std::cout << vel << std::endl;
}

void Dino :: Draw(){
    /* Draw As rectangle for now */
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle((int) getX(), (int) getY(), getWidth(), getHeight());
}

void Dino :: Erase(){
    /* Draws current position as black to erase dino */
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle((int) getX(), (int) getY(), getWidth(), getHeight());
}

void Dino :: Jump(){

    /* If dino on floor, set velocity to jump value */
    if(getY() == FLOOR_HEIGHT - getHeight()){
        vel = JUMP_VEL * FPS;
    }
}