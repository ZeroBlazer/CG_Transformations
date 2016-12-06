#include "polygon.h"

Vertex::Vertex(int x, int y) :
    x(x),
    y(y)
{}

void Vertex::translate(float dx, float dy) {
    x += dx;
    y += dy;
}

void Vertex::scale(float sx, float sy) {
    x *= sx;
    y *= sy;
}

void Vertex::rotate(float theta) {
    cout << "x: " << x << "\ty: " << y << endl;
    x = x*cos(theta) - y*sin(theta);
    y = x*sin(theta) + y*cos(theta);
    cout << "x: " << x << "\ty: " << y << "\t Cos_O: " << cos(theta) << ", Sin_O: " << sin(theta) << endl;
}

Polygon::Polygon() 
{}

void Polygon::addVertex(int x, int y) {
    if(!closed) {
        vertices.push_back(Vertex(x,y));
        cout << "New vertex @ (" << x << ", " << y << ")\n";
    }
}

void Polygon::close() {
    if(!closed) {
        closed = true;
        cout << "Polygon was closed" << endl;
    }
}

bool Polygon::isClosed() {
    return closed;
}

void Polygon::translate(float dx, float dy) {
    for(auto it = vertices.begin(); it != vertices.end(); ++it) {
        it->translate(dx, dy);
    }
}

void Polygon::scale(float sx, float sy) {
    for(auto it = vertices.begin(); it != vertices.end(); ++it) {
        it->scale(sx, sy);
    }
}

void Polygon::rotate(float theta) {
    cout << "Rotate " << theta << " degrees" << endl;
    for(auto it = vertices.begin(); it != vertices.end(); ++it) {
        it->rotate(theta);
    }
}