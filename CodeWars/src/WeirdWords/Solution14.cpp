#include <map>
#include <ctype.h>
std::map<char,char> createConversionMap()
{
    std::map<char,char> result;
    for (int i = 65 ; i < 90; ++i)
        result[i] = i + 1;
    result[90] = 65;
  
    for (int i = 97 ; i < 122; ++i)
        result[i] = i + 1;
    result[122] = 97;
  
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