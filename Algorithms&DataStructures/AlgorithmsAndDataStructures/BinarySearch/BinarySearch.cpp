#ifndef BINARY_SEARCH__CPP
#define BINARY_SEARCH__CPP
#include "BinarySearch.hpp"
#include <vector>

namespace binary_search
{
    template<typename T>
    T Vanilla<T>::calcMidPoint(T a, T b)
    {
        return (a + b) / 2;
    }

    template<typename T>
    T Vanilla<T>::search(std::vector<T>& nums)
    {
        while (leftIndex <= rightIndex)
        {
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

    template<typename T>
    T Vanilla<T>::search(std::vector<T>& nums, T targetInput)
    {
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
            //midIndex = leftIndex +  (rightIndex - leftIndex) / 2;
            auto temp1 =  rightIndex - leftIndex;
            auto temp2 =  rightIndex + leftIndex;
            
            //cast leftIndex + rightIndex (_not_ the division result) to size_t to expand storage size for
            //this intermediated calculation (wrap around otherwise, resulting in slow/incomplete algo)
            midIndex = (size_t)(leftIndex + rightIndex) / 2;
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
#endif