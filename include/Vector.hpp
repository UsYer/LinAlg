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
        using const_iterator = typename std::vector<Type>::const_iterator;
        using iterator = typename std::vector<Type>::iterator;

        /** Default constructor */
        Vector() {}
        Vector(const Vector<Type>& other);
        Vector(Vector<Type>&& v);
        Vector(unsigned num_elements);
        ///creates Vector with num_elements of val
        Vector(unsigned num_elements, Type val);
        Vector(const std::initializer_list<Type>& vals);
        /** Default destructor */
        ~Vector() {}

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
        const_iterator begin() const
        {
            return m_elements.begin();
        }
        const_iterator cend() const
        {
            return m_elements.cend();
        }
        const_iterator end() const
        {
            return m_elements.end();
        }

        Type& operator[](std::size_t idx);
        const Type& operator[](std::size_t idx) const;

        template <typename T>
        friend bool operator==(std::initializer_list<T>& vals,const Vector<T>& v);
        template <typename T>
        friend bool operator==(const Vector<T>& lhs, const Vector<T>& rhs);
        template <typename T>
        friend bool operator< (const Vector<T>& lhs, const Vector<T>& rhs);

        template<typename T>
        friend std::ostream& operator<<(std::ostream& os, const Vector<T>& v );
    protected:
    private:
        std::vector<Type> m_elements;
        bool m_is_col = true;
};
template<typename Type>
Vector<Type>::Vector(Vector<Type>&& v):
    m_elements(std::move(v.m_elements)),
    m_is_col(v.m_is_col)
{

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

} //ns LinAlg
#endif // VECTOR_HPP
