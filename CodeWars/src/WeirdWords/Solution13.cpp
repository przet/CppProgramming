#include <map>
#include <ctype.h>
std::map<char,char> createConversionMap()
{
    std::map<char,char> result;
    for (int i = 0; i < 256; ++i)
    {
        if (isalpha(i))
            result[i] = i + 1;
        else
            result[i] = i;
    }
    result[90] = 65;
    result[122] = 97;
    return result;
  
}
std::string nextLetter(std::string str)
{
    auto convMap = createConversionMap();
    for (auto& elem : str)
    {
        elem = convMap[elem];
    }
    return str;
}