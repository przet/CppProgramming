#include "IGenerator.hpp"
#include <vector>
#include <utility>
#include <algorithm>

struct Generator : public IGenerator
{
    // TODO ctor in ifce
    Generator(const std::vector<int>& rInputSizeList)
        : mInputSizeList(rInputSizeList) {}

    void Generate() override
    {
        for (auto elem : mInputSizeList)
        {
            std::vector<int> data(elem);
            auto f = [](){return rand() % 10000;};
            std::generate(data.begin(), data.end(), f);
            mData_InputSizeList.push_back({data,elem});
        }
    }

    const std::vector<std::pair<std::vector<int>,int>>& generatedData() override
    {
        return mData_InputSizeList;
    }

    std::vector<std::pair<std::vector<int>,int>> mData_InputSizeList;
    std::vector<int> mInputSizeList;

};
