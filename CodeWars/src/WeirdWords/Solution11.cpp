#include <ctype.h>

std::string nextLetter(std::string str)
{
    for (auto& elem : str)
    {
        if (isalpha(elem))
        {
            if (!isalpha(++elem))
                elem = elem % 10 == 3 ? 'a' : 'A';
        }
    }
    return str;
}