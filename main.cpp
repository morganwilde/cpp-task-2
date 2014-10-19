#include <iostream>
// Controllers
#include "Controllers/Window.h"

int main(int argc, char *argv[])
{
    Window &window = Window::getSingleton(400, 200);

    std::cout << window.getWidth() << std::endl;

    return 0;
}
