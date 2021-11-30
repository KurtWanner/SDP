#include <FEHLCD.h>
#include <FEHFile.h>
#include <FEHUtility.h>
#include <LCDColors.h>
#include <FEHRandom.h>
#include <tigr.h>
#include <OBJECT.h>

/* Just set the FPS to 30 as a default value */
#define FPS 30

void UpdateFrame();
void UpdateDinosaur();
void UpdateObstacles();

int main() {
    // Clear background
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    // Testing object class
    Object a;
    a.setX(30);
    a.setY(10);
    a.setWidth(100);
    a.setHeight(50);
    LCD.DrawRectangle(a.getX(), a.getY(), a.getWidth(), a.getHeight());

    while (1) {
        LCD.Update();
        // Never end
    }
    return 0;
}

void UpdateFrame(){
    UpdateDinosaur();
    UpdateObstacles();
    //TODO
}

void UpdateDinosaur(){
    //TODO
}

void UpdateObstacles(){
    //TODO
}