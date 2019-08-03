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
            std::vector<std::pair<int, int>> DistanceArray;
        for (int i = 0; i < arr.size(); ++i)
        {
            DistanceArray.push_back({abs(x-arr[i]), i});
        }
        
        for (int j = 0; j < DistanceArray.size(); ++j)
        {
           
           for (int i = j; i + 1 < DistanceArray.size();++i)
           {
               if (DistanceArray[i+1].first < DistanceArray[j].first)
               {
                   auto temp = DistanceArray[j];
                   DistanceArray[j] = DistanceArray[i+1];
                   DistanceArray[i+1] = temp;
               }
           }
        }
        
        
        std::vector<int> ResultStaging;
        for (auto elem : DistanceArray)
            ResultStaging.push_back(arr[elem.second]);
        
        
        auto Result = std::vector<int>(ResultStaging.begin(), ResultStaging.begin() + k);
            
        for (int j = 0; j < Result.size(); ++j)
        {
           
           for (int i = j; i + 1 < Result.size();++i)
           {
               if (Result[i+1] < Result[j])
               {
                   int temp = Result[j];
                   Result[j] = Result[i+1];
                   Result[i+1] = temp;
               }
           }
        }
        
        return Result;
        }


    };

    // TODO
    // - Handle duplicates when I am searchin for target indx
    // - Correctly account for non-tie situations - currently its not k _closest_ 

	
}// namespace binary_search

//Template Definitions-TODO make it a header file
#include "BinarySearch.cpp"

#endif // !BINARY_SEARCH__H