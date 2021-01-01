#include <ctype.h>

std::string nextLetter(std::string str)
{
    for (auto& elem : str)
    {
        if (isalpha(elem))
        {
            if (!isalpha(++elem))
                elem = elem == '{'  ? 'a' : 'A';
        }
    }
    return str;
}