#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

 // @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size();i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == target) return target;
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    res = sum;
                }
                if (sum > target) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

