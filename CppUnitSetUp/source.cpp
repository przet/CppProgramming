#include "header.hpp"


MyClass::MyClass(): a(4), b(5)
{
};

int MyClass::get_a()
{
    return a;
}

void MyClass::set_a(int _a)
{
    a = _a;
}
