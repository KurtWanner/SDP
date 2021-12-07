#include <FEHLCD.h>

#include "Constants.h"
#include "Ground.h"

/* Made by Hunter */
/* Updates the ground X position */
void Ground :: UpdateGround(int speed) {
    setX(getX() - speed / FPS);
}

/* Made by Hunter */
/* Draws the ground to the LCD */
void Ground :: DrawGround() {
    sprite.Draw(getX(), getY());
}