#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

 // @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
        if (x == 0) { return true; }
        int temp = x;
        long long y = 0;
        while (temp != 0) {
            y = y * 10 + temp % 10;
            temp /= 10;
        }
        return x == y;
    }
};
// @lc code=end

