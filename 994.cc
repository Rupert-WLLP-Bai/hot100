#include "stdcc.h"

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q; // 记录腐烂源
        int fresh = 0, time = 0;  // 记录新鲜橘子数量 和 分钟数

        // 初始化队列，统计新鲜橘子
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2)
                    q.emplace(i, j);
                else if (grid[i][j] == 1)
                    fresh++;

        // BFS 传播腐烂
        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy; // 遍历四个方向
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.emplace(nx, ny);
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
