#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingNum = nums.size(); // 设置初始值为 n
        for (int i = 0; i < nums.size(); ++i) {
            missingNum ^= i ^ nums[i];
        }
        return missingNum;
    }
};
// @lc code=end

