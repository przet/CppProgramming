#ifndef BINARY_SEARCH__H
#define BINARY_SEARCH__H

#include <vector>
#include <memory> // std::allocator
#include <stack> 
#include <cmath>

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
        // For finding target index (B.S allowing for duplicates)
        FindKClosetNeighbours _FindKClosetNeighbours;

        bool LeftDist_Eq_RightDist(const std::vector<int>& arr, const int idx, const int tgtNum, const int LeftPtr, const int RightPtr)
        {
            if (idx + RightPtr >= arr.size() && idx - LeftPtr >= 0)
                return true;
            if (idx - LeftPtr < 0)
                return false;
            else
                return abs(tgtNum - arr[idx - LeftPtr]) == abs(tgtNum - arr[idx + RightPtr]);
        }
        bool LeftDist_Lt_RightDist(const std::vector<int>& arr, const int idx, const int tgtNum, const int LeftPtr, const int RightPtr)
        {
            if (idx + RightPtr >= arr.size() && idx - LeftPtr >= 0)
                return true;
            if (idx - LeftPtr < 0)
                return false;
            else
                return abs(tgtNum - arr[idx - LeftPtr]) < abs(tgtNum - arr[idx + RightPtr]);
        }
        void StackPush_Incr(const std::vector<int>& arr, const int idx, int& leftPtr, std::stack<int>& stack)
        {
            // TODO check for within bounds? or okay in context? Can't hurt, or overkill?
            // Yes!
            if (idx - leftPtr >= 0)
                stack.push(arr[idx - leftPtr]);
            // TODO why we need here (the inc?) take it out and see what happens...failed test!
            ++leftPtr;
        }
        void VectorPush_Incr(const std::vector<int>& arr, const int idx, int& rightPtr, std::vector<int>& vector)
        {
            if (idx + rightPtr <= arr.size() - 1)
                vector.push_back(arr[idx + rightPtr]);
            ++rightPtr;
        }
        void PopulateVectorFromStack(std::vector<int>& Destination, std::stack<int>& Source)
        {
            while (!Source.empty())
            {
                Destination.push_back(Source.top());
                Source.pop();
            }
        }
        std::vector<int> CombineTwoVectors(std::vector<int> LeftPart, std::vector<int> RightPart)
        {
            std::vector<int> FinalSolution(LeftPart);
            FinalSolution.insert(FinalSolution.end(), RightPart.begin(), RightPart.end());
            return FinalSolution;

        }
        std::vector<int> Solution(std::vector<int>& inputArr, int k, int tgtNum)
        {
            // Quick wins
            if (k == inputArr.size())
                return inputArr;
            if (tgtNum < inputArr[0])
                return std::vector<int>(inputArr.begin(), inputArr.begin() + k);
            if (tgtNum > inputArr[inputArr.size() - 1])
            {
                // TODO - find a quicker/more consise way?
                std::stack<int> tempStack;
                int count = 0;
                for (auto rit = inputArr.rbegin(); rit != inputArr.rend(), count < k; ++rit, ++count)
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

            // Tgt num is inside the array (present or not present) 
            int leftPtr = 1, rightPtr = 1;
            int startIdx = _FindKClosetNeighbours.FindTgtIdx(inputArr, tgtNum);
            std::stack<int> Stack;
            std::vector<int> Vector;

            // TODO: initially I had (in error) push_back(tgtNum)...WHY did the test
            // {1,2,4,5} x = 3, k =4 pass??...I thought 3 would have been pushed back!
            Vector.push_back(inputArr[startIdx]);
            int count = 1;
            while (count < k)
            {
                // TODO get rid of all braces and observe what happens ;)
                if (LeftDist_Eq_RightDist(inputArr, startIdx, tgtNum, leftPtr, rightPtr))
                {
                    if (leftPtr >= inputArr[0])
                        StackPush_Incr(inputArr, startIdx, leftPtr, Stack);
                }
                else if (LeftDist_Lt_RightDist(inputArr, startIdx, tgtNum, leftPtr, rightPtr))
                {
                    if (leftPtr >= inputArr[0])
                        StackPush_Incr(inputArr, startIdx, leftPtr, Stack);
                }
                else
                {
                    if (rightPtr <= inputArr[inputArr.size()-1])
                        VectorPush_Incr(inputArr, startIdx, rightPtr, Vector);

                }
                ++count;
            }
            std::vector<int> LeftSolution;
            PopulateVectorFromStack(LeftSolution, Stack);
            return CombineTwoVectors(LeftSolution,Vector);
        }


    };

    // TODO
    // - Handle duplicates when I am searchin for target indx
    // - Correctly account for non-tie situations - currently its not k _closest_ 

	
}// namespace binary_search

//Template Definitions-TODO make it a header file
#include "BinarySearch.cpp"

#endif // !BINARY_SEARCH__H