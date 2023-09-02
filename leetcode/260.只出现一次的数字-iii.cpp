#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

 // @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }

        int rightmostOne = xorResult & (~xorResult + 1);

        int a = 0, b = 0;
        for (int num : nums) {
            if ((num & rightmostOne) != 0) {
                a ^= num;
            }
            else {
                b ^= num;
            }
        }

        return { a, b };
    }
};
// @lc code=end

