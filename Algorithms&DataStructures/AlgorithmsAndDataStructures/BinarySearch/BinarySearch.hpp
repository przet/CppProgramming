#ifndef BINARY_SEARCH__H
#define BINARY_SEARCH__H

#include <vector>
#include <memory> // std::allocator

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
}// namespace binary_search

//Template Definitions-TODO make it a header file
#include "BinarySearch.cpp"

#endif // !BINARY_SEARCH__H