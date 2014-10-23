#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#define TEST_SUCCESS true
#define TEST_FAILURE false
#define COLOR_SUCCESS "\033[32m"
#define COLOR_FAILURE "\033[31m"
#define COLOR_TITLE "\033[47;30m"
#define COLOR_RESET "\033[0m"
#define LINE_LENGTH 80
#define PADDING_RIGHT 1

#include <iostream>

class TestWindow
{
private:
    int testsPassed;
    int testsFailed;
    std::string testingFunctionName;
public:
    TestWindow();
    ~TestWindow();
    void test(bool (TestWindow::*testMethod)(void));
    // Actual tests
    bool testWindowSingletonCreation();
    bool testConstructor();
};

#endif
