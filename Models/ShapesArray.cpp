#include "ShapesArray.h"

ShapesArray::ShapesArray()
{
    this->shapeCount = 0;
    this->array = (Shape *)malloc(this->shapeCount * sizeof(Shape));
}

ShapesArray::~ShapesArray()
{
    free(this->array);
    this->array = NULL;
}

int ShapesArray::getShapeCount()
{
    return this->shapeCount;
}

Shape *ShapesArray::getShapeArray()
{
    return this->array;
}
