#include "stdcc.h"

class Solution {
  public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        // 找出nums1中第一个非负数的位置
        int pos1 = 0, pos2 = 0;
        while (pos1 < n1 && nums1[pos1] < 0) {
            pos1++;
        }
        // 找出nums2中第一个非负数的位置
        while (pos2 < n2 && nums2[pos2] < 0) {
            pos2++;
        }
        
        // 二分查找第k小的乘积
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0; // 记录小于等于mid的乘积对数
            
            // 情况1：nums1中负数与nums2中负数相乘 -> 正数结果
            for (int i1 = 0, i2 = pos2 - 1; i1 < pos1 && i2 >= 0;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++; // 乘积太大，需要更负的nums1值
                } else {
                    count += pos1 - i1; // 当前nums2值能与剩余所有nums1负数形成符合条件的乘积
                    i2--;
                }
            }
            
            // 情况2：nums1中非负数与nums2中非负数相乘 -> 非负数结果
            for (int i1 = pos1, i2 = n2 - 1; i1 < n1 && i2 >= pos2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2--; // 乘积太大，减小nums2值
                } else {
                    count += i2 - pos2 + 1; // 当前nums1值能与所有更小的nums2非负值形成符合条件的乘积
                    i1++;
                }
            }
            
            // 情况3：nums1中负数与nums2中非负数相乘 -> 负数或零结果
            for (int i1 = 0, i2 = pos2; i1 < pos1 && i2 < n2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2++; // 乘积太大（负数的绝对值小），增大nums2值
                } else {
                    count += n2 - i2; // 当前nums1值能与所有更大的nums2非负值形成符合条件的乘积
                    i1++;
                }
            }
            
            // 情况4：nums1中非负数与nums2中负数相乘 -> 负数或零结果
            for (int i1 = pos1, i2 = 0; i1 < n1 && i2 < pos2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++; // 乘积太大（负数的绝对值小），增大nums1值
                } else {
                    count += n1 - i1; // 当前nums2值能与所有更大的nums1非负值形成符合条件的乘积
                    i2++;
                }
            }
            
            // 调整二分查找边界
            if (count < k) {
                left = mid + 1; // 数量不足k个，提高下界
            } else {
                right = mid - 1; // 数量达到或超过k个，降低上界
            }
        }
        return left; // 返回第k小的乘积
    }
};

int main() {
    vector<int> nums1 = {-2, -1, 0, 1, 2};
    vector<int> nums2 = {-3, -1, 2, 4, 5};
    long long k = 3;
    Solution sol;
    cout << sol.kthSmallestProduct(nums1, nums2, k) << endl; // Output:
    return 0;
}