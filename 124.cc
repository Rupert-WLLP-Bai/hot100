#include "stdcc.h"

class Solution {
  public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = max(dfs(root->left), 0); // 如果子树贡献为负就不要
        int right = max(dfs(root->right), 0);
        maxSum = max(maxSum, root->val + left + right); // 以当前root为顶点的路径和
        return root->val + max(left, right); // 返回从root往下走最大的一条路径和
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
