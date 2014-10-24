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
    int getPointCount() const;
    Point *getPointArray() const;
    // Point array methods
    void pushToPointArray(Point point);
    Point popFromPointArray();
    // Operators
    bool operator==(const Shape &shapeForComparison);
    bool operator!=(const Shape &shapeForComparison);
};

#endif
