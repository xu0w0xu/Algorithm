#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0;i <= n;i++) {
            int count = 0;
            int num = i;
            // 逐个消去最低位的1，直到0
            while (num) {
                num &= (num - 1);
                count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
// @lc code=end

