#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size();i++) {
            mp[nums[i]] = i;
        }
        for (int i = 0;i < nums.size();i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1;j < nums.size();j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (mp.count(-nums[i] - nums[j]) && mp[-nums[i] - nums[j]] > j) {
                    res.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                }
            }
        }
        return res;
    }
};
// @lc code=end

