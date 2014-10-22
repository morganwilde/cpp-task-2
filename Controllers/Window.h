#ifndef WINDOW_H
#define WINDOW_H

#include <string>
// Mac OpenGL libraries
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

class Window
{
private:
    // These methods are private to hide constructor and copy functionality
    Window();
    void operator=(Window const &windowRight);
    Window(Window const &windowCopy);
    // Properties
    int width;
    int height;
    std::string title;
    char *titleCString;
    // Glut related properties
    bool glutInitialised;
    int *glutArgcp;
    char **glutArgv;
    GLuint glutProgram;
    GLint glutCoordinateAttribute;
    std::string glutCoordinateAttributeName;
    // Flags
    bool displayLoopActive;

public:
    ~Window();
    static Window &getSingleton();
    static Window &getSingleton(int width, int height, std::string title);
    // Setters
    void setTitle(std::string title);
    void setDisplayLoopActive(bool isActive);
    // Setters glut related
    void setGlutArguments(int *glutArgcp, char **glutArgv);
    void setGlutCoordinateAttribute(const char *name);
    // Getters
    int getWidth();
    int getHeight();
    std::string getTitle();
    char *getTitleCString();
    bool isDisplayLoopActive();
    // Getters glut related
    GLuint getGlutProgram();
    GLint getGlutCoordinateAttribute();

    // Glut wrapper methods
    void glutInitWrapper(int *glutArgcp, char *glutArgv[]);
    void glutDisplayFrame();
    void glutDisplayLoop();
};

void windowDisplay();

#endif
