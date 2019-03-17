#include "stdafx.h"
#include <vector>
#include <algorithm>
#include "SampleSpaceGenerator.hpp"

namespace sample_space
{
    typedef std::vector<int> Vec;
    typedef std::vector<Vec> VecOfVec;

    Vec v1, v2;
    VecOfVec tableu{ v1,v2 };

    void SampleSpaceGenerator::generator(const int sampleSize)
    {
        table.resize(sampleSize);
        std::for_each(begin(table), end(table), [i = 1](auto& elem) mutable{elem.resize(i++);
        std::generate(begin(elem), end(elem), [i = 0]() mutable{return ++i; }); });
    }

}

