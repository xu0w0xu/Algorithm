#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res += nums[i];
            nums[i] = res;
        }
        return nums;
    }
};
// @lc code=end

