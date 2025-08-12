#include "stdcc.h"
#include <cstddef>

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& candidates, size_t start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (size_t i = start; i < candidates.size(); i++) {
            // 同一层去重
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break; // 剪枝
            path.push_back(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }
};