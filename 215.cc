#include "stdcc.h"
#include <vector>

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }

  private:
    // partition函数 把数组分成两部分
    // 大于等于pivot的在左边，小于pivot的在右边
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        swap(nums[pivotIndex], nums[right]); // 把pivot放到最后
        int storeIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] > pivotValue) {
                swap(nums[storeIndex], nums[i]);
                storeIndex++;
            }
        }
        swap(nums[storeIndex], nums[right]); // 把pivot放到它的最终位置
        return storeIndex;
    }

    // quickSelect函数
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) {
            return nums[left]; // 只有一个元素
        }
        int pivotIndex = left + rand() % (right - left + 1); // 随机选择一个pivot
        pivotIndex = partition(nums, left, right, pivotIndex);
        // 计算pivot的位置
        if (k == pivotIndex) {
            return nums[k]; // 找到第k大的元素
        } else if (k < pivotIndex) {
            return quickSelect(nums, left, pivotIndex - 1, k); // 在左边部分继续查找
        } else {
            return quickSelect(nums, pivotIndex + 1, right, k); // 在右边部分继续查找
        }
    }
};