#include "stdcc.h"

class Solution {
  public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            // 如果nums[i] == 0，直接跳过
            if (nums[i] == 0) continue;
            int k = i + 2; // 初始化k为i+2
            for (int j = i + 1; j < n - 1; ++j) {
                // 确保k在j之后
                while (k < n && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                // k - j - 1是满足条件的三角形数量
                count += k - j - 1;
            }
        }
        return count;
    }
};