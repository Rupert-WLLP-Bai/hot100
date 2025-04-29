#include "stdcc.h"

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int left = 1, right = 1;
        for (int i = 0; i < n; i++) {
            res[i] *= left;
            res[n - i - 1] *= right;
            left *= nums[i];
            right *= nums[n - i - 1];
        }
        return res;
    }
};