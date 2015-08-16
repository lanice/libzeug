

#include <gmock/gmock.h>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;



class PropertyString_test : public testing::Test
{
public:
    PropertyString_test()
    {
    }

protected:
};


TEST_F(PropertyString_test, toString)
{
    auto obj = new MyObject<std::string>;
    auto prop = new Property<std::string>("stringProperty", obj, &MyObject<std::string>::constgetterconst, &MyObject<std::string>::setterconst);
    prop->setValue("42");

    ASSERT_EQ(typeid(std::string), typeid(prop->toString()));
    ASSERT_EQ("42", prop->toString());

    delete prop;
    delete obj;
}

TEST_F(PropertyString_test, fromString)
{
    auto obj = new MyObject<std::string>;
    auto prop = new Property<std::string>("stringProperty", obj, &MyObject<std::string>::constgetterconst, &MyObject<std::string>::setterconst);
    prop->setValue("42");

    auto newString = "newString";
    prop->fromString(newString);
    ASSERT_EQ(newString, prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyString_test, toVariant)
{
    auto obj = new MyObject<std::string>;
    auto prop = new Property<std::string>("stringProperty", obj, &MyObject<std::string>::constgetterconst, &MyObject<std::string>::setterconst);
    prop->setValue("this is a string");

    auto var = prop->toVariant();

    ASSERT_EQ(typeid(std::string), var.type());
    ASSERT_EQ("this is a string", var.value<std::string>());

    delete prop;
    delete obj;
}

TEST_F(PropertyString_test, fromVariant)
{
    auto obj = new MyObject<std::string>;
    auto prop = new Property<std::string>("stringProperty", obj, &MyObject<std::string>::constgetterconst, &MyObject<std::string>::setterconst);
    prop->setValue("this is a string");

    auto var = Variant("this is another string");

    prop->fromVariant(var);

    ASSERT_EQ("this is another string", prop->value());

    delete prop;
    delete obj;
}
