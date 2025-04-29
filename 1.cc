#include "stdcc.h"
#include <unordered_map>

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i])) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
            // cout << "nums[i] = " << nums[i] << ", i = " << i << endl;
        }
        return {-1, -1};
    }
};