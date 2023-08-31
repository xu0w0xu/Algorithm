#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

 // @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 位运算，10000 & 01111 = 0，10000 - 1 = 01111
        return (n > 0) && (n & (n - 1)) == 0;
    }
};
// @lc code=end

