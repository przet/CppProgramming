// Thanks to Casey Muratori
// Compare this to the C solution in my CProgramming repository: note the difference
// in syntax (in C need to explicitly state the struct keyword in the return type, and inside
// the funciton - not so in C++

#include <iostream>

#define print(arg) std::cout << arg << std::endl;

struct ReturnValues
{
    int returnValue1;
    double returnValue2;
};

ReturnValues func1(int input1, double input2)
{
    ReturnValues returnvalues;
    returnvalues.returnValue1 = input1;
    returnvalues.returnValue2 = input2;

    return returnvalues;
}

int main()
{
    print(func1(458,123.123).returnValue1);
    print(func1(458,123.123).returnValue2);

    return 0;
}

