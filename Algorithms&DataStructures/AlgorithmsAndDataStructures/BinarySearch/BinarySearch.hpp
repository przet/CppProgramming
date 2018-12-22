#ifndef BINARY_SEARCH__H
#define BINARY_SEARCH__H

#include <vector>

namespace binary_search
{
    class Solution
    {
    private:
        int leftIndex, rightIndex, midIndex, target;
        int calcMidPoint(int, int);
        //TODO: Template
        int search(std::vector<int>& nums);
    public:
        int search(std::vector<int>& nums, int targetInput);
    };
}// namespace binary_search

#endif // !BINARY_SEARCH__H