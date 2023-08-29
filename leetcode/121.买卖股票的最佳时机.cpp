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
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0;i < prices.size();i++) {
            // if (prices[i] < minPrice) {
            //     minPrice = prices[i];
            // }
            // else if (prices[i] - minPrice > maxProfit) {
            //     maxProfit = prices[i] - minPrice;
            // }
            prices[i] < minPrice ? minPrice = prices[i] : prices[i] - minPrice > maxProfit ? maxProfit = prices[i] - minPrice : 0;
        }
        return maxProfit;
    }
};
// @lc code=end

