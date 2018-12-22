#include "BinarySearch.hpp"
#include <vector>

namespace binary_search
{

    int Vanilla::calcMidPoint(int a, int b)
    {
        return (a + b) / 2;
    }

    int Vanilla::search(std::vector<int> &nums)
    {
        while (leftIndex <= rightIndex) {
            if (target == nums[midIndex])
                return midIndex;
            if (target < nums[midIndex])
                rightIndex = midIndex - 1;
            else
                leftIndex = midIndex + 1;
            midIndex= calcMidPoint(rightIndex, leftIndex);
            //midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        }
        return -1;
    }
    int Vanilla::search(std::vector<int> &nums, int targetInput) {
        leftIndex = 0;
        rightIndex = nums.size() - 1;
        target = targetInput;
        midIndex= calcMidPoint(rightIndex, leftIndex);
        //midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        return search(nums);
    }
    int NumberHigherLower::guess(int num)
    {
        if (m_targetNumber < num)
            return -1;
        if (m_targetNumber > num)
            return 1;
        else
            return 0;
    }
    int NumberHigherLower::guessNumber(int n)
    {
        leftIndex = 0;
        rightIndex = n;
        while (leftIndex <= rightIndex)
        {
            midIndex = leftIndex +  (rightIndex - leftIndex) / 2;
            if (guess(midIndex) == 0)
                return midIndex;
            else if (guess(midIndex) == -1)
                rightIndex = midIndex - 1;
            else if (guess(midIndex) == 1)
                leftIndex = midIndex + 1;
        }
        return -1;
    }
}//namespace binary_search
