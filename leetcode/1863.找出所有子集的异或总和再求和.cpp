#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=1863 lang=cpp
 *
 * [1863] 找出所有子集的异或总和再求和
 */

// @lc code=start
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int i,j,ans;
        int sum = 0;
        for(i=0;i<(1<<nums.size());i++){
            ans = 0;
            for(j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    ans ^= nums[j];
                }
            }
            sum += ans;
        }
        return sum;
    }
};
// @lc code=end

