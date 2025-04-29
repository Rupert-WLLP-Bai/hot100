#include "stdcc.h"
#include <utility>

class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
        int p = 0, q = 0; // p为第一个0的位置, q为第一个非0的位置
        while (true) {
            while (nums[p] != 0) {
                if (++p >= nums.size()) return;
            }
            while (nums[q] == 0 || q < p) {
                if (++q >= nums.size()) return;
            }
            swap(nums[p], nums[q]);
        }
    }
};