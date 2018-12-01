// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <vector>
#include <cmath> //abs()
#include <iostream>

class Solution {
private:
    int l, r, m, t;
    int calcMid(int a, int b) {
        return (a + b) / 2;
    }
    int search(std::vector<int> &nums) {
        while (l <= r) {
            if (t == nums[m])
                return m;
            if (t < nums[m])
                r = m - 1;
            else
                l = m + 1;
            m = calcMid(r, l);
        }
        return -1;
    }

public:
    Solution() {}

    int search(std::vector<int> &nums, int target) {
        l = 0;
        r = nums.size() - 1;
        t = target;
        m = calcMid(r, l);
        return search(nums);
    }
};

int main(){
        Solution solution;
        std::vector<int> nums{-1,0,3,5,9,12};
        int target = 2;
        std::cout << (solution.search(nums, target)) << std::endl;
        system("pause");
}