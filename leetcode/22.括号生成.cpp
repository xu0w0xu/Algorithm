#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

 // @lc code=start
class Solution {
public:
    void backtrack(int left, int right, string& track, vector<string>& res) {
        if (left < 0 || right<0 || left>right) {
            return;
        }
        if (left == 0 && right == 0) {
            res.push_back(track);
            return;
        }
        track.push_back('(');
        backtrack(left - 1, right, track, res);
        track.pop_back();

        track.push_back(')');
        backtrack(left, right - 1, track, res);
        track.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        vector<string> res;
        string track;
        backtrack(n, n, track, res);
        return res;
    }
};
// @lc code=end

