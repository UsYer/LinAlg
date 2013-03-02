#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED
#include <stdexcept>
#include <numeric>
#include <cmath>
#include <algorithm>
namespace LinAlg
{
    Matrix<int> zeros(unsigned n)
    {
        return Matrix<int>(n,n,0);
    }
    Matrix<int> zeros(unsigned m, unsigned n)
    {
        return Matrix<int>(m,n,0);
    }
    Matrix<int> ones(unsigned n)
    {
        return Matrix<int>(n,n,1);
    }
    Matrix<int> ones(unsigned m, unsigned n)
    {
        return Matrix<int>(n,n,1);
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
        Vector<T> v(m.col_size());
        for( unsigned col = 0; col < m.col_size(); ++col )
        {
            v[col] = max(m.col(col));
        }
        return v;
    }
    template <typename T>
    Vector<T> diag(const Matrix<T>& m)
    {
        Vector<T> v(m.col_size());
        for( unsigned col = 0; col < m.col_size(); ++col )
        {
            v[col] = m.col(col)[col];
        }
        return v;
    }
    template <typename T>
    Vector<T> transpose(Vector<T> v) //since we need a copy in every case we use copy-by-value and leverage copy-ellision
    {
        return v.transpose();
    }
    template <typename T>
    Matrix<T> transpose(const Matrix<T>& m)
    {
        if( m.empty() )
            return m;

        unsigned row_size = m.row_size();
        unsigned col_size = m.col_size();
        Matrix<T> m_new(col_size,row_size);

        int j = 0;
        for( unsigned i = 0; i < row_size; ++i )
        {
            for( unsigned k = 0; k < col_size; ++k )
            {
                m_new[j++] = m[i+k*row_size];
            }
        }

        return m_new;
    }
    template <typename T>
    T sum(const Vector<T>& v)
    {
        return std::accumulate(v.cbegin(),v.cend(),0);
    }
    template <typename T>
    Vector<T> sum(const Matrix<T>& m)
    {
        Vector<T> v(m.col_size());
        for( unsigned col = 0; col < m.col_size(); ++col )
        {
            v[col] = sum(m.col(col));
        }
        return v;
    }
    template <typename T>
    Vector<T> abs(Vector<T> v)
    {
        for( auto& elem: v )
        {
            elem = std::abs(elem);
        }
        return v;
    }
    template <typename T>
    Matrix<T> abs(Matrix<T> m)
    {
        for( unsigned col = 0; col < m.col_size(); ++col )
        {
            m.col(col) = abs(m.col(col));
        }
        return m;
    }
    template <typename T>
    Vector<T> sqrt(Vector<T> v)
    {
        for( auto& elem: v )
        {
            if( elem < 0 )
                throw std::invalid_argument("Only non-negative numbers are allowed for sqrt.");
            elem = std::sqrt(elem);
        }
        return v;
    }
    template <typename T>
    Matrix<T> sqrt(Matrix<T> m)
    {
        for( unsigned col = 0; col < m.col_size(); ++col )
        {
            m.col(col) = sqrt(m.col(col));
        }
        return m;
    }
    template <typename T>
    double norm(const Vector<T>& v,unsigned p = 2)
    {
        //sum(abs(A).^p)^(1/p)
        auto abs_pow = [p](T res, T val){return res + std::pow(std::abs(val),p);};
        auto sum = std::accumulate(v.cbegin(),v.cend(),0,abs_pow);
        return std::pow(sum,1.0f/p);
    }
    enum Norm
    {
        inf,
        fro
    };
    template <typename T>
    T norm(const Matrix<T>& m, Norm n)
    {
        if( n == Norm::inf )
        {
            //max(sum(abs(A')))
            return max(sum(abs(transpose(m))));
        }
        else if(n == Norm::fro)
        {
            //fro:
            //sqrt(sum(diag(A'*A))).
            //return sqrt(sum(diag(transpose(m)*m)));
            return 0;
        }
    }
    template <typename T>
    T norm(Matrix<T> m, unsigned p)
    {
        if( p == 1 )
        {
            //max(sum(abs(A)))
            return max(sum(abs(m)));
        }
        else if(p == 2)
        {

            return 0;//max(svd(A));
        }
        else throw std::invalid_argument("The only matrix norms available are 1, 2, inf, and fro.");
    }
}


#endif // FUNCTIONS_HPP_INCLUDED
