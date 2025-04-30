#include "stdcc.h"

class Solution {
  public:
    vector<int> rightSideView(TreeNode* root) {
        // 层序遍历取最右边
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // If it's the rightmost node in this level, add to result
                if (i == levelSize - 1) {
                    res.push_back(node->val);
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return res;
    }
};