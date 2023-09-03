#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        s.erase(remove(s.begin(), s.end(), '-'), s.end());
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if(s.empty()) return "";
        else if(s.size() <= k )return s;


        int first = s.size() % k;
        ostringstream ss;
        if(first != 0){
            ss << s.substr(0, first);
            ss << '-';
        }
        for(int i = first; i < s.size(); i += k){
            ss << s.substr(i, k);
            ss << '-';
        }
        string res = ss.str();
        res.pop_back();
        return res;
    }
};
// @lc code=end

