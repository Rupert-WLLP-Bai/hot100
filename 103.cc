#include "stdcc.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        vector<vector<int>> result;
        if (!root) return result;
        q.push_back(root);
        // 双端 两头出
        bool fromLeft = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node;
                if (fromLeft) {
                    node = q.front();
                    q.pop_front();
                } else {
                    node = q.back();
                    q.pop_back();
                }
                level.push_back(node->val);
                if (fromLeft) {
                    if (node->left) q.push_back(node->left);
                    if (node->right) q.push_back(node->right);
                } else {
                    if (node->right) q.push_front(node->right);
                    if (node->left) q.push_front(node->left);
                }
            }
            result.push_back(level);
            fromLeft = !fromLeft; // 换方向
        }
        return result;
    }
};