#include "DINO.h"
#include "Graphics.h"
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
    for (int i = 0; i < TREX_IDLE_HEIGHT; ++i) {
        for (int j = 0; j < TREX_IDLE_WIDTH; ++j) {
            if (t_rex_idle[i*TREX_IDLE_WIDTH + j] != 0xff)
                LCD.DrawPixel(getX()+j, getY()+i);
        }
    }
    //LCD.DrawRectangle((int) getX(), (int) getY(), getWidth(), getHeight());
}

void Dino :: Erase(){
    /* Draws current position as black to erase dino */
    LCD.SetFontColor(WHITE);
    for (int i = 0; i < TREX_IDLE_HEIGHT; ++i) {
        for (int j = 0; j < TREX_IDLE_WIDTH; ++j) {
                LCD.DrawPixel(getX()+j, getY()+i);
        }
    }
}

void Dino :: Jump(){

    /* If dino on floor, set velocity to jump value */
    if(getY() == FLOOR_HEIGHT - getHeight()){
        vel = JUMP_VEL * FPS;
    }
}