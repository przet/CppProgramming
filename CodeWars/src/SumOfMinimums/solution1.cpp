#include <vector>
#include <set>

int sum_of_minimums(const std::vector<std::vector<int>> &numbers)
{
    std::vector<int> vectorOfMins;
    
    for (const auto& elem : numbers)
    {
        std::set<int> set(std::begin(elem), std::end(elem));
        vectorOfMins.push_back(*std::begin(set));
    }
    int sum = 0;
    for (auto elem : vectorOfMins)
      sum += elem;
    return sum ;
}
