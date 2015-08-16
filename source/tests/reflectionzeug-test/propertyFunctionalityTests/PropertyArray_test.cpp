

#include <gmock/gmock.h>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;



class PropertyArray_test : public testing::Test
{
public:
    PropertyArray_test()
    {
    }

protected:
};


TEST_F(PropertyArray_test, setValue)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 3>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);

    prop->setValue(std::array<int, 3>{1,2,3});
    std::array<int, 3> arr1{1,2,3};
    ASSERT_EQ(arr1, prop->value());

    prop->setValue(std::array<int, 3>{-10,12343,0});
    std::array<int, 3> arr2{-10,12343,0};
    ASSERT_EQ(arr2, prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyArray_test, getValue)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 3>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    prop->setValue(std::array<int, 3>{1,2,3});
    
    std::array<int, 3> arr1{1,2,3};
    ASSERT_EQ(arr1, prop->value());

    prop->setValue(std::array<int, 3>{-10,12343,0});
    std::array<int, 3> arr2{-10,12343,0};
    ASSERT_EQ(arr2, prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyArray_test, getElement)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 3>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    prop->setValue(std::array<int, 3>{1,2,3});

    ASSERT_EQ(1, prop->getElement(0));
    ASSERT_EQ(2, prop->getElement(1));
    ASSERT_EQ(3, prop->getElement(2));

    delete prop;
    delete obj;
}

TEST_F(PropertyArray_test, setElement)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 3>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    prop->setValue(std::array<int, 3>{1,2,3});

    prop->setElement(0, 5);
    prop->setElement(1, 123);
    prop->setElement(2, -10000);

    ASSERT_EQ(5, prop->getElement(0));
    ASSERT_EQ(123, prop->getElement(1));
    ASSERT_EQ(-10000, prop->getElement(2));

    delete prop;
    delete obj;
}

TEST_F(PropertyArray_test, toString)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 3>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    prop->setValue(std::array<int, 3>{1,2,3});

    ASSERT_EQ("(1, 2, 3)", prop->toString());

    delete prop;
    delete obj;
}

TEST_F(PropertyArray_test, fromString)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 3>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    prop->setValue(std::array<int, 3>{1,2,3});

    ASSERT_TRUE(prop->fromString("(-10, 1000, 654)"));
    std::array<int, 3> array{-10, 1000, 654};

    ASSERT_EQ(array, prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyArray_test, toVariant)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 3>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    prop->setValue(std::array<int, 3>{1,2,3});

    auto var = prop->toVariant();

    auto varArray = Variant::array();
    varArray.asArray()->push_back(Variant(1));
    varArray.asArray()->push_back(Variant(2));
    varArray.asArray()->push_back(Variant(3));

    ASSERT_EQ(varArray.asArray()->at(0).value<int>(), var.asArray()->at(0).value<int>());
    ASSERT_EQ(varArray.asArray()->at(1).value<int>(), var.asArray()->at(1).value<int>());
    ASSERT_EQ(varArray.asArray()->at(2).value<int>(), var.asArray()->at(2).value<int>());

    delete prop;
    delete obj;
}

TEST_F(PropertyArray_test, fromVariant)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 3>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    prop->setValue(std::array<int, 3>{0,0,0});

    auto varArray = Variant::array();
    varArray.asArray()->push_back(Variant(1));
    varArray.asArray()->push_back(Variant(2));
    varArray.asArray()->push_back(Variant(3));

    prop->fromVariant(varArray);

    std::array<int, 3> array{1, 2, 3};

    ASSERT_EQ(array, prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyArray_test, isEmpty)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 0>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    auto prop2 = new Property<std::array<int, 1>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    auto prop3 = new Property<std::array<int, 100>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);

    ASSERT_TRUE(prop->isEmpty());
    ASSERT_FALSE(prop2->isEmpty());
    ASSERT_FALSE(prop3->isEmpty());

    delete prop;
    delete prop2;
    delete prop3;
    delete obj;
}

TEST_F(PropertyArray_test, count)
{
    auto obj = new MyObject<int>;
    auto prop = new Property<std::array<int, 0>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    auto prop2 = new Property<std::array<int, 1>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);
    auto prop3 = new Property<std::array<int, 100>>("ArrayProperty", obj, &MyObject<int>::arrayConstgetterconst, &MyObject<int>::arraySetterconst);

    ASSERT_EQ(0, prop->count());
    ASSERT_EQ(1, prop2->count());
    ASSERT_EQ(100, prop3->count());

    delete prop;
    delete prop2;
    delete prop3;
    delete obj;
}
