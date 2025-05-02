#include "stdcc.h"
#include <vector>

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used; // 记录已经使用的
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path); // 或做其他处理
            return;
        }
        
        for (int i =0;i<nums.size();++i){
            if (used[i]) continue;
            path.emplace_back(nums[i]);
            used[i] = true;
            backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }
};