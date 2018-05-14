//! Need to use clang (with std=c++17) - gcc won't do it
#include <tuple> //std::make_tuple
#include <string>
#include <iostream>
int main()
{
    int numberOne = 1;
    int numberTwo = 2;
    auto string_a = "a";
    auto char_a = 'a';
    
    auto tuple_1 = std::make_tuple (numberOne,numberTwo, string_a, char_a);

    auto [a,b,c,d] = tuple;

    std::cout <<a << " " << b << " " << c << " " << d << " " <<std::endl;
    
    //pointer types don't seem to work. Will need to do the pre-c++17 way
    //( thanks go to https://skebanga.github.io/structured-bindings/ )

    k
    








    return 0;
}
