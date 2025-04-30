#include "stdcc.h"
#include <stack>
#include <vector>

class Solution {
  public:
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> vec;
        stack<TreeNode*> st;
        auto node = root;
        // 前序遍历然后从头连接
        while (!st.empty() || node) {
            // 根
            while (node) {
                vec.emplace_back(node);
                st.push(node);
                node = node->left;
            }
            // 左
            node = st.top();
            st.pop();
            // 右
            node = node->right;
        }
        // 连接
        vec.emplace_back(nullptr);
        for (int i = 0; i< vec.size()-1;++i){
            vec[i]->right = vec[i+1];
            vec[i]->left = nullptr;
        }
    }
};