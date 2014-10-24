#include "TestShapesArray.h"
#include "../Models/ShapesArray.h"

TestShapesArray::TestShapesArray()
{
    this->testingClassName = "ShapesArray";
    this->init();
}

void TestShapesArray::testConstructor()
{
    this->testInit(__func__);
    ShapesArray array = ShapesArray();
    if (array.getShapeArray() == NULL) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestShapesArray::testShapeCount()
{
    this->testInit(__func__);
    ShapesArray array = ShapesArray();
    if (array.getShapeCount() != 0) {
        this->testFailed();
    }
    this->testInterpret();
}
