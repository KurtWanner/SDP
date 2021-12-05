#include <OBSTACLE.h>
#include <FEHLCD.h>
#include <Constants.h>

void Obstacle :: UpdatePosition(){
    setX(getX() - vel/FPS);
    if(getX() < 0){
        setX(LCD_WIDTH);
    }
}

void Obstacle :: Draw(){
    /* Draw as rectangle for now */
    LCD.DrawRectangle(getX(), getY(), getWidth(), getHeight());
}