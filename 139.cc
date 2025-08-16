#include "stdcc.h"
#include <cstddef>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    // LeetCode 139 单词拆分
    bool wordBreak(string s, vector<string>& wordDict) {
        auto n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, 0);
        dp[0] = true; // initialization
        // transforming
        // dp[i]: s[0:i-1]
        // dp[i] = true if dp[j] && s[j:i] in dict
        for (size_t i = 1; i <= n; ++i) { // 注意这里的边界是 1 ~ n
            for (size_t j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};