#include "Shape.h"
#include <cstdlib>

Shape::Shape()
{
    this->pointCount = 0;
    this->pointArray = (Point *)malloc(this->pointCount * sizeof(Point));
}

Shape::~Shape()
{
    free(this->pointArray);
    this->pointArray = NULL;
}

int Shape::getPointCount()
{
    return this->pointCount;
}

Point *Shape::getPointArray()
{
    return this->pointArray;
}

void Shape::pushToPointArray(Point point)
{
    this->pointCount++;
    this->pointArray = (Point *)realloc(this->pointArray, sizeof(Point) * this->pointCount);
    this->pointArray[this->pointCount - 1] = point;
}

Point Shape::popFromPointArray()
{
    Point point = this->pointArray[this->pointCount - 1];
    this->pointCount--;
    this->pointArray = (Point *)realloc(this->pointArray, sizeof(Point) * this->pointCount);
    return point;
}
