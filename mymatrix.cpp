//template<typename T>
#include "mymatrix.h"

MyMatrix::MyMatrix(size_t m, size_t n) :
    m(m),
    n(n)
{
    m_data = new T[m*n];
}

//template<typename T>
MyMatrix::~MyMatrix()
{
    delete[] m_data;
}

//template<typename T>
MyMatrix::T& MyMatrix::operator()(size_t i, size_t j) {
    return m_data[i*m + j];
}

//template<typena You might think that if you had two files that wanted to use SimpleMap (say, Foo and Bar), and both included SimpleMap.h, then the compiler would complain about SimpleMap.cpp being included and compiled twice. Yet, surprisingly, it doesn't complain in g++ and cxx (although, it may depend on your compiler). me T>
MyMatrix::T MyMatrix::operator()(size_t i, size_t j) const {
    return m_data[i*m + j];
}

//template<typename T>
void MyMatrix::operator+(MyMatrix b) {
    if(m == b.m && n == b.n) {
        cout << "adding" << endl;
    }
    else
        cout << "Can't add matrix: fix size" << endl;
}

//template<typename T>
size_t MyMatrix::nRow() {
    return m;
}

//template<typename T>
size_t MyMatrix::nCol() {
    return n;
}