#include <set>
using set = std::set<int>;
using mset = std::multiset<int>;
using vec = std::vector<int>;
std::vector<int> testit(std::vector<int> a, std::vector<int> b)
{
    set _set(std::begin(a), std::end(a));
    mset _mset(std::begin(_set), std::end(_set));
    _set.clear();
    _set.insert(std::begin(b), std::end(b));
    _mset.insert(std::begin(_set), std::end(_set));
    
    return vec(std::begin(_mset), std::end(_mset));
}
