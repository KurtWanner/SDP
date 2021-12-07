#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Constants.h"

/* Class defition for the sprite */
class Sprite {
public:
    const unsigned char *pixels;
    int width, height;

    Sprite() {}
    void Set(const unsigned char *p, int w, int h);
    void Draw(int x, int y);
};

/* Various constants relating to animation sprites */
#define TREX_TITLE_WIDTH (150)
#define TREX_TITLE_HEIGHT (12)
extern const unsigned char t_rex_title[TREX_TITLE_WIDTH*TREX_TITLE_HEIGHT];

#define TREX_IDLE_WIDTH (20)
#define TREX_IDLE_HEIGHT (21)
extern const unsigned char t_rex_idle[TREX_IDLE_WIDTH*TREX_IDLE_HEIGHT];


#define TREX_DEAD_WIDTH TREX_IDLE_WIDTH
#define TREX_DEAD_HEIGHT TREX_IDLE_HEIGHT
extern const unsigned char t_rex_dead[TREX_DEAD_WIDTH*TREX_DEAD_HEIGHT];

#define TREX_RUN_1_WIDTH TREX_IDLE_WIDTH
#define TREX_RUN_1_HEIGHT TREX_IDLE_HEIGHT
extern const unsigned char t_rex_run_1[TREX_RUN_1_WIDTH*TREX_RUN_1_HEIGHT];

#define TREX_RUN_2_WIDTH TREX_IDLE_WIDTH
#define TREX_RUN_2_HEIGHT TREX_IDLE_HEIGHT
extern const unsigned char t_rex_run_2[TREX_RUN_2_WIDTH*TREX_RUN_2_HEIGHT];

#define TREX_DUCK_1_WIDTH (27)
#define TREX_DUCK_1_HEIGHT (13)
extern const unsigned char t_rex_duck_1[TREX_DUCK_1_WIDTH*TREX_DUCK_1_HEIGHT];

#define TREX_DUCK_2_WIDTH TREX_DUCK_1_WIDTH
#define TREX_DUCK_2_HEIGHT TREX_DUCK_1_HEIGHT
extern const unsigned char t_rex_duck_2[TREX_DUCK_2_WIDTH*TREX_DUCK_2_HEIGHT];

#define BIRD_1_WIDTH (21)
#define BIRD_1_HEIGHT (18)
extern const unsigned char bird_1[BIRD_1_WIDTH*BIRD_1_HEIGHT];

#define BIRD_2_WIDTH (BIRD_1_WIDTH)
#define BIRD_2_HEIGHT (BIRD_1_HEIGHT)
extern const unsigned char bird_2[BIRD_1_WIDTH*BIRD_1_HEIGHT];

#define CACTUS_SMALL_SINGLE_WIDTH (15)
#define CACTUS_SMALL_SINGLE_HEIGHT (33)
extern const unsigned char cactus_small_single[CACTUS_SMALL_SINGLE_WIDTH*CACTUS_SMALL_SINGLE_HEIGHT];

#define CACTUS_SMALL_DOUBLE_WIDTH (32)
#define CACTUS_SMALL_DOUBLE_HEIGHT (CACTUS_SMALL_SINGLE_HEIGHT)
extern const unsigned char cactus_small_double[CACTUS_SMALL_DOUBLE_WIDTH*CACTUS_SMALL_DOUBLE_HEIGHT];

#define CACTUS_SMALL_TRIPLE_WIDTH (49)
#define CACTUS_SMALL_TRIPLE_HEIGHT (CACTUS_SMALL_SINGLE_HEIGHT)
extern const unsigned char cactus_small_triple[CACTUS_SMALL_TRIPLE_WIDTH*CACTUS_SMALL_TRIPLE_HEIGHT];

#define CACTUS_BIG_SINGLE_WIDTH (23)
#define CACTUS_BIG_SINGLE_HEIGHT (46)
extern const unsigned char cactus_big_single[CACTUS_BIG_SINGLE_WIDTH*CACTUS_BIG_SINGLE_HEIGHT];

#define CACTUS_BIG_DOUBLE_WIDTH (48)
#define CACTUS_BIG_DOUBLE_HEIGHT (CACTUS_BIG_SINGLE_HEIGHT)
extern const unsigned char cactus_big_double[CACTUS_BIG_DOUBLE_WIDTH*CACTUS_BIG_DOUBLE_HEIGHT];

#define CACTUS_BIG_QUAD_WIDTH (73)
#define CACTUS_BIG_QUAD_HEIGHT (49)
extern const unsigned char cactus_big_quad[CACTUS_BIG_QUAD_WIDTH*CACTUS_BIG_QUAD_HEIGHT];

#define GROUND_WIDTH LCD_WIDTH
#define GROUND_HEIGHT (8)
extern const unsigned char ground_sprite[GROUND_WIDTH*GROUND_HEIGHT];
#endif