#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int tmp = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                tmp++;
            }else{
                if(tmp > max){
                    max = tmp;
                }
                tmp = 0;
            }
        }
        if(tmp > max){
            max = tmp;
        }
        return max;
    }
};
// @lc code=end

