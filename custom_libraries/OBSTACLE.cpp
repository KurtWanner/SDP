
#include <FEHLCD.h>

#include "Constants.h"
#include "Graphics.h"
#include "OBSTACLE.h"

/* Made by Hunter */
/* Updates the X position of the obstacle based on velocity */
void Obstacle :: UpdatePosition(){
    if (type != OT_NONE) {
        setX(getX() - vel/FPS);
        if(getX() < 0){
            Reset();
        }
    }
}

/* Made by Hunter */
/* Resets the object to the right of the screen with no set obstacle type */
void Obstacle :: Reset() {
    setWidth(0);
    setHeight(0);
    setX(LCD_WIDTH);
    setY(0);

    type = OT_NONE;
    spriteType = OS_CACT_SMALL_ONE;
}

/* Made by Hunter */
/* Draws the obstacle sprite to the LCD */
void Obstacle :: Draw(){
    if (type != OT_NONE) {
        sprite.Draw(getX(), getY());
    }
}

/* Made by Hunter */
/* Sets the pixel count, width and height of the obstacle */
void Obstacle :: setSprite(ObstacleSprite t) {
    sprite.Set(obstacle_sprite_list[t], obstacle_sprite_widths[t], obstacle_sprite_heights[t]);
}

/* Made by Hunter */
/* Returns the type of current obstacle */
ObstacleType Obstacle :: getType() {
    return type;
}

/* Made by Hunter */
/* Sets the type of the obstacle */
void Obstacle :: setType(ObstacleType t) {
    type = t;
}

/* Made by Hunter */
/* If the obstacle is a bird, update the animation frame */
void Obstacle :: UpdateAnimation(int tic) {
    if (type == OT_BIRD) {
        spriteType = (tic / 10) % 2 ? OS_BIRD_1 : OS_BIRD_2;
        sprite.Set(obstacle_sprite_list[spriteType], obstacle_sprite_widths[spriteType], obstacle_sprite_heights[spriteType]);
    }
}

/* Made by Hunter */
/* Set the velocity of the obstacle */
void Obstacle :: setVel(int v) {
    vel = v;
}

/* All Char arrays Made by Hunter */
const unsigned char *obstacle_sprite_list[NUM_OBST_SPRITES] {
    cactus_small_single,
    cactus_small_double,
    cactus_small_triple,
    cactus_big_single,
    cactus_big_double,
    cactus_big_quad,
    bird_1,
    bird_2
};

const int obstacle_sprite_widths[NUM_OBST_SPRITES] {
    CACTUS_SMALL_SINGLE_WIDTH,
    CACTUS_SMALL_DOUBLE_WIDTH,
    CACTUS_SMALL_TRIPLE_WIDTH,
    CACTUS_BIG_SINGLE_WIDTH,
    CACTUS_BIG_DOUBLE_WIDTH,
    CACTUS_BIG_QUAD_WIDTH,
    BIRD_1_WIDTH,
    BIRD_2_WIDTH
};

const int obstacle_sprite_heights[NUM_OBST_SPRITES] {
    CACTUS_SMALL_SINGLE_HEIGHT,
    CACTUS_SMALL_DOUBLE_HEIGHT,
    CACTUS_SMALL_TRIPLE_HEIGHT,
    CACTUS_BIG_SINGLE_HEIGHT,
    CACTUS_BIG_DOUBLE_HEIGHT,
    CACTUS_BIG_QUAD_HEIGHT,
    BIRD_1_HEIGHT,
    BIRD_2_HEIGHT,
};