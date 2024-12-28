#include <iostream>
#include <GLFW\glfw3.h>
#include "../include/vectors.hpp"
#include "../include/polygon.hpp"

Polygon::Polygon(Vector3f *_vertexes, Vector3f _color, int _size) {
    Polygon::vertexes = _vertexes;
    Polygon::color = _color;
    Polygon::size = _size;
}

Polygon::~Polygon() {
    delete[] Polygon::vertexes;
}

void Polygon::setColor(Vector3f _color) {
    Polygon::color = _color;
}

void Polygon::drawTriangles() {
    int _triangles = Polygon::size - 2;
    GLfloat _vertexes[_triangles * 9];

    int current_index = 0;
    for (int i = 1; i < Polygon::size - 1; i++) {
        _vertexes[current_index++] = Polygon::vertexes[0].x;
        _vertexes[current_index++] = Polygon::vertexes[0].y;
        _vertexes[current_index++] = Polygon::vertexes[0].z;

        _vertexes[current_index++] = Polygon::vertexes[i].x;
        _vertexes[current_index++] = Polygon::vertexes[i].y;
        _vertexes[current_index++] = Polygon::vertexes[i].z;

        _vertexes[current_index++] = Polygon::vertexes[i + 1].x;
        _vertexes[current_index++] = Polygon::vertexes[i + 1].y;
        _vertexes[current_index++] = Polygon::vertexes[i + 1].z;
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, _vertexes);

    glColor3f(Polygon::color.x, Polygon::color.y, Polygon::color.z);
    glDrawArrays(GL_TRIANGLES, 0, _triangles * 3);

    glDisableClientState(GL_VERTEX_ARRAY);
}