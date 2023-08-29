#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

 // @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (auto it = columnTitle.begin();it != columnTitle.end();++it) {
            res = res * 26 + (*it - 'A' + 1);
        }
        return res;
    }
};
// @lc code=end

