#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

 // @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0;i <= m;i++) {
            for(int j = 1;j <= n;j++){
                if(p[j-1] == '*'){
                    //表示当前p[j-1]和p[j-2]匹配0次，且s[0...i-1]和p[0...j-3]匹配
                    dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }else{
                    //表示当前s[i-1]和p[j-1]匹配，且s[0...i-2]和p[0...j-2]匹配
                    dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

