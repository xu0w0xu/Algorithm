#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.empty()) return res;
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return res;
                }
            }
            res += c;
        }
        return res;
    }
};
// @lc code=end

