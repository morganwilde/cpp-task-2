#include <iostream>
// Controllers
#include "Controllers/Window.h"

int main(int argc, char *argv[])
{
    Window::getSingleton();
    Window::getSingleton();

    std::cout << "Stack is being removed" << std::endl;

    return 0;
}
