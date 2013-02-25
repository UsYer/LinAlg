#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED
#include <stdexcept>
#include <numeric>
#include <cmath>
#include <algorithm>
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
    T max(Vector<T> v)
    {
        auto it = std::max_element(v.cbegin(), v.cend());
        if( it == v.cend() )
            return 0;
        else return *it;
    }
    template <typename T>
    Vector<T> max(Matrix<T> m)
    {

    }
    template <typename T>
    Vector<T> diag(const Matrix<T>& m)
    {

    }
    template <typename T>
    Vector<T> transpose(Vector<T> v) //since we need a copy in every case we use copy-by-value and leverage copy-ellision
    {
        return v.transpose();
    }
    template <typename T>
    Matrix<T> transpose(const Matrix<T>& m)
    {
        row_size = m.row_size();
        Matrix<T> m_new(m.col_size(),row_size);
        for( int i = 0; i < m.col_size() )
            m_new[i+ row_size] = m[i];

        return m_new;
    }
    template <typename T>
    T sum(Vector<T>);
    template <typename T>
    Vector<T> sum(Matrix<T>);

    template <typename T>
    T norm(Vector<T> v,unsigned p = 2)
    {
        //sum(abs(A).^p)^(1/p)
        auto abs_pow = [p](T val){return std::pow(std::abs(val),p)};
        return std::pow(std::accumulate(v.cbegin(),v.cend(),0,abs_pow),1/p);
    }
    enum Norm
    {
        inf,
        fro
    };
    template <typename T>
    T norm(Matrix<T> m, Norm n)
    {
        if( n == Norm::inf )
        {
            //max(sum(abs(A')))
            return 0;
        }
        else if(n == Norm::fro)
        {
        //fro:
        //sqrt(sum(diag(A'*A))).
            return 0;
        }
    }
    template <typename T>
    T norm(Matrix<T> m, unsigned p)
    {
        if( p == 1 )
        {
            //max(sum(abs(A')))
            return 0;
        }
        else if(p == 2)
        {
        //fro:
        //sqrt(sum(diag(A'*A))).
            return 0;
        }
        else throw std::invalid_argument("The only matrix norms available are 1, 2, inf, and fro.");
    }
}


#endif // FUNCTIONS_HPP_INCLUDED
