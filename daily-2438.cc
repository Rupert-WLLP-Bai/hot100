#include "stdcc.h"

// 费马小定理: a^(-1) = a^(p-2) (mod p), 其中 p 是质数
// 快速幂: a^b (mod p) 的计算可以通过分治法实现
// 具体做法是将 b 反复拆分为 b/2 和 b%2 的形式
// 例如: 3^13 mod 100
// 用二进制分解: 13 = (1101)_2
// 得到: 3^13 = 3^8 * 3^4 * 3^1


class Solution {
public:
    const int mod = 1e9 + 7;

    long long modPow(long long a, long long e) {
        long long res = 1;
        while (e) {
            if (e & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            e >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) powers.push_back(1 << i);
        }

        int m = powers.size();
        vector<long long> prefix(m);
        prefix[0] = powers[0] % mod;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i - 1] * powers[i]) % mod;
        }

        // 预处理前缀积的逆元
        vector<long long> invPrefix(m);
        for (int i = 0; i < m; i++) {
            invPrefix[i] = modPow(prefix[i], mod - 2); // 费马小定理
        }

        vector<int> res;
        res.reserve(queries.size());
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                res.push_back((int)prefix[r]);
            } else {
                long long val = (prefix[r] * invPrefix[l - 1]) % mod;
                res.push_back((int)val);
            }
        }
        return res;
    }
};
