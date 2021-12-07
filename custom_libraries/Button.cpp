#include <FEHLCD.h>
#include "Constants.h"
#include "Button.h"
#include "Util.h"

/* Draws the button to the LCD Screen */
void Button :: draw(){

    /* Drawing the button border */
    LCD.DrawRectangle(getX(), getY(), getWidth(), getHeight());

    /* Writing the text to the screen */
    LCD.WriteAt(text, getX() + (getWidth() - (CHAR_WIDTH * StringLength(text))) / 2, getY() + BTN_TXT_Y);

}

/* Test if the x, y arguments are within the borders of the button */
bool Button :: btnClicked(int x, int y){

    /* Collision detection */
    if(x < getLeftBound()){ return false;};
    if(x > getRightBound()){ return false;};
    if(y > getLowerBound()){ return false;};
    if(y < getUpperBound()){ return false;};

    /* If none of the following if statement are triggered, the click was inside the button */
    return true;

}