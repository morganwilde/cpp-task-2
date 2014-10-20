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
    // Glut related properties
    bool glutInitialised;
    int *glutArgcp;
    char **glutArgv;
    GLuint glutProgram;
    GLint glutCoordinateAttribute;
    std::string glutCoordinateAttributeName;

public:
    ~Window();
    static Window &getSingleton();
    static Window &getSingleton(int width, int height, std::string title);
    // Setters
    void setGlutArgcp(int *glutArgcp);
    void setGlutArgv(char **glutArgv);
    void setGlutArguments(int *glutArgcp, char **glutArgv);
    // Getters
    int getWidth();
    int getHeight();
    std::string getTitle();
    // Getters glut related
    int *getGlutArgcp();
    char **getGlutArgv();
    GLuint getGlutProgram();

    // Glut wrapper methods
    void glutInit(int *glutArgcp, char **glutArgv);
    void glutDisplayFrame();
};

void windowDisplay();

#endif
