#include <iostream>

#include <reflectionzeug/new/AccessorGetSet.h>
#include <reflectionzeug/new/AccessorValue.h>
#include <reflectionzeug/new/ArrayAccessorGetSet.h>
#include <reflectionzeug/new/ArrayAccessorValue.h>
#include <reflectionzeug/new/Typed.h>
#include <reflectionzeug/new/Property.h>
#include <reflectionzeug/new/Visitor.h>


using namespace reflectionzeug;


// Global getter/setter test
int globalInt = 1;

int get()
{
    return globalInt;
}

void set(int value)
{
    globalInt = value;
}

// Global array getter/setter
int v1 = 10, v2 = 11, v3 = 12;

int getArray(size_t i)
{
         if (i == 0) return v1;
    else if (i == 1) return v2;
    else if (i == 2) return v3;
    else             return 0;
}

void setArray(size_t i, int value)
{
         if (i == 0) v1 = value;
    else if (i == 1) v2 = value;
    else if (i == 2) v3 = value;
}

// Custom class test
class TestClass {
public:
    static TestClass fromString(const std::string &str, bool * ok) {
        *ok = true;
        return TestClass();
    }

public:
    TestClass() {}
    ~TestClass() {}

    std::string toString() const
    {
        return "";
    }
};

// Enum test
enum MyEnum {
    One = 1,
    Two,
    Three
};

namespace reflectionzeug
{

template <>
struct EnumDefaultStrings<MyEnum>
{
    std::map<MyEnum, std::string> operator()()
    {
        std::map<MyEnum, std::string> values = {
            {One,   "One"},
            {Two,   "Two"},
            {Three, "Three"}
        };

        return values;
    }
};

}

// Visitor test
class MyVisitor : public reflectionzeug::Visitor<
                            AbstractCollection,
                            AbstractSignedIntegralInterface,
                            AbstractUnsignedIntegralInterface,
                            AbstractFloatingPointInterface,
                            AbstractBooleanInterface,
                            AbstractStringInterface,
                            AbstractColorInterface,
                            AbstractEnumInterface,
                            TypedSignedIntegral<int>,
                            TypedUnsignedIntegral<unsigned int>,
                            TypedFloatingPoint<float>,
                            TypedFloatingPoint<double>,
                            TypedBool,
                            TypedString,
                            TypedColor,
                            TypedFilePath,
                            TypedClass<TestClass>,
                            TypedEnum<MyEnum>,
                            TypedArray<int, 3>,
                            Typed<int>,
                            Typed<unsigned int>,
                            Typed<float>,
                            Typed<double>,
                            Typed<bool>,
                            Typed<std::string>,
                            Typed<FilePath>,
                            Typed<Color>,
                            Typed<TestClass>,
                            Typed<MyEnum>,
                            Typed<std::array<int, 3>>,
                            Property2<int> >
{
public:
    virtual void visit(AbstractCollection * typed) override
    {
        std::cout << "found AbstractCollection\n";
    }

    virtual void visit(AbstractSignedIntegralInterface * typed) override
    {
        std::cout << "found SignedIntegralInterface\n";
    }

    virtual void visit(AbstractUnsignedIntegralInterface * typed) override
    {
        std::cout << "found AbstractUnsignedIntegralInterface\n";
    }

    virtual void visit(AbstractFloatingPointInterface * typed) override
    {
        std::cout << "found AbstractFloatingPointInterface\n";
    }

    virtual void visit(AbstractBooleanInterface * typed) override
    {
        std::cout << "found AbstractBooleanInterface\n";
    }

    virtual void visit(AbstractStringInterface * typed) override
    {
        std::cout << "found AbstractStringInterface\n";
    }

    virtual void visit(AbstractColorInterface * typed) override
    {
        std::cout << "found AbstractColorInterface\n";
    }

    virtual void visit(AbstractEnumInterface * typed) override
    {
        std::cout << "found AbstractEnumInterface\n";
    }

    virtual void visit(TypedSignedIntegral<int> * typed) override
    {
        std::cout << "found TypedSignedIntegral<int>\n";
    }

    virtual void visit(TypedUnsignedIntegral<unsigned int> * typed) override
    {
        std::cout << "found TypedUnsignedIntegral<unsigned int>\n";
    }

    virtual void visit(TypedFloatingPoint<float> * typed) override
    {
        std::cout << "found TypedFloatingPoint<float>\n";
    }

    virtual void visit(TypedFloatingPoint<double> * typed) override
    {
        std::cout << "found TypedFloatingPoint<double>\n";
    }

    virtual void visit(TypedBool * typed) override
    {
        std::cout << "found TypedBool\n";
    }

    virtual void visit(TypedString * typed) override
    {
        std::cout << "found TypedString\n";
    }

    virtual void visit(TypedColor * typed) override
    {
        std::cout << "found TypedColor\n";
    }

    virtual void visit(TypedFilePath * typed) override
    {
        std::cout << "found TypedFilePath\n";
    }

    virtual void visit(TypedClass<TestClass> * typed) override
    {
        std::cout << "found TypedClass<TestClass>\n";
    }

    virtual void visit(TypedEnum<MyEnum> * typed) override
    {
        std::cout << "found TypedEnum<MyEnum>\n";
    }

    virtual void visit(TypedArray<int, 3> * typed) override
    {
        std::cout << "found TypedArray<int, 3>\n";
    }

    virtual void visit(Typed<int> * typed) override
    {
        std::cout << "found Typed<int>\n";
    }

    virtual void visit(Typed<unsigned int> * typed) override
    {
        std::cout << "found Typed<unsigned int>\n";
    }

    virtual void visit(Typed<float> * typed) override
    {
        std::cout << "found Typed<float>\n";
    }

    virtual void visit(Typed<double> * typed) override
    {
        std::cout << "found Typed<double>\n";
    }

    virtual void visit(Typed<bool> * typed) override
    {
        std::cout << "found Typed<bool>\n";
    }

    virtual void visit(Typed<std::string> * typed) override
    {
        std::cout << "found Typed<std::string>\n";
    }

    virtual void visit(Typed<Color> * typed) override
    {
        std::cout << "found Typed<Color>\n";
    }

    virtual void visit(Typed<FilePath> * typed) override
    {
        std::cout << "found Typed<FilePath>\n";
    }

    virtual void visit(Typed<TestClass> * typed) override
    {
        std::cout << "found Typed<TestClass>\n";
    }

    virtual void visit(Typed<MyEnum> * typed) override
    {
        std::cout << "found Typed<MyEnum>\n";
    }

    virtual void visit(Typed<std::array<int, 3>> * typed) override
    {
        std::cout << "found Typed<std::array<int, 3>>\n";
    }

    virtual void visit(Property2<int> * typed) override
    {
        std::cout << "found Property<int>\n";
    }
};


int main(int argc, char *argv[])
{
    // Create read/write accessor
    {
        std::cout << "Read/write accessor\n";

        AccessorGetSet<int> accessor(&get, &set);
        std::cout << "value = " << accessor.getValue() << " (1)\n";
        accessor.setValue(10);
        std::cout << "value = " << accessor.getValue() << " (10)\n";

        AccessorValue<int> accessor2(0);
        std::cout << "value = " << accessor2.getValue() << " (0)\n";
        accessor2.setValue(10);
        std::cout << "value = " << accessor2.getValue() << " (10)\n";

        std::cout << "\n";
    }

    // Create read-only accessor
    {
        std::cout << "Read-only accessor\n";

        AccessorGetSet<const int> accessor(&get);
        std::cout << "value = " << accessor.getValue() << " (10)\n";
        accessor.setValue(20);
        std::cout << "value = " << accessor.getValue() << " (10)\n";

        AccessorValue<const int> accessor2(0);
        std::cout << "value = " << accessor2.getValue() << " (0)\n";
        accessor2.setValue(20);
        std::cout << "value = " << accessor2.getValue() << " (0)\n";

        std::cout << "\n";
    }

    // Create read/write typed value
    {
        std::cout << "Read/write typed value\n";

        Typed<int> typeInt1(new AccessorGetSet<int>(&get, &set));
        Typed<int> typeInt2(&get, &set);

        long long l = typeInt1.toLongLong();

        std::cout << "value = " << typeInt1.getValue() << " (10)\n";
        typeInt1.setValue(20);
        std::cout << "value = " << typeInt2.getValue() << " (20)\n";

        std::cout << "\n";
    }

    // Create read-only typed value
    {
        std::cout << "Read-only typed value\n";

        Typed<const int> typeInt(&get);

        std::cout << "value = " << typeInt.getValue() << " (20)\n";
        typeInt.setValue(30);
        std::cout << "value = " << typeInt.getValue() << " (20)\n";

        std::cout << "\n";
    }

    // Check other data types
    {
        Typed<int>          typeInt;
        Typed<unsigned int> typeUInt;
        Typed<float>        typeFloat;
        Typed<double>       typeDouble;
        Typed<bool>         typeBool;
        Typed<std::string>  typeString;
        Typed<Color>        typeColor;
        Typed<FilePath>     typeFilePath;
        Typed<TestClass>    typeTestClass;
    }

    // Create array-accessors
    {
        // Direct value
        std::cout << "Array accessor (direct value)\n";

        ArrayAccessorValue<int, 3> accessor1({1, 2, 3});
        std::cout << "value[0] = " << accessor1.getElement(0) << " (1)\n";
        std::cout << "value[1] = " << accessor1.getElement(1) << " (2)\n";
        std::cout << "value[2] = " << accessor1.getElement(2) << " (3)\n";

        accessor1.setElement(0, 10);
        std::cout << "value[0] = " << accessor1.getElement(0) << " (10)\n";
        std::cout << "value[1] = " << accessor1.getElement(1) << " (2)\n";
        std::cout << "value[2] = " << accessor1.getElement(2) << " (3)\n";

        accessor1.setElement(1, 10);
        std::cout << "value[0] = " << accessor1.getElement(0) << " (10)\n";
        std::cout << "value[1] = " << accessor1.getElement(1) << " (10)\n";
        std::cout << "value[2] = " << accessor1.getElement(2) << " (3)\n";

        accessor1.setElement(2, 10);
        std::cout << "value[0] = " << accessor1.getElement(0) << " (10)\n";
        std::cout << "value[1] = " << accessor1.getElement(1) << " (10)\n";
        std::cout << "value[2] = " << accessor1.getElement(2) << " (10)\n";

        std::cout << "\n";

        // Getter/setter
        std::cout << "Array accessor (getter/setter)\n";

        ArrayAccessorGetSet<int, 3> accessor2(getArray, setArray);

        std::cout << "value[0] = " << accessor2.getElement(0) << " (10)\n";
        std::cout << "value[1] = " << accessor2.getElement(1) << " (11)\n";
        std::cout << "value[2] = " << accessor2.getElement(2) << " (12)\n";

        accessor2.setElement(0, 20);
        std::cout << "value[0] = " << accessor2.getElement(0) << " (20)\n";
        std::cout << "value[1] = " << accessor2.getElement(1) << " (11)\n";
        std::cout << "value[2] = " << accessor2.getElement(2) << " (12)\n";

        accessor2.setElement(1, 21);
        std::cout << "value[0] = " << accessor2.getElement(0) << " (20)\n";
        std::cout << "value[1] = " << accessor2.getElement(1) << " (21)\n";
        std::cout << "value[2] = " << accessor2.getElement(2) << " (12)\n";

        accessor2.setElement(2, 22);
        std::cout << "value[0] = " << accessor2.getElement(0) << " (20)\n";
        std::cout << "value[1] = " << accessor2.getElement(1) << " (21)\n";
        std::cout << "value[2] = " << accessor2.getElement(2) << " (22)\n";

        std::cout << "\n";
    }

    // Create array-value
    {
        std::cout << "Array value\n";

        Typed<std::array<int, 3>> typeArray(getArray, setArray);

        std::cout << "value.empty = " << (typeArray.isEmpty() ? "yes (no)\n" : "no (no)\n");
        std::cout << "value.size = " << typeArray.count() << " (3)\n";
        std::cout << "value[0] = " << typeArray.getElement(0) << " (20)\n";
        std::cout << "value[1] = " << typeArray.getElement(1) << " (21)\n";
        std::cout << "value[2] = " << typeArray.getElement(2) << " (22)\n";

        typeArray.forEach([] (AbstractValue & value) {
            AbstractTyped<int> & typed = static_cast<AbstractTyped<int> &>(value);
            typed.setValue(100);
        });

        std::cout << "value.empty = " << (typeArray.isEmpty() ? "yes (no)\n" : "no (no)\n");
        std::cout << "value.size = " << typeArray.count() << " (3)\n";
        std::cout << "value[0] = " << typeArray.getElement(0) << " (100)\n";
        std::cout << "value[1] = " << typeArray.getElement(1) << " (100)\n";
        std::cout << "value[2] = " << typeArray.getElement(2) << " (100)\n";

        std::cout << "\n";
    }

    // Create enum-value
    {
        std::cout << "Enum value\n";

        Typed<MyEnum> typeEnum;
        typeEnum.setValue(One);
        std::cout << "value = " << typeEnum.getValue() << " '" << typeEnum.toString() << "'" << " (1 'One')\n";

        typeEnum.setValue((MyEnum)2);
        std::cout << "value = " << typeEnum.getValue() << " '" << typeEnum.toString() << "'" << " (2 'Two')\n";

        typeEnum.fromString("Three");
        std::cout << "value = " << typeEnum.getValue() << " '" << typeEnum.toString() << "'" << " (3 'Three')\n";

        std::cout << "\n";
    }

    // Test visitor
    {
        std::cout << "Visitor test\n";

        MyVisitor visitor;

        Typed<int> typeInt;
        typeInt.accept(&visitor);

        Typed<unsigned int> typeUInt;
        typeUInt.accept(&visitor);

        Typed<float> typeFloat;
        typeFloat.accept(&visitor);

        Typed<double> typeDouble;
        typeDouble.accept(&visitor);

        Typed<bool> typeBool;
        typeBool.accept(&visitor);

        Typed<std::string> typeString;
        typeString.accept(&visitor);

        Typed<Color> typeColor;
        typeColor.accept(&visitor);

        Typed<FilePath> typeFilePath;
        typeFilePath.accept(&visitor);

        Typed<TestClass> typeTestClass;
        typeTestClass.accept(&visitor);

        Typed<MyEnum> typeMyEnum;
        typeMyEnum.accept(&visitor);

        Typed<std::array<int, 3>> typeArray;
        typeArray.accept(&visitor);

        Property2<int> propertyInt;
        propertyInt.accept(&visitor);

        std::cout << "\n";
    }

    // Create changed-signal
    {
        std::cout << "Signal test\n";

        Typed<int> typeInt;
        typeInt.valueChanged.connect([] () {
            std::cout << "typeInt changed.\n";
        });

        for (int i=0; i<10; i++) {
            typeInt.setValue(i);
            std::cout << "value = " << typeInt.getValue() << " (" << i << ")\n";
        }

        std::cout << "\n";
    }

    // Casting test
    {
        std::cout << "Casting test\n";

        AbstractValue * typeInt = new Typed<int>;
        if (typeInt->isCollection()) {
            std::cout << "typeInt is a collection.\n";
        } else {
            std::cout << "typeInt is NOT a collection.\n";
        }
        if (typeInt->isGroup()) {
            std::cout << "typeInt is a group.\n";
        } else {
            std::cout << "typeInt is NOT a group.\n";
        }

        AbstractValue * typeArray = new Typed<std::array<int, 3>>;
        if (typeArray->isCollection()) {
            std::cout << "typeArray is a collection.\n";
        } else {
            std::cout << "typeArray is NOT a collection.\n";
        }
        if (typeArray->isGroup()) {
            std::cout << "typeArray is a group.\n";
        } else {
            std::cout << "typeArray is NOT a group.\n";
        }

        std::cout << "\n";
    }
}
