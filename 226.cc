#include "stdcc.h"

class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        auto left = invertTree(root->left);
        auto right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};