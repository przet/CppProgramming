// BinarySearchDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "../BinarySearch/BinarySearch.hpp"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <random> 
int main()
{
    //input data TODO delegate to a lib
    typedef std::vector<int> Vec;
    typedef std::vector<std::vector<int>> VecOfVec;
    const double sampleSize = 10;
    VecOfVec sampleSpace(sampleSize);
    
    std::for_each(begin(sampleSpace), end(sampleSpace), [i = 1](auto& elem) mutable{elem.resize(i++);
        std::generate(begin(elem), end(elem), [i = 0]() mutable{return i++; }); });
    //----------------

    binary_search::Solution soln;
    
    for (auto vec : sampleSpace)
    {

        //----generate random target val
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<>dis(-sampleSize, sampleSize);
        auto targetVal = dis(gen);
        //-------
        auto startTime = std::chrono::high_resolution_clock::now();
        auto result = soln.search(vec, targetVal);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        std::cout << "Input of size " << vec.size() << " has execution time of " << duration << " ms" << " and result of search is " << result <<"\n";
    }
    
}

