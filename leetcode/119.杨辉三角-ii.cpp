#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

 // @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return { 1 };
        vector<int> res = { 1 };
        for (int i = 1;i <= rowIndex;i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1;j < i;j++) {
                tmp.push_back(res[j - 1] + res[j]);
            }
            tmp.push_back(1);
            res = tmp;
        }
        return res;
    }
};
// @lc code=end

