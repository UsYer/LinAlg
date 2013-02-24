#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED
namespace LinAlg
{
    Matrix<int> zeros(unsigned m, unsigned n = m)
    {
        return Matrix<int>(n,m,0);
    }
    Matrix<int> ones(unsigned n)
    {
        return Matrix<int>(n,m,1);
    }
    void magic()
    {

    }
    void round()
    {

    }
    template <typename T>
    T sum(Vector<T>);
    template <typename T>
    Vector<T> sum(Matrix<T>);
}


#endif // FUNCTIONS_HPP_INCLUDED
