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
    while (x < y)
    {
        const auto xStr = std::to_string(x);
        std::string vRotatedStr;
        int i{0};
        for (auto rIt = std::rbegin(xStr); rIt != std::rend(xStr); ++rIt)
        {
            vRotatedStr += hashMap[*rIt];
            if (xStr[i] != vRotatedStr[i])
                break;
            ++i;
        }
        ++x;
        if (vRotatedStr == xStr)
            ++result;

    }
    return result;
}
