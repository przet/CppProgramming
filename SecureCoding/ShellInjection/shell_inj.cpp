#include <string>
#include <iostream>
#include <stdlib.h>
int main()
{
    //! Very Dangerous! User can enter any command, including rm etc...
    std::string name;
    std::cout << "Please enter you name" << std::endl;
    std::getline (std::cin, name);
    system(name.c_str());
    return 0;
}
