#include "MyClass.hpp"
#include<iostream>
#include<memory>

int main ()
{
    std::shared_ptr<MyClass> myclass(new MyClass);
    std::cout << myclass->get_a() << std::endl;
    myclass->set_a(44);
    std::cout << myclass->get_a() << std::endl;
    

    return 0;
}

