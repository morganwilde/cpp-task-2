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

Window &Window::getSingleton(int width, int height)
{
    Window &window = Window::getSingleton();
    
    window.width = width;
    window.height = height;

    return window;
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
