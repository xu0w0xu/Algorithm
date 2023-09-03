#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        while(num / 10 != 0){
            int tmp = 0;
            while(num != 0){
                tmp += num % 10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};
// @lc code=end

