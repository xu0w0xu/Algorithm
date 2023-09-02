#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 从高位到低位，找到left和right的公共前缀
        int shift = 0;
        // left和right的公共前缀
        while (left < right) {
            // 将left和right同时右移一位
            left >>= 1;
            right >>= 1;
            // 记录右移的次数
            shift++;
        }
        // 将left左移shift位
        return left << shift;
    }
};
// @lc code=end

