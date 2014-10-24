#ifndef SHAPESARRAY_H
#define SHAPESARRAY_H

#include "Shape.h"

class ShapesArray
{
private:
    int shapeCount;
    Shape *array;
public:
    ShapesArray();
    ~ShapesArray();
    // Getters
    int getShapeCount();
    Shape *getShapeArray();
};

#endif
