#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

 // @lc code=start
class Solution {
public:
    // 打家劫舍
    int rob(vector<int>& nums) {
            vector<int> dp(nums.size(), 0);
            dp[0] = nums[0];
            
            for(int i=1;i<nums.size();++i){
                if(i==1) dp[i] = max(dp[i-1], nums[i]);
                else dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            }
            return dp[nums.size()-1];
        }

    int deleteAndEarn(vector<int>& nums) {
        vector<int> sum(10001, 0);
        vector<int> val(10001, 0);
        for (int i = 0;i < nums.size();++i) {
            ++sum[nums[i]];
        }
        for (int i = 1;i < 10001;++i) {
            val[i] = i * sum[i];
        }
        return rob(val);
    }
};
// @lc code=end

