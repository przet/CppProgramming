#include <vector>
#include <cmath>
#include <algorithm>

class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b)
    {
        std::vector<int> a_sq;
        for (auto elem : a)
          a_sq.push_back(pow(elem,2));
        std::sort(std::begin(b), std::end(b));
        std::sort(std::begin(a_sq), std::end(a_sq));
        return a_sq == b;
    }
};
