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

void UpdateFrame(int tic);
void ClearFrame();
void UpdateDinosaur(int tic);
void UpdateObstacles();
void drawMainMenu();
bool CheckCollisions();
void DrawGameOver();
void ResetDino();
void ResetObstacles();

// WriteTextArray is used since LCD.WriteLine doesn't reset the row that it is on when the screen clears
void WriteTextArray(const char **, int);


Sprite title;
// Dino :)
Dino dino(TREX_IDLE_WIDTH, TREX_IDLE_HEIGHT, 50.0, FLOOR_HEIGHT - TREX_IDLE_HEIGHT);
Obstacle cactus(15, 15, LCD_WIDTH, FLOOR_HEIGHT - 40);

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

    title.Init(t_rex_title, TREX_TITLE_WIDTH, TREX_TITLE_HEIGHT);

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
                            gameState = GS_GAME;
                        }
                        /* Testing button collision */
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

            
        
        case GS_GAME:
            {
<<<<<<< HEAD
            LCD.Clear();

            /* Draw floor once until floor animation added */
            LCD.SetFontColor(BLACK);
            ResetDino();
            ResetObstacles();

            int tic = 0;
            while (gameState == GS_GAME) {

                LCD.Update();
                //Sleep(1.0 / FPS);
                UpdateFrame(tic);


                /* Clicking the screen makes dino jump */
                /* Added tic requirement so dino doesn't immediately jump on game starting */
                if(LCD.Touch(&x, &y) && tic > 10){ 
                    //printf("Touch\n");
                    if(y < FLOOR_HEIGHT){
                        dino.Jump();
                        dino.DecreaseGravity();
=======
                LCD.Clear();

                /* Draw floor once until floor animation added */
                LCD.SetBackgroundColor(WHITE);
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
>>>>>>> hunter
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
                break;
            }
            

        case GS_GAMEOVER:
            {
                int tic = 0;
                float x, y;
                DrawGameOver();
                while(!LCD.Touch(&x, &y) || tic < 10){ tic++; }
                gameState = GS_MENU;
                break;
            }

        case GS_HELP:
            {
                Button backBtn(BTN_WIDTH, BTN_HEIGHT, LCD_WIDTH-BTN_WIDTH-2.0, LCD_HEIGHT-BTN_HEIGHT-2.0, "Back"); // Define button
                const char * help_title =   "Instructions";
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
        
        case GS_STATS:
            {
                Button backBtn(BTN_WIDTH, BTN_HEIGHT, LCD_WIDTH-BTN_WIDTH-2.0, LCD_HEIGHT-BTN_HEIGHT-2.0, "Back"); // Define button
                const char * stats_title =   "High Scores";

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

void UpdateFrame(int tic) {
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
    LCD.SetBackgroundColor(WHITE);
    LCD.SetFontColor(BLACK);
    LCD.Clear();

    /* I added a horizontal offset to have the title in the middle of the screen */
    int horz_offset = (LCD_WIDTH - TREX_TITLE_WIDTH) / 2;
    title.Draw(horz_offset, 0);

    /* Draw all btns to screen */
    playBtn.draw();
    helpBtn.draw();
    statsBtn.draw();
    quitBtn.draw();
    creditsBtn.draw();
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

void WriteTextArray(const char **str, int size){
    for (int i = 0; i < size; ++i) {
        LCD.WriteAt(str[i], (LCD_WIDTH - (CHAR_WIDTH * (StringLength(str[i]) - 1))) / 2, CHAR_HEIGHT * (i + 2));
    }
}