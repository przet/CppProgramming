#include <iostream>
#include <thread>
#include <exception>

void func()
{
    for (int i = 0;i < 10; ++i)
        std::cout << "I am thread number one!" << std::endl;
}
void func2(int x)
{
    int i = 10;
    while (i > 0)
    {
        std::cout << x++ << std::endl;
        i--;
    }
}
class MyClass
{
public:
    void func()
    {
        for (int i = 0;i < 10; ++i)
            std::cout << "I have thread entry point into a member function !" << std::endl;
    }
};

struct MyFunctor
{
    void operator()(int x)
    {
        if (x == 4)
            for (int i = 0;i < 10; ++i)
                std::cout << "Functor! I have thread entry point into a functor! " << std::endl;
        else
          std::cout << "Functor BUT...not 4" << std::endl;

    }
};

struct MyFunctor2
{
    void operator()()
    {
        std::cout << "*****FUNCTOR 2 IS IN THE HOUSE...or rather a thread entry point" << std::endl;
    }
};



int main()
{
    std::thread thread(&func);// can be without '&' too
    std::thread thread2(&func2, 5);
    MyClass myObject;
    std::thread thread3(&MyClass::func, &myObject);
    std::thread thread4(MyFunctor(), 4);//This works..but...MyFunctor2 will NOT..Also, '&' will NOT compile
    std::thread thread4_a((MyFunctor2()));
    
    std::thread thread5([]() {std::cout << "I have entry point via a lambda(which is just ss for a functor" << std::endl;});
    


    //main thread
    for (int i = 0; i < 10;++i)
        std::cout << "I am the main thread" << std::endl;
    system("pause");
    return 0;
}
