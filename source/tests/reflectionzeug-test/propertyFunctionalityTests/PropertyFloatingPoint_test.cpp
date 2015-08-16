

#include <gmock/gmock.h>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;



class PropertyFloatingPoint_test : public testing::Test
{
public:
    PropertyFloatingPoint_test()
    {
    }

protected:
};


TEST_F(PropertyFloatingPoint_test, toDouble)
{
    auto obj = new MyObject<float>;
    auto prop = new Property<float>("unsignedIntegralProperty", obj, &MyObject<float>::constgetterconst, &MyObject<float>::setterconst);
    prop->setValue(100.42f);

    ASSERT_EQ(typeid(double), typeid(prop->toDouble()));

    ASSERT_EQ(static_cast<double>(100.42f), prop->toDouble());

    delete prop;
    delete obj;
}

TEST_F(PropertyFloatingPoint_test, fromDouble)
{
    auto obj = new MyObject<float>;
    auto prop = new Property<float>("unsignedIntegralProperty", obj, &MyObject<float>::constgetterconst, &MyObject<float>::setterconst);
    prop->setValue(0.01f);

    auto val = 100.42;
    prop->fromDouble(val);
    ASSERT_EQ(static_cast<float>(val), prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyFloatingPoint_test, toVariant)
{
    auto obj = new MyObject<float>;
    auto prop = new Property<float>("unsignedIntegralProperty", obj, &MyObject<float>::constgetterconst, &MyObject<float>::setterconst);
    prop->setValue(100.42f);

    auto var = prop->toVariant();

    ASSERT_EQ(typeid(float), var.type());
    ASSERT_EQ(100.42f, var.value<float>());

    delete prop;
    delete obj;
}

TEST_F(PropertyFloatingPoint_test, fromVariant)
{
    auto obj = new MyObject<float>;
    auto prop = new Property<float>("unsignedIntegralProperty", obj, &MyObject<float>::constgetterconst, &MyObject<float>::setterconst);
    prop->setValue(0.01f);

    auto var = Variant(100.42f);

    prop->fromVariant(var);

    ASSERT_EQ(100.42f, prop->value());

    delete prop;
    delete obj;
}

