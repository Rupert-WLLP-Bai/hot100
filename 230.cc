#include "stdcc.h"
#include <stack>

class Solution {
  public:
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历 找到第k个
        stack<TreeNode*> st;
        while (root != nullptr || st.size() > 0) {
            // 左
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            // 根
            root = st.top();
            st.pop();
            --k;
            if (k == 0) {
                break;
            }
            // 右
            root = root->right;
        }
        return root->val;
    }
};