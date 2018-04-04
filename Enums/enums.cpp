#include <iostream>


enum MyEnum_1 {Something, SomethingElse, SomethingElseMore}; //global so that printEnum can be defined
int main()
{
    MyEnum_1 myEnum1;
    myEnum1 = Something;

    if (myEnum1 == Something)
        std::cout << "We enter here, even though" 
            " if condition evaluates to "<< myEnum1 <<" "<< std::endl;

    void printEnum(MyEnum_1);
    printEnum(SomethingElseMore); //type checking will occur if you enter something not defined in MyEnum_1;

    return 0;
}

void printEnum(MyEnum_1 myEnumInstance)
{
    std::cout << myEnumInstance << std::endl;
}

    
