#include "DINO.h"
#include "Graphics.h"
#include <FEHLCD.h>
#include <iostream>
#include <Constants.h>

Dino :: Dino(int w, int h, float x, float y) :  Object(w, h, x, y),
                                                vel(0),
                                                acc(0),
                                                animationState(DF_RUN_1),
                                                dinoState(DS_RUN)
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
        acc = 0;
        setY(FLOOR_HEIGHT - getHeight());

    }
}

void Dino :: UpdateVelocity(){
    vel += (acc / FPS);
    //std::cout << vel << std::endl;
}

void Dino :: Draw(){
    animationFrames[animationState].Draw(getX(),getY()); 
    /* Drawing rectangle to check hitboxes */
    LCD.DrawRectangle((int) getX(), (int) getY(), getWidth(), getHeight());
}

void Dino :: UpdateAnimation(int tic) {
    switch (dinoState)
    {
    case DS_JUMP:
    case DS_IDLE:
        animationState = DF_IDLE;
        break;
    
    case DS_RUN:
        animationState = (tic / 3) % 2 ? DF_RUN_1 : DF_RUN_2;
        break;

    case DS_DUCK:
        animationState = (tic / 3) % 2 ? DF_DUCK_1 : DF_DUCK_2;
        break;

    case DS_DEAD:
        animationState = DF_DEAD;
    
    default:
        break;
    }
}

void Dino :: Jump(){

    /* If dino on floor, set velocity to jump value */
    if(getY() == FLOOR_HEIGHT - getHeight()){
        vel = JUMP_VEL * FPS;
        acc = DEF_DINO_ACC * FPS;
    }

    setHeight(TREX_IDLE_HEIGHT);
    setWidth(DINO_HIT_WIDTH);

    dinoState = DS_JUMP;
}

void Dino :: Duck(){
    

    /* If dino on floor */
    if(getY() == FLOOR_HEIGHT - getHeight()){
        setY(getY() + (TREX_IDLE_HEIGHT - TREX_DUCK_1_HEIGHT));
    }

    if(getY() < FLOOR_HEIGHT - getHeight() && dinoState != DS_DUCK){
        setY(getY() + (TREX_IDLE_HEIGHT - TREX_DUCK_1_HEIGHT));
    }
    
    setHeight(TREX_DUCK_1_HEIGHT);
    setWidth(TREX_DUCK_1_WIDTH);
    
    dinoState = DS_DUCK;
}

/* For when input is remove from screen, what animation to use */
void Dino :: Settle(){
    setHeight(TREX_IDLE_HEIGHT);
    setWidth(DINO_HIT_WIDTH);

    /* If beneath floor, set to normal height */
    if(getLowerBound() > FLOOR_HEIGHT){
        setY(FLOOR_HEIGHT - TREX_IDLE_HEIGHT);
    }
    
    if(getY() == FLOOR_HEIGHT - getHeight()){
        dinoState = DS_RUN;
    } else {
        dinoState = DS_JUMP;
    }
}

void Dino :: IncreaseGravity(){
    if(acc == 0) { return;}
    if(acc < MAX_DINO_ACC * FPS){
        acc += ACC_INC_VAR * FPS;
    }
    
    //std::cout << acc << std::endl;
}

void Dino :: DecreaseGravity(){
    if(acc == 0) { return;}

    if(acc > MIN_DINO_ACC * FPS){
        acc -= ACC_DEC_VAR * FPS;
    }
    //std::cout << acc << std::endl;

}

void Dino :: Kill(){
    dinoState = DS_DEAD;
    vel = 0;
    acc = 0;
}