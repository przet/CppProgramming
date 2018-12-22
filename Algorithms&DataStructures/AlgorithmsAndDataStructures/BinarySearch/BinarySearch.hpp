#ifndef BINARY_SEARCH__H
#define BINARY_SEARCH__H

#include <vector>

namespace binary_search
{
    class Vanilla 
    {
    private:
        int leftIndex, rightIndex, midIndex, target;
        int calcMidPoint(int, int);
        //TODO: Template
        int search(std::vector<int>& nums);
    public:
        int search(std::vector<int>& nums, int targetInput);
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

#endif // !BINARY_SEARCH__H