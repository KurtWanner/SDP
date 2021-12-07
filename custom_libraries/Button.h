#ifndef Button_H
#define Button_H
#include <OBJECT.h>
#include <string.h>

/* Made by Kurt */
/* Class definition of a button */
class Button : public Object{

    private:
        char text[10];
        
    public:

        /* Constructor inherited from Object */
        Button(int w, int h, float x, float y, const char *t) : Object(w, h, x, y) {
            strcpy(text, t);
        }

        void draw();
        bool btnClicked(int, int);

};

#endif