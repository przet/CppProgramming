#include "pch.h"
#include <BinarySearch.hpp>

TEST(KClosestNeighbours, InsideBounds)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 5;
	int tgtIdx = 3;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours(inputArr, k, tgtIdx);
	auto expectedResult = std::vector<int>{ 2,3,4,5,6 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}

TEST(KClosestNeighbours, ReachLeftBound)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 5;
	int tgtIdx = 1;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours(inputArr, k, tgtIdx);
	auto expectedResult = std::vector<int>{ 1,2,3,4,5 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}

