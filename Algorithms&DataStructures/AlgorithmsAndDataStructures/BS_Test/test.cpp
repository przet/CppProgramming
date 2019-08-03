#include "pch.h"
#include <BinarySearch.hpp>

TEST(KClosestElements, Test_TgtNumInsideAndPresent_1)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 1,2,3,4,5 };
    int tgtNum = 3;
    int k = 4;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{ 1,2,3,4 };
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumInsideAndPresent_2)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 1,2,3,4,5 };
    int tgtNum = 3;
    int k = 1;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{3};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumInsideAndPresent_3)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 1,2,3,4,5 };
    int tgtNum = 3;
    int k = 5;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{1,2,3,4,5};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumInsideAndPresent_4)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 1,2,3,4,5 };
    int tgtNum = 1;
    int k = 3;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{1,2,3};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumInsideAndPresent_5)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 1,2,3,4,5 };
    int tgtNum = 5;
    int k = 3;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{3,4,5};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumInsideAndPresent_6)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 1,2,3,4,5 };
    int tgtNum = 2;
    int k = 4;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{1,2,3,4};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumInsideAndPresent_7)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 1,2,3,4,5 };
    int tgtNum = 4;
    int k = 4;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{2,3,4,5};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}


TEST(KClosestElements, Test_TgtNumInsideAndPresent_8)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{-10, -9,3,100,120,1000 };
    int tgtNum = -9;
    int k = 4;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{-10, -9, 3, 100};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumInsideNOTPresent_1)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 1,2,4,5 };
    int tgtNum = 3;
    int k = 4;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{1,2,4,5};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumInsideNOTPresent_2)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 2,4,100,};
    int tgtNum = 3;
    int k = 2;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{2,4};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumOutside_1)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 2,4,100,};
    int tgtNum = 1;
    int k = 2;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{2,4};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumOutside_2)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 2,4,100,};
    int tgtNum = -10;
    int k = 1;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{2};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
TEST(KClosestElements, Test_TgtNumOutside_3)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 2,4,100,};
    int tgtNum = 200;
    int k = 2;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{4,100};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}

TEST(KClosestElements, Test_TgtNumOutside_4)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 2,4,100,};
    int tgtNum = 200;
    int k = 1;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{100};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}

TEST(KClosestElements, Test_TgtNumInsideAndPresent_Duplicates)
{
    binary_search::KClosestElements _KClosestElements;
    std::vector<int> inputArr{ 1,1,1,3,4,5 };
    int tgtNum = 3;
    int k = 4;
    auto result = _KClosestElements.Solution(inputArr, k, tgtNum);
    auto expectedResult = std::vector<int>{1,1,3,4};
    EXPECT_EQ(result, expectedResult);
    EXPECT_TRUE(true);
}
/*
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetIn_1)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
    int tgtNum = 3;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
	auto expectedResult = 2;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetIn_2)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{1,2,3,3,4,5,6 };
    int tgtNum = 3;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
	auto expectedResult = 2;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetIn_3)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{1,1,1,1,1,2,2,2,3,4,5,6,7,7,7 };
    int tgtNum = 2;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
	auto expectedResult = 5;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetIn_4)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{100, 250, 300};
    int tgtNum = 250;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
	auto expectedResult = 1;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetIn_5)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{100, 250};
    int tgtNum = 250;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
	auto expectedResult = 1;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetIn_6)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{100};
    int tgtNum = 100;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
    auto expectedResult = 0;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}*/
/*/
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetOutOfBounds_1)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
    int tgtNum = 8;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
    auto expectedResult = FindKClosestNeighbours.OutOfBounds;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetOutOfBounds_2)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
    int tgtNum = -1;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
    auto expectedResult = FindKClosestNeighbours.OutOfBounds;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetInBoundsNotPresent_1)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{1,2,3,3,4,7};
    int tgtNum = 5;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
	auto expectedResult = 4;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetInBoundsNotPresent_2)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{1};
    int tgtNum = 5;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
	auto expectedResult = 0;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, Test_FindTargetIdx_TargetInBoundsNotPresent_3)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{1,2,3,3,3,6,7,8};
    int tgtNum = 4;
	
	auto result = FindKClosestNeighbours.FindTgtIdx(inputArr, tgtNum);
	auto expectedResult = 4;

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}*/
/*
TEST(KClosestNeighbours, InsideBounds_1)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 5;
	int tgtIdx = 3;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours(inputArr, k, tgtIdx);
	auto expectedResult = std::vector<int>{1,2,3,4,5};

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

TEST(KClosestNeighbours, TargetValueIsSmallest)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 5;
	int tgtVal = -1;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours_TARGETOUT(inputArr, k, tgtVal);
	auto expectedResult = std::vector<int>{ 1,2,3,4,5 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}

TEST(KClosestNeighbours, TargetValueIsLargest)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 5;
	int tgtVal = 10;
	
	auto result = FindKClosestNeighbours.PrintKClosestNeighbours_TARGETOUT(inputArr, k, tgtVal);
	auto expectedResult = std::vector<int>{ 3,4,5,6,7 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}

TEST(KClosestNeighbours, TargetValueIsLargest_2)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 1,2,3,4,5,6,7 };
	int k = 5;
	int tgtVal = 10;
	
	auto result = FindKClosestNeighbours.Solution(inputArr, k, tgtVal);
	auto expectedResult = std::vector<int>{ 3,4,5,6,7 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, leetcode_1)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{ 0,1,1,1,2,3,6,7,8,9};
	int k = 9;
	int tgtVal = 4;
	
	auto result = FindKClosestNeighbours.Solution(inputArr, k, tgtVal);
	auto expectedResult = std::vector<int>{ 0,1,1,1,2,3,6,7,8};

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, leetcode_2)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{1,2,3,4,5 };
	int k = 4;
	int tgtVal = 3;
	
	auto result = FindKClosestNeighbours.Solution(inputArr, k, tgtVal);
	auto expectedResult = std::vector<int>{1,2,3,4 };

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, leetcode_3)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{0,0,0,1,3,5,6,7,8,8 };
	int k = 2;
	int tgtVal = 2;
	
	auto result = FindKClosestNeighbours.Solution(inputArr, k, tgtVal);
    auto expectedResult = std::vector<int>{ 1,3 }; // I think this is wrong and should be {0,1} !! 

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
TEST(KClosestNeighbours, leetcode_4)
{
	binary_search::FindKClosetNeighbours FindKClosestNeighbours;
	std::vector<int> inputArr{1,2,5,5,6,6,7,7,8,9 };
	int k = 7;
	int tgtVal = 7;
	
	auto result = FindKClosestNeighbours.Solution(inputArr, k, tgtVal);
    auto expectedResult = std::vector<int>{5,5,6,6,7,7,8};

	EXPECT_EQ(result, expectedResult);
	EXPECT_TRUE(true);
}
*/
