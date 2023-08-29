#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

 // @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m;i < m + n;i++) {
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.end());
    }
};
// @lc code=end

