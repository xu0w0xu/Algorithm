#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // // 暴力法
        // int minPrice = INT_MAX;
        // int maxProfit = 0;
        // for (int i = 0;i < prices.size();i++) {
        //     // if (prices[i] < minPrice) {
        //     //     minPrice = prices[i];
        //     // }
        //     // else if (prices[i] - minPrice > maxProfit) {
        //     //     maxProfit = prices[i] - minPrice;
        //     // }
        //     prices[i] < minPrice ? minPrice = prices[i] : prices[i] - minPrice > maxProfit ? maxProfit = prices[i] - minPrice : 0;
        // }
        // return maxProfit;

        // 动态规划
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(2));
        // dp[i][0]表示第i天不持有股票的最大利润
        // dp[i][1]表示第i天持有股票的最大利润
        for (int i = 0;i < n;i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            dp[i][1] = max(-prices[i], dp[i - 1][1]);
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

