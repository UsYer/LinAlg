#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <initializer_list>
#include <stdexcept>
namespace LinAlg
{
/**
A Column vector.

*/
template<typename Type>
class Vector
{
    public:
        using const_iterator = typename std::vector<Type>::const_iterator;
        using iterator = typename std::vector<Type>::iterator;

        /** Default constructor */
        Vector() {}
        Vector(const Vector<Type>& other);
        Vector(Vector<Type>&& v);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Vector& operator=(Vector<Type> other);
        Vector(unsigned num_elements);
        ///creates Vector with num_elements of val
        Vector(unsigned num_elements, Type val);
        Vector(const std::initializer_list<Type>& vals);
        /** Default destructor */
        ~Vector() {}

        template <typename T>
        friend void swap(Vector<T>& lhs, Vector<T>& rhs) noexcept;

        //-- capacity related functions --
        std::size_t size() const
        {
            return m_elements.size();
        }
        bool empty() const
        {
            return m_elements.empty();
        }

        bool is_col_vec() const
        {
            return m_is_col;
        }
        Vector<Type>& transpose()
        {
            m_is_col = !m_is_col;
            return *this;
        }

        //-- iterator interface --
        const_iterator cbegin() const
        {
            return m_elements.cbegin();
        }
        iterator begin()
        {
            return m_elements.begin();
        }
        const_iterator begin() const
        {
            return m_elements.begin();
        }
        const_iterator cend() const
        {
            return m_elements.cend();
        }
        iterator end()
        {
            return m_elements.end();
        }
        const_iterator end() const
        {
            return m_elements.end();
        }

        Type& operator[](std::size_t idx);
        const Type& operator[](std::size_t idx) const;

        //-- comparison --
        template <typename T>
        friend bool operator==(std::initializer_list<T>& vals,const Vector<T>& v);
        template <typename T>
        friend bool operator==(const Vector<T>& lhs, const Vector<T>& rhs);
        template <typename T>
        friend bool operator< (const Vector<T>& lhs, const Vector<T>& rhs);

        template<typename T>
        friend std::ostream& operator<<(std::ostream& os, const Vector<T>& v );

        //-- arithmetic --
        Vector<Type>& operator+=(const Vector<Type>& rhs);
        Vector<Type>& operator-=(const Vector<Type>& rhs);
        Vector<Type>& operator*=(Type rhs);
    protected:
    private:
        std::vector<Type> m_elements;
        bool m_is_col = true;
};
template<typename Type>
Vector<Type>::Vector(Vector<Type>&& v):
    Vector()
{
    swap(*this, v);
}
template<typename Type>
Vector<Type>::Vector(const Vector<Type>& v):
    m_elements(v.m_elements),
    m_is_col(v.m_is_col)
{

}
template<typename Type>
Vector<Type>::Vector(unsigned num_elements):
    m_elements(num_elements, Type())
{
}
template<typename Type>
Vector<Type>::Vector(unsigned num_elements, Type val):
    m_elements(num_elements, val)
{
}
template<typename Type>
Vector<Type>::Vector(const std::initializer_list<Type>& vals):
    m_elements(vals)
{
}
template <typename Type>
Vector<Type>& Vector<Type>::operator=(Vector<Type> v)
{
    swap(*this, v);
    return *this;
}
template <typename Type>
void swap(Vector<Type>& lhs, Vector<Type>& rhs) noexcept
{
    // enable ADL (not necessary in our case, but good practice)
    using std::swap;

    // by swapping the members of two classes,
    // the two classes are effectively swapped
    swap(lhs.m_elements, rhs.m_elements);
    swap(lhs.m_is_col, rhs.m_is_col);
}

template <typename Type>
Type& Vector<Type>::operator[](std::size_t idx)
{
    return m_elements[idx];
}
template <typename Type>
const Type& Vector<Type>::operator[](std::size_t idx) const
{
    return m_elements[idx];
}
template <typename T>
bool operator==(std::initializer_list<T>& vals, const Vector<T>& v)
{
    if( vals.size() != v.size() )
        return false;
    int i = 0;
    for(const auto& val: vals)
    {
        if( val != v[i++])
            return false;
    }
    return true;
}
///Should these operators work like their matlab counterparts or behave like c++ ones?
template <typename T>
inline bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
{
    return lhs.m_elements == rhs.m_elements && lhs.m_is_col == rhs.m_is_col;
}
template <typename T>
inline bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
{
    return !operator==(lhs,rhs);
}
template <typename T>
inline bool operator< (const Vector<T>& lhs, const Vector<T>& rhs)
{
    return lhs.m_elements < rhs.m_elements && lhs.m_is_col == rhs.m_is_col; // the orientation must be the same because the dimension must agree for comparison
}
template <typename T>
inline bool operator> (const Vector<T>& lhs, const Vector<T>& rhs){return  operator< (rhs,lhs);}
template <typename T>
inline bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs){return !operator> (lhs,rhs);}
template <typename T>
inline bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs){return !operator< (lhs,rhs);}

template<typename Type>
std::ostream& operator<<(std::ostream& os, const Vector<Type>& v )
{
    const char* sep = v.is_col_vec() ? "\n" : " ";
    for(auto elem : v.m_elements)
    {
        os << elem << sep;
    }
    return os;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& rhs)
{
    if( *this != rhs )
        throw std::invalid_argument("Dimensions must be equal.");

    for( auto it = m_elements.begin(), it_rhs = rhs.begin(); it != m_elements.end(); ++it, ++it_rhs)
        *it += *it_rhs;

    return *this;
}
template<typename T>
inline Vector<T> operator+(Vector<T> lhs, const Vector<T>& rhs)
{
  lhs += rhs;
  return lhs;
}
template<typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& rhs)
{
    if( *this != rhs )
        throw std::invalid_argument("Dimensions must be equal.");

    for( auto it = m_elements.begin(), it_rhs = rhs.begin(); it != m_elements.end(); ++it, ++it_rhs)
        *it -= *it_rhs;

    return *this;
}
template<typename T>
inline Vector<T> operator-(Vector<T> lhs, const Vector<T>& rhs)
{
  lhs -= rhs;
  return lhs;
}
//-- scalar multiplication --
template<typename T>
Vector<T>& Vector<T>::operator*=(T rhs)
{
    for( auto& elem : m_elements)
        elem *= rhs;

    return *this;
}
template<typename T>
inline Vector<T> operator*(T lhs, Vector<T> rhs)
{
  rhs *= lhs;
  return rhs;
}
template<typename T>
inline Vector<T> operator*(Vector<T> lhs, T rhs)
{
  lhs *= rhs;
  return lhs;
}
//-- vector-vector multiplication --
// Not possible right now, because it's not clear what should be returned.
// Could either be a scalar or a Matrix.
//template<typename T>
//Vector<T>& Vector<T>::operator*=(const Vector<T>& rhs)
//{
//    if( !m_is_col && rhs.is_col_vec() ) // scalar product: a'*b
//    {
//        if( size() != rhs.size() )
//            throw std::invalid_argument("Dimensions must be equal.");
//
//        T sum = 0;
//        for( auto it = m_elements.begin(), it_rhs = rhs.begin(); it != m_elements.end(); ++it, ++it_rhs)
//            sum += *it * *it_rhs;
//        //how do we return sum??
//    }
//
//    return *this;
//}
} //ns LinAlg
#endif // VECTOR_HPP
