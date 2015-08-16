

#include <gmock/gmock.h>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;


enum class EnumClass : int {
    Flag1 = 0,
    Flag2 = 1,
    Flag3 = 2,
};

class EnumObject : public reflectionzeug::Object
{
public:
    void setter(const EnumClass & val)
    {
        m_enum = val;
    }

    const EnumClass & getter() const
    {
        return m_enum;
    }

private:
    EnumClass m_enum;
};


class PropertyEnum_test : public testing::Test
{
public:
    PropertyEnum_test()
    {
    }

protected:
};


// TEST_F(PropertyEnum_test, setValue)
// {
//     auto obj = new EnumObject;
//     auto prop = new Property<EnumClass>("EnumProperty", obj, &EnumObject::getter, &EnumObject::setter);



//     delete prop;
//     delete obj;
// }

