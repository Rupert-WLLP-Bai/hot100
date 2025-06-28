#include "stdcc.h"

class Solution {
  public:
    string ans = "";

    // 判断 t 是否是 s 的子序列
    bool isSubsequence(const string& t, const string& s) {
        size_t i = 0;
        for (char c : s) {
            if (i < t.size() && t[i] == c) {
                i++;
            }
        }
        return i == t.size();
    }

    // 判断 seq 重复 k 次是否是 s 的子序列
    bool check(const string& seq, const string& s, int k) {
        string repeated = "";
        for (int i = 0; i < k; ++i) repeated += seq;
        return isSubsequence(repeated, s);
    }

    // DFS 尝试构造子序列
    void dfs(string& cur, const string& s, int k, size_t maxLen) {
        if (cur.size() > maxLen) return;
        if (cur.size() > ans.size() || (cur.size() == ans.size() && cur > ans)) {
            if (check(cur, s, k)) {
                ans = cur;
            }
        }
        for (char c = 'z'; c >= 'a'; --c) {
            cur.push_back(c);
            if (check(cur, s, k)) {
                dfs(cur, s, k, maxLen);
            }
            cur.pop_back();
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        // 字符频率预处理：只保留出现次数 >= k 的字符
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        string filtered = "";
        for (char c : s) {
            if (freq[c] >= k) filtered += c;
        }

        string cur = "";
        dfs(cur, filtered, k, 7); // 最多尝试长度为7的子序列
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "letsleetcode";
    int k = 2;
    cout << sol.longestSubsequenceRepeatedK(s, k) << endl;
    return 0;
}