

#include <gmock/gmock.h>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;



class PropertyUnsignedIntegral_test : public testing::Test
{
public:
    PropertyUnsignedIntegral_test()
    {
    }

protected:
};


TEST_F(PropertyUnsignedIntegral_test, toULongLong)
{
    auto obj = new MyObject<unsigned long long>;
    auto prop = new Property<unsigned long long>("unsignedIntegralProperty", obj, &MyObject<unsigned long long>::constgetterconst, &MyObject<unsigned long long>::setterconst);
    prop->setValue(100000000000ULL);

    ASSERT_EQ(typeid(unsigned long long), typeid(prop->toULongLong()));

    ASSERT_EQ(100000000000ULL, prop->toULongLong());

    delete prop;
    delete obj;
}

TEST_F(PropertyUnsignedIntegral_test, fromULongLong)
{
    auto obj = new MyObject<unsigned long long>;
    auto prop = new Property<unsigned long long>("unsignedIntegralProperty", obj, &MyObject<unsigned long long>::constgetterconst, &MyObject<unsigned long long>::setterconst);
    prop->setValue(0ULL);

    auto longlong = 100000000000ULL;
    prop->fromULongLong(longlong);
    ASSERT_EQ(longlong, prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyUnsignedIntegral_test, toVariant)
{
    auto obj = new MyObject<unsigned long long>;
    auto prop = new Property<unsigned long long>("unsignedIntegralProperty", obj, &MyObject<unsigned long long>::constgetterconst, &MyObject<unsigned long long>::setterconst);
    prop->setValue(123ULL);

    auto var = prop->toVariant();

    ASSERT_EQ(typeid(unsigned long long), var.type());
    ASSERT_EQ(123ULL, var.value<unsigned long long>());

    delete prop;
    delete obj;
}

TEST_F(PropertyUnsignedIntegral_test, fromVariant)
{
    auto obj = new MyObject<unsigned long long>;
    auto prop = new Property<unsigned long long>("unsignedIntegralProperty", obj, &MyObject<unsigned long long>::constgetterconst, &MyObject<unsigned long long>::setterconst);
    prop->setValue(123ULL);

    auto var = Variant(100000000000ULL);

    prop->fromVariant(var);

    ASSERT_EQ(100000000000ULL, prop->value());

    delete prop;
    delete obj;
}

