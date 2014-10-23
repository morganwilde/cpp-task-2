#ifndef TESTPOINT_H
#define TESTPOINT_H

#include "Test.h"

class TestPoint : public Test
{
public:
    void testConstructor();
    void testSetterX();
    void testSetterY();
    void testSetterZ();
    void testGetterX();
    void testGetterY();
    void testGetterZ();
};

#endif
