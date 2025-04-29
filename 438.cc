#include "stdcc.h"
#include <unordered_map>
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {}; // 特判
        unordered_map<char, int> ori;       // 原始字符串的字符个数
        unordered_map<char, int> cur;       // 当前区间字符串的字符个数
        vector<int> ans;
        for (const auto& c : p) ori[c]++;

        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            ++cur[s[right]]; // 添加字符
            if (right - left + 1 > p.size()) {
                // 移除左侧字符
                --cur[s[left]];
                if (cur[s[left]] == 0) cur.erase(s[left]);
                ++left;
            }
            if (right - left + 1 == p.size() && cur == ori) ans.emplace_back(left); // 正确情况
        }
        return ans;
    }
};