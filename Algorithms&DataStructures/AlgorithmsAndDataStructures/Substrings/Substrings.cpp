// Substrings.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Substrings.h"
#include <string>
#include <assert.h>
#include <algorithm>
#include <numeric>
#if _DEBUG
#include <set>
#endif



bool substringExists(std::string parent, std::string target)
{
    // Quick win
    if (target.size() > parent.size())
        return false;

    // Construct frequency array
    int target_array[128] = { 0 };

    for (const auto& elem : target)
    {
        ++target_array[elem];
    }

    #if _DEBUG
    int debug_count =std::count_if(std::begin(target_array), std::end(target_array), [](const auto& elem) {return elem != 0; });
    std::set<int> debug_set;
    std::for_each(std::begin(target), std::end(target), [&](const auto& elem) {debug_set.insert(elem); });
    assert(debug_count == debug_set.size());


    #endif

    int targetSize = target.size();
    int hitCount = 0;

    auto algo = [&](const auto& elem)
    {
        if (hitCount == target.size())
            return true;
        if (target_array[elem])
        {
            --target_array[elem];
            ++hitCount;
        }
    };
    std::for_each(std::begin(parent), std::end(parent), algo);
    return hitCount == target.size();
}
