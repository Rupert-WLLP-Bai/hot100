#include "stdcc.h"

class Solution {
public:
    int maxDiff(int num) {
        // num to string
        string s = to_string(num);
        string max_s = s;
        string min_s = s;
        auto it = find_if(s.begin(), s.end(), [](char c) { return c != '9'; });
        if (it != s.end()) {
            char c = *it;
            replace(max_s.begin(), max_s.end(), c, '9');
        }

        // 第一位是1 将后面的第一个不是0或1的数字替换为0
        if (s[0] != '1') {
            char c = s[0];
            replace(min_s.begin(), min_s.end(), c, '1');
        } else {
            auto it = find_if(s.begin() + 1, s.end(), [](char c) { return c != '0' && c != '1'; });
            if (it != s.end()) {
                char c = *it;
                replace(min_s.begin(), min_s.end(), c, '0');
            }
        }

        return stoi(max_s) - stoi(min_s);
    }
};

