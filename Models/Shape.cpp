#include "Shape.h"

Shape::Shape()
{
    this->pointArray = new Point;
}

Shape::~Shape()
{
    delete this->pointArray;
}
