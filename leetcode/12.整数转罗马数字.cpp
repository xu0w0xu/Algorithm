#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> strs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res = "";
        for(int i=0;i<nums.size();++i){
            while(num>=nums[i]){
                res += strs[i];
                num -= nums[i];
            }
        }
        return res;
    }
};
// @lc code=end

