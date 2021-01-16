#include <algorithm>

int sum_of_minimums(const std::vector<std::vector<int>> &numbers)
{
    auto sum{0};
    for (auto elem : numbers)
    {
        std::sort(std::begin(elem), std::end(elem));
        sum += elem[0] ;
    }
    return sum ;
}
