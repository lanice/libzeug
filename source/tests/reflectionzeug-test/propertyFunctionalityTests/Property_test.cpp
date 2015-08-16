

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



TEST_F(PropertyBool_test, hasName)
{
    auto obj = new MyObject<bool>;
    auto prop0 = new Property<bool>("", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);
    auto prop1 = new Property<bool>("name", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);

    ASSERT_FALSE(prop0->hasName());
    ASSERT_TRUE(prop1->hasName());

    delete prop0;
    delete prop1;
}

TEST_F(PropertyBool_test, name)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("name", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);

    ASSERT_EQ("name", prop->name());

    delete prop;
    delete obj;
}

TEST_F(PropertyBool_test, isValue_shouldSucceed)
{
    auto obj0 = new MyObject<bool>;
    auto prop0 = new Property<bool>("name", obj0, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);
    auto obj1 = new MyObject<std::string>;
    auto prop1 = new Property<std::string>("name", obj1, &MyObject<std::string>::constgetterconst, &MyObject<std::string>::setterconst);

    ASSERT_TRUE(prop0->isValue());
    ASSERT_TRUE(prop1->isValue());

    delete prop0;
    delete obj0;
    delete prop1;
    delete obj1;
}

TEST_F(PropertyBool_test, isValue_shouldFail)
{
    auto prop = new PropertyGroup("name");

    ASSERT_FALSE(prop->isValue());

    delete prop;
}

TEST_F(PropertyBool_test, isCollection_shouldSucceed)
{
    auto prop = new PropertyGroup("name");

    ASSERT_TRUE(prop->isCollection());

    delete prop;
}

TEST_F(PropertyBool_test, isCollection_shouldFail)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("name", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);

    ASSERT_FALSE(prop->isCollection());

    delete prop;
    delete obj;
}

TEST_F(PropertyBool_test, isGroup_shouldSucceed)
{
    auto prop = new PropertyGroup("name");

    ASSERT_TRUE(prop->isGroup());

    delete prop;
}

TEST_F(PropertyBool_test, isGroup_shouldFail)
{
    auto obj = new MyObject<bool>;
    auto prop = new Property<bool>("name", obj, &MyObject<bool>::constgetterconst, &MyObject<bool>::setterconst);

    ASSERT_FALSE(prop->isGroup());

    delete prop;
    delete obj;
}
