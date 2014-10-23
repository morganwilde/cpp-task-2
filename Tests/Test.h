#ifndef TEST_H
#define TEST_H

#define TEST_SUCCESS true
#define TEST_FAILURE false
#define STYLE_SUCCESS "\033[32m"
#define STYLE_FAILURE "\033[31m"
#define STYLE_TITLE "\033[4m"
#define STYLE_FOOTER "\033[4m"
#define STYLE_RESET "\033[0m"
#define STYLE_RESET_COLOR "\033[0m\033[4m"
#define LINE_LENGTH 80
#define PADDING_LEFT 5
#define PADDING_RIGHT 5

#include <iostream>
#include <sstream>

class Test
{
private:
    int testsPassed;
    int testsFailed;
    bool testResult;
    std::string testingFunctionName;
public:
    Test();
    ~Test();
    //void test(bool (Test::*testMethod)(void));
    void testInterpret();
    void testInit(std::string name);
    void testFailed();
};

#endif
