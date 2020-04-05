//#include "ISolution.hpp" 
//#include "IGenerator.hpp"
#include <utility>
#include <vector>
#include <chrono>
#include "generator_test.hpp"
#include "solution_test.hpp"
#include <iostream>

struct Time
{
    Time(ISolution<std::vector,int>* rSolution, IGenerator* rGenerator)
        : pSolution(rSolution), pGenerator(rGenerator) {}

    
    const std::vector<std::pair<int,int>>& result()
    {
        pGenerator->Generate();
        auto mGeneratedData = pGenerator->generatedData();
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
        

    ISolution<std::vector,int>* pSolution;
    IGenerator* pGenerator;
    std::vector<std::pair<int, int>> mResult;
    

};


int main ()
{
    Solution mSolution;
    std::vector<int> mInputSizeList{1,5,10,15,20};
    Generator mGenerator(mInputSizeList);

    Time mTime(&mSolution, &mGenerator);
    const std::vector<std::pair<int,int>>& result = mTime.result();

    for (const auto& elem : result)
        std::cout << "InputSize: " << elem.first << "    " << "RunTime: " << elem.second << std::endl;
    
    return 0;
}
