// Credit to KenKamau for std::to_string idea

#include <unordered_map>
#include <string>

int solve(int x, int y)
{
    auto result{ 0 };
    std::unordered_map<char, char> hashMap
    {
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'8' , '8'},
        {'9', '6'}
    };
    const auto hashMapEnd = std::end(hashMap);
    while (x < y)
    {
        const auto xStr = std::to_string(x);
        const auto xRevStr = std::string(std::rbegin(xStr), std::rend(xStr));
        std::string vRotatedStr;

        bool earlyExit = false;
        for (auto elem : xRevStr)
        {
            if (hashMap.find(elem) != hashMapEnd)
            {
                vRotatedStr += hashMap[elem];
            }
            else
            {
                earlyExit = true;
                break;
            }
        }
        ++x;
        if (!earlyExit && vRotatedStr == xStr)
            ++result;
    }
    return result;
}
