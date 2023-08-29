#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int res = mp[s.back()];
        for (int i = 0; i < s.size() - 1; ++i) {
            if(mp[s[i]] < mp[s[i + 1]]) {
                res -= mp[s[i]];
            } else {
                res += mp[s[i]];
            }
        }
        return res;
    }
};
// @lc code=end

