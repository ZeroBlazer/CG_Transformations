#ifdef MATRIX_H
#define MATRIX_H

template<typename T>
class Matrix {
public:
    Matrix(size_t m, size_t n);

    ~Matrix();

    T& operator()(size_t i, size_t j);

    T operator()(size_t i, size_t j) const;

private:
    size_t m,
           n; 
    T *m_data;   
};


template<typename T>
Matrix<T>::Matrix(size_t m, size_t n) :
    m(m),
    n(n)
{
    m_data = new T[m*n];
}

template<typename T>
Matrix<T>::~Matrix()
{
    delete[] m_data;
}

template<typename T>
T& Matrix<T>::operator()(size_t i, size_t j) {
    return m_data[i*m + j];
}

template<typename T>
T Matrix<T>::operator()(size_t i, size_t j) const {
    return m_data[i*m + j];
}

#endif // !MATRIX_H