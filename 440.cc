#include "stdcc.h"

class Solution {
  public:
    int findKthNumber(int n, int k) {
        // 字典第k小数的查找
        int current = 1; // 从1开始
        k--;             // 因为我们从1开始，所以k需要减1
        while (k > 0) {
            int count = countPrefix(current, n);
            if (count <= k) {
                // 如果当前前缀的数量小于等于k，说明需要跳过这个前缀
                current++;
                k -= count; // 减去当前前缀的数量
            } else {
                // 如果当前前缀的数量大于k，说明k在这个前缀下
                current *= 10; // 进入下一个层级
                k--;           // 减1因为我们进入了下一层
            }
        }
        return current;
    }

    int countPrefix(int prefix, int n) {
        // 计算以prefix为前缀的数的数量
        long long count = 0;
        long long first = prefix;
        long long last = prefix + 1;
        while (first <= n) {
            count += min(static_cast<long long>(n + 1), last) - first; // 计算当前前缀范围内的数量
            first *= 10;                                               // 进入下一个层级
            last *= 10;                                                // 同样更新上限
        }
        return count;
    }
};
