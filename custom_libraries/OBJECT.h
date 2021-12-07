#ifndef OBJECT_H
#define OBJECT_H

/* Object class declaration */
/* To be parent class for dinosaur, obstacles, and ground */
class Object {
    private: 
        /* Assume all objects are rectangles */
        int Width, Height;

        /* X and Y Positions for each object */
        float PosX, PosY;
    public:
        Object(int, int, float, float);

        /* These functions will be used for colision detection */
        int getLeftBound();
        int getRightBound();
        int getUpperBound();
        int getLowerBound();

        /* Following function used to access private variables */
        int getWidth();
        int getHeight();

        void setWidth(int);
        void setHeight(int);

        float getX();
        float getY();

        void setX(float);
        void setY(float); 

        /* Tests for collision between current object and argument object */
        bool collision(Object);
        
};


#endif 