#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numIndex;
        for (int i = 0; i < nums.size(); ++i) {
            if (numIndex.count(nums[i]) && i - numIndex[nums[i]] <= k) {
                return true;
            }
            numIndex[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

