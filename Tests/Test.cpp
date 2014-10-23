#include "Test.h"

Test::Test()
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
    std::cout << STYLE_TITLE << padding << prefix << classNameProper << padding << paddingExtra << STYLE_RESET << std::endl;
    std::cout << std::endl;
}

Test::~Test()
{
    // Calculate summary data
    int total = this->testsPassed + this->testsFailed;

    // Prepare the message
    std::stringstream message;
    message << this->testsPassed << "/" << total;

    // Align it
    int paddingLength = LINE_LENGTH - ( + PADDING_LEFT + STATUS_LENGTH);
    int paddingRightLength = LINE_LENGTH - paddingLength - message.str().length();
    std::string padding = "";
    std::string paddingRight = "";
    for (int i = 0; i < paddingLength; i++) {
        padding += " ";
    }
    for (int i = 0; i < paddingRightLength; i++) {
        paddingRight += " ";
    }
    std::cout << STYLE_FOOTER << padding << message.str() << paddingRight << STYLE_RESET << std::endl;
    std::cout << std::endl;
    //std::cout << " + succeeded: " << this->testsPassed << " (" << (this->testsPassed / total) * 100 << "%)" << std::endl;
    //std::cout << " -    failed: " << this->testsFailed << " (" << (this->testsFailed / total) * 100 << "%)" << std::endl;
}

//void Test::test(bool (Test::*testMethod)(void))
void Test::testInterpret()
{
    // Prepare user message
    std::string prefix = "+ ";
    std::string function = this->testingFunctionName;
    std::string status = "none";
    std::string postfix = "()";
    std::string style = STYLE_SUCCESS STYLE_RESET;
    if (this->testResult == TEST_SUCCESS) {
        this->testsPassed++;
        status = STYLE_SUCCESS "succeeded" STYLE_RESET;
    } else {
        this->testsFailed++;
        status = STYLE_FAILURE "failed   " STYLE_RESET;
    }

    // Add padding from the left of the result list
    std::string paddingLeft = "";
    for (int i = 0; i < PADDING_LEFT; i++) {
        paddingLeft += " ";
    }

    // Add padding to align statuses
    int paddingLength = LINE_LENGTH - (PADDING_LEFT + prefix.length() + function.length() + postfix.length() + status.length() - style.length() + PADDING_RIGHT);
    std::string padding = "";
    for (int i = 0; i < paddingLength; i++) {
        padding += ".";
    }

    // Print message
    std::cout << paddingLeft << prefix << function << postfix << padding << status << std::endl;
}

void Test::testInit(std::string name)
{
    this->testResult = true;
    this->testingFunctionName = name;
}

void Test::testFailed()
{
    this->testResult = false;
}
