#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */

// @lc code=start
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0));
        vector<double> sum(n + 1, 0);
        for (int i = 1;i <= n;i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
            dp[i][1] = sum[i] / i;
        }
        for (int i = 1;i <= n;i++) {
            for (int j = 2;j <= k;j++) {
                for (int p = 0;p < i;p++) {
                    dp[i][j] = max(dp[i][j], dp[p][j - 1] + (sum[i] - sum[p]) / (i - p));
                }
            }
        }
        return dp[n][k];
    }
};
// @lc code=end

