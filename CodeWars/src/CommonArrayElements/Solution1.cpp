#include <vector>
#include <set>
#include <algorithm>

using VecInt = std::vector<int>;
using SetInt = std::multiset<int>; 

VecInt commonElements(const VecInt& a, const VecInt& b)
{
    SetInt a_set(std::begin(a), std::end(a));
    SetInt b_set(std::begin(b), std::end(b));
    VecInt vec(std::size(a) + std::size(b));
    std::vector<int>::iterator it;
    it = std::set_intersection(std::begin(a_set), std::end(a_set),
                                std::begin(b_set), std::end(b_set), std::begin(vec));
    vec.resize(it - std::begin(vec));
    return vec;
}

int common(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
  
    VecInt vCommonElements = commonElements(a, commonElements(b,c));
    auto sum{0};
    for (auto elem : vCommonElements)
        sum += elem;
    
    return sum;
}
