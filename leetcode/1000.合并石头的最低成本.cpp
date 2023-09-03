#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

 // @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + stones[i - 1];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int t = i; t < j; t += k - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][t] + dp[t + 1][j]);
                }
                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] += sum[j + 1] - sum[i];
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

