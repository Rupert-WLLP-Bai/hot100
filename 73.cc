#include "stdcc.h"

class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 用第一列和第一行进行记录
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag_row = false, flag_col = false;
        // 遍历第一行和第一列
        for (int i = 0; i < m; ++i) {
            if (!matrix[i][0]) {
                flag_col = true; // 第一列有0
            }
        }
        for (int j = 0; j < n; ++j) {
            if (!matrix[0][j]) {
                flag_row = true; // 第一行有0
            }
        }
        // 遍历其他
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][j]) {
                    // cout << "i =" << i << ", j = " << j << endl;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // 遍历其他
        for (int i = 1; i < m; ++i) {
            if (!matrix[i][0]) {
                // cout << "i = " << i << endl;
                for (int j = 1; j < n; ++j) matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (!matrix[0][j]) {
                // cout << "j = " << j << endl;
                for (int i = 1; i < m; ++i) matrix[i][j] = 0;
            }
        }
        // 修改第一行和第一列
        if (flag_row)
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        if (flag_col)
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
};