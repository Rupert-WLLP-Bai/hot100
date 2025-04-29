#include "stdcc.h"

class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Empty subarray with sum 0
        int count = 0;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;
            // If (currentSum - k) exists in the map, it means we have subarrays that sum to k
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};