#include "stdcc.h"
#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        // 1. s = n[i] + n[i+1] + n[i+2] 得到一个组合
        // 2. s = n[i] + n[n-2] + n[n-1] 得到另一个组合 比较取最优
        for (size_t i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int s = nums[i] + nums[left] + nums[right];
                if (s == target) {
                    return s;
                }
                if (abs(s - target) < abs(ans - target)) {
                    ans = s;
                }
                if (s < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};