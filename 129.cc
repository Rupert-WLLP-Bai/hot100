#include "stdcc.h"
#include <numeric>
#include <vector>

class Solution {
  public:
    void dfs(TreeNode* node, string& path, vector<int>& nums) {
        path.push_back(node->val + '0');

        // If it's a leaf node, add the number to our results
        if (!node->left && !node->right) {
            nums.push_back(stoi(path));
        }

        // Continue DFS
        if (node->left) {
            dfs(node->left, path, nums);
        }
        if (node->right) {
            dfs(node->right, path, nums);
        }

        // Backtrack
        path.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        string s;
        if (!root) return 0;
        dfs(root, s, nums);
        return accumulate(nums.begin(), nums.end(), 0);
    }
};