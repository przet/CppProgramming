#include "ISolution.hpp"
#include "IGenerator.hpp"
#include <utility>
#include <vector>
#include <chrono>
#include "generator_test.hpp"
#include "solution_test.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

template <template <typename... > class Container, typename ContainerDataType>
struct Time
{
    Time(ISolution<Container, ContainerDataType>* rSolution, IGenerator<Container,ContainerDataType>* rGenerator)
        : pSolution(rSolution), pGenerator(rGenerator) {}

    
    const std::vector<std::pair<int,int>>& result()
    {
        auto mGeneratedData = pGenerator->generateData();
        for (const auto& elem : mGeneratedData)
        {
            auto start = std::chrono::high_resolution_clock::now();
            pSolution->Algorithm(elem.first);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
            mResult.push_back({elem.second, duration.count()});
        }
        return mResult;
    }
        

    ISolution<Container,ContainerDataType>* pSolution;
    IGenerator<Container,ContainerDataType>* pGenerator;
    std::vector<std::pair<int, int>> mResult;
    

};


int main (int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "Must provide at least max size of input list" << std::endl;
        std::cout << "Exiting.... " << std::endl;
        return 1;
    }
        
    std::string maxSize_string(*(argv + 1));
    Solution mSolution;
    int maxSize  = std::stoi(maxSize_string);
    std::vector<int> mInputSizeList(maxSize);
    std::generate(begin(mInputSizeList), end(mInputSizeList), [n = 0]() mutable {return n +=50 ;});
    Generator mGenerator(mInputSizeList);

    Time mTime(&mSolution, &mGenerator);
    const std::vector<std::pair<int,int>>& result = mTime.result();

    std::ofstream vOutputCSV;
    // TODO cl arg for outputfilename
    vOutputCSV.open("test.csv");

    if (!vOutputCSV.good())
    {
        std::cout << "Output file not 'good'. Exiting...";
        return 1;
    }

    vOutputCSV << "InputSize, RunTime\n";

    for (const auto& elem : result)
        vOutputCSV << std::to_string(elem.first) + "," + std::to_string(elem.second) + "\n";

    vOutputCSV.close();

    return 0;
}
