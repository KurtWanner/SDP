#include "DINO.h"
#include "Graphics.h"
#include <FEHLCD.h>
#include <iostream>
#include <Constants.h>

/* Made by Kurt */
/* Class constructor for the dino inherited from Object */
Dino :: Dino(int w, int h, float x, float y) :  Object(w, h, x, y),
                                                vel(0),
                                                acc(0),
                                                animationState(DF_RUN_1),
                                                dinoState(DS_RUN)
{
    /* Initilize Sprite objects for each dino animation frame */
    animationFrames[DF_IDLE].Set(t_rex_idle, TREX_IDLE_WIDTH, TREX_IDLE_HEIGHT);
    animationFrames[DF_DEAD].Set(t_rex_dead, TREX_DEAD_WIDTH, TREX_DEAD_HEIGHT);
    animationFrames[DF_RUN_1].Set(t_rex_run_1, TREX_RUN_1_WIDTH, TREX_RUN_1_HEIGHT);
    animationFrames[DF_RUN_2].Set(t_rex_run_2, TREX_RUN_2_WIDTH, TREX_RUN_2_HEIGHT);
    animationFrames[DF_DUCK_1].Set(t_rex_duck_1, TREX_DUCK_1_WIDTH, TREX_DUCK_1_HEIGHT);
    animationFrames[DF_DUCK_2].Set(t_rex_duck_2, TREX_DUCK_2_WIDTH, TREX_DUCK_2_HEIGHT);
}

/* Made by Kurt */
/* To be run every frame to update the position of the dino */
void Dino :: UpdatePosition(){

    /* Change y position based on velocity and FPS */
    setY(getY() + (vel / FPS));

    /* Ensures dino doesn't go below floor */
    if(getY() + getHeight() > FLOOR_HEIGHT){
        vel = 0;
        acc = 0;
        setY(FLOOR_HEIGHT - getHeight());
    }
}

/* Made by Kurt */
/* To be run every frame to update the velocity of the dino */
void Dino :: UpdateVelocity(){
    vel += (acc / FPS);
}

/* Made by Hunter */
/* Draw the dino to the LCD screen using the current animation state */
void Dino :: Draw(){
    animationFrames[animationState].Draw(getX() - DINO_X_OFFSET,getY()); 
}

/* Made by Hunter */
/* Update the dino animation Sprite depending on the current dinoState */
void Dino :: UpdateAnimation(int tic) {
    switch (dinoState)
    {
    case DS_JUMP:
    case DS_IDLE:
        animationState = DF_IDLE;
        break;
    
    case DS_RUN:

        /* Alternates between the two run Sprites each frame */
        animationState = (tic / 3) % 2 ? DF_RUN_1 : DF_RUN_2;
        break;

    case DS_DUCK:

        /* Alternates between the two duck Sprites each frame */
        animationState = (tic / 3) % 2 ? DF_DUCK_1 : DF_DUCK_2;
        break;

    case DS_DEAD:
        animationState = DF_DEAD;
    
    default:
        break;
    }
}

/* Made by Kurt */
/* Causes the dinosaur to be given a negative velocity (jump) */
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

/* Made by Kurt */
/* Causes the dinosaur to duck by adjusting hitbox and animation frames */
void Dino :: Duck(){
    
    /* If dino on floor */
    if(getY() == FLOOR_HEIGHT - getHeight()){

        /* Adjust Y position to account for different dinosaur height */
        setY(getY() + (TREX_IDLE_HEIGHT - TREX_DUCK_1_HEIGHT));
    }

    /* If dino above floor and not already set to ducking */
    if(getY() < FLOOR_HEIGHT - getHeight() && dinoState != DS_DUCK){

        /* Adjust Y position to account for different dinosaur height */
        setY(getY() + (TREX_IDLE_HEIGHT - TREX_DUCK_1_HEIGHT));
    }
    
    /* Set height and width of dinosaur */
    setHeight(TREX_DUCK_1_HEIGHT);
    setWidth(TREX_DUCK_1_WIDTH - DINO_X_OFFSET);
    
    dinoState = DS_DUCK;
}

/* Made by Kurt */
/* For when input is remove from screen, what animation to use */
void Dino :: Settle(){

    /* Set height and width of dino */
    setHeight(TREX_IDLE_HEIGHT);
    setWidth(DINO_HIT_WIDTH);

    /* If beneath floor, set to normal height */
    if(getLowerBound() > FLOOR_HEIGHT){
        setY(FLOOR_HEIGHT - TREX_IDLE_HEIGHT);
    }
    
    /* If on floor, set to run */
    if(getY() == FLOOR_HEIGHT - getHeight()){
        dinoState = DS_RUN;

    /* If not on floor, the dinosaur is jumping */
    } else {
        dinoState = DS_JUMP;
    }
}

/* Made by Kurt */
/* When the user is ducking in the air, increase the vertical acceleration */
void Dino :: IncreaseGravity(){

    /* If acceleration is zero, the dino is on the ground */
    if(acc == 0) { return;}

    /* As long as acceleration is below limit, increase gravity */
    if(acc < MAX_DINO_ACC * FPS){
        acc += ACC_INC_VAR * FPS;
    }
}

/* Made by Kurt */
/* When the user is holding the jump button, decrease the verical acceleration */
void Dino :: DecreaseGravity(){

    /* If acceleration is zero, the dino is on the ground */
    if(acc == 0) { return;}

    /* As long as acceleration is above limit, decrease gravity */
    if(acc > MIN_DINO_ACC * FPS){
        acc -= ACC_DEC_VAR * FPS;
    }
}

/* Made by Kurt */
/* Kills the dinosaur movement and sets animation to dead */
void Dino :: Kill(){
    dinoState = DS_DEAD;
    vel = 0;
    acc = 0;
}