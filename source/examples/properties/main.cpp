
#include <cstdio>
#include <iostream>

#include <reflectionzeug/Property.h>
#include <reflectionzeug/PropertyGroup.h>
#include <reflectionzeug/PropertyDeserializer.h>
#include <reflectionzeug/PropertySerializer.h>

#include "SomeObject.h"

#ifdef WIN32
#define INI_PATH "data\\properties.ini"
#else
#define INI_PATH "data/properties.ini"
#endif

using namespace reflectionzeug;

void printGroup(const PropertyGroup & group)
{
    std::cout << group.path() << std::endl;

    group.forEachValuePropertyInterface([] (const ValuePropertyInterface & property)
    {
        std::cout << property.path() << " = " << property.toString() << std::endl;
    });

    group.forEachSubGroup([] (const PropertyGroup & subGroup)
    {
        printGroup(subGroup);
    });
}

void subscribeToChanges()
{
    std::cout << ">> subscribeToChanges()" << std::endl;

    Property<std::string> name("name", "Littlefinger");

    name.valueChanged.connect([] (const std::string & string) {
        std::cout << "Value Changed to \"" << string << "\"" << std::endl;
    });

    name.setValue("Tyrion Lannister");

    Property<int> number("number", 12);

    SomeObject object;
    number.valueChanged.connect(&object, &SomeObject::valueChanged);

    number.setValue(13);
}

void iterateOverProperties()
{
    std::cout << ">> iterateOverProperties()" << std::endl;

    PropertyGroup * group = new PropertyGroup("group");

    group->addProperty<double>("first", 0.3);
    group->addGroup("second");
    group->addProperty<int>("third", 7);
    group->addGroup("fourth");
    group->addProperty<Color>("fifth", Color(125, 125, 125));
    group->addProperty<std::array<int, 3>>("sixth", std::array<int, 3>{ 1, 2, 3 });

    group->forEachValuePropertyInterface([](AbstractProperty & property) {
        std::cout << property.title() << std::endl;
    });

    group->forEachSubGroup([](PropertyGroup & subGroup) {
        std::cout << subGroup.title() << std::endl;
    });

    delete group;
}

void accessProperties()
{
    std::cout << ">> accessProperties()" << std::endl;

    PropertyGroup * root = new PropertyGroup("root");
    auto * subGroup = root->addGroup("subGroup");
    subGroup->addProperty<int>("value", 12);

    std::cout << "Value of root/subGroup/value: ";
    std::cout << root->value<int>("subGroup/value") << std::endl;
}

void enumProperty()
{
    std::cout << ">> enumProperty()" << std::endl;

    PropertyGroup root("root");
    auto * normalModeProperty = root.addProperty<NormalMode>("normal_mode", NormalMode::LookAt);
    normalModeProperty->setStrings({ 
        { NormalMode::Vertex, "Vertex" },
        { NormalMode::Custom, "Custom" },
        { NormalMode::LookAt, "LookAt" }
    });
    
    printGroup(root);
}

void typeUsage()
{
    std::cout << ">> typeUsage()" << std::endl;
    
    ValuePropertyInterface * property = new Property<int>("property", 12);
    
    if (property->type() == Property<int>::stype())
    {
        std::cout << property->name() << " is of type int." << std::endl;
    }
}

bool saveProperties()
{
    std::cout << ">> saveProperties()" << std::endl;

    PropertyGroup root("root");

    root.addProperty<std::array<double, 3>>("normal", std::array<double, 3>{ -1.3, 2.6, -4.2 });
    root.addProperty<bool>("eatable", true);

    PropertyGroup * subGroup = root.addGroup("more");

    subGroup->addProperty<Color>("spinach_green", Color(74, 84, 43));
    subGroup->addProperty<int>("apple_count", 17);

    PropertySerializer serializer;
    return serializer.serialize(root, INI_PATH);
}

bool loadProperties()
{
    PropertyGroup root("root");

    root.addProperty<std::array<double, 3>>("normal", std::array<double, 3>{ 0.0, 0.0, 0.0 });
    root.addProperty<bool>("eatable", false);

    PropertyGroup * subGroup = root.addGroup("more");

    subGroup->addProperty<Color>("spinach_green", Color());
    subGroup->addProperty<int>("apple_count", 0);

    PropertyDeserializer deserializer;
    if (!deserializer.deserialize(root, INI_PATH))
        return false;


    printGroup(root);

    return true;
}

int main(int argc, char const *argv[])
{
    subscribeToChanges();
    iterateOverProperties();
    accessProperties();
    enumProperty();
    typeUsage();

    if (saveProperties() && loadProperties())
        std::remove(INI_PATH);

    return 0;
}
