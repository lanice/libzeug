

#include <gmock/gmock.h>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;



class PropertySignedIntegral_test : public testing::Test
{
public:
    PropertySignedIntegral_test()
    {
    }

protected:
};


TEST_F(PropertySignedIntegral_test, toLongLong)
{
    auto obj = new MyObject<long long>;
    auto prop = new Property<long long>("signedIntegralProperty", obj, &MyObject<long long>::constgetterconst, &MyObject<long long>::setterconst);
    prop->setValue(100000000000LL);

    ASSERT_EQ(typeid(long long), typeid(prop->toLongLong()));

    ASSERT_EQ(100000000000LL, prop->toLongLong());

    delete prop;
    delete obj;
}

TEST_F(PropertySignedIntegral_test, fromLongLong)
{
    auto obj = new MyObject<long long>;
    auto prop = new Property<long long>("signedIntegralProperty", obj, &MyObject<long long>::constgetterconst, &MyObject<long long>::setterconst);
    prop->setValue(0LL);

    auto longlong = 100000000000LL;
    prop->fromLongLong(longlong);
    ASSERT_EQ(longlong, prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertySignedIntegral_test, toVariant)
{
    auto obj = new MyObject<long long>;
    auto prop = new Property<long long>("signedIntegralProperty", obj, &MyObject<long long>::constgetterconst, &MyObject<long long>::setterconst);
    prop->setValue(123LL);

    auto var = prop->toVariant();

    ASSERT_EQ(typeid(long long), var.type());
    ASSERT_EQ(123LL, var.value<long long>());

    delete prop;
    delete obj;
}

TEST_F(PropertySignedIntegral_test, fromVariant)
{
    auto obj = new MyObject<long long>;
    auto prop = new Property<long long>("signedIntegralProperty", obj, &MyObject<long long>::constgetterconst, &MyObject<long long>::setterconst);
    prop->setValue(123LL);

    auto var = Variant(100000000000LL);

    prop->fromVariant(var);

    ASSERT_EQ(100000000000LL, prop->value());

    delete prop;
    delete obj;
}

