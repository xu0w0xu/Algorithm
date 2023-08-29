#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

 // @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0;i < s.length();i++) {
            // 以s[i]为中心的最长回文子串
            string s1 = palindrome(s, i, i);
            // 以s[i]和s[i+1]为中心的最长回文子串
            string s2 = palindrome(s, i, i + 1);
            // res = longest(res,s1,s2)
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }

    string palindrome(string s, int l, int r) {
        // 防止索引越界
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            // 向两边展开
            l--;
            r++;
        }
        // 返回以s[l]和s[r]为中心的最长回文串
        return s.substr(l + 1, r - l - 1);
    }
};
// @lc code=end

