#pragma once

#include <reflectionzeug/Object.h>


template<typename Type>
class MyObject : public reflectionzeug::Object
{
public:
    const Type & constgetterconst() const
    {
        return m_var;
    }

    Type getterconst() const
    {
        return m_var;
    }

    void setterconst(const Type & val)
    {
        m_var = val;
    }

    void setter(Type val)
    {
        m_var = val;
    }

    const Type & arrayConstgetterconst(size_t index) const
    {
        return m_array[index];
    }

    Type arrayGetterconst(size_t index) const
    {
        return m_array[index];
    }

    void arraySetterconst(size_t index, const Type & val)
    {
        m_array[index] = val;
    }

    void arraySetter(size_t index, Type val)
    {
        m_array[index] = val;
    }

protected:
    Type m_var;
    std::array<Type, 3> m_array;
};