#include "stdcc.h"
#include <climits>
#include <unordered_map>

class Solution {
  public:
    unordered_map<char, int> ori; // t的字符数
    unordered_map<char, int> cnt; // s子串的字符数
    bool check() {
        for (auto it = ori.begin(); it != ori.end(); ++it) {
            const auto& key = it->first;
            const auto& value = it->second;
            if (cnt[key] < value) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        if (s.length() < t.length()) return "";               // 特判
        for (const auto& c : t) {
            ori[c]++; // 添加t的字符
        }
        int l = 0, r = -1;             // 边界
        int len = INT_MAX;
        int final_l = 0, final_r = 0; // 记录最小子串的边界
        // 向右扩展边界 直到符合条件
        // 符合条件之后尝试收缩左边界
        // 维护一个最小的区间
        while (r < (int)s.length()) {
            // Expand right boundary until we find a valid window
            if (r < (int)s.length() - 1 && !check()) {
                r++;
                cnt[s[r]]++;
            } else {
                // If we have a valid window or can't expand further
                if (check()) {
                    // Update minimum window if current is smaller
                    if (r - l + 1 < len) {
                        len = r - l + 1;
                        final_l = l;
                        final_r = r;
                    }
                    // Try to shrink from left
                    cnt[s[l]]--;
                    l++;
                } else {
                    // Can't expand further but window is not valid
                    break;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(final_l, len);
    }
};