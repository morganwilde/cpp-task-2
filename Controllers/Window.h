#ifndef WINDOW_H
#define WINDOW_H

class Window
{
private:
    Window();
    void operator=(Window const &windowRight);
    Window(Window const &windowCopy);

public:
    ~Window();
    static Window &getSingleton();
};

#endif
