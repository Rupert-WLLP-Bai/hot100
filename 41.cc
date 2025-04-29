#include "stdcc.h"

class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // 第一步：把所有小于等于0的数修改成n+1（因为缺失的一定在1~n之间）
        for (int& num : nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }

        // 第二步：使用下标标记数组中出现过的正数
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]); // 取绝对值，避免之前已经被标记为负数的影响
            if (num <= n) {         // 只处理1到n之间的数
                nums[num - 1] = -abs(nums[num - 1]); // 把对应位置的数变成负数表示出现过
            }
        }

        // 第三步：找到第一个正数，说明对应的下标+1的数没有出现
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) { // 第一个正数对应的索引 + 1 就是答案
                return i + 1;
            }
        }

        // 如果都出现了，缺失的就是n+1
        return n + 1;
    }
};
