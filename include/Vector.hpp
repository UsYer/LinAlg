#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <initializer_list>
namespace LinAlg
{
/**
A Column vector.

*/
template<typename Type>
class Vector
{
    public:
        /** Default constructor */
        Vector() {}
        Vector(unsigned num_elements);
        ///creates Vector with num_elements of val
        Vector(unsigned num_elements, Type val);
        Vector(const std::initializer_list<Type>& vals);
        /** Default destructor */
        ~Vector() {}
        std::size_t size() const
        {
            return m_elements.size();
        }
        bool empty() const
        {
            return m_elements.empty();
        }
        Type& operator[](std::size_t idx);
        const Type& operator[](std::size_t idx) const;

        template <typename T>
        friend bool operator==(std::initializer_list<T>& vals, Vector<T> v);
        template <typename T>
        friend bool operator==(const Vector<T>& lhs, const Vector<T>& rhs);
        template <typename T>
        friend bool operator< (const Vector<T>& lhs, const Vector<T>& rhs);
    protected:
    private:
        std::vector<Type> m_elements;
};

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
bool operator==(std::initializer_list<T>& vals, Vector<T> v)
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
    return lhs.m_elements == rhs.m_elements;
}
template <typename T>
inline bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
{
    return !operator==(lhs,rhs);
}
template <typename T>
inline bool operator< (const Vector<T>& lhs, const Vector<T>& rhs)
{
    return lhs.m_elements < rhs.m_elements;
}
template <typename T>
inline bool operator> (const Vector<T>& lhs, const Vector<T>& rhs){return  operator< (rhs,lhs);}
template <typename T>
inline bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs){return !operator> (lhs,rhs);}
template <typename T>
inline bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs){return !operator< (lhs,rhs);}
} //ns LinAlg
#endif // VECTOR_HPP
