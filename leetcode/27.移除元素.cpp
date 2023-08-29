#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i =0;
        for(int n : nums){
            if(n!=val){
                nums[i] = n;
                i++;
            }
        }
        return i;
    }
};
// @lc code=end

