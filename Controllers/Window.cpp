#include "Window.h"
#include <iostream>

Window::Window()
{
    // Bare constructor
    #ifdef DEBUG
    std::cout << "Window created   -> " << this << std::endl;
    #endif
}

Window::Window(Window const &windowCopy)
{
    // Copy constructor
    #ifdef DEBUG
    std::cout << "Window copied    -> " << this << " <- from " << &windowCopy << std::endl;
    #endif
}

void Window::operator=(Window const &windowRight)
{
    // Assignment constructor
    #ifdef DEBUG
    std::cout << "Window assigned  -> " << this << " <- from " << &windowRight << std::endl;
    #endif
}

Window::~Window()
{
    #ifdef DEBUG
    std::cout << "Window destroyed -> " << this << std::endl;
    #endif
}

// Singleton creator/getter
Window &Window::getSingleton()
{
    static Window singleton;
    return singleton;
}

Window &Window::getSingleton(int width, int height, std::string title)
{
    Window &window = Window::getSingleton();
    
    window.width = width;
    window.height = height;
    window.title = title;

    return window;
}

// Setters
void Window::setGlutArgcp(int *glutArgcp)
{
    Window::getSingleton().glutArgcp = glutArgcp;
}
void Window::setGlutArgv(char **glutArgv)
{
    Window::getSingleton().glutArgv = glutArgv;
}
void Window::setGlutArguments(int *glutArgcp, char **glutArgv)
{
    Window &window = Window::getSingleton();

    window.setGlutArgcp(glutArgcp);
    window.setGlutArgv(glutArgv);
}

// Getters
int Window::getWidth()
{
    return Window::getSingleton().width;
}
int Window::getHeight()
{
    return Window::getSingleton().height;
}
std::string Window::getTitle()
{
    return Window::getSingleton().title;
}
// Getters glut related
int *Window::getGlutArgcp()
{
    return Window::getSingleton().glutArgcp;
}
char **Window::getGlutArgv()
{
    return Window::getSingleton().glutArgv;
}
GLuint Window::getGlutProgram()
{
    return Window::getSingleton().glutProgram;
}

// Glut wrapper methods
void Window::glutInit(int *glutArgcp, char **glutArgv)
{
    Window &window = Window::getSingleton();
    if (!window.glutInitialised) {
        // Save object state
        window.setGlutArguments(glutArgcp, glutArgv);
        window.glutInitialised = true;
        
        // Initialise glut
        glutInit(window.getGlutArgcp(), window.getGlutArgv());
        glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
        glutInitWindowSize(window.getWidth(), window.getHeight());
        glutCreateWindow(window.getTitle().c_str());
        /*
        */

        /*
        // Initialise resources
        GLint linkError = GL_FALSE;
        window.glutProgram = glCreateProgram();

        // Shaders
        GLuint vs = glCreateShader(GL_VERTEX_SHADER);
        GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
        // Vertex shader
        const char *vsSource =
            "#version 120\n"
            "void main(void) {\n"
            "};";
        // Fragment shader
        const char *fsSource =
            "#version 120\n"
            "void main(void) {\n"
            "};";

        glShaderSource(vs, 1, &vsSource, NULL);
        glShaderSource(fs, 1, &fsSource, NULL);
        glCompileShader(vs);
        glCompileShader(fs);
        GLint compileError = GL_FALSE;
        glGetShaderiv(vs, GL_COMPILE_STATUS, &compileError);
        glGetShaderiv(fs, GL_COMPILE_STATUS, &compileError);

        // Link resources
        glAttachShader(window.glutProgram, vs);
        glAttachShader(window.glutProgram, fs);
        glLinkProgram(window.glutProgram);
        glGetProgramiv(window.glutProgram, GL_LINK_STATUS, &linkError);
        */

        // Assign callback functions
        glutDisplayFunc(windowDisplay);
    }
}
void Window::glutDisplayFrame()
{
    glutCheckLoop();
}

// Functions that need to declared outside of the Window object scope
void windowDisplay()
{
    // Clear background to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    /*
    // Use program
    Window &window = Window::getSingleton();
    glUseProgram(window.getGlutProgram());
    */

    // Display result
    glutSwapBuffers();
}
