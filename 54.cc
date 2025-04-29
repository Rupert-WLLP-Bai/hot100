#include "stdcc.h"
#include <vector>

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int step = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        const vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        vector<vector<bool>> vistied(m, vector<bool>(n, false));
        vistied[0][0] = true;
        res.push_back(matrix[0][0]);

        if (m == 1 && n == 1) return res;

        int direction = 0;         // 初始向右
        if (n == 1) direction = 1; // 如果只有一列, 初始向下
        int i = 0, j = 0;
        while (true) {
            i += directions[direction][0];
            j += directions[direction][1];
            res.push_back(matrix[i][j]);
            vistied[i][j] = true;
            ++step;
            if (step == m * n) break;
            if (check(i, j, m, n, direction)) {
                direction = (direction + 1) % 4;
            } // 换下一个方向
            if (vistied[i + directions[direction][0]][j + directions[direction][1]]) {
                direction = (direction + 1) % 4;
            } // 换下一个方向
        }
        return res;
    }

    bool check(int i, int j, int m, int n, int direction) {
        bool flag = false;
        switch (direction) {
        case 0:
            if (j == n - 1) flag = true; // 右边界
            break;
        case 1:
            if (i == m - 1) flag = true; // 下边界
            break;
        case 2:
            if (j == 0) flag = true; // 左边界
            break;
        case 3:
            if (i == 0) flag = true; // 上边界
            break;
        default:
            break;
        }
        return flag;
    }
};