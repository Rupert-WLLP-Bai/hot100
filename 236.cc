#include "stdcc.h"

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root; // 如果当前节点为空或者为p或q 返回
        TreeNode* left = lowestCommonAncestor(root->left, p, q); // 在左子树找p,q
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // 在右子树找p,q
        if (left && right) return root; // p 和 q 分别在左右子树
        return left ? left : right;     // p 和 q 都在一边
    }
};