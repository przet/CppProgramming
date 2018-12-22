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
#include <assert.h>
int main()
{

    sample_space::SampleSpaceGenerator SSG;
    SSG.generator(100);
    binary_search::Vanilla vanillaBinary;

    
    for (auto vec : SSG.table)
    {

        //----generate random target val
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<>dis(0, 10);
        auto targetVal = dis(gen);
        //-------
        auto startTime = std::chrono::high_resolution_clock::now();
        auto result = vanillaBinary.search(vec, targetVal);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        std::cout << "Input of size " << vec.size() << " has execution time of " << duration << " us" << " and result of search is " << result <<"\n";
    }

    std::vector <int> bigVec(2126753390);
    std::generate(begin(bigVec), end(bigVec), [i = 0]()mutable{return i++; });
    auto startTime = std::chrono::high_resolution_clock::now();
    auto result = vanillaBinary.search(bigVec,1702766719);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << duration << "\n";


    binary_search::NumberHigherLower NHL(1702766719);
    assert(NHL.guessNumber(2126753390) == 1702766719);

    auto startTime2 = std::chrono::high_resolution_clock::now();
    auto result2 = NHL.guessNumber(2126753390);
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(endTime2 - startTime2).count();
    std::cout << duration2 << "\n";

    
}

