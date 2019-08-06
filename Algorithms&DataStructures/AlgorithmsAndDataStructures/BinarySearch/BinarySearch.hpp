#ifndef BINARY_SEARCH__H
#define BINARY_SEARCH__H

#include <vector>
#include <memory> // std::allocator
#include <stack> 
#include <cmath>
#include <utility>

namespace binary_search
{
    template<typename T> 
    class Vanilla 
    {
    private:
        T leftIndex, rightIndex, midIndex, target;
        T calcMidPoint(T a, T b);
        T search_I(std::vector<T>& nums);
        T search_II(std::vector<T>& nums);
        T search_III(std::vector<T>& nums);
    public:
        T search(std::vector<T>& nums, T targetInput);
    };
    

    class NumberHigherLower
    {
    private:
        int m_targetNumber;
        int leftIndex, rightIndex, midIndex;
        int guess(int num);
    public:
        NumberHigherLower(int targetNumber) : m_targetNumber(targetNumber){}
        int guessNumber(int n);
    };

    template<typename T> 
	class RotatedArraySearch
	{
	private:
		T left, right, left_1, right_1, left_2, right_2, mid, target;
		//TODO friendship or something to reuse this function.
        T calcMidPoint(T a, T b);
		bool isRotated(std::vector<T>& nums);
		T pivotPoint(std::vector<T>& nums);
		T search(std::vector<T>& nums, T leftIdx, T rightIdx);
	public:
		T search(std::vector<T>& nums, T targetInput);
		
	};

    class FindKClosetNeighbours
    {
    private:
        std::vector<int> tgtStore;
        std::vector<int> leftOfTgtStore;
        std::stack<int> leftOfTgt_intermediate_Store;
        std::vector<int> rightOfTgtStore;
    public:
        enum {OutOfBounds = -1};

        int FindTgtIdx(std::vector<int>& inputArr, int tgtNum);

        std::vector<int> PrintKClosestNeighbours(
            std::vector<int>& inputArr,
            const int k,
            const int tgtIdx
        );

        std::vector<int> PrintKClosestNeighbours_TARGETOUT(
            std::vector<int>& inputArr,
            const int k,
            const int tgtVal
        );

        // Combined use of above functions
        std::vector<int> Solution(std::vector<int>& inputArr, int k, int tgtNum)
        {
            if (tgtNum < inputArr[0] || tgtNum > inputArr[inputArr.size() - 1])
                return PrintKClosestNeighbours_TARGETOUT(inputArr, k, tgtNum);

            int tgtIdx = FindTgtIdx(inputArr, tgtNum);
            return PrintKClosestNeighbours(inputArr, k, tgtIdx);
        }
    };

    struct KClosestElements
    {
        std::vector<int> Solution(std::vector<int>& arr, int k, int x)
        {
            if (k == arr.size())
                return arr;
            if (x < arr[0])
                return std::vector<int>(arr.begin(), arr.begin() + k);
            if (x > arr[arr.size() - 1])
            {
                // TODO - find a quicker/more consise way?
                std::stack<int> tempStack;
                int count = 0;
                for (auto rit = arr.rbegin(); rit != arr.rend(), count < k; ++rit, ++count)
                {
                    tempStack.push(*rit);
                }
                std::vector<int> returnVec;
                while (!tempStack.empty())
                {
                    returnVec.push_back(tempStack.top());
                    tempStack.pop();
                }
                return returnVec;
            }


            FindKClosetNeighbours _FKCN;
            int TgtIdx = _FKCN.FindTgtIdx(arr, x);

            int Left = TgtIdx;
            int Right = ++TgtIdx;

            int count = 0;
            int Size = arr.size();
            std::stack<int> Stack;
            std::vector<int> RightVector;
            
            while (Left >= 0 && Right < Size && count < k)
            {
                if (x - arr[Left] <= arr[Right] - x)
                    Stack.push(arr[Left--]);
                else
                    RightVector.push_back(arr[Right++]);
                ++count;
            }

            while (count < k && Left >= 0)
            {
                Stack.push(arr[Left--]);
                ++count;
            }

            while (count < k && Right < Size)
            {
                RightVector.push_back(arr[Right++]);
                ++count;
            }

            // Create the left part of the solution
            std::vector<int> LeftVector;
            while (!Stack.empty())
            {
                LeftVector.push_back(Stack.top());
                Stack.pop();
            }

            std::vector<int> FinalSolution(LeftVector);
            FinalSolution.insert(FinalSolution.end(), RightVector.begin(), RightVector.end());

            return FinalSolution;

        }
        



    };

    // TODO
    // - Handle duplicates when I am searchin for target indx
    // - Correctly account for non-tie situations - currently its not k _closest_ 

	
}// namespace binary_search

//Template Definitions-TODO make it a header file
#include "BinarySearch.cpp"

#endif // !BINARY_SEARCH__H