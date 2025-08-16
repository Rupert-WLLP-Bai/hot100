#include "stdcc.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        // 如果只有一个房子，直接返回其值
        if (nums.size() == 1) return nums[0];
        // 如果有两个房子，返回两者中的最大值
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            // 对于每个房子，选择偷或不偷
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1]; // 返回最后一个房子的最大值
    }
};