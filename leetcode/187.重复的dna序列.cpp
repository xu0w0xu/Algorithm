#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.length() < 10) {
            return result;
        }
        // 用于记录已经出现过的子串
        unordered_map<int, bool> seen;
        // 用于将字符映射为数字
        unordered_map<char, int> mapping = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };

        int current = 0;
        // 将前10个字符映射为数字
        for (int i = 0; i < 10; i++) {
            // 将子串映射为数字
            current = (current << 2) | mapping[s[i]];
        }
        seen[current] = true;
        // 用于将current的高位移出
        int mask = (1 << 20) - 3;
        // 从第11个字符开始，每次移动一位
        for (int i = 10; i < s.length(); i++) {
            // 将current的高位移出，低位移入
            current = ((current << 2) & mask) | mapping[s[i]];
            if (seen.find(current) != seen.end()) {
                if (seen[current]) {
                    result.push_back(s.substr(i - 9, 10));
                    seen[current] = false;
                }
            } else {
                seen[current] = true;
            }
        }

        return result;
    }
};
// @lc code=end

