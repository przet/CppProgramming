#include <iostream>
#include <functional> //for use of less<T>

/******************************
 * Lippman et al (C++ Primer 5th) edition
 * claim on pg 656 in the Template Programming
 * Section, that my making function paramters
 * references to const, we ensure that a function
 * can be used to types that cannot be copied.
 *
 * But copying does not change an object, so I am not
 * quite sure if it is a matter of just making the paramters
 * references, and adding const gives other benefits (not discussed here
 * but discussed in Lippman)
 *
 * These are my explorations....
 *
 * *************************************************/

//First lets create a class that allows copying
class MyCopyableClass
{
    private:
        int m_a =10;
        int m_b =20;
    public:
        MyCopyableClass() = default;
        MyCopyableClass(MyCopyableClass &existingInstance)
        {
            std::cout << "cctor called" << std::endl;
            m_a = existingInstance.m_a;
            m_b = existingInstance.m_b;
        }


};

//Now lets make copying private - the class can't be copied
class MyNONCOPYClass
{
    private:
        int m_a = 30;
        int m_b = 40;
        MyNONCOPYClass(MyNONCOPYClass &existingInstance)
        {
            std::cout << "cctor is called, but its private: generally "
                "shouldn't see this" << std::endl;
            m_a = existingInstance.m_a;
            m_b = existingInstance.m_b;
        }
    public:
        MyNONCOPYClass() = default;
        bool operator<(const MyNONCOPYClass &obj2) const
        {
            return m_a < obj2.m_a && m_b < obj2.m_b;
        }
        

        
};


//now lets write the template function in Lippman, the compare one.
template <typename T>
int compare(T &v1, T &v2)  //refence to const NOT needed (but better - see conclusions)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
int main()
{
    MyCopyableClass mycc;
    MyCopyableClass mycc2(mycc);

    MyNONCOPYClass nCC;
    //MyNONCOPYClass nCC_2(nCC); //error: won't copy

    //now lets use compare  on my non-copyable class
    MyNONCOPYClass ncc;

    compare(nCC, ncc);

    




    return 0;
}

/******Conclusions******
 * reference to const (aka const ref) is NOT needed - its just the reference, as otherwise it would be
 * pass by value which by definition for funcitons in C/C++ mean a local (to the function) copy must be made.
 * So the statement "By making the function parameters reference to const, we ensure that our functions
 * can be used on types that cannot be copied" is true, but misleading in that it implies a stronger condition
 * than necessary - all the function paramters need be be are _references_ to allow use of the function on types
 * that are not copyable.
 *
 * HOWEVER, it is a good idea to add const, so that the function (unless we want it too) does NOT change the
 * referrant. Also not that I should use, for the same reason, const refs in my copy constructors
 *
 * **************************/
