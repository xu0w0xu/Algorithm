#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        //记录结果
        string res = "";
        
        int m = a.size(),n = b.size();
        //记录进位
        int carry = 0;
        int i = 0;

        while(i<max(m,n) || carry >0){
            int val = carry;
            val += i<m ? (a[i] == '0') : 0;
            val += i<n ? (b[i] == '0') : 0;
            res.push_back(val%2 + '0');
            carry = val/2;
            i++;
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end
