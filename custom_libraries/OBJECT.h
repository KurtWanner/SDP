#ifndef OBJECT_H
#define OBJECT_H

/* To be parent class for dinosaur and obstacles */
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

        int getWidth();
        int getHeight();

        void setWidth(int);
        void setHeight(int);

        float getX();
        float getY();

        void setX(float);
        void setY(float); 
        
};


#endif 