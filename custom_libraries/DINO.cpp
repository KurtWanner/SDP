#include "DINO.h"
#include <FEHLCD.h>
#include <iostream>


Dino :: Dino(){
    vel = -38;
    acc = 13; //Going downward
}

void Dino :: UpdatePosition(){
    setY(getY() + (vel / 30.0));
    //std::cout << "Position: " << getY() << std::endl;
}

void Dino :: UpdateVelocity(){
    vel += (acc / 30.0);
    //std::cout << vel << std::endl;
}

void Dino :: Draw(){
    /* Draw As rectangle for now */
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle((int) getX(), (int) getY(), getWidth(), getHeight());
}

void Dino :: Erase(){
    /* Draws current position as black to erase dino */
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle((int) getX(), (int) getY(), getWidth(), getHeight());
}