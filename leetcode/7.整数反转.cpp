#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

 // @lc code=start
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            //判断是否溢出
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) return 0;
            result = result * 10 + pop;
        }
        return result;
    }
};
// @lc code=end

