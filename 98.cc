#include "stdcc.h"
#include <climits>
#include <stack>

class Solution {
  public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        // 用stack中序遍历
        stack<TreeNode*> st;
        long long inorder = static_cast<long long>(INT_MIN) - 1;
        while (!st.empty() || root) {
            // 左
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); // 取出最后入栈的
            st.pop();
            // 根
            if (root->val <= inorder) return false;
            inorder = root->val;
            // 右
            root = root->right;
        }
        return true;
    }
};