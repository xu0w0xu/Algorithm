#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        // 0: not rob the first house
        dp[0][0] = 0;
        // 1: rob the first house
        dp[0][1] = nums[0];
        for(int i=1;i<nums.size();++i){
            if(i==1){
                dp[i][0] = max(dp[i-1][0], nums[i]);
                dp[i][1] = max(dp[i-1][1], nums[i]);
            }
            else if(i==nums.size()-1){
                dp[i][0] = max(dp[i-1][0], dp[i-2][0] + nums[i]);
                dp[i][1] = dp[i-1][1];
            }
            else{
                dp[i][0] = max(dp[i-1][0], dp[i-2][0] + nums[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-2][1] + nums[i]);
            }
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};
// @lc code=end

