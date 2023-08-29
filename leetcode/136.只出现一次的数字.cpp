#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int, int> mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second == 1){
                return it->first;
            }
        }
        return 0;
    }
};
// @lc code=end

