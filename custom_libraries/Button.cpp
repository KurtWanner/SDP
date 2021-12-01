#include <Button.h>
#include <FEHLCD.h>
#include <Constants.h>

void Button :: draw(){
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(getX(), getY(), getWidth(), getHeight());
    LCD.WriteAt(text, getX() + BTN_TXT_X, getY() + BTN_TXT_Y);

}

bool Button :: btnClicked(int x, int y){
    if(x < getLeftBound()){ return false;};
    if(x > getRightBound()){ return false;};
    if(y > getLowerBound()){ return false;};
    if(y < getUpperBound()){ return false;};
    return true;

}