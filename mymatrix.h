#pragma once

#include <iostream>
using namespace std;

class MyMatrix {
public:
    typedef float T;
    MyMatrix(size_t m, size_t n);

    ~MyMatrix();

    T& operator()(size_t i, size_t j);

    T operator()(size_t i, size_t j) const;

    void operator+(MyMatrix b);

    size_t nRow();

    size_t nCol();

private:
    size_t m,
           n; 
    T *m_data;
};