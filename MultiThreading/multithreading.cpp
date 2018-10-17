#include <iostream>
#include <thread>
#include <exception>
#include<mutex>

//TODO: Why is ONE mutex, for the shared resource std::cout, not enough?
std::mutex mutex;
void func()
{
    mutex.lock();
    for (int i = 0;i < 10; ++i)
        std::cout << "I am thread number one!" << std::endl;
    mutex.unlock();
}
void func2(int x)
{
    mutex.lock();
    int i = 10;
    while (i > 0)
    {
        std::cout << x++ << std::endl;
        i--;
    }
    mutex.unlock();
}
class MyClass
{
public:
    void func()
    {
        mutex.lock();
        for (int i = 0;i < 10; ++i)
            std::cout << "I have thread entry point into a member function !" << std::endl;
        mutex.unlock();
    }
};

struct MyFunctor
{
    void operator()(int x)
    {
        mutex.lock();
        if (x == 4)
            for (int i = 0;i < 10; ++i)
                std::cout << "Functor! I have thread entry point into a functor! " << std::endl;
        else
          std::cout << "Functor BUT...not 4" << std::endl;
        mutex.unlock();

    }
};

struct MyFunctor2
{
    void operator()()
    {
        mutex.lock();
        std::cout << "*****FUNCTOR 2 IS IN THE HOUSE...or rather a thread entry point" << std::endl;
        mutex.unlock();
    }
};

class ClassWithThread
{
public:
    ClassWithThread() {};
private:
    void f() {}
    std::thread thread6;
};



int main()
{
    std::thread thread(&func);// can be without '&' too
    thread.detach();
    std::thread thread2(&func2, 5);
    thread2.detach();
    MyClass myObject;
    std::thread thread3(&MyClass::func, &myObject);
    thread3.detach();
    std::thread thread4(MyFunctor(), 4);//This works..but...MyFunctor2 will NOT..Also, '&' will NOT compile
    thread4.detach();
    std::thread thread4_a((MyFunctor2()));
    thread4_a.detach();
    
    std::thread thread5([]() { mutex.lock(); std::cout << "I have entry point via a lambda(which is just ss for a functor)" << std::endl; mutex.unlock(); });
    thread5.detach();

    

    mutex.lock();
    //main thread
    for (int i = 0; i < 10;++i)
        std::cout << "I am the main thread" << std::endl;

    mutex.unlock();
    return 0;
}
