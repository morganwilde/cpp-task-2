#include <iostream>
// Controllers
#include "Controllers/Window.h"
// Models
#include "Models/ShapeTriangle.h"

int main(int argc, char *argv[])
{
    Window &window = Window::getSingleton(400, 200, "Title");
    window.glutInitWrapper(&argc, argv);

    // Add shapes
    ShapeTriangle *triangle = new ShapeTriangle(Point(0, 0, 0), 200, 100);
    ShapeTriangle *triangle1 = new ShapeTriangle(Point(-200, -100, 0), 200, 100);
    window.shapesArray.add(triangle);
    window.shapesArray.add(triangle1);

    window.glutDisplayLoop();

    return 0;
}
