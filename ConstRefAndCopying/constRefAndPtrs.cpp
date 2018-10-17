#include <iostream>
void function(const int& r)
{
    std::cout << r << std::endl;
}
    
int main()
{
    int a = 4;
    auto &ra = a;
    std::cout << ra << std::endl;
    const auto &ra2 = a;
    std::cout << ra2 << std::endl;

    ra = 5;
    std::cout <<ra << " " << a << std::endl;
    std::cout << &ra << " " << &ra2 << " " << &a << std::endl;
    
    int b = 10;
    int c = 20;
    auto *pb = &b;
    auto *pc = &c;
    pb = &c;
    (*pb)++;
    std::cout << c << std::endl;
    auto &rb = b;
    auto &rc = c;
    rb = c;
    rb++;
    std::cout << b << std::endl;
    std::cout << std::boolalpha <<"It is "<< (&rb == &b) <<" that the &rb=&b "<< std::endl;
    std::cout << std::boolalpha <<"It is "<< (&rb == &c) <<" that the &rb=&c "<< std::endl;
    std::cout << std::boolalpha <<"It is "<< (pb == &c) <<" that the pb=&c "<< std::endl;
    function(a);

    std::cout.setf(std::ios::boolalpha);
    
    int d = 50;
    int e = 60;
    d = e;
    std::cout <<(&d != &e) <<std::endl;
    std::cout << (d == e) << std::endl;
    e++;
    std::cout << (d!=e) << std::endl;

    std::cout << "---------------------" << std::endl;
    int f = 100;
    int *const pf = &f;
    int *p = pf;
    std::cout << (p==  pf) << std::endl;
    (*p)++;
    std::cout << (f==101) <<std::endl;
    std::cout << "---------------------" << std::endl;
    
    std::cout << "---------------------" << std::endl;
    int g = 0;
    const int cg = 42;
    const int *pcg = &cg;
    g =1;
    pcg = &g;
    g++;
    //(*pcg)++; error; won't work: pcg is a pointer to const, even though g is not const






    std::cout << "---------------------" << std::endl;
    return 0;
}
