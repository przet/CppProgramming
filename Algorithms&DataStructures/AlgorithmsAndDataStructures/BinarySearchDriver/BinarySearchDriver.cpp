// BinarySearchDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "../BinarySearch/BinarySearch.hpp"
#include "../DriverInputData/SampleSpaceGenerator.hpp"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <random> 
int main()
{

    sample_space::SampleSpaceGenerator SSG;
    SSG.generator(100);
    binary_search::Solution soln;

    
    for (auto vec : SSG.table)
    {

        //----generate random target val
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<>dis(0, 10);
        auto targetVal = dis(gen);
        //-------
        auto startTime = std::chrono::high_resolution_clock::now();
        auto result = soln.search(vec, targetVal);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        std::cout << "Input of size " << vec.size() << " has execution time of " << duration << " ms" << " and result of search is " << result <<"\n";
    }
    
}

