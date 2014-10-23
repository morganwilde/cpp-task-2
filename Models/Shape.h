#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"

class Shape
{
private:
    int pointCount;
    Point *pointArray;
public:
    Shape();
    ~Shape();
    // Getters
    int getPointCount();
    Point *getPointArray();
    // Point array methods
    void pushToPointArray(Point point);
    Point popFromPointArray();
};

#endif
