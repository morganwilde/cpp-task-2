#include <iostream>
// Controllers
#include "Controllers/Window.h"

int main(int argc, char *argv[])
{
    Window &window = Window::getSingleton(400, 200, "Title");
    window.glutInit(&argc, argv);
    //window.glutDisplayFrame();

    return 0;
}
