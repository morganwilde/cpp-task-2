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
    // Flags
    bool displayLoopActive;

public:
    ~Window();
    static Window &getSingleton();
    static Window &getSingleton(int width, int height, std::string title);
    // Setters
    void setWidth(int width);
    void setHeight(int height);
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
    int *getGlutArgumentsArgcp();
    char **getGlutArgumentsArgv();
    GLuint getGlutProgram();
    GLint getGlutCoordinateAttribute();

    // Glut wrapper methods
    void glutInitWrapper(int *glutArgcp, char *glutArgv[]);
    void glutDisplayFrame();
    void glutDisplayLoop();
};

void windowDisplay();
void windowKeyboardSpecial(int key, int x, int y);
void windowKeyboard(unsigned char key, int x, int y);

#endif
