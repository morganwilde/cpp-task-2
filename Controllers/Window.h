#ifndef WINDOW_H
#define WINDOW_H

class Window
{
private:
    Window();
    Window(Window const &windowCopy);
    void operator=(Window const &windowRight);

public:
    ~Window();
    static Window getSingleton();
};

#endif
