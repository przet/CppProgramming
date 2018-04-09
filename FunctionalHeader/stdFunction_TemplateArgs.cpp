#include <functional>
#include <iostream>

template <typename T, typename U>
bool isTrue(T t, U u)
{
    if (t < u)
        return true;
    return false;
}



