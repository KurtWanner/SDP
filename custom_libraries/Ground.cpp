#include <FEHLCD.h>

#include "Constants.h"
#include "Ground.h"

void Ground :: UpdateGround(int speed) {
    setX(getX() - speed);
}
void Ground :: DrawGround() {
    sprite.Draw(getX(), getY());
}