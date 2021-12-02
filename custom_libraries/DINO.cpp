#include "DINO.h"
#include "Graphics.h"
#include <FEHLCD.h>
#include <iostream>
#include <Constants.h>

Dino :: Dino(int w, int h, float x, float y) :  Object(w, h, x, y),
                                                vel(0),
                                                acc(DINO_ACC * FPS),
                                                animationState(DF_DUCK_1)
{
    animationFrames[DF_IDLE].Init(t_rex_idle, TREX_IDLE_WIDTH, TREX_IDLE_HEIGHT);
    animationFrames[DF_DEAD].Init(t_rex_dead, TREX_DEAD_WIDTH, TREX_DEAD_HEIGHT);
    animationFrames[DF_RUN_1].Init(t_rex_run_1, TREX_RUN_1_WIDTH, TREX_RUN_1_HEIGHT);
    animationFrames[DF_RUN_2].Init(t_rex_run_2, TREX_RUN_2_WIDTH, TREX_RUN_2_HEIGHT);
    animationFrames[DF_DUCK_1].Init(t_rex_duck_1, TREX_DUCK_1_WIDTH, TREX_DUCK_1_HEIGHT);
    animationFrames[DF_DUCK_2].Init(t_rex_duck_2, TREX_DUCK_2_WIDTH, TREX_DUCK_2_HEIGHT);
}

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
    animationFrames[animationState].Draw(getX(),getY());
    /* Draw As rectangle for now */
    //LCD.DrawRectangle((int) getX(), (int) getY(), getWidth(), getHeight());
}

void Dino :: Erase(){
    /* Draws current position as black to erase dino 
    LCD.SetFontColor(WHITE);
    for (int i = 0; i < TREX_IDLE_HEIGHT; ++i) {
        for (int j = 0; j < TREX_IDLE_WIDTH; ++j) {
                LCD.DrawPixel(getX()+j, getY()+i);
        }
    }*/
}

void Dino :: Jump(){

    /* If dino on floor, set velocity to jump value */
    if(getY() == FLOOR_HEIGHT - getHeight()){
        vel = JUMP_VEL * FPS;
    }
}