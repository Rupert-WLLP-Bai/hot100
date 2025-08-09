#include "stdcc.h"

class Solution {
  public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 单调栈
        if (matrix.empty() || matrix[0].empty()) return 0;
        int maxArea = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0); // 表示每列的高度
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++; // 增加高度
                } else {
                    heights[j] = 0; // 重置高度
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        // 使用单调栈计算最大矩形面积
        stack<int> s;
        heights.push_back(0);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1; // 计算宽度
                maxArea = max(maxArea, h * w);
            }
            s.push(i);
        }
        heights.pop_back(); // 恢复原数组
        return maxArea;
    }
};