#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numCount;
        for (int num : nums) {
            if (numCount[num] == 1) {
                return true;
            }
            numCount[num]++;
        }
        return false;
    }
};
// @lc code=end

