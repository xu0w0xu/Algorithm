#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int last = 0;
        for(int i = 0; i < timeSeries.size(); i++){
            if(timeSeries[i] >= last){
                res += duration;
            }else{
                res += timeSeries[i] + duration - last;
            }
            last = timeSeries[i] + duration;
        }
        return res;
    }
};
// @lc code=end

