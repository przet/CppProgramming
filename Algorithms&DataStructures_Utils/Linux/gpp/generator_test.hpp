#ifndef __Generator__H
#define __Generator__H

#include "IGenerator.hpp"
#include <vector>
#include <utility>
#include <algorithm>

struct Generator : public IGenerator<std::vector,int>
{
    Generator(const std::vector<int>& rInputSizeList)
        : mInputSizeList(rInputSizeList) {}


    const std::vector<std::pair<std::vector<int>,int>>& generateData() override
    {
        for (auto elem : mInputSizeList)
        {
            std::vector<int> data(elem);
            auto f = [](){return rand() % 10000;};
            std::generate(data.begin(), data.end(), f);
            mData_InputSizeList.push_back({data,elem});
        }
        return mData_InputSizeList;
    }

    std::vector<std::pair<std::vector<int>,int>> mData_InputSizeList;
    std::vector<int> mInputSizeList;

};

#endif
