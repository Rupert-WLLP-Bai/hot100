#include "stdcc.h"
#include <algorithm>

class Solution {
  public:
    int diameterOfBinaryTree(TreeNode* root) {
        // 求所有节点的左右子节点的深度和的最大值
        ans = 1;
        depth(root);
        return ans - 1;
    }

  private:
    int ans;
    int depth(TreeNode* t) {
        if (t == nullptr) return 0;
        int L = depth(t->left);
        int R = depth(t->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1; // 当前深度
    }
};