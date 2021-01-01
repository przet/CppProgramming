#include <ctype.h>

std::string nextLetter(std::string str)
{
    for (auto& elem : str)
    {
        if (isalpha(elem))
        {
          if (elem == 'Z')
            elem = 'A'; 
          else if (elem == 'z')
            elem = 'a'; 
          else
            elem = (elem + 1) ; 
          
        }
    }
    return str;
}