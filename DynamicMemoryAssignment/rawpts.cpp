#include"MyClass.hpp"
#include<iostream>

int main()
{
    MyClass myclass;
    std::cout << sizeof(myclass) << std::endl;
    myclass.get_a();
    MyClass *myclass_ptr = new MyClass;
    delete myclass_ptr; //TODO: why is myclass_ptr still accessible? Is it to do with heap allocation, and program still running?
    int t =myclass_ptr->get_a();
    std::cout << t << std::endl;


    return 0;
}

    
