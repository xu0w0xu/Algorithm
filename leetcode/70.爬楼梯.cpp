#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

 // @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2;
        for (int i = 3;i <= n;i++) {
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};
// @lc code=end

