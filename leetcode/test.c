#include <stdio.h>
#include <stdlib.h>


int divide(int dividend, int divisor) {
        // 记录结果符号，并将两数取绝对值
        int neg;
        if (dividend < 0 && divisor > 0) neg = 1;
        dividend = abs(dividend);   divisor = abs(divisor);

        int shift = 0;
        int res = 0;
        while (dividend > divisor) {
            divisor <<= 1;
            shift++;
        }
        while (shift) {
            res <<= 1;
            divisor >>= 1;
            shift--;
            if (dividend >= divisor) {
                dividend -= divisor;
                res++;
            }
        }
        return neg ? -res : res;
}

int main() {
    printf("%d\n",divide(10,3));
    system("pause");
    return 0;
}

