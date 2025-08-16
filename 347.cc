#include "stdcc.h"

class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 快速选择算法
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }
        vector<pair<int, int>> frequencyVec(frequencyMap.begin(), frequencyMap.end());
        nth_element(frequencyVec.begin(),
                    frequencyVec.begin() + k - 1,
                    frequencyVec.end(),
                    [](const pair<int, int>& a, const pair<int, int>& b) {
                        return a.second > b.second; // 按频率降序排列
                    });
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(frequencyVec[i].first);
        }
        return result;
    }
};
