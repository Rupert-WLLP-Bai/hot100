#include "stdcc.h"
#include <algorithm>
#include <unordered_set>

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sets;
        int l = 0, r = 0;
        int len = 0;
        int max_len = 0;
        while (r < s.length()) {
            auto right = s[r];
            auto left = s[l];
            if (!sets.count(right)) {
                sets.insert(right);
                len += 1;
                ++r;
            } else {
                // 移动左侧
                ++l;
                sets.erase(left);
                len -= 1;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};