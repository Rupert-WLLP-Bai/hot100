#include "stdcc.h"

class Solution {
  public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;      // 初始化左右指针
        while (l <= r) {                     // 当左指针小于等于右指针时继续搜索
            int m = (l + r) / 2;             // 计算中间索引
            if (nums[m] == target) return m; // 如果找到目标值，直接返回索引

            if (nums[m] >= nums[l]) {                      // 如果左半部分是有序的
                if (nums[l] <= target && target < nums[m]) // 如果目标值在左半部分有序区间内
                    r = m - 1;                             // 在左半部分继续搜索
                else
                    l = m + 1;                             // 否则在右半部分搜索
            } else {                                       // 如果右半部分是有序的
                if (nums[m] < target && target <= nums[r]) // 如果目标值在右半部分有序区间内
                    l = m + 1;                             // 在右半部分继续搜索
                else
                    r = m - 1; // 否则在左半部分搜索
            }
        }
        return -1; // 没有找到目标值，返回-1
    }
};