#include "Shape.h"
#include <cstdlib>

Shape::Shape()
{
    this->pointCount = 0;
    this->pointArray = (Point *)malloc(this->pointCount * sizeof(Point));
}

Shape::~Shape()
{
    try {
        free(this->pointArray);
        this->pointArray = NULL;
    } catch(...) {
        std::cout << "Trying to free Shape failed!" << std::endl;
    }
}

int Shape::getPointCount() const
{
    return this->pointCount;
}

Point *Shape::getPointArray() const
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

bool Shape::operator==(const Shape &shapeForComparison)
{
    bool equal = true;
    if (this->getPointCount() != shapeForComparison.getPointCount()) {
        equal = false;
    } else {
        for (int i = 0; i < this->getPointCount(); i++) {
            if (this->getPointArray()[i] != shapeForComparison.getPointArray()[i]) {
                equal = false;
            }
        }
    }
    return equal;
}

bool Shape::operator!=(const Shape &shapeForComparison)
{
    return !(*this == shapeForComparison);
}
