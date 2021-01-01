#include <ctype.h>

void letterPlusOne(char& elem)
{
      if (isalpha(elem))
      {
         elem =  isupper(elem) ?  ((elem - 65 + 1) % 26) + 65
             :((elem - 97 + 1) % 26) + 97;
      }
}

std::string nextLetter(std::string str)
{
    for (auto& elem : str)
       letterPlusOne(elem);
  
    return str;
}