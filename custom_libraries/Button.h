#ifndef Button_H
#define Button_H
#include <OBJECT.h>
#include <string.h>

class Button : public Object{
    private:
        char text[10];
    public:
        Button(int w, int h, float x, float y, const char *t) : Object(w, h, x, y) {
            strcpy(text, t);
        }
        void draw();
        bool btnClicked(int, int);


};

#endif