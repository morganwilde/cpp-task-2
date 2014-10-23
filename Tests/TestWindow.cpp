#include "TestWindow.h"
#include "../Controllers/Window.h"

TestWindow::TestWindow()
{
    this->testsPassed = 0;
    this->testsFailed = 0;
    this->testingFunctionName = "";

    // Convert compiler formatted class name to the original
    std::string prefix = "Unit testing class ";
    std::string className = typeid(this).name();
    std::string classNameProper = "";
    bool numbers = false;
    bool proper = false;
    for (int i = 0; i < className.length(); i++) {
        // Loop char by char and remove prefix, usually "P10ClassName"
        if (isdigit(className[i])) {
            numbers = true;
        }
        if (!isdigit(className[i]) && numbers && !proper) {
            proper = true;
        }
        if (proper) {
            classNameProper += className[i];
        }
    }

    // Calculate necessary paddings to center the title
    int titleLength = prefix.length() + classNameProper.length();
    int paddingAvailable = LINE_LENGTH - titleLength;
    int paddingLength = paddingAvailable / 2;
    std::string padding = "";
    for (int i = 0; i < paddingLength; i++) {
        padding += " ";
    }
    std::string paddingExtra = "";
    if (paddingLength*2 < LINE_LENGTH) {
        paddingExtra = " ";
    }

    // Announce the start of testing
    std::cout << COLOR_TITLE << padding << prefix << classNameProper << padding << paddingExtra << COLOR_RESET << std::endl;
}

TestWindow::~TestWindow()
{
    float total = this->testsPassed + this->testsFailed;
    std::cout << " + succeeded: " << this->testsPassed << " (" << (this->testsPassed / total) * 100 << "%)" << std::endl;
    std::cout << " -    failed: " << this->testsFailed << " (" << (this->testsFailed / total) * 100 << "%)" << std::endl;
}

void TestWindow::test(bool (TestWindow::*testMethod)(void))
{
    // Run test
    bool testResult = (this->*testMethod)();

    // Prepare user message
    std::string prefix = " * testing ";
    std::string function = this->testingFunctionName;
    std::string status = "none";
    std::string postfix = "()";
    std::string style = COLOR_SUCCESS COLOR_RESET;
    if (testResult == TEST_SUCCESS) {
        this->testsPassed++;
        status = COLOR_SUCCESS "succeeded" COLOR_RESET;
    } else {
        this->testsFailed++;
        status = COLOR_FAILURE "failed   " COLOR_RESET;
    }

    // Add padding to align statuses
    int paddingLength = LINE_LENGTH - (prefix.length() + function.length() + postfix.length() + status.length() - style.length() + PADDING_RIGHT);
    std::string padding = "";
    for (int i = 0; i < paddingLength; i++) {
        padding += ".";
    }

    // Print message
    std::cout << prefix << function << postfix << padding << status << std::endl;
}

bool TestWindow::testWindowSingletonCreation()
{
    this->testingFunctionName = __func__;
    Window &window1 = Window::getSingleton();
    Window &window2 = Window::getSingleton();
    if (&window1 != &window2) {
        return false;
    }
    return true;
}
bool TestWindow::testConstructor()
{
    this->testingFunctionName = __func__;
    Window &window = Window::getSingleton(100, 200, "Test");
    if (window.getWidth() != 200) {
        return false;
    }
    if (window.getHeight() != 200) {
        return false;
    }
    if (window.getTitle() != "Test") {
        return false;
    }
    return true;
}
