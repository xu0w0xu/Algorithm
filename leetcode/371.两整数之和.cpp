#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

 // @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        return b = 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};
// @lc code=end

