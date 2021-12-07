
#include <FEHLCD.h>

#include "Constants.h"
#include "Graphics.h"
#include "OBSTACLE.h"

void Obstacle :: UpdatePosition(){
    if (type != OT_NONE) {
        setX(getX() - vel/FPS);
        if(getX() < 0){
            Reset();
        }
    }
}

void Obstacle :: Reset() {
    setWidth(0);
    setHeight(0);
    setX(LCD_WIDTH);
    setY(0);

    type = OT_NONE;
    spriteType = OS_CACT_SMALL_ONE;
}

void Obstacle :: Draw(){
    if (type != OT_NONE) {
        //LCD.DrawRectangle(getX(), getY(), getWidth(), getHeight());
        sprite.Draw(getX(), getY());
    }
}

void Obstacle :: setSprite(ObstacleSprite t) {
    sprite.Init(obstacle_sprite_list[t], obstacle_sprite_widths[t], obstacle_sprite_heights[t]);
}

ObstacleType Obstacle :: getType() {
    return type;
}

void Obstacle :: setType(ObstacleType t) {
    type = t;
}

void Obstacle :: UpdateAnimation(int tic) {
    if (type == OT_BIRD) {
        spriteType = (tic / 10) % 2 ? OS_BIRD_1 : OS_BIRD_2;
    }
}

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