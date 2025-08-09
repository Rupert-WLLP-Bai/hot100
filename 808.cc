#include "stdcc.h"

class Solution {
  public:
    double soupServings(int n) {
        // 起始为4, 每次操作 A:x , B:y
        if (n > 1e6) return 1.0;
        n = (n + 24) / 25;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1.0));
        return dfs(n, n, dp);
    }

    double dfs(int a, int b, vector<vector<double>>& dp) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (dp[a][b] != -1.0) return dp[a][b];
        // 四种操作的概率
        dp[a][b] = 0.25 * (dfs(a - 4, b, dp) + dfs(a - 3, b - 1, dp) + dfs(a - 2, b - 2, dp) +
                           dfs(a - 1, b - 3, dp));
        return dp[a][b];
    }
};