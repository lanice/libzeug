

#include <gmock/gmock.h>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;



class PropertyFilePath_test : public testing::Test
{
public:
    PropertyFilePath_test()
    {
    }

protected:
};


TEST_F(PropertyFilePath_test, toString)
{
    auto obj = new MyObject<FilePath>;
    auto prop = new Property<FilePath>("FilePathProperty", obj, &MyObject<FilePath>::constgetterconst, &MyObject<FilePath>::setterconst);
    prop->setValue(FilePath("/path/to/file.ext"));

    ASSERT_EQ("/path/to/file.ext", prop->toString());

    delete prop;
    delete obj;
}

TEST_F(PropertyFilePath_test, fromString)
{
    auto obj = new MyObject<FilePath>;
    auto prop = new Property<FilePath>("FilePathProperty", obj, &MyObject<FilePath>::constgetterconst, &MyObject<FilePath>::setterconst);

    prop->fromString("/path/to/file.ext");

    ASSERT_EQ(FilePath("/path/to/file.ext").string(), prop->value().string());

    delete prop;
    delete obj;
}

TEST_F(PropertyFilePath_test, toVariant)
{
    auto obj = new MyObject<FilePath>;
    auto prop = new Property<FilePath>("FilePathProperty", obj, &MyObject<FilePath>::constgetterconst, &MyObject<FilePath>::setterconst);
    prop->setValue(FilePath("/path/to/file.ext"));

    auto var = prop->toVariant();

    ASSERT_EQ(Variant("/path/to/file.ext").value<std::string>(), var.value<std::string>());

    delete prop;
    delete obj;
}

TEST_F(PropertyFilePath_test, fromVariant)
{
    auto obj = new MyObject<FilePath>;
    auto prop = new Property<FilePath>("FilePathProperty", obj, &MyObject<FilePath>::constgetterconst, &MyObject<FilePath>::setterconst);
    prop->setValue(FilePath("/some/other/path.ext"));

    auto variant = Variant("/path/to/file.ext");

    prop->fromVariant(variant);

    ASSERT_EQ(FilePath("/path/to/file.ext").string(), prop->value().string());

    delete prop;
    delete obj;
}
