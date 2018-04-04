#include <iostream>


enum MyEnum_1 {Something, SomethingElse, SomethingElseMore}; //global so that printEnum can be defined
enum class MyEnum_scoped {Something_Scoped, SomethingElse_Scoped, SomethingElseMore_Scoped};
int main()
{
    //-------Non-scoped enum -----
    MyEnum_1 myEnum1;
    myEnum1 = Something;
    
    if (myEnum1 == Something)
        std::cout << "We enter here, even though" 
            " if condition evaluates to "<< myEnum1 <<" "<< std::endl;

    void printEnum(MyEnum_1);
    printEnum(SomethingElseMore); //type checking will occur if you enter something not defined in MyEnum_1;

    //-------Scoped enum -----
    MyEnum_scoped mES;
    //mES = SomethingElse_Scoped; //error: Undeclared identifier: i.e not in scope here
    mES = MyEnum_scoped::SomethingElse_Scoped;  //O.K.
    std::cout << static_cast<int>(mES) << std::endl;   //NOT explicitly casting to an int cast will not work like in unscoped enums

    
    
    
    
    
    
    
    
    return 0;
}

void printEnum(MyEnum_1 myEnumInstance)
{
    std::cout << myEnumInstance << std::endl;
}

    
