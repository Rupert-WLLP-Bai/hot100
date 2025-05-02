#include "stdcc.h"

class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findLeft(nums, target), findRight(nums, target)};
    }

    int findLeft(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] >= target)
                r = m - 1;
            else
                l = m + 1;
            if (nums[m] == target) ans = m;
        }
        return ans;
    }
    int findRight(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] <= target)
                l = m + 1;
            else
                r = m - 1;
            if (nums[m] == target) ans = m;
        }
        return ans;
    }
};