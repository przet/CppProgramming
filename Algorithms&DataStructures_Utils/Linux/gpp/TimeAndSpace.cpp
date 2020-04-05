//#include "ISolution.hpp" 
//#include "IGenerator.hpp"
#include <utility>
#include <vector>
#include <chrono>
#include "generator_test.hpp"
#include "solution_test.hpp"
#include <iostream>

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
    Solution mSolution;
    std::vector<int> mInputSizeList{0,500,1000,5000,10000,50000,100000};
    Generator mGenerator(mInputSizeList);

    Time mTime(&mSolution, &mGenerator);
    const std::vector<std::pair<int,int>>& result = mTime.result();

    for (const auto& elem : result)
        std::cout << "InputSize: " << elem.first << "    " << "RunTime: " << elem.second << std::endl;
    
    return 0;
}
