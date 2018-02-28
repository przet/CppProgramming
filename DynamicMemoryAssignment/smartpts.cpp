#include "MyClass.hpp"
#include<iostream>
#include<memory>

int main ()
{
    std::shared_ptr<MyClass> myclass(new MyClass);
    myclass->get_a();

    return 0;
}

