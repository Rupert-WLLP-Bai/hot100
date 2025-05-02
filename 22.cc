#include "stdcc.h"

class Solution {
  public:
    vector<string> res;
    string path;
    vector<string> generateParenthesis(int n) {
        // 结果的长度为2n
        dfs(path, 0, 0, n);
        return res;
    }

    void dfs(string& path, int open, int close, int n) {
        if (path.size() == 2 * n) {
            res.push_back(path);
            return;
        }
        if (open < n) { // 左括号小于n个
            path.push_back('(');
            dfs(path, open + 1, close, n);
            path.pop_back();
        }
        if (close < open) { // 右括号不够
            path.push_back(')');
            dfs(path, open, close + 1, n);
            path.pop_back();
        }
    }
};