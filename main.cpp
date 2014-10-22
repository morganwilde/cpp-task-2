#include <iostream>
// Controllers
#include "Controllers/Window.h"

int main(int argc, char *argv[])
{
    Window &window = Window::getSingleton(400, 200, "Title");
    window.glutInitWrapper(&argc, argv);
    while (1) {
        window.glutDisplayFrame();
    }

    return 0;
}
