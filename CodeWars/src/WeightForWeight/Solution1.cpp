#include <map>
#include <vector>
#include <string>
#include <set>

using String = std::string;
using VectorOfStrs = std::vector<std::string>;
using MultiMap = std::multimap<int, std::string>;
using MultiSet = std::multiset<std::string>;

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
        
        return vVectorOfStrs;
    }
  
    static int sumDigits(const String& input)
    {
        return sumDigits(std::stoi(input));
    }
  
    static int sumDigits(int input)
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
        // Assume whitespaces in input do not need to be preserved in output
        
        // Parse input into standalone strings
        auto vStrList = parseString(input);
        
        // Store string as int keyed on the sum of its digits - this will be sorted on the key also
        MultiMap vMMap;
        for (auto elem : vStrList)
        {
            vMMap.insert({sumDigits(elem), elem});
        }
    
        // Insert the values for each key into the result string, inserting a space in between each.
      auto vIt = std::cbegin(vMMap);
      const auto vEndIt = std::cend(vMMap);
      String vResult;
      while (vIt != vEndIt)
      {
          if (vMMap.count(vIt->first) > 1)
          {
              auto vRange = vMMap.equal_range(vIt->first);
              MultiSet vMMSet;
              for (auto it = vRange.first; it != vRange.second; ++it)
              {
                  vMMSet.insert(it->second);
              }
              for (const auto& elem : vMMSet)
              {
                  vResult.append(elem);
                  vResult.append(" ");
              }
              vIt = std::next(vRange.second);
          }
          else
          {
              for (const auto& elem : vMMap)
              {
                  vResult.append(elem.second);
                  vResult.append(" ");
              }
              ++vIt;
          }
        
      }
    return vResult;
    }
};
