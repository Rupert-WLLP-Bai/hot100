#include "stdcc.h"

class Solution {
  public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool end = false;
        while (!q.empty()) {
            TreeNode* node = q.front(); // 取出队列头
            q.pop();
            if (!node) {
                end = true; // 遇到空节点后，后续节点必须都是空
            } else {
                if (end) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};