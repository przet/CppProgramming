#include <set>

template <typename T>
std::set<T> filterDuplicates (const std::vector<T>& vec)
{
    return std::set<T>(std::begin(vec), std::end(vec));
}

template <typename T>
std::vector<T> mergeFiltered(const std::set<T>& set1, const std::set<T>& set2)
{
    auto v =  std::multiset<T>(std::begin(set1), std::end(set1));
    for (auto elem : set2)
      v.insert(elem);
  
    return std::vector<T>(std::begin(v), std::end(v));
}


std::vector<int> testit(std::vector<int> a, std::vector<int> b)
{
  return mergeFiltered(filterDuplicates(a), filterDuplicates(b));
  
}
