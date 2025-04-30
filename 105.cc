#include "stdcc.h"

class Solution {
  public:
    unordered_map<int, int> inorderIndex; // 中序值 -> 下标映射

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 构建中序值到下标的映射，提升查找效率
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    // 处理 [L,R) 左闭右开 子区间长度为 R-L
    TreeNode* build(const vector<int>& preorder,
                    int preL,
                    int preR,
                    const vector<int>& inorder,
                    int inL,
                    int inR) {
        if (preL >= preR || inL >= inR) return nullptr;

        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inorderIndex[rootVal]; // 根节点在中序中的位置
        int leftSize = idx - inL;        // 左子树的节点数

        root->left = build(preorder, preL + 1, preL + 1 + leftSize, inorder, inL, idx);
        root->right = build(preorder, preL + 1 + leftSize, preR, inorder, idx + 1, inR);
        return root;
    }
};
