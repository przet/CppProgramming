#include "pch.h"
#include <BinarySearch.hpp>

TEST(KClosestNeighbours, InsideBounds_1)
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

TEST(KClosestNeighbours, InsideBounds_2)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 3, 8, 9, 56, 100, 123  };
	int k = 5;
	int tgtIdx = 2;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours(inputArr, k, tgtIdx);
	auto expectedResult = std::vector<int>{ 3,8,9,56,100 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}

TEST(KClosestNeighbours, ReachLeftBoundInOneStep_1)
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

TEST(KClosestNeighbours, ReachLeftBoundInOneStep_2)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 4;
	int tgtIdx = 1;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours(inputArr, k, tgtIdx);
	auto expectedResult = std::vector<int>{ 1,2,3,4 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, ReachLeftBoundInTwoSteps)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 5;
	int tgtIdx = 2;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours(inputArr, k, tgtIdx);
	auto expectedResult = std::vector<int>{1,2,3,4,5 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}

TEST(KClosestNeighbours, NextLeftIsLeftBound)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 5;
	int tgtIdx = 0;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours(inputArr, k, tgtIdx);
	auto expectedResult = std::vector<int>{ 1,2,3,4,5 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}

TEST(KClosestNeighbours, NextRightisRightBound)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 5;
	int tgtIdx = 6;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours(inputArr, k, tgtIdx);
	auto expectedResult = std::vector<int>{ 3,4,5,6,7 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}

