#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    void dfs(string& digits, int index, string& path, vector<string>& res, unordered_map<char, string>& m){
        if(index == digits.size()){
            res.push_back(path);
            return;
        }
        for(auto c : m[digits[index]]){
            path.push_back(c);
            dfs(digits, index+1, path, res, m);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> res;
        unordered_map<char, string> m = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        string path;
        dfs(digits, 0, path, res, m);
        return res;
    }
};
// @lc code=end

