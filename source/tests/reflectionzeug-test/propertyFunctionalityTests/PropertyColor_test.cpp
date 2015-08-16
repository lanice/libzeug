

#include <gmock/gmock.h>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;



class PropertyColor_test : public testing::Test
{
public:
    PropertyColor_test()
    {
    }

protected:
};


TEST_F(PropertyColor_test, toString)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(50, 100, 200, 0));

    ASSERT_EQ("#003264C8", prop->toString());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, fromString)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);

    auto color = Color(50, 100, 200, 0);

    prop->fromString("#003264C8");

    ASSERT_EQ(color, prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, toVariant)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(50, 100, 200, 0));

    auto var = prop->toVariant();

    const VariantMap & map = *(var.asMap());
    auto r = map.count("r") >= 1 ? map.at("r").value<int>() : 0;
    auto g = map.count("g") >= 1 ? map.at("g").value<int>() : 0;
    auto b = map.count("b") >= 1 ? map.at("b").value<int>() : 0;
    auto a = map.count("a") >= 1 ? map.at("a").value<int>() : 255;
    auto color = Color(r, g, b, a);

    ASSERT_EQ(Color(50, 100, 200, 0), color);

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, fromVariant)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setRGBA(0, 0, 00, 0);

    auto variant = Variant::map();
    (*(variant.asMap()))["r"] = 50;
    (*(variant.asMap()))["g"] = 100;
    (*(variant.asMap()))["b"] = 200;
    (*(variant.asMap()))["a"] = 0;

    prop->fromVariant(variant);
    auto colorFromProperty = Color(prop->red(), prop->green(), prop->blue(), prop->alpha());

    ASSERT_EQ(Color(50, 100, 200, 0), prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, getRGBA)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(50, 100, 200, 0));

    int r, g, b, a;
    prop->getRGBA(r, g, b, a);

    ASSERT_EQ(Color(50, 100, 200, 0), Color(r, g, b, a));

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, setRGBA)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setRGBA(50, 100, 200, 0);

    ASSERT_EQ(Color(50, 100, 200, 0), prop->value());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, red)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(50, 100, 200, 0));

    ASSERT_EQ(50, prop->red());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, setRed)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(0, 0, 0, 0));
    prop->setRed(50);

    ASSERT_EQ(50, prop->value().red());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, green)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(50, 100, 200, 0));

    ASSERT_EQ(100, prop->green());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, setGreen)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(0, 0, 0, 0));
    prop->setGreen(100);

    ASSERT_EQ(100, prop->value().green());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, blue)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(50, 100, 200, 0));

    ASSERT_EQ(200, prop->blue());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, setBlue)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(0, 0, 0, 0));
    prop->setBlue(200);

    ASSERT_EQ(200, prop->value().blue());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, alpha)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(50, 100, 200, 0));

    ASSERT_EQ(0, prop->alpha());

    delete prop;
    delete obj;
}

TEST_F(PropertyColor_test, setAlpha)
{
    auto obj = new MyObject<Color>;
    auto prop = new Property<Color>("ColorProperty", obj, &MyObject<Color>::constgetterconst, &MyObject<Color>::setterconst);
    prop->setValue(Color(0, 0, 0, 0));
    prop->setAlpha(123);

    ASSERT_EQ(123, prop->value().alpha());

    delete prop;
    delete obj;
}
