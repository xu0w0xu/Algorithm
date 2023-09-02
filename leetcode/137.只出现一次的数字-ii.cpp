#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0}; // 用于统计每一位的计数
        int result = 0;

        for (int i = 0; i < 32; ++i) {
            for (int num : nums) {
                // 统计第i位的计数
                count[i] += (num >> i) & 1;
            }
            // 构造只出现一次的元素的第i位
            result |= (count[i] % 3) << i;
        }

        return result;
    }
};
// @lc code=end

