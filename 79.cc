#include "stdcc.h"

class Solution {
  public:
    int m, n;
    vector<vector<bool>> visited;

    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int idx) {
        if (idx == word.size()) return true;
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[idx])
            return false;

        visited[x][y] = true;
        bool res = dfs(board, word, x + 1, y, idx + 1) || dfs(board, word, x - 1, y, idx + 1) ||
                   dfs(board, word, x, y + 1, idx + 1) || dfs(board, word, x, y - 1, idx + 1);
        visited[x][y] = false;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited.assign(m, vector<bool>(n, false)); // 赋值
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(board, word, i, j, 0)) return true; // 从每一个位置开始dfs
        return false;
    }
};
