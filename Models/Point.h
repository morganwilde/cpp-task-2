#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
private:
    double x;
    double y;
    double z;
public:
    Point();
    Point(double x, double y, double z);
    ~Point();
    // Setters
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    // Getters
    double getX() const;
    double getY() const;
    double getZ() const;
    // Operators
    bool operator==(const Point &pointForComparison);
    bool operator!=(const Point &pointForComparison);
    friend std::ostream& operator<<(std::ostream &stream, const Point &point);
};

#endif
