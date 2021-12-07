#include <FEHLCD.h>

#include "Constants.h"
#include "Ground.h"

/* Updates the ground X position */
void Ground :: UpdateGround(int speed) {
    setX(getX() - speed / FPS);
}

/* Draws the ground to the LCD */
void Ground :: DrawGround() {
    sprite.Draw(getX(), getY());
}