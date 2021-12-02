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

void UpdateFrame(int tic);
void ClearFrame();
void UpdateDinosaur(int tic);
void UpdateObstacles();
void drawMainMenu();

// Dino :)
Dino dino(15, 15, 50.0, FLOOR_HEIGHT - 15.0);

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
            break;
        
        case GS_GAME:
            LCD.Clear();

            /* Draw floor once until floor animation added */
            LCD.SetFontColor(BLACK);
            LCD.DrawLine(0, FLOOR_HEIGHT, LCD_WIDTH, FLOOR_HEIGHT);
            int tic = 0;
            while (gameState == GS_GAME) {

                LCD.Update();
                Sleep(1.0 / FPS);
                UpdateFrame(tic);

                /* Clicking the screen makes dino jump */
                if(LCD.Touch(&x, &y)){
                    //printf("Touch\n");
                    dino.Jump();
                }
                // Never end
                tic++;
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
    //TODO
}

void ClearFrame() {
    LCD.Clear();
}

void UpdateDinosaur(int tic){
    dino.Erase();
    dino.UpdateVelocity();
    dino.UpdatePosition();
    dino.UpdateAnimation(tic);
    dino.Draw();
}

void UpdateObstacles(){
    //TODO
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