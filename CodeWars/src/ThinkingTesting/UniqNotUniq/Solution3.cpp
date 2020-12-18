#include <set>
#include <algorithm>

template <typename T>
std::set<T> filterDuplicates (const std::vector<T>& vec)
{
    return std::set<T>(std::begin(vec), std::end(vec));
}

template <typename T>
std::vector<T> mergeFiltered(const std::set<T>& set1, const std::set<T>& set2)
{
    std::vector<T> result;
    std::merge(std::begin(set1), std::end(set1),std::begin(set2), std::end(set2), std::back_inserter(result));
    return result;
}

std::vector<int> testit(std::vector<int> a, std::vector<int> b)
{
    return mergeFiltered(filterDuplicates(a), filterDuplicates(b));
}
