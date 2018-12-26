#include "stdafx.h"
#include <vector>
#include <algorithm>
#include "SampleSpaceGenerator.hpp"

namespace sample_space
{
    typedef std::vector<int> Vec;
    typedef std::vector<std::vector<int>> VecOfVec;

    void SampleSpaceGenerator::generator(const int sampleSize)
    {
        table.resize(sampleSize);
        std::for_each(begin(table), end(table), [i = 1](auto& elem) mutable{elem.resize(i++);
        std::generate(begin(elem), end(elem), [i = 0]() mutable{return i++; }); });
    }

}

