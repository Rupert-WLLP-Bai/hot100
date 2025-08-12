#include "stdcc.h"

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pivot = nums[right];
            int l = left, r = right;
            for (int i = left; i < r; i++) {
                if (nums[i] > pivot) swap(nums[i], nums[l++]);
            }
            swap(nums[l], nums[r]);
            if (l == k - 1)
                return nums[l];
            else if (l < k - 1)
                left = l + 1;
            else
                right = l - 1;
        }
    }

    inline int idx(int i, int n) { return (2 * i + 1) % (n | 1); }

    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int median = findKthLargest(nums, (n + 1) / 2);
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (nums[idx(j, n)] > median) {
                swap(nums[idx(i++, n)], nums[idx(j++, n)]);
            } else if (nums[idx(j, n)] < median) {
                swap(nums[idx(j, n)], nums[idx(k--, n)]);
            } else {
                j++;
            }
        }
    }
};