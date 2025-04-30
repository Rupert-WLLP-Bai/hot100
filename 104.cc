#include "stdcc.h"
#include <algorithm>

class Solution {
  public:
    int maxDepth(TreeNode* root) { return depth(root, 0); }

    int depth(TreeNode* node, int dep) {
        if (node == nullptr) return dep;
        return max(depth(node->left, dep + 1), depth(node->right, dep + 1));
    }
};