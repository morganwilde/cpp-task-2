#ifndef WINDOW_H
#define WINDOW_H

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

public:
    ~Window();
    static Window &getSingleton();
    static Window &getSingleton(int width, int height);
    // Getters
    int getWidth();
    int getHeight();
};

#endif
