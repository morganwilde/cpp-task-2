#include "Tests/TestWindow.h"

int main(int argc, char *argv[])
{
    {
        TestWindow testWindow;
        testWindow.test(&TestWindow::testWindowSingletonCreation);
        testWindow.test(&TestWindow::testConstructor);
    } 
    {
        TestWindow testWindow;
        testWindow.test(&TestWindow::testWindowSingletonCreation);
        testWindow.test(&TestWindow::testConstructor);
    } 

    return 0;
}
