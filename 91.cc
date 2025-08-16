#include "stdcc.h"

class Solution {
public:
    int numDecodings(string s) {
        // 动态规划数组，dp[i]表示前i个字符的解码方法数
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1; // 空字符串有一种解码方式

        for (int i = 1; i <= s.size(); ++i) {
            // 如果当前字符不是'0'，则可以单独解码
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            // 如果前一个字符和当前字符可以组成一个合法的两位数，则也可以解码
            if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }
};