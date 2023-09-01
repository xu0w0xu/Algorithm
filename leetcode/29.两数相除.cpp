#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

 // @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 处理除数为0的情况
        if (divisor == 0) {
            // 根据具体需求返回特殊值或抛出异常
            // 这里返回INT_MAX作为示例
            return INT_MAX;
        }
        
        // 处理被除数为0的情况
        if (dividend == 0) {
            return 0;
        }
        
        // 记录结果符号，并将两数取绝对值
        int neg = 0;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            neg = 1;
        }
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        // 处理被除数为最小负数的情况
        if (absDividend == INT_MIN) {
            if (absDivisor == 1) {
                return neg ? INT_MIN : INT_MAX;
            } else if (absDivisor == -1) {
                return neg ? INT_MAX : INT_MIN;
            }
        }

        long long shift = 0;
        long long res = 0;
        
        // 循环左移除数，直到除数大于被除数
        while (absDividend >= absDivisor) {
            absDivisor <<= 1;
            shift++;
        }
        
        // 循环右移除数，进行除法运算
        while (shift) {
            res <<= 1;
            absDivisor >>= 1;
            shift--;
            if (absDividend >= absDivisor) {
                absDividend -= absDivisor;
                res++;
            }
        }
        
        res = neg ? -res : res;
        
        // 处理结果溢出的情况
        if (res > INT_MAX) {
            return INT_MAX;
        } else if (res < INT_MIN) {
            return INT_MIN;
        }
        
        return res;
    }
};
// @lc code=end

