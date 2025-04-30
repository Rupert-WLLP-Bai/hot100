#include "stdcc.h"
#include <queue>
#include <vector>

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int current_level_size = q.size();
            level.clear();
            for (int i = 0; i < current_level_size; ++i) {
                auto node = q.front(); // 取出队头 最早入队的元素
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};