#include <vector>
#include <unordered_set>
#include <algorithm>

using Vec = std::vector<int>;
using UMSet = std::unordered_multiset<int>;
using USet = std::unordered_set<int>;

int common(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
    UMSet a_multiset(std::begin(a), std::end(a));
    UMSet b_multiset(std::begin(b), std::end(b));
    UMSet c_multiset(std::begin(c), std::end(c));
  
    USet a_set(std::begin(a), std::end(a));
  
    auto sum{0};
    for (auto elem : a_set)
    {
         auto b_count = b_multiset.count(elem);
         if (b_count == 0)
             continue;
      
         auto c_count = c_multiset.count(elem);
         if (c_count == 0)
             continue;
      
         sum += elem * std::min(a_multiset.count(elem), std::min(b_count, c_count)); 
    }
    return sum;
  
}
