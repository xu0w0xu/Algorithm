#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push_back(c);
            } else {
                if (stk.empty()) return false;
                if (c == ')' && stk.back() != '(') return false;
                if (c == ']' && stk.back() != '[') return false;
                if (c == '}' && stk.back() != '{') return false;
                stk.pop_back();
            }
        }
        return stk.empty();
    }
};
// @lc code=end

