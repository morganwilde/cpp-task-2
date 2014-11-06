#include <iostream>
// Controllers
#include "Controllers/Window.h"
// Models
#include "Models/ShapeTriangle.h"
#include "Models/ShapeRectangle.h"

int main(int argc, char *argv[])
{
    Window &window = Window::getSingleton(800, 600, "Title");
    window.glutInitWrapper(&argc, argv);

    // Add shapes
    ShapeTriangle *triangle1    = new ShapeTriangle(Point(0, 400, 0), 800, 100);
    ShapeRectangle *rect1       = new ShapeRectangle(Point(0, 0, 0), 200, 200);
    ShapeRectangle *line        = new ShapeRectangle(Point(400, 0, 0), 20, 600);

    window.shapesArray.add(triangle1);
    window.shapesArray.add(rect1);
    window.shapesArray.add(line);

    /*
    Point p(1, 2, 3);
    std::cout << p << std::endl;
    std::cin >> p;
    std::cout << p << std::endl;
    */

    window.glutDisplayLoop();

    return 0;
}
