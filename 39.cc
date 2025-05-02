#include "stdcc.h"
#include <algorithm>
#include <vector>

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue;
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i); // 可以重复用
            path.pop_back();
        }
    }
};