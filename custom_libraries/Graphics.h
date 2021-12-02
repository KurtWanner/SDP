#ifndef GRAPHICS_H
#define GRAPHICS_H

class Sprite {
public:
    const unsigned char *pixels;
    int width, height;

    Sprite() {}
    void Init(const unsigned char *p, int w, int h);
    void Draw(int x, int y);
};

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

#endif