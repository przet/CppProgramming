#include <vector>
#include <cmath> //abs()
#include <iostream>

class Solution {
        private:
                int left_index, right_index, middle_index;
                
                bool stop(int right_index, int left_index){
                        return right_index - left_index + 1 <= 3; 
                }
                int mid(int a, int b){
                        return abs(a-b)/2;
                }
                
                int searchInternal(std::vector<int> &nums,int target, int left_index, int right_index,int middle_index){
                if(!stop(right_index,left_index)){
                    if (target == nums[middle_index])
                        return middle_index;

                    else if (target < nums[middle_index]) {
                        //originally in my design I had the following logic in a function
                        //"updateIndex(...)" but I think I needed the use of enums (for neatness).
                        //For the moment putting in logic here.

                        right_index = middle_index;
                        middle_index = mid(right_index, left_index) + left_index;
                        return searchInternal(nums, target, left_index, right_index, middle_index);
                    }
                    else if (target > nums[middle_index]) {
                        left_index = middle_index;
                        middle_index = mid(right_index, left_index) + left_index;
                        return searchInternal(nums, target, left_index, right_index, middle_index);
                    }
                }
                else {
                        if (target == nums[middle_index])
                            return middle_index;
                        else if (target == nums[left_index])
                            return left_index;
                        else if (target == nums[right_index])
                            return right_index;
                        else
                            return -1;
                }
                
                }

                //TODO: implement a functor object to call middle_index(val). Might have to but functor class
                //outside of this file for neatness.
        public:
                Solution(std::vector<int> &nums) : left_index(0) , right_index (nums.size() -1), 
                        middle_index (mid(left_index, right_index)) {}
                Solution() {}

                int search (std::vector<int> &nums, int target){
                        left_index = 0;
                        right_index = nums.size()-1;
                        middle_index = mid(left_index,right_index);
                        return searchInternal(nums,target,left_index,right_index,middle_index);
                }
};
 
int main(){
        Solution solution;
        std::vector<int> nums{-1,0,3,5,9,12};
        int target = 2;
        std::cout << (solution.search(nums, target)) << std::endl;
        system("pause");
}
