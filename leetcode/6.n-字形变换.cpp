#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

 // @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string result = "";
        //the size of a cycle(period)
        int cycle = 2 * numRows - 2;
        // i is the row number
        for (int i = 0;i < numRows;++i) {
            // j is the index of the character in the row
            for (int j = i;j < s.length();j = j + cycle) {
                result += s[j];
                int secondJ = (j - i) + cycle - i;
                if (i != 0 && i != numRows - 1 && secondJ < s.length()) {
                    result += s[secondJ];
                }
            }
        }
        return result;
    }
};
// @lc code=end

