#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

 // @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n); // 存储每个单词的二进制映射结果
        int maxProd = 0;

        // 计算每个单词的二进制映射结果
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                masks[i] |= (1 << (c - 'a'));
            }
        }

        // 遍历所有的单词对，计算乘积并更新最大值
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((masks[i] & masks[j]) == 0) { // 判断两个单词是否含有公共字母
                    int product = words[i].length() * words[j].length();
                    maxProd = max(maxProd, product);
                }
            }
        }

        return maxProd;
    }
};
// @lc code=end

