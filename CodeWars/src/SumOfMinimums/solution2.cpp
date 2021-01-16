#include <vector>
#include <set>

int sum_of_minimums(const std::vector<std::vector<int>> &numbers)
{
    auto sum{0};
    for (const auto& elem : numbers)
    {
        std::set<int> set(std::begin(elem), std::end(elem));
        sum += *std::begin(set);
    }
    return sum ;
}
