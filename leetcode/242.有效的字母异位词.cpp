#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for (char c : s) {
            map[c]++;
        }
        for (char c : t) {
            map[c]--;
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

