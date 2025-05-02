#include "stdcc.h"

class Solution {
  public:
    vector<vector<string>> res; // 存储所有可能的分割结果
    vector<string> path;        // 存储当前的分割路径

    /**
     * 判断字符串s的子串[l,r]是否为回文串
     * @param s 原字符串
     * @param l 左边界
     * @param r 右边界
     * @return 是否为回文串
     */
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false; // 如果对应位置字符不相等，则不是回文串
        }
        return true; // 所有对应位置字符都相等，是回文串
    }

    /**
     * 深度优先搜索所有可能的分割方案
     * @param s 原字符串
     * @param start 当前分割的起始位置
     */
    void dfs(string& s, int start) {
        if (start == s.size()) { // 如果已经处理到字符串末尾
            res.push_back(path); // 将当前路径添加到结果中
            return;
        }

        for (int i = start; i < s.size(); ++i) {                // 尝试所有可能的分割点
            if (isPalindrome(s, start, i)) {                    // 如果[start,i]是回文串
                path.push_back(s.substr(start, i - start + 1)); // 将这部分加入当前路径
                dfs(s, i + 1);                                  // 递归处理剩余部分
                path.pop_back(); // 回溯，移除最后添加的部分
            }
        }
    }

    /**
     * 分割字符串使得每个子串都是回文串
     * @param s 要分割的字符串
     * @return 所有可能的分割方案
     */
    vector<vector<string>> partition(string s) {
        dfs(s, 0);  // 从索引0开始深度优先搜索
        return res; // 返回所有结果
    }
};
