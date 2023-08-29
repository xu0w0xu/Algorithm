#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i =0, j = 0, res = 0, cnt = 0;
        while (j < nums.size()) {
            if (nums[j] >= left && nums[j] <= right) {
                cnt = j - i + 1;
            }
            else if (nums[j] < left) {
                cnt = cnt;
            }
            else {
                i = j + 1;
                cnt = 0;
            }
            res += cnt;
            j++;
        }
        return res;
    }
};
// @lc code=end

