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
    // Clean up
    free(this->getTitleCString());
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
    
    window.setWidth(width);
    window.setHeight(height);
    window.setTitle(title);

    return window;
}

// Setters
void Window::setWidth(int width)
{
    this->width = width;
    this->shapesArray.setWindowSize(this->getWidth(), this->getHeight());
}
void Window::setHeight(int height)
{
    this->height = height;
    this->shapesArray.setWindowSize(this->getWidth(), this->getHeight());
}
void Window::setTitle(std::string title)
{
    // C++ string title
    this->title = title;
    // C string title
    const char *temp = title.c_str();
    const int size = title.size() + 1;
    // allocate room for it
    if (!this->titleCString) {
        this->titleCString = (char *)malloc(sizeof(char) * size);
    } else {
        this->titleCString = (char *)realloc(this->titleCString, sizeof(char) * size);
    }
    // copy char by char
    for (int i = 0; i < size; i++) {
        this->titleCString[i] = temp[i];
    }
}
void Window::setDisplayLoopActive(bool isActive)
{
    this->displayLoopActive = isActive;
}
// Setters glut related
void Window::setGlutArguments(int *glutArgcp, char **glutArgv)
{
    this->glutArgcp = glutArgcp;
    this->glutArgv  = glutArgv;
}
void Window::setGlutCoordinateAttribute(const char *name)
{
    this->glutCoordinateAttribute = glGetAttribLocation(this->getGlutProgram(), name);
}

// Getters
int Window::getWidth()
{
    return this->width;
}
int Window::getHeight()
{
    return this->height;
}
std::string Window::getTitle()
{
    return this->title;
}
char *Window::getTitleCString()
{
    return this->titleCString;
}
bool Window::isDisplayLoopActive()
{
    return this->displayLoopActive;
}
// Getters glut related
int *Window::getGlutArgumentsArgcp()
{
    return this->glutArgcp;
}
char **Window::getGlutArgumentsArgv()
{
    return this->glutArgv;
}
GLuint Window::getGlutProgram()
{
    return this->glutProgram;
}
GLint Window::getGlutCoordinateAttribute()
{
    return this->glutCoordinateAttribute;
}

// Glut wrapper methods
void Window::glutInitWrapper(int *glutArgcp, char *glutArgv[])
{
    if (!this->glutInitialised) {
        // Save object state
        this->setGlutArguments(glutArgcp, glutArgv);
        this->glutInitialised = true;
        this->setDisplayLoopActive(true);
        
        // Initialise glut
        glutInit(glutArgcp, glutArgv);
        glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
        glutInitWindowSize(this->getWidth(), this->getHeight());
        glutCreateWindow(this->getTitleCString());

        // Assign callback functions
        glutDisplayFunc(windowDisplay);
        glutKeyboardFunc(windowKeyboard);
        glutSpecialFunc(windowKeyboardSpecial);

        // == TEMP ==
        // Initialise resources
        GLint linkError = GL_FALSE;
        this->glutProgram = glCreateProgram();

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
        //std::cout << "vs: " << vs << " compile: " << compileError << std::endl;
        glGetShaderiv(fs, GL_COMPILE_STATUS, &compileError);
        //std::cout << "fs: " << fs << " compile: " << compileError << std::endl;

        // Link resources
        glAttachShader(this->getGlutProgram(), vs);
        glAttachShader(this->getGlutProgram(), fs);
        glLinkProgram(this->getGlutProgram());
        glGetProgramiv(this->getGlutProgram(), GL_LINK_STATUS, &linkError);
        glGetProgramiv(this->getGlutProgram(), GL_ATTACHED_SHADERS, &linkError);
        //std::cout << "active attributes: " << linkError << std::endl;

        this->setGlutCoordinateAttribute("coord3d");
        // /= TEMP ==
    }
}
void Window::glutDisplayFrame()
{
    glutCheckLoop();
}

void Window::glutDisplayLoop()
{
    while (this->isDisplayLoopActive()) {
        this->glutDisplayFrame();
    }
}

// Functions that need to declared outside of the Window object scope
void windowDisplay()
{
    // Clear background to white
    glClearColor(1.0, 0.5, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Use program
    Window &window = Window::getSingleton();
    glUseProgram(window.getGlutProgram());

    // Temp
    glEnableVertexAttribArray(window.getGlutCoordinateAttribute());
    GLfloat a = 0.9;
    GLfloat vertices[] = {
        0, 0, 0,
        0, 1, 0,
        1, 0, 0
    };
    //std::cout << window.getGlutCoordinateAttribute() << std::endl;
    GLfloat *vertexArray = window.shapesArray.getVertexArray();
    int components = 3;
    int points = window.shapesArray.getVertexCount() / components;

    glVertexAttribPointer(
        window.getGlutCoordinateAttribute(),
        components, // TODO change this to a dynamic getter
        GL_FLOAT,
        GL_FALSE,
        0,
        vertexArray
        //vertices
    );
    glDrawArrays(GL_TRIANGLES, 0, points);
    glDisableVertexAttribArray(window.getGlutCoordinateAttribute());
    // /Temp

    // Display result
    glutSwapBuffers();
}

void windowKeyboard(unsigned char key, int x, int y)
{
    Window &window = Window::getSingleton();

    // Interpret the key
    switch (key) {
        case 27: // Escape
            window.setDisplayLoopActive(false);
            break;
        default: std::cout << (int)key << std::endl;
    }
}

void windowKeyboardSpecial(int key, int x, int y)
{
    Window &window = Window::getSingleton();

    // Interpret the key
    switch (key) {
        default: std::cout << key << std::endl;
    }
}
