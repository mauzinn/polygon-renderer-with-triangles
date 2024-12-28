#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "./vectors.hpp"

class Polygon {
    private:
    Vector3f *vertexes, color;
    int size;

    public:
    Polygon(Vector3f *_vertexes, Vector3f _color, int _size);
    ~Polygon();

    void setColor(Vector3f _color);
    void drawTriangles();
};

#endif