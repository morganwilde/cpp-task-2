#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include "Test.h"

class TestWindow : public Test
{
public:
    void testWindowSingletonCreation();
    void testConstructor();
    void testSetterWidth();
    void testSetterHeight();
    void testSetterTitle();
    void testSetterTitleCString();
    void testSetterDisplayLoop();
    void testSetterGlutArguments();
};

#endif
