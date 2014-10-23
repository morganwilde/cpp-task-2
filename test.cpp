#include "Tests/TestWindow.h"

int main(int argc, char *argv[])
{
    {
        TestWindow testWindow;
        testWindow.testWindowSingletonCreation();
        testWindow.testConstructor();
    } 
    {
        TestWindow testWindow;
        testWindow.testWindowSingletonCreation();
        testWindow.testConstructor();
    } 

    return 0;
}
