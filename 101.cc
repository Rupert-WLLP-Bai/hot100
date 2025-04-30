#include "stdcc.h"

class Solution {
  public:
    bool isSymmetric(TreeNode* root) { return check(root->left, root->right); }

    bool check(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false; // 此时已经排除了00的情况 只有可能是01,10
        return left->val == right->val && check(left->left, right->right) &&
               check(left->right, right->left);
    }
};