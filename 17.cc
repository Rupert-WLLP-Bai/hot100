#include "stdcc.h"

class Solution {
  public:
    vector<string> res;
    string path;
    unordered_map<char, string> phoneMap = {{'2', "abc"},
                                            {'3', "def"},
                                            {'4', "ghi"},
                                            {'5', "jkl"},
                                            {'6', "mno"},
                                            {'7', "pqrs"},
                                            {'8', "tuv"},
                                            {'9', "wxyz"}};

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        backtrack(digits, 0);
        return res;
    }

    void backtrack(const string& digits, int index) {
        // 终止条件
        if (index == digits.size()) {
            res.emplace_back(path);
            return;
        }
        // 回溯
        for (const auto& c : phoneMap[digits[index]]) {
            path.push_back(c);
            backtrack(digits, index + 1);
            path.pop_back();
        }
    }
};