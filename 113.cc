#include "stdcc.h"
#include <functional>

class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        function<void(TreeNode*, int, vector<int>, vector<vector<int>>&)> dfs =
            [&](TreeNode* node, int remainingSum, vector<int> path, vector<vector<int>>& result) {
                if (!node) return;
                path.push_back(node->val);
                remainingSum -= node->val;
                if (!node->left && !node->right && remainingSum == 0) {
                    result.push_back(path); // 遍历到叶子节点且路径和等于目标值时，记录路径
                } else {
                    dfs(node->left, remainingSum, path, result); // 递归遍历左子树
                    dfs(node->right, remainingSum, path, result); // 递归遍历右子树
                }
            };
        vector<vector<int>> result;
        dfs(root, targetSum, {}, result); // pathSum 的初始路径为空
        return result;
    }
};