#ifndef Constants_H
#define Constants_H

#define FPS 60

/* Dino Gravity variables */
#define JUMP_VEL -8
#define MAX_DINO_ACC 100
#define DEF_DINO_ACC 60
#define MIN_DINO_ACC 30

/* Controls how fast gravity is increased or decreased */
#define ACC_DEC_VAR 3
#define ACC_INC_VAR 10

/* Where the floor is */
#define FLOOR_HEIGHT 160

/* Dimensions of the screen */
#define LCD_WIDTH 320
#define LCD_HEIGHT 240

/* Dimensions of a single character on the scree*/
#define CHAR_WIDTH 12
#define CHAR_HEIGHT 17

/* Game state constants */
enum GameState {
    GS_MENU,
    GS_GAME,
    GS_GAMEOVER,
    GS_STATS,
    GS_CREDITS,
    GS_HELP,
    GS_QUIT
};

/* Width, height, and x position for main menu buttons */
#define BTN_WIDTH 130
#define BTN_HEIGHT 30
#define BTN_X ((double)(((LCD_WIDTH) - (BTN_WIDTH)) / (2)))

/* Offset for button text */
#define BTN_TXT_Y 7
#define BTN_TXT_X 20


#endif