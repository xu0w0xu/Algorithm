#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> m;
        for(int i = lowLimit; i <= highLimit; i++){
            int tmp = i;
            int sum = 0;
            while(tmp){
                sum += tmp % 10;
                tmp /= 10;
            }
            m[sum]++;
        }
        int res = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            res = max(res, it->second);
        }
        return res;
    }
};
// @lc code=end

