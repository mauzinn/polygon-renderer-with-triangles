#include <GLFW\glfw3.h>
#include <iostream>
#include "./include/polygon.hpp"
#include "./include/vectors.hpp"
#include "./include/time.hpp"

Polygon newSquare(Vector3f _position, Vector3f _size, Vector3f _color);

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow *window = glfwCreateWindow(800, 600, "2d Renderer", nullptr, nullptr);
    Time time;

    if (!window) {
        std::cerr << "-->Window<-- Error to initializate.\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    Polygon square1 = newSquare(Vector3f(0.4f, 0.3f, 0.0f), Vector3f(0.4f, 0.5f, 0.0f), Vector3f(1.0f, 1.0f, 1.0f));

    Vector3f *polygon1_vertexes = new Vector3f[5]{
        Vector3f(-0.5f, 0.8f, 0.0f),
        Vector3f(0.5f, -0.4f, 0.0f),
        Vector3f(0.4f, -0.6f, 0.0f),
        Vector3f(-0.1f, -0.8f, 0.0f),
        Vector3f(-0.8f, -0.3f, 0.0f)
    };
    Polygon polygon1(polygon1_vertexes, Vector3f(0.0f, 0.0f, 1.0f), 5);

    while (!glfwWindowShouldClose(window)) {
        if (time.canUpdate(24)) {
            glClear(GL_COLOR_BUFFER_BIT);

            polygon1.drawTriangles();
            square1.drawTriangles();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

Polygon newSquare(Vector3f _position, Vector3f _size, Vector3f _color) {
    Vector3f *new_square_vertexes = new Vector3f[4] {
        Vector3f(_position.x, _position.y, 0.0f),
        Vector3f(_position.x + _size.x, _position.y, 0.0f),
        Vector3f(_position.x + _size.x, _position.y - _size.y, 0.0f),
        Vector3f(_position.x, _position.y - _size.y, 0.0f)
    };

    return Polygon(new_square_vertexes, _color, 4);
}