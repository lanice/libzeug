

#include <gmock/gmock.h>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;



class PropertyBool_test : public testing::Test
{
public:
    PropertyBool_test()
    {
    }

protected:
};



TEST_F(PropertyBool_test, toggleValue)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("boolProperty", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);

    prop->setValue(false);
    prop->toggleValue();
    ASSERT_TRUE(prop->value());

    prop->toggleValue();
    ASSERT_FALSE(prop->value());

    prop->toggleValue();
    prop->toggleValue();
    ASSERT_FALSE(prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyBool_test, toBool)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("boolProperty", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);
    prop->setValue(false);

    ASSERT_EQ(typeid(bool), typeid(prop->toBool()));
    ASSERT_FALSE(prop->toBool());

    delete prop;
    delete obj;
}

TEST_F(PropertyBool_test, fromBool)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("boolProperty", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);
    prop->setValue(false);

    prop->fromBool(true);
    ASSERT_TRUE(prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyBool_test, toString)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("boolProperty", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);

    prop->setValue(false);
    ASSERT_EQ("false", prop->toString());

    prop->setValue(true);
    ASSERT_EQ("true", prop->toString());

    delete prop;
    delete obj;
}

TEST_F(PropertyBool_test, fromString)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("boolProperty", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);
    prop->setValue(true);

    prop->fromString("false");
    ASSERT_FALSE(prop->value());

    prop->setValue("true");
    ASSERT_TRUE(prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyBool_test, toVariant)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("boolProperty", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);
    prop->setValue(true);

    auto var = prop->toVariant();

    ASSERT_EQ(typeid(bool), var.type());
    ASSERT_TRUE(var.value<bool>());

    delete prop;
    delete obj;
}

TEST_F(PropertyBool_test, fromVariant)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("boolProperty", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);
    prop->setValue(false);

    auto var = Variant(true);

    prop->fromVariant(var);

    ASSERT_TRUE(prop->value());

    delete prop;
    delete obj;
}
