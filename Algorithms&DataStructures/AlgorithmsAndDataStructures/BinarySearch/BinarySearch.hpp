#ifndef BINARY_SEARCH__H
#define BINARY_SEARCH__H

#include <vector>
#include <memory> // std::allocator
#include <stack> 

namespace binary_search
{
    template<typename T> 
    class Vanilla 
    {
    private:
        T leftIndex, rightIndex, midIndex, target;
        T calcMidPoint(T a, T b);
        T search(std::vector<T>& nums);
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
	};

	
}// namespace binary_search

//Template Definitions-TODO make it a header file
#include "BinarySearch.cpp"

#endif // !BINARY_SEARCH__H