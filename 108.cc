#include "stdcc.h"
#include <vector>

class Solution {
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = construct(nums, 0, mid);
        root->right = construct(nums, mid + 1, n);
        return root;
    }

    TreeNode* construct(vector<int>& nums, int l, int r) {
        if (l >= r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = construct(nums, l, mid);
        root->right = construct(nums, mid + 1, r);
        return root;
    }
};