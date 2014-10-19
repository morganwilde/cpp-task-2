#ifndef WINDOW_H
#define WINDOW_H

class Window
{
private:
    Window();
    void operator=(Window const &windowRight);

public:
    Window(Window const &windowCopy);
    ~Window();
    static Window &getSingleton();
};

#endif
