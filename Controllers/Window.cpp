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
void Window::setGlutCoordinateAttribute(const char *name)
{
    Window &window = Window::getSingleton();
    
    std::cout << "set: " << window.getGlutCoordinateAttribute() << " to: " << name << std::endl;
    window.glutCoordinateAttribute = glGetAttribLocation(window.getGlutProgram(), name);
    std::cout << "set: " << window.getGlutCoordinateAttribute() << std::endl;
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
GLint Window::getGlutCoordinateAttribute()
{
    return Window::getSingleton().glutCoordinateAttribute;
}

// Glut wrapper methods
void Window::glutInitWrapper(int *glutArgcp, char *glutArgv[])
{
    Window &window = Window::getSingleton();
    if (!window.glutInitialised) {
        // Save object state
        window.setGlutArguments(glutArgcp, glutArgv);
        window.glutInitialised = true;
        
        // Initialise glut
        glutInit(glutArgcp, glutArgv);
        glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
        glutInitWindowSize(window.getWidth(), window.getHeight());
        glutCreateWindow(window.getTitle().c_str());

        // Assign callback functions
        glutDisplayFunc(windowDisplay);

        // Initialise resources
        GLint linkError = GL_FALSE;
        window.glutProgram = glCreateProgram();
        std::cout << "window.glutProgram: " << window.glutProgram << std::endl;

        // Shaders
        GLuint vs = glCreateShader(GL_VERTEX_SHADER);
        GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
        // Vertex shader
        const char *vsSource =
            "#version 120\n"
            "attribute vec3 coord3d;\n"
            "void main(void) {\n"
            "    gl_Position = vec4(coord3d, 1.0);\n"
            "}";
        // Fragment shader
        const char *fsSource =
            "#version 120\n"
            "void main(void) {\n"
            "    gl_FragColor[0] = 0.2;\n"
            "    gl_FragColor[1] = 0.2;\n"
            "    gl_FragColor[2] = 0.2;\n"
            "}";

        glShaderSource(vs, 1, &vsSource, NULL);
        glShaderSource(fs, 1, &fsSource, NULL);
        glCompileShader(vs);
        glCompileShader(fs);
        GLint compileError = GL_FALSE;
        glGetShaderiv(vs, GL_COMPILE_STATUS, &compileError);
        std::cout << "vs: " << vs << " compile: " << compileError << std::endl;
        glGetShaderiv(fs, GL_COMPILE_STATUS, &compileError);
        std::cout << "fs: " << fs << " compile: " << compileError << std::endl;

        // Link resources
        glAttachShader(window.glutProgram, vs);
        glAttachShader(window.glutProgram, fs);
        glLinkProgram(window.glutProgram);
        glGetProgramiv(window.glutProgram, GL_LINK_STATUS, &linkError);
        glGetProgramiv(window.glutProgram, GL_ATTACHED_SHADERS, &linkError);
        std::cout << "active attributes: " << linkError << std::endl;

        const char *name = "coord3d";
        std::cout << "window.glutCoordinateAttribute: " << window.glutCoordinateAttribute << std::endl;
        window.glutCoordinateAttribute = glGetAttribLocation(window.glutProgram, name);
        std::cout << "window.glutCoordinateAttribute: " << window.glutCoordinateAttribute << std::endl;
        //window.setGlutCoordinateAttribute("coord2d");

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
    
    // Use program
    Window &window = Window::getSingleton();
    glUseProgram(window.getGlutProgram());

    // Temp
    glEnableVertexAttribArray(window.getGlutCoordinateAttribute());
    GLfloat a = 0.4;
    GLfloat vertices[] = {
        -a, a,
        a, a,
        a, -a,
    };
    //std::cout << window.getGlutCoordinateAttribute() << std::endl;
    glVertexAttribPointer(
        window.getGlutCoordinateAttribute(),
        2,
        GL_FLOAT,
        GL_FALSE,
        0,
        vertices
    );
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(window.getGlutCoordinateAttribute());
    // /Temp

    // Display result
    glutSwapBuffers();
}
