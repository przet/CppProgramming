#include <map>
#include <ctype.h>
std::map<char,char> createConversionMap()
{
    std::map<char,char> result;
    for (int i = 'a' ; i < 'z'; ++i)
        result[i] = i + 1;
    result['z'] = 'a';
  
    for (int i = 'A' ; i < 'Z'; ++i)
        result[i] = i + 1;
    result['Z'] = 'A';
  
    return result;
  
}
std::string nextLetter(std::string str)
{
    auto convMap = createConversionMap();
    for (auto& elem : str)
    {
        if (isalpha(elem))
          elem = convMap[elem];
    }
    return str;
}