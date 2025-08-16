#include "stdcc.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }
        // Remove trailing "null," and return
        if (!result.empty()) {
            result.pop_back();
            result.pop_back();
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while (getline(ss, val, ',')) {
            TreeNode* parent = q.front();
            q.pop();
            if (val != "null") {
                parent->left = new TreeNode(stoi(val));
                q.push(parent->left);
            }
            if (getline(ss, val, ',')) {
                if (val != "null") {
                    parent->right = new TreeNode(stoi(val));
                    q.push(parent->right);
                }
            }
        }
        return root;
    }
};