#include "stdcc.h"

class Solution {
  public:
    int divide(int dividend, int divisor) {
        // 使用位运算
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long a = abs((long long)dividend), b = abs((long long)divisor), ans = 0;
        while (a >= b) {
            long long tmp = b, cnt = 1;
            // 找到最大的倍数
            while (a >= (tmp << 1)) {
                tmp <<= 1;
                cnt <<= 1;
            }
            a -= tmp;
            ans += cnt;
        }
        return (dividend > 0) == (divisor > 0) ? ans : -ans;
    }
};
