#include "stdcc.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        function<void(int, int, string)> backtrack = [&](int start, int parts, string current) {
            if (parts == 4) {
                if (start == s.size()) {
                    result.push_back(current.substr(0, current.size() - 1)); // Remove trailing dot
                }
                return;
            }
            for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
                string part = s.substr(start, len);
                if ((len > 1 && part[0] == '0') || (len == 3 && stoi(part) > 255)) {
                    continue; // Skip invalid parts
                }
                backtrack(start + len, parts + 1, current + part + ".");
            }
        };
        backtrack(0, 0, "");
        return result;
    }
};