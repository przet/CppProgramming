#ifndef __Solution__H
#define __Solution__H

#include "ISolution.hpp"
#include <vector>

//TODO move defn's into cpp

struct Solution : public ISolution<std::vector,int>
{
    void Algorithm(const std::vector<int>& rInputData) override
    {
        //TODO have Solution class wrap the actual algo
        //count number of elements in inputdata without STL
        int count = 0;
        for (int i = 0; i< rInputData.size(); i++)
            ++count;
    }


};

#endif

