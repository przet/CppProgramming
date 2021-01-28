#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b)
    {
        if (!std::size(a) && !std::size(b))
          return true;
        if (!std::size(a) || !std::size(b) || std::size(a) != std::size(b))
          return false;
        
        std::unordered_multiset<int> b_set(std::begin(b), std::end(b));
        std::vector<int> a_sq;
        for (auto elem : a)
          a_sq.push_back(pow(elem,2));
      
        for (auto elem : a_sq)
          if (b_set.count(elem) != std::count(std::begin(a_sq), std::end(a_sq), elem))
              return false;
        return true;
    }
};
