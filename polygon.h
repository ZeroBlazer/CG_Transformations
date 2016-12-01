#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <vector>
#include <math.h>
#include "matrix.h"

using namespace std;

struct Vertex {
    int     x,
            y;

    Vertex(int x, int y);

    void translate(float dx, float dy);

    void scale(float sx, float sy);

    void rotate(float theta);
};

struct Polygon
{
    vector<Vertex> vertices;
    bool closed;

    Polygon();

    void addVertex(int x, int y);

    void close();

    bool isClosed();

    void translate(float dx, float dy);

    void scale(float sx, float sy);

    void rotate(float theta);
};

#endif // !POLYGON_H