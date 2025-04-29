#include "stdcc.h"
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (const auto& str : strs) {
            auto key = str;               // 记录当前字符串
            sort(key.begin(), key.end()); // 排序之后当作key
            m[key].emplace_back(str);     // m["aet"] 添加 {"eat"}
        }
        // 构建返回值
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            auto val = it->second;
            res.emplace_back(val);
        }
        return res;
    }
};