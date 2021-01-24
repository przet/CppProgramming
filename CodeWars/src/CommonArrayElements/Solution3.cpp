#include <unordered_set>
#include <algorithm>

using UMap = std::unordered_map<int,int>;
using USet = std::unordered_set<int>;

int common(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c)
{
    UMap a_map;
    for (auto elem : a)
        a_map[elem]++;
  
    UMap b_map;
    for (auto elem : b)
        b_map[elem]++;
  
    UMap c_map;
    for (auto elem : c)
        c_map[elem]++;
  
    USet a_set(std::begin(a), std::end(a));
  
    const auto bMapEnd = std::cend(b_map);
    const auto cMapEnd = std::cend(c_map);
  
    auto sum{0};
    for (auto elem : a_set)
    {
         if (b_map.find(elem) == bMapEnd || c_map.find(elem) == cMapEnd)
             continue;
      
         sum += elem * std::min(a_map[elem], std::min(b_map[elem], c_map[elem])); 
    }
    return sum;
  
}
