#include "stdcc.h"
#include <unordered_map>
#include <vector>

class Solution {
  public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<char, int>> maps;
        unordered_map<char, int> res_map;
        vector<string> res;
        for (const auto& s : words) {
            unordered_map<char, int> m;
            for (const auto& c : s) {
                ++m[c];
            }
            maps.emplace_back(m);
        }

        res_map = maps[0];

        for (auto& [ch, count] : res_map) {
            for (size_t i = 1; i < maps.size(); ++i) {
                auto it = maps[i].find(ch);
                if (it == maps[i].end()) {
                    count = 0;
                    break;
                }
                count = min(count, it->second);
            }
        }

        for (const auto& [ch, count] : res_map) {
            for (int i = 0; i < count; ++i) {
                res.push_back(string(1, ch));
            }
        }

        return res;
    }
};