#include "TestWindow.h"
#include "../Controllers/Window.h"

void TestWindow::testWindowSingletonCreation()
{
    this->testInit(__func__);
    Window &window1 = Window::getSingleton();
    Window &window2 = Window::getSingleton();
    if (&window1 != &window2) {
        this->testFailed();
    }
    this->testInterpret();
}
void TestWindow::testConstructor()
{
    this->testInit(__func__);
    Window &window = Window::getSingleton(100, 200, "Test");
    if (window.getWidth() != 200) {
        this->testFailed();
    }
    if (window.getHeight() != 200) {
        this->testFailed();
    }
    if (window.getTitle() != "Test") {
        this->testFailed();
    }
    this->testInterpret();
}
