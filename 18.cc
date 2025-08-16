#include "stdcc.h"

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        using LL = long long;
        vector<vector<int>> result;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    LL sum = LL(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == result.back()[2]) left++;
                        while (left < right && nums[right] == result.back()[3]) right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
                while (j + 1 < nums.size() && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return result;
    }
};