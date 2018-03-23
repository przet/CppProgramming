#include <iostream>
template<typename T>
int compare(const T &v1, const T &v2)
{
    if (less<T>()(v1, v2)) return -1;
    if (less<T>()(v2, v1)) return 1;
}


int main()
{

    system("pause");
    return 0;


}