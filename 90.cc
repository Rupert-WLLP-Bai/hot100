#include "stdcc.h"
#include <cstddef>
#include <functional>

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 先排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        function<void(size_t)> backtrack = [&](size_t start) {
            result.push_back(subset);
            for (size_t i = start; i < nums.size(); i++) {
                if (i > start && nums[i] == nums[i - 1]) continue;
                subset.push_back(nums[i]);
                backtrack(i + 1);
                subset.pop_back();
            }
        };
        backtrack(0);
        return result;
    }
};