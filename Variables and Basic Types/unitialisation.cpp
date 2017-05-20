//Shows what happens with unitialisation in C++
#include <iostream>

int main ()
{
    int a; //declares and defines a variable of type int.
    std::cout << "a = " << a << std::endl;
    //std::cout << "mem addr of a = " << &a << std::endl;
    std::cout << "preincrement of a = " << ++a << std::endl;
    //std::cout << sizeof(a) << std::endl;
    int b;
    std::cout << " b = " << b << std::endl;
    //std::cout << "hello there" << std::endl;
    std::cout << " a+1 = " << (a+1) << std::endl;
    //Observation: if you have unitialised a and b, they seem to always self
    //initialise to 0. However as soo as you apply unary operator & to a, both
    //a and b's inital value behaviour is undefined - their initial value 
    //changes at each runtime invokation (i.e each time you run the compiled
    //program).




    return 0;
}
