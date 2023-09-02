#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

 // @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> mp;
        while (mp[n] != true) {
            mp[n] = true;
            int temp = n;
            int temp_sum = 0;
            while (temp) {
                temp_sum += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            n = temp_sum;
            if (n == 1) return true;
        }
        return false;
    }
};
// @lc code=end

