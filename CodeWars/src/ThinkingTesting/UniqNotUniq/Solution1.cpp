#include <set>
std::vector<int> testit(std::vector<int> a, std::vector<int> b)
{
  std::set<int> aUniq;
  std::set<int> bUniq;
  for (auto elem : a)
    aUniq.insert(elem);
  
  for (auto elem : b)
    bUniq.insert(elem);
    
  std::multiset<int> intermediate;
  std::vector<int> result;
  for (auto elem : aUniq)
    intermediate.insert(elem);
  for (auto elem : bUniq )
    intermediate.insert(elem);
  
  for (auto elem : intermediate)
    result.push_back(elem);
  
  return result;
  
}
