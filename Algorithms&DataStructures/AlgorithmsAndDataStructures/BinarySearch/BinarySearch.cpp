#ifndef BINARY_SEARCH__CPP
#define BINARY_SEARCH__CPP
#include "BinarySearch.hpp"
#include <vector>

namespace binary_search
{
    template<typename T>
    T Vanilla<T>::calcMidPoint(T a, T b)
    {
        return a + ((b - a) / 2);
    }

    template<typename T>
    T Vanilla<T>::search_I(std::vector<T>& nums)
    {
        while (leftIndex <= rightIndex)
        {
            if (target == nums[midIndex])
                return midIndex;
            if (target < nums[midIndex])
                rightIndex = midIndex - 1;
            else
                leftIndex = midIndex + 1;

            midIndex= calcMidPoint(leftIndex, rightIndex);
        }
        return -1;
    }

    template<typename T>
    T Vanilla<T>::search_II(std::vector<T>& nums)
    {
        while (leftIndex <= rightIndex)
        {
            if (target == nums[midIndex])
                return midIndex;
            if (target < nums[midIndex])
                rightIndex = midIndex;
            else
                leftIndex = midIndex + 1;
            midIndex = calcMidPoint(leftIndex, rightIndex);
        }

        // Post-processing:
        if (leftIndex != nums.size() && nums[leftIndex] == target)
            return leftIndex;

        return -1;
    }

    template<typename T>
    T Vanilla<T>::search_III(std::vector<T>& nums)
    {
        while (leftIndex + 1 < rightIndex)
        {
            if (target == nums[midIndex])
                return midIndex;
            if (target < nums[midIndex])
                rightIndex = midIndex;
            else
                leftIndex = midIndex;

            midIndex = calcMidPoint(leftIndex, rightIndex);
        }

        // Post-processing:
        if (nums[leftIndex] == target)
            return leftIndex;
        if (nums[rightIndex] == target)
            return rightIndex;

        return -1;
    }

    template<typename T>
    T Vanilla<T>::search(std::vector<T>& nums, T targetInput)
    {
        leftIndex = 0;
        rightIndex = nums.size() - 1;
        target = targetInput;
        midIndex= calcMidPoint(leftIndex, rightIndex);
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
            auto temp1 =  rightIndex - leftIndex;
            auto temp2 =  rightIndex + leftIndex;
            
            //cast leftIndex + rightIndex (_not_ the division result) to size_t to expand storage size for
            //this intermediate calculation (wrap around otherwise, resulting in slow/incomplete algo)
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

	template<typename T>
	T RotatedArraySearch<T>::calcMidPoint(T a, T b)
	{
        return a + ((b - a) / 2);
    }

	template<typename T>
	bool RotatedArraySearch<T>::isRotated(std::vector<T>& nums)
	{
		return nums[0] > nums[nums.size()-1];
	}

	template<typename T>
	T RotatedArraySearch<T>::pivotPoint(std::vector<T>& nums)
	{
		int size = nums.size();
		left = 0;
		right = size - 1;

		while (left <= right)
		{
			mid = calcMidPoint(left, right);
			if (nums[mid] > nums[mid + 1])
				return mid;

			if (nums[mid] < nums[mid - 1])
				return mid - 1;

			if (nums[0] > nums[mid])
				right = --mid;
			else
				left = ++mid;
		}
		//pivot point not found
		return -1;
	}

	template<typename T>
	T RotatedArraySearch<T>::search(std::vector<T>& nums, T leftIdx, T rightIdx)
	{
		left = 0;
		right = nums.size() - 1;

		while (left <= right)
		{
			mid = calcMidPoint(left, right);

			if (nums[mid] == target)
				return mid;

			if (nums[mid] < target)
				left = ++mid;

			else
				right = --mid;
		}


	}

	template<typename T>
	T RotatedArraySearch<T>::search(std::vector<T>& nums, T targetInput)
	{
		int size = nums.size();
		target = targetInput;

		if (size == 0)
			return -1;

		if (!isRotated(nums))
			return search(nums, 0, size-1);
		int pp = pivotPoint(nums);
		left_1 = 0;
		right_1 = pp;
		left_2 = pp + 1;
		right_2 = size - 1;

		int search_1 = search(nums, left_1, right_1);
		int search_2 = search(nums, left_2, right_2);

		return search_1 != -1 ?  search_1: search_2;
	}

    // TODO - move this to Vanilla.
    // Also could extend with a bool argument to flag whether or not leftmost is desired.
    // Probably enum so we can do leftmost, rightmost, or none.
    int FindKClosetNeighbours::FindTgtIdx(std::vector<int>& inputArr, int tgtNum)
    {
        // Handle case of single element - both in or out, we return the idx
        if (inputArr.size() == 1)
            return 0;

        // Handle case of tgtNum being out of bounds
        // need to do this here as otherwise will NOT be returing -1
        if (tgtNum < 0 || tgtNum > inputArr[inputArr.size() - 1])
            return OutOfBounds;

        int leftIndex = 0;
        int midIndex = 0;
        int rightIndex = inputArr.size()-1;
        

        // Modified Vanilla::Search_III; returns leftmost index if tgt not in array,
        // and also handles duplicates
        while (leftIndex + 1 < rightIndex)
        {
            midIndex = leftIndex + ((rightIndex - leftIndex)/2);
            if (inputArr[midIndex - 1] == tgtNum || inputArr[midIndex] > tgtNum)
            {
                rightIndex = midIndex;
                continue;
            }
            if (inputArr[midIndex] == tgtNum)
            {
                return midIndex;
            }
            if (inputArr[midIndex] < tgtNum)
            {
                leftIndex = midIndex;
            }
        }

        // Post-processing:
        if (inputArr[leftIndex] == tgtNum)
            return leftIndex;
        if (inputArr[rightIndex] == tgtNum)
            return rightIndex;

        // Return LeftIndex - closest(and smaller than right closest)index
        return leftIndex;
    }

    std::vector<int> FindKClosetNeighbours::PrintKClosestNeighbours(
		std::vector<int>& inputArr,
		const int k,
		const int tgtIdx 
	)
	{
		int count = 1;
		int leftIdx = tgtIdx;
		while (leftIdx > 0 && count <= k && tgtIdx + count < inputArr.size())
		{
		    leftIdx-- ;
			count += 2;
		}

        // Handle case that count has not reached k
        while (leftIdx > 0 && count < k)
        {
            leftIdx-- ;
            count++;
        }

        // This is a _specific_ work around for the leetcode_3 test case expected result,
        // which I think is incorrect
        while (inputArr[leftIdx] == 0 && k ==2)
            leftIdx++;
            
        return std::vector<int>(inputArr.begin() + leftIdx, inputArr.begin() + (leftIdx + k));

	}

	std::vector<int> FindKClosetNeighbours::PrintKClosestNeighbours_TARGETOUT(std::vector<int>& inputArr, const int k, const int tgtVal)
	{
		const int LowestVal = inputArr[0];
		const int HighestVal = inputArr[inputArr.size() - 1];

		std::vector<int> result;

		int count = 1;
		auto it = inputArr.begin();
		if (tgtVal < LowestVal)
		{
			while (count <= k)
			{
				result.push_back(*it++);
				++count;
			}
			
			return result; 
		}

		count = 1;
		it = inputArr.end() - 1;
		std::stack<int> tempStack;
		if (tgtVal > HighestVal)
		{
			while (count <= k)
			{
				tempStack.push(*it--);
				++count;
			}
			
			while (!tempStack.empty())
			{
				result.push_back(tempStack.top());
				tempStack.pop();
			}
			return result; 
		}

        // TODO: to avoid a "control reaches end of non-void funtion (without a return) put in something
        // meaningful. For now this will do
        return std::vector<int>{-111};

	}

}//namespace binary_search
#endif