#include "stdcc.h"
#include <algorithm>
#include <vector>

class Solution {
  public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int leftmax = 0, rightmax = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            leftmax = max(leftmax, height[l]);
            rightmax = max(rightmax, height[r]);
            if (height[l] < height[r]) {
                // 计算
                ans += leftmax - height[l];
                // 移动l
                ++l;
            } else {
                // 移动r
                ans += rightmax - height[r];
                --r;
            }
        }
        return ans;
    }
};