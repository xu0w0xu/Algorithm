#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) {
            return res;
        }
        
        int wordLen = words[0].size();
        int wordNum = words.size();
        int windowLen = wordLen * wordNum;
        if(s.size() < windowLen){
            return res;
        }
        unordered_map<string, int> wordCnt;
        for (auto& word : words) {
            wordCnt[word]++;
        }
        
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int count = 0;
            unordered_map<string, int> windowCnt;
            
            for (int j = i; j <= s.size() - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                
                if (wordCnt.find(word) == wordCnt.end()) {
                    // 当前单词不在words中，重置窗口状态
                    windowCnt.clear();
                    count = 0;
                    left = j + wordLen;
                } else {
                    windowCnt[word]++;
                    count++;
                    
                    while (windowCnt[word] > wordCnt[word]) {
                        // 当某个单词出现次数超过words中的次数，左边界右移
                        string leftWord = s.substr(left, wordLen);
                        windowCnt[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    
                    if (count == wordNum) {
                        // 当窗口中的单词数量等于words中的单词数量，找到一个匹配位置
                        res.push_back(left);
                        
                        // 左边界右移一个单词长度
                        string leftWord = s.substr(left, wordLen);
                        windowCnt[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

