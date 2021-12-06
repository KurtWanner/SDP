#include <OBSTACLE.h>
#include <FEHLCD.h>
#include <Constants.h>
#include <random>

void Obstacle :: UpdatePosition(){
    setX(getX() - vel/FPS);
    if(getX() < 0){
        setX(LCD_WIDTH);
        setY(FLOOR_HEIGHT - (rand() % 20) - getHeight());
    }
}

void Obstacle :: Draw(){
    /* Draw as rectangle for now */
    LCD.DrawRectangle(getX(), getY(), getWidth(), getHeight());
}