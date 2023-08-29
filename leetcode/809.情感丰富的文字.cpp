#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

/*
 * @lc app=leetcode.cn id=809 lang=cpp
 *
 * [809] 情感丰富的文字
 */

 // @lc code=start
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        // 用vector存储s中连续相同的字符及其个数
        vector<pair<char, int>> v;
        char cache = s[0];
        int cache_cnt = 1;
        // 遍历s，将连续相同的字符及其个数存入vector
        for (int i = 1;i < s.length();i++) {
            if (s[i] == cache) {
                cache_cnt++;
            }
            else {
                v.push_back({ cache, cache_cnt });
                cache = s[i];
                cache_cnt = 1;
            }
        }
        v.push_back({ cache, cache_cnt });

        int res = 0;
        // 遍历words，判断每个word是否符合要求
        for (auto word : words) {
            int k =0;
            word = word + 'X';
            cache = word[0];
            cache_cnt = 1;
            for (int i = 1;i < word.length();i++) {
                // 如果此时k == v.size()，说明word还没判断完，不符合要求，直接break
                if(k == v.size()){
                    res--;
                    break;
                }
                if(word[i] != cache){
                    auto p = v[k];
                    // 如果word[i] != cache，但是v[k]的字符和cache相同，且v[k]的个数大于等于3或者v[k]的个数等于cache_cnt，那么k++，否则break
                    if(cache != p.first || (p.second < cache_cnt) || (p.second < 3 && p.second > cache_cnt)) break;
                    k++;
                    cache = word[i];
                    cache_cnt = 1;
                }
                else cache_cnt++;
            }
            // 如果k == v.size()，说明word符合要求
            if(k == v.size()) res++;
        }
        return res;
    }
};
// @lc code=end

