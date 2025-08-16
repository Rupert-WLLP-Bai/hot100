#include "stdcc.h"
#include <vector>

class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        // 贪心 + 二分
        // tail[n] 存储长度为n的上升子序列的最小尾部元素
        //
        return dp[nums.size()];
    }
};