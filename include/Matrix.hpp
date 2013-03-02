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
        using const_iterator = typename std::vector<Vector<Type>>::const_iterator;
        using iterator = typename std::vector<Vector<Type>>::iterator;

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
        /** Move constructor
         *  \param other Object to move from
         */
        Matrix(Matrix&& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Matrix& operator=(Matrix other);

        template <typename T>
        friend void swap(Matrix<T>& lhs, Matrix<T>& rhs) noexcept;

        Type& operator[](std::size_t idx);
        const Type& operator[](std::size_t idx) const;
        Vector<Type>& col(unsigned col);
        const Vector<Type>& col(unsigned col) const;

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

        template<typename T>
        friend std::ostream& operator<<(std::ostream& os, const Matrix<T>&m );
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
Matrix<Type>::Matrix(const Matrix<Type>& other):
    m_cols(other.m_cols)
{
    //copy ctor
}
template <typename Type>
Matrix<Type>::Matrix(Matrix<Type>&& other):
    Matrix()
{
    swap(*this, other);
}
// FIXME (Marius#9#): Implement assignment operator in an idiomatic way
template <typename Type>
Matrix<Type>& Matrix<Type>::operator=(Matrix<Type> rhs)
{
    swap(*this,rhs);
    return *this;
}
template <typename Type>
void swap(Matrix<Type>& lhs, Matrix<Type>& rhs) noexcept
{
    // enable ADL (not necessary in our case, but good practice)
    using std::swap;

    // by swapping the members of two classes,
    // the two classes are effectively swapped
    swap(lhs.m_cols, rhs.m_cols);
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
Vector<Type>& Matrix<Type>::col(unsigned col)
{
    return m_cols[col];
}

template <typename Type>
const Vector<Type>& Matrix<Type>::col(unsigned col) const
{
    return m_cols[col];
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
template<typename Type>
std::ostream& operator<<(std::ostream& os, const Matrix<Type>& m )
{
    for(unsigned row = 0; row < m.row_size(); ++row )
    {
        for(unsigned col = 0; col < m.col_size(); ++col )
            os << m.m_cols[col][row] << "\t";
        os << "\n";
    }
    return os;
}

}//ns LinAlg
#endif // MATRIX_H
