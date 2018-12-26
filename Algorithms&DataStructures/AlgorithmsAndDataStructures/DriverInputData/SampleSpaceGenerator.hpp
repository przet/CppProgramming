#pragma once
namespace sample_space
{
    struct SampleSpaceGenerator
    {
        std::vector<std::vector<int>> table;
        void generator(int sampleSize);
    };
}
