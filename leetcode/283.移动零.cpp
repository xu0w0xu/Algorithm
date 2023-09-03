#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

 // @lc code=start
class Solution {
public:
    // 移动数列中的0到队尾，返回移动后第一个0的下标
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        while(fast < nums.size()){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }

    void moveZeroes(vector<int>& nums) {
        int p = removeElement(nums, 0);

        for(; p < nums.size(); p++){
            nums[p] = 0;
        }   
    }
};
// @lc code=end

