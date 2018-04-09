#include <functional>
#include <iostream>

//template <typename T, typename U>
int aFunction(int a,int b,std::function <bool(double t, long u) >f)
{
    if (f)
        return a+b;
    return 0;
}

bool aBoolFunc(double c, long d)
{
    if(c >4 || d>4)
        return true;
    return false;
}

int main()
{
    auto blah = std::bind(aBoolFunc,5,4);
    aFunction(1,2,blah);

    return 0;
}

    





