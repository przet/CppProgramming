#include <set>
using set = std::set<int>;
using mset = std::multiset<int>;
using vec = std::vector<int>;
std::vector<int> testit(std::vector<int> a, std::vector<int> b)
{
    set set_a(std::begin(a), std::end(a));
    set set_b(std::begin(b), std::end(b));
  
    mset _mset(std::begin(set_a), std::end(set_a));
  
    for (auto elem : set_b)
      _mset.insert(elem);
  
    return vec(std::begin(_mset), std::end(_mset)); 
      
}
