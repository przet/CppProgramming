#include "BinarySearch.hpp"
#include <vector>

namespace binary_search
{

    int Solution::calcMidPoint(int a, int b)
    {
        return (a + b) / 2;
    }

    int Solution::search(std::vector<int> &nums)
    {
        while (leftIndex <= rightIndex) {
            if (target == nums[midIndex])
                return midIndex;
            if (target < nums[midIndex])
                rightIndex = midIndex - 1;
            else
                leftIndex = midIndex + 1;
            //m = calcMid(r, l);
            midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        }
        return -1;
    }
    int Solution::search(std::vector<int> &nums, int targetInput) {
        leftIndex = 0;
        rightIndex = nums.size() - 1;
        target = target;
        // m = calcMid(r, l);
        midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        return search(nums);
    }
}//namespace binary_search
