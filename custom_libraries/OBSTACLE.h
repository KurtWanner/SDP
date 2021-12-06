#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "OBJECT.h"
#include "Constants.h"

enum ObstacleType {
    OT_CACTUS,
    OT_BIRD
};

enum ObstacleSprite {
    OS_CACT_SMALL_ONE,
    OS_CACT_SMALL_DUO,
    OS_CACT_SMALL_TRI,
    OS_CACT_BIG_ONE,
    OS_CACT_BIG_DUO,
    OS_CACT_BIG_QUAD,
    OS_BIRD_1,
    OS_BIRD_2,
    NUM_OBST_SPRITES
};

class Obstacle : public Object{
    private:
        ObstacleType type;
        ObstacleSprite spriteType;
        Sprite sprite;
        int vel = 4 * FPS;

        void setSprite(ObstacleSprite);
    public:
        /* Constructor inhereted from Object */
        Obstacle(int w, int h, float x, float y) : Object(w, h, x, y) {}
        
        void UpdatePosition();
        void Draw();
};

extern const unsigned char *obstacle_sprite_list[NUM_OBST_SPRITES];
extern const int obstacle_sprite_widths[NUM_OBST_SPRITES];
extern const int obstacle_sprite_heights[NUM_OBST_SPRITES];
#endif