#include "stdcc.h"
#include <algorithm>
#include <unordered_set>

class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (const auto& val : nums) {
            s.insert(val);
        }
        int max_len = 0;
        for (const auto& val : s) {
            // 判断是否是序列的起点
            // val-1不存在 即为序列的起点
            int streak = 0;
            if (!s.count(val - 1)) {
                // 在set中向后找
                while (s.count(++streak + val));
                max_len = max(max_len, streak);
            }
            // 否则跳过 没有额外时间复杂度
        }
        return max_len;
    }
};