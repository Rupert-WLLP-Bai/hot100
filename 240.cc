#include "stdcc.h"

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 以右上角为二叉搜索树的根
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while (true) {
            int cur = matrix[i][j];
            if (cur == target) {
                return true;
            } else if (cur > target) {
                // 向左
                --j;
                if (j < 0) return false;
            } else {
                // 向右
                ++i;
                if (i >= m) return false;
            }
        }
        return false;
    }
};