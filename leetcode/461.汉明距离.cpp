#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int c = 0;
        while (z) {
            z &= (z - 1);
            c++;
        }
        return c;
    }
};
// @lc code=end

