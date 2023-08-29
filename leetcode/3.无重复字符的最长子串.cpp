#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string res = "";
        int max = 0;
        for (auto it = s.begin();it != s.end();++it) {
            auto pos = res.find(*it);
            if (pos != string::npos) {
                res = res.substr(pos + 1);
            }
            res.push_back(*it);
            if (res.size() > max) max = res.size();
        }
    return max;
    }
};
// @lc code=end

