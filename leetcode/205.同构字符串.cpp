#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 用两个哈希表分别记录s和t中字符的映射关系
        unordered_map<char, char> mp;
        unordered_map<char, char> mp2;
        // 遍历s和t，记录映射关系
        for (int i = 0; i < s.size(); ++i) {
            // 如果s[i]和t[i]之前没有出现过，就记录映射关系
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = t[i];
            } else {
                if (mp[s[i]] != t[i]) return false;
            }
            if (mp2.find(t[i]) == mp2.end()) {
                mp2[t[i]] = s[i];
            } else {
                // 如果s[i]和t[i]之前出现过，但是映射关系不对，就返回false
                if (mp2[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

