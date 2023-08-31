#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

 // @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // // 1. 递归
        // if (n <= 2) return n;
        // int a = 1, b = 2;
        // for (int i = 3;i <= n;i++) {
        //     int tmp = a + b;
        //     a = b;
        //     b = tmp;
        // }
        // return b;
        // 2. 动态规划
        vector<int> dp(n + 1);
        if (n <= 2) return n;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3;i <= n;i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end

