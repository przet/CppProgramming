#include <ctype.h>

bool lastAlpha(char character)
{
    return character == 'Z' || character == 'z';
}

char firstAlpha(char character)
{
    return character = isupper(character) ? 'A' : 'a';
}

std::string nextLetter(std::string str)
{
    for (auto& elem : str)
    {
        if (isalpha(elem))
            elem = lastAlpha(elem) ? firstAlpha(elem) : ++elem;
    }
    return str;
}