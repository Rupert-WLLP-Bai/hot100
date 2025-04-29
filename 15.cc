#include "stdcc.h"
#include <algorithm>
#include <vector>

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 跳过重复元素

            // 找到nums[l] + nums[r] = -nums[i]
            int l = i + 1;
            int r = nums.size() - 1;
            int target = -nums[i];

            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    // 遍历找到所有结果
                    res.emplace_back(vector<int>{nums[l], nums[r], nums[i]});
                    // 跳过重复元素继续找结果
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                } else if (sum > target) {
                    // 收缩右边
                    --r;
                } else {
                    // 收缩左边
                    ++l;
                }
            }
        }
        return res;
    }
};