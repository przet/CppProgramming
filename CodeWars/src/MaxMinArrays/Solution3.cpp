#include <set>
std::vector<int> solve(std::vector<int>v)
{
    std::set<int> set(std::begin(v), std::end(v));
    auto it = std::begin(set); 
    auto rit = std::rbegin(set);
    unsigned long moveCount = 0;
  
    while (moveCount < set.size())
    {
        v[moveCount++] = *rit++;
        v[moveCount++] = *it++;
    }
  
    return v;
}