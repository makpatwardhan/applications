/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/
#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
         std::vector<int> index;
        for(int i=0 ; i < nums.size(); i++)
        {
            int j = i+1;
            int val = nums[i];
            auto it = std::find_if(nums.begin()+j, nums.end(),[target,val,&j](auto it)
                                 {
                                         return it == target-val;
                                         j++;
                                 });
            if(it != nums.end())
            {
               std::cout << *it <<std::endl;
               index.emplace_back(i);
               index.emplace_back(j); 
            }
        }
        return index;
    }
};

int main()
{
    Solution s;
    s.twoSum({2,7,11,15},9);
    s.twoSum({3,2,4},6);
    s.twoSum({3,3},6);

}