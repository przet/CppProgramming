#include <vector>
#include <set>

using namespace std;
std::vector <int> Pendulum (std::vector <int> values)
{
    std::multiset<int> set(std::begin(values), std::end(values));
    size_t n = std::size(values);
    auto result = std::vector<int>(n , 0);
    int i = n % 2 == 0 ? (n-1)/2 : n/2;
    int j = i + 1;
  
    auto it = std::begin(set);
    result[i--] = *it++;
    while (it != std::end(set))
    {
        assert(j<n);
        result [j++] = *it++;
        if (i>=0)
        {
            result[i--] = *it++;
        }
    }
  
    return result;
    
}
