#include <FEHLCD.h>
#include <FEHFile.h>
#include <FEHUtility.h>
#include <LCDColors.h>
#include <FEHRandom.h>
#include <tigr.h>

#include "OBJECT.h"
#include "Dino.h"
#include "Graphics.h"
#include "Constants.h"
#include "Button.h"
#include "OBSTACLE.h"
#include "Util.h"
#include "Ground.h"


/* Function prototypes */
void UpdateFrame(int tic, int speed);
void ClearFrame();
void UpdateDinosaur(int tic);
void UpdateObstacles(int tic, int speed);
void drawMainMenu();
bool CheckCollisions();
void DrawGameOver();
void ResetDino();
void SpawnObstacle();
void ResetObstacles();

// WriteTextArray is used since LCD.WriteLine doesn't reset the row that it is on when the screen clears
void WriteTextArray(const char **, int);

/* Title banner on the main menu */
Sprite title;

/* Dinosaur :) */
Dino dino(DINO_HIT_WIDTH, TREX_IDLE_HEIGHT, 30.0 + DINO_X_OFFSET, FLOOR_HEIGHT - TREX_IDLE_HEIGHT);

/* Obstacle list */
Obstacle obstacles[OBSTACLE_LIST_SIZE];

/* Ground object */
Ground ground;

/* Initilize the game state to main menu */
GameState gameState = GS_MENU;

/* x and y used for LCD.Touch() */
float x, y;

/* Initilize buttons for main menu */
Button playBtn(BTN_WIDTH, BTN_HEIGHT, BTN_X, 40.0, "Play");
Button helpBtn(BTN_WIDTH, BTN_HEIGHT, BTN_X, 80.0, "Help");
Button statsBtn(BTN_WIDTH, BTN_HEIGHT, BTN_X, 120.0, "Stats");
Button creditsBtn(BTN_WIDTH, BTN_HEIGHT, BTN_X, 160.0, "Credits");
Button quitBtn(BTN_WIDTH, BTN_HEIGHT, BTN_X, 200.0, "Quit");


int main() {

    /* Clear background */
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    Random.Seed();

    title.Set(t_rex_title, TREX_TITLE_WIDTH, TREX_TITLE_HEIGHT);

    /* To always run */
    while(gameState != GS_QUIT){

        switch (gameState)
        {

        /* Main menu */
        case GS_MENU:
            {
                /* Draw main menu only once */
                drawMainMenu();

                /* If LCD held between screens, wait until touch release */
                while (LCD.Touch(&x, &y));

                /* Continue running until user makes choice */
                while(gameState == GS_MENU){
                    if(LCD.Touch(&x, &y)){

                        /* Testing button collision */
                        if(playBtn.btnClicked(x, y)){
                            gameState = GS_GAME;
                        }                        
                        if(statsBtn.btnClicked(x, y)){
                            gameState = GS_STATS;
                        }
                        if(quitBtn.btnClicked(x, y)){
                            gameState = GS_QUIT;
                        }
                        if (creditsBtn.btnClicked(x, y)){
                            gameState = GS_CREDITS;
                        }
                        if(helpBtn.btnClicked(x, y)){
                            gameState = GS_HELP;
                        }
                    }
                }
                break;
            }

            
        /* Active game */
        case GS_GAME:
            {
                LCD.Clear();

                LCD.SetBackgroundColor(WHITE);
                LCD.SetFontColor(BLACK);
                ResetDino();
                ResetObstacles();

                int speed = START_SPEED;
                int score = 1;

                /* Tics used for animations and timing */
                int tic = 0;

                /* Continue until dino hit by obstacle */
                while (gameState == GS_GAME) {

                    LCD.Update();
                    UpdateFrame(tic, speed);

                    /* Clicking the screen makes dino jump */
                    /* Added tic requirement so dino doesn't immediately jump on game starting */
                    if(LCD.Touch(&x, &y) && tic > 10){ 
                        
                        /* If touch is above floor, jump and decrease gravity */
                        if(y < FLOOR_HEIGHT){
                            dino.Jump();
                            dino.DecreaseGravity();

                        /* If touch is below floor, duck an increase gravity */
                        } else {
                            dino.Duck();
                            dino.IncreaseGravity();
                        }
                    
                    /* If touch is released */
                    } else {
                        /* Chooses animation state */
                        dino.Settle();
                    }

                    /* Check collision with obstacles */
                    if(CheckCollisions()){ 
                        gameState = GS_GAMEOVER;
                        dino.Kill();
                        UpdateDinosaur(tic);
                    }

                    // Attempt to perform spawn twice a second
                    if (!(tic % (FPS/13 * 5))) {
                        // 1 in 3 chance of spawn
                        if (Random.RandInt() % 3) {
                            SpawnObstacle();
                        }
                    }

                    /* Increases speed for each multiple of 100 score */
                    if (score % 100 == 0 && tic % 3 == 0) {
                        speed += FPS;
                    }

                    // Never end
                    tic++;

                    /* Increase score once every 3 tics */
                    score = (tic%3) ? score : score + 1;
                }
                break;
            }
            
        /* Dead game */
        case GS_GAMEOVER:
            {
                float x, y;
                DrawGameOver();

                /* If LCD is held down between screens, wait until touch released */
                while(LCD.Touch(&x, &y)){}

                /* Wait until screen is touched, then return to main menu */
                while(!LCD.Touch(&x, &y)){}
                gameState = GS_MENU;
                break;
            }

        /* Help page */
        case GS_HELP:
            {
                Button backBtn(BTN_WIDTH, BTN_HEIGHT, LCD_WIDTH-BTN_WIDTH-2.0, LCD_HEIGHT-BTN_HEIGHT-2.0, "Back"); // Define button
                const char * help_title = "Instructions";
                const char * help_instr[] = {   "Press top half of screen", 
                                                "to jump over obstacles.",
                                                "",
                                                "Press Bottom half of ",
                                                "screen to duck.",
                                                "",
                                                "Go as far as you can!"};
                
                
                LCD.SetBackgroundColor(BLACK);
                LCD.SetFontColor(WHITE);
                LCD.Clear();
                LCD.ClearBuffer();

                LCD.WriteAt(help_title, (LCD_WIDTH - (CHAR_WIDTH * (StringLength(help_title) - 1))) / 2, 0);
                LCD.DrawLine(0, CHAR_HEIGHT + 2, LCD_WIDTH, CHAR_HEIGHT);
                WriteTextArray(help_instr, ARRAY_SIZE(help_instr));

                while (gameState == GS_HELP) {
                    backBtn.draw();
                    int x, y;
                    if (LCD.Touch(&x, &y) && backBtn.btnClicked(x, y)) {
                        gameState = GS_MENU;
                    }
                }
            }
            break;
        
        /* Stats page */
        case GS_STATS:
            {
                Button backBtn(BTN_WIDTH, BTN_HEIGHT, LCD_WIDTH-BTN_WIDTH-2.0, LCD_HEIGHT-BTN_HEIGHT-2.0, "Back"); // Define button
                const char * stats_title = "High Scores";

                LCD.SetBackgroundColor(BLACK);
                LCD.SetFontColor(WHITE);
                LCD.Clear();

                LCD.WriteAt(stats_title, (LCD_WIDTH - (CHAR_WIDTH * (StringLength(stats_title) - 1))) / 2, 0);
                LCD.DrawLine(0, CHAR_HEIGHT + 2, LCD_WIDTH, CHAR_HEIGHT);
                LCD.Write("\n\n\n");
                
                while (gameState == GS_STATS) {
                    backBtn.draw();
                    int x, y;
                    if (LCD.Touch(&x, &y) && backBtn.btnClicked(x, y)) {
                        gameState = GS_MENU;
                    }
                }

                break;
            }
        
        /* Credits page */
        case GS_CREDITS:
            {
                Button backBtn(BTN_WIDTH, BTN_HEIGHT, LCD_WIDTH-BTN_WIDTH-2.0, LCD_HEIGHT-BTN_HEIGHT-2.0, "Back"); // Define button
                const char * credits_title =    "Credits";
                const char * credits_text[] = { "Programmed by", 
                                                "Kurt Wanner",
                                                "and",
                                                "Hunter Seachrist",
                                                "",
                                                "Graphics by",
                                                "Unknown Google",
                                                "Artist"};

                LCD.SetBackgroundColor(BLACK);
                LCD.SetFontColor(WHITE);
                LCD.Clear();

                LCD.WriteAt(credits_title, (LCD_WIDTH - (CHAR_WIDTH * (StringLength(credits_title) - 1))) / 2, 0);
                LCD.DrawLine(0, CHAR_HEIGHT + 2, LCD_WIDTH, CHAR_HEIGHT);
                LCD.Write("\n\n\n");
                WriteTextArray(credits_text, ARRAY_SIZE(credits_text));
                
                while (gameState == GS_CREDITS) {
                    backBtn.draw();
                    int x, y;
                    if (LCD.Touch(&x, &y) && backBtn.btnClicked(x, y)) {
                        gameState = GS_MENU;
                    }
                }

                break;
            }
        }
        
    }

    return 0;
}

/* Update the frame for each tic */
void UpdateFrame(int tic, int speed) {
    ClearFrame();

    /* Update dino */
    UpdateDinosaur(tic);

    /* Update obstacles */ 
    UpdateObstacles(tic, speed);

    /* Update Ground */
    ground.UpdateGround(speed);
    ground.DrawGround();
}

/* Clears LCD frame */
void ClearFrame() {
    LCD.Clear();
}

/* Updates dinosaur velocity, position, and animation */
void UpdateDinosaur(int tic){
    dino.UpdateVelocity();
    dino.UpdatePosition();
    dino.UpdateAnimation(tic);
    dino.Draw();
}

/* Updates obstacles' velocity, position, and animation */
void UpdateObstacles(int tic, int speed){
    for (int i = 0; i < OBSTACLE_LIST_SIZE; ++i) {
        obstacles[i].setVel(speed);
        obstacles[i].UpdatePosition();
        obstacles[i].UpdateAnimation(tic);
        obstacles[i].Draw();
    }
}

/* Resets the dinosaur position between runs */
void ResetDino(){
    dino.setHeight(TREX_IDLE_HEIGHT);
    dino.setWidth(DINO_HIT_WIDTH);
    dino.setY(FLOOR_HEIGHT - TREX_IDLE_HEIGHT);
    dino.Settle();
}

/* Set obstacle by setting obstacle type and sprites */
void SpawnObstacle() {
    for (int i = 0; i < OBSTACLE_LIST_SIZE; ++i) {
        if (obstacles[i].getType() == OT_NONE) {
            if (Random.RandInt() % 8) {
                obstacles[i].setType(OT_CACTUS);
                ObstacleSprite type = (ObstacleSprite) (Random.RandInt() % (NUM_OBST_SPRITES - 2));
                obstacles[i].setSprite(type);
                obstacles[i].setWidth(obstacle_sprite_widths[type]);
                obstacles[i].setHeight(obstacle_sprite_heights[type]);

                obstacles[i].setX(LCD_WIDTH - obstacles[i].getWidth());
                obstacles[i].setY(FLOOR_HEIGHT - obstacles[i].getHeight() + 1);
                return;
            } else {
                obstacles[i].setType(OT_BIRD);
                obstacles[i].setSprite(OS_BIRD_1);
                obstacles[i].setWidth(BIRD_HIT_WIDTH);
                obstacles[i].setHeight(BIRD_HIT_HEIGHT);

                obstacles[i].setX(LCD_WIDTH - obstacles[i].getWidth());
                obstacles[i].setY(LCD_WIDTH - FLOOR_HEIGHT - obstacles[i].getHeight() - BIRD_FLY_HEIGHT);
                return;
            }
        }
    }

    return;
}

/* Reset all obstacles */
void ResetObstacles(){
    for (int i = 0; i < OBSTACLE_LIST_SIZE; ++i) {
        obstacles[i].Reset();
    }
}

/* Collisions between dinosaur and all obstacles */
bool CheckCollisions(){
    for (int i = 0; i < OBSTACLE_LIST_SIZE; ++i) {
        if (dino.collision(obstacles[i])) return true;
    }
    return false;
}

/* Draws the main menu */
void drawMainMenu(){
    LCD.SetBackgroundColor(WHITE);
    LCD.SetFontColor(BLACK);
    LCD.Clear();

    /* Horizontal offset to have the title in the middle of the screen */
    int horz_offset = (LCD_WIDTH - TREX_TITLE_WIDTH) / 2;
    title.Draw(horz_offset, 0);

    /* Draw all btns to screen */
    playBtn.draw();
    helpBtn.draw();
    statsBtn.draw();
    quitBtn.draw();
    creditsBtn.draw();
}

/* Draws game over screen to LCD */
void DrawGameOver(){
    ClearFrame();
    dino.UpdateAnimation(0);
    dino.Draw();

    for (int i = 0; i < OBSTACLE_LIST_SIZE; ++i){
        obstacles[i].Draw();
    }
    
    ground.DrawGround();
    LCD.Update();
}

/* Draws a string to the LCD */
void WriteTextArray(const char **str, int size){
    for (int i = 0; i < size; ++i) {
        LCD.WriteAt(str[i], (LCD_WIDTH - (CHAR_WIDTH * (StringLength(str[i]) - 1))) / 2, CHAR_HEIGHT * (i + 2));
    }
}