#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps(int num) {
        int c = 0;
        while (num) {
            num = (num & 1) ? num - 1 : num >> 1;
            c++;
        }
        return c;
    }
};
// @lc code=end

