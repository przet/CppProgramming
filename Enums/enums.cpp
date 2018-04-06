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

    void printEnum_Scoped(MyEnum_scoped);  //needs to be const - otherwise compiler will compain the non-const lval reference
                                                  // to type 'MyEnum_Scoped' cannot bind to a temporary of type 'MyEnum_scoped'.
                                                  //DOES not need to be a reference type though - in fact, then it does NOT need to be const
    
    printEnum_Scoped(mES);
    printEnum_Scoped(MyEnum_scoped::Something_Scoped);

    
    
    
    
    
    
    
    
    return 0;
}

void printEnum(MyEnum_1 myEnumInstance)
{
    std::cout << myEnumInstance << std::endl;
}

void printEnum_Scoped(MyEnum_scoped myEnum_scopedInstance) //needs to be const if using rerefence type - see comment at decleration inside main()
{
    std::cout << static_cast<int>(myEnum_scopedInstance) << std::endl;
}

    
