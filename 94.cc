#include "stdcc.h"
#include <vector>

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    void inorder(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        inorder(node->left, res);
        res.emplace_back(node->val);
        inorder(node->right, res);
    }
};