#include "Point.h"

Point::Point()
{
    this->setX(0);
    this->setY(0);
    this->setZ(0);
}

Point::Point(double x, double y, double z)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
}

Point::~Point()
{

}

// Setters
void Point::setX(double x)
{
    this->x = x;
}
void Point::setY(double y)
{
    this->y = y;
}
void Point::setZ(double z)
{
    this->z = z;
}
// Getters
double Point::getX()
{
    return this->x;
}
double Point::getY()
{
    return this->y;
}
double Point::getZ()
{
    return this->z;
}
