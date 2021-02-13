#include <map>
#include <vector>
#include <string>
#include <set>
#include <utility>

using IntType = unsigned long long;
using String = std::string;
using VectorOfStrs = std::vector<std::string>;
using MultiSet = std::multiset<std::pair<IntType, std::string>>;
using PairIntStr = std::pair<IntType, std::string>;

struct Comparator
{
    bool operator() (const PairIntStr& lhs, const PairIntStr& rhs)
    {
        if (lhs.first != rhs.first)
            return lhs.first < rhs.first;
        else
            return lhs.second < rhs.second;
    }
};

struct WeightSort
{
    static VectorOfStrs parseString(const String& input)
    {
        VectorOfStrs vVectorOfStrs;
        String vTempString;
        for (auto elem : input)
        {
            if (elem != ' ')
                vTempString.push_back(elem);
            else
            {
                vVectorOfStrs.push_back(vTempString);
                vTempString.clear();
            }
        }
      
        vVectorOfStrs.push_back(vTempString);
        vTempString.clear();
        auto vLastIt = std::prev(std::end(vVectorOfStrs));
        if (!vLastIt->size())
            vVectorOfStrs.erase(vLastIt);
        return vVectorOfStrs;
    }
  
    static IntType sumDigits(const String& input)
    {
        return sumDigits(std::stoull(input));
    }
  
    static IntType sumDigits(IntType input)
    {
        auto q{input};
        auto sum{0};
        do
        {
            sum += q % 10;
            q /= 10;
        } while (q);
      
        return sum;
    }
  
  static String orderWeight(const String& input)
    {
        if (!input.size())
            return "";
        auto vStrList = parseString(input);
        
        MultiSet vMSet;
        for (auto elem : vStrList)
        {
            vMSet.insert({sumDigits(elem), elem});
        }
    
        String vResult;
        for (const auto& elem : vMSet)
        {
            vResult.append(elem.second);
            vResult.append(" ");
        }
        vResult.erase(std::prev(std::end(vResult)));

        return vResult;
    }
};

