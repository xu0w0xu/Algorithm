#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0,right = height.size()-1;
        int res = 0;
        while(left<right){
            res = max(res, min(height[left],height[right])*(right-left));
            // 为什么要移动较小的那个指针？
            // 因为移动较大的那个指针，容器的短板不会变长，容器的面积只会变小。
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

