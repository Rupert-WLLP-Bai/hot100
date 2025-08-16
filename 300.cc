#include "stdcc.h"

class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
        // 贪心 二分
        vector<int> dp;
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num; // 替换
            }
        }
        return dp.size();
    }
};