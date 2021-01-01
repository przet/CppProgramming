#include <ctype.h>

char letterPlusOne(char elem)
{
      if (isalpha(elem))
      {
         elem =  isupper(elem) ?  ((elem - 65 + 1) % 26) + 65
             :((elem - 97 + 1) % 26) + 97;
      }
      return elem;
}

std::string nextLetter(std::string str)
{
    for (auto& elem : str)
       elem = letterPlusOne(elem);
  
    return str;
}