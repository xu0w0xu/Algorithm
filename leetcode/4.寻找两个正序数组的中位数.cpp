#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

 // @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0.0;
        int m = nums1.size();
        int n = nums2.size();
        // 保证m <= n
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0, right = m;
        int half = (m + n + 1) / 2; //中位数，向上取整

        while (left <= right) {
            int cut1 = left + (right - left) / 2;
            int cut2 = half - cut1;

            int nums1LeftMax = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int nums1RightMin = (cut1 == m) ? INT_MAX : nums1[cut1];
            int nums2LeftMax = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int nums2RightMin = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                // 找到合适的位置，计算中位数
                if ((m + n) % 2 == 0) {
                    return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
                }
                else {
                    return max(nums1LeftMax, nums2LeftMax);
                }
            }
            else if (nums1LeftMax > nums2RightMin) {
                // cut1 太大，减小 cut1 的值
                right = cut1 - 1;
            }
            else {
                // cut1 太小，增大 cut1 的值
                left = cut1 + 1;
            }
        }
        return res;
    }
};
// @lc code=end

