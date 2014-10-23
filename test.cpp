#include "Tests/TestWindow.h"
#include "Tests/TestPoint.h"

int main(int argc, char *argv[])
{
    {
        TestWindow testWindow;
        testWindow.testWindowSingletonCreation();
        testWindow.testConstructor();
        testWindow.testSetterWidth();
        testWindow.testSetterHeight();
        testWindow.testSetterTitle();
        testWindow.testSetterTitleCString();
        testWindow.testSetterDisplayLoop();
        testWindow.testSetterGlutArguments();
    } 
    {
        TestPoint testPoint;
        testPoint.testConstructor();
        testPoint.testSetterX();
        testPoint.testSetterY();
        testPoint.testSetterZ();
        testPoint.testGetterX();
        testPoint.testGetterY();
        testPoint.testGetterZ();
    }

    return 0;
}
