#include "stdcc.h"
#include <vector>

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int start) {
        // 每次遍历都加入oath
        res.emplace_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.emplace_back(nums[i]);
            backtrack(nums, i + 1); // 从下一个位置继续回溯
            path.pop_back();
        }
    }
};