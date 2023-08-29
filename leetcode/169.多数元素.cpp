#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

 // @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }
        for (auto it = mp.begin();it != mp.end();it++) {
            if (it->second > nums.size() / 2) return it->first;
        }
        return -1;
    }
};
// @lc code=end

