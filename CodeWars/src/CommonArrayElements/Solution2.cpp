#include <vector>
#include <unordered_set>
#include <algorithm>

using Vec = std::vector<int>;
using UMSet = std::unordered_multiset<int>;
using USet = std::unordered_set<int>;

bool operator > (const std::vector<unsigned long>& vector, unsigned long value)
{
    for (auto elem : vector)
        if (elem <= value )
            return false;
    return true;
}
int common(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
    UMSet a_multiset(std::begin(a), std::end(a));
    UMSet b_multiset(std::begin(b), std::end(b));
    UMSet c_multiset(std::begin(c), std::end(c));
  
    USet a_set(std::begin(a), std::end(a));
  
    auto sum{0};
    for (auto elem : a_set)
    {
         std::vector<unsigned long> countList {a_multiset.count(elem), b_multiset.count(elem) ,c_multiset.count(elem)};
         if (countList > 0 )
           sum += elem * std::min(a_multiset.count(elem), std::min(b_multiset.count(elem), c_multiset.count(elem))); 
    }
    return sum;
  
}
