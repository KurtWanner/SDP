#include <FEHLCD.h>
#include <FEHFile.h>
#include <FEHUtility.h>
#include <LCDColors.h>
#include <FEHRandom.h>
#include <tigr.h>
#include "OBJECT.h"
#include <Dino.h>
#include "Graphics.h"
#include <Constants.h>
#include <Button.h>
#include <OBSTACLE.h>

void UpdateFrame(int tic);
void ClearFrame();
void UpdateDinosaur(int tic);
void UpdateObstacles();
void drawMainMenu();
bool CheckCollisions();
void DrawGameOver();
void ResetDino();
void ResetObstacles();

// Dino :)
Dino dino(TREX_IDLE_WIDTH, TREX_IDLE_HEIGHT, 50.0, FLOOR_HEIGHT - TREX_IDLE_HEIGHT);
Obstacle cactus(15, 15, LCD_WIDTH, FLOOR_HEIGHT - 40);

GameState gameState = GS_MENU;

/* x and y used for LCD.Touch() */
float x, y;

/* Initilize buttons for main menu */
Button playBtn(BTN_WIDTH, BTN_HEIGHT, BTN_X, 50.0, "Play");
Button statsBtn(BTN_WIDTH, BTN_HEIGHT, BTN_X, 100.0, "Stats");
Button quitBtn(BTN_WIDTH, BTN_HEIGHT, BTN_X, 150.0, "Quit");


int main() {

    /* Clear background */
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();

    /* To always run */
    while(gameState != GS_QUIT){

        switch (gameState)
        {
        case GS_MENU:
            {
            /* Draw main menu only once */
            drawMainMenu();

            /* Continue running until user makes choice */
            while(gameState == GS_MENU){
                if(LCD.Touch(&x, &y)){
                    if(playBtn.btnClicked(x, y)){ 
                        printf("Play");
                        gameState = GS_GAME;
                    }
                    /* Testing button collision */
                    if(statsBtn.btnClicked(x, y)){ 
                        printf("Stats");
                        gameState = GS_STATS;
                    }
                    if(quitBtn.btnClicked(x, y)){
                        printf("Quit");
                        gameState = GS_QUIT;
                    };
                }
            }
            }
            break;

            
        
        case GS_GAME:
            {
            LCD.Clear();

            /* Draw floor once until floor animation added */
            LCD.SetFontColor(BLACK);
            ResetDino();
            ResetObstacles();

            int tic = 0;
            while (gameState == GS_GAME) {

                LCD.Update();
                Sleep(1.0 / FPS);
                UpdateFrame(tic);


                /* Clicking the screen makes dino jump */
                /* Added tic requirement so dino doesn't immediately jump on game starting */
                if(LCD.Touch(&x, &y) && tic > 10){ 
                    //printf("Touch\n");
                    if(y < FLOOR_HEIGHT){
                        dino.Jump();
                        dino.DecreaseGravity();
                    } else {
                        dino.Duck();
                        dino.IncreaseGravity();
                    }
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

                // Never end
                tic++;
            }
            }
            break;
            

        case GS_GAMEOVER:
            {
            int tic = 0;
            float x, y;
            DrawGameOver();
            while(!LCD.Touch(&x, &y) || tic < 10){ tic++; }
            gameState = GS_GAME;

            }
            break;
            
        }
        
    }

    return 0;
}

void UpdateFrame(int tic){
    ClearFrame();
    UpdateDinosaur(tic); 
    UpdateObstacles();

    /* Added floor line for reference */
    LCD.DrawLine(0, FLOOR_HEIGHT, LCD_WIDTH, FLOOR_HEIGHT); //REMOVE
    //TODO
}

void ClearFrame() {
    LCD.Clear();
}

void UpdateDinosaur(int tic){
    dino.UpdateVelocity();
    dino.UpdatePosition();
    dino.UpdateAnimation(tic);
    dino.Draw();
}

void UpdateObstacles(){
    cactus.UpdatePosition();
    cactus.Draw();
}

void ResetDino(){
    dino.setHeight(TREX_IDLE_HEIGHT);
    dino.setWidth(TREX_IDLE_WIDTH);
    dino.setY(FLOOR_HEIGHT - TREX_IDLE_HEIGHT);
    dino.Settle();
}

void ResetObstacles(){
    cactus.setX(LCD_WIDTH);
}

bool CheckCollisions(){
    return dino.collision(cactus);
}

void drawMainMenu(){

    /* I added a horizontal offset to have the title in the middle of the screen */
    int horz_offset = 80;
    for (int i = 0; i < TREX_TITLE_HEIGHT; ++i) {
        for (int j = horz_offset; j < TREX_TITLE_WIDTH + horz_offset; ++j) {
            int col = t_rex_title[i * TREX_TITLE_WIDTH + j - horz_offset];
            LCD.SetFontColor(col ? WHITE : BLACK);
            LCD.DrawPixel(j, i);
        }
    }

    /* Draw all btns to screen */
    playBtn.draw();
    statsBtn.draw();
    quitBtn.draw();
}

void DrawGameOver(){
    ClearFrame();
    dino.UpdateAnimation(0);
    dino.Draw();
    cactus.Draw();
    
    /* Added floor line for reference */
    LCD.DrawLine(0, FLOOR_HEIGHT, LCD_WIDTH, FLOOR_HEIGHT); //REMOVE
    LCD.Update();
}