#ifndef POINT_H
#define POINT_H

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
    double getX();
    double getY();
    double getZ();
};

#endif
