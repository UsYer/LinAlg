#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include "Vector.hpp"
namespace LinAlg
{
template <typename Type>
class Matrix
{
    public:
        /** Default constructor */
        Matrix();
        Matrix(unsigned rows, unsigned cols);
        Matrix(unsigned rows, unsigned cols, Type val);
        Matrix(const std::initializer_list<Vector<Type>>& vals);
        /** Default destructor */
        ~Matrix();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Matrix(const Matrix& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Matrix& operator=(const Matrix& other);

        Type& operator[](std::size_t idx);
        const Type& operator[](std::size_t idx) const;

        std::size_t size() const
        {
            return m_cols.empty() ? 0 : m_cols.size() * m_cols[0].size();
        }
        std::size_t row_size() const
        {
            return m_cols.empty() ? 0 : m_cols[0].size();
        }
        std::size_t col_size() const
        {
            return m_cols.size();
        }
        bool empty() const;
    protected:
    private:
        std::vector<Vector<Type>> m_cols;
};

template <typename Type>
Matrix<Type>::Matrix(unsigned rows, unsigned cols):
    m_cols(cols, Vector<Type>(rows))
{

}
template<typename Type>
Matrix<Type>::Matrix(unsigned rows, unsigned cols, Type val):
    m_cols(cols, Vector<Type>(rows, val))
{
}
template<typename Type>
Matrix<Type>::Matrix(const std::initializer_list<Vector<Type>>& vals):
    m_cols(vals)
{
}

template <typename Type>
Matrix<Type>::Matrix()
{
    //ctor
}

template <typename Type>
Matrix<Type>::~Matrix()
{
    //dtor
}
template <typename Type>
Matrix<Type>::Matrix(const Matrix<Type>& other)
{
    //copy ctor
}

template <typename Type>
Matrix<Type>& Matrix<Type>::operator=(const Matrix<Type>& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
template <typename Type>
Type& Matrix<Type>::operator[](std::size_t idx)
{
    std::size_t row_size = m_cols[0].size();
    if( idx > row_size - 1 )
    {
        std::size_t col = idx / row_size;
        std::size_t row = idx % row_size;
        return m_cols[col][row];
    }
    else return m_cols[0][idx];
}
template <typename Type>
const Type& Matrix<Type>::operator[](std::size_t idx) const
{
    std::size_t row_size = m_cols[0].size();
    if( idx > row_size - 1 )
    {
        std::size_t col = idx / row_size;
        std::size_t row = idx % row_size;
        return m_cols[col][row];
    }
    else return m_cols[0][idx];
}
template <typename Type>
bool Matrix<Type>::empty() const
{
    for(const auto& col : m_cols)
    {
        if(!col.empty())
            return false;
    }
    return true;
}
}//ns LinAlg
#endif // MATRIX_H
