#include "stdcc.h"
#include <unordered_set>

class Solution {
  public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // 2 freq maps
        unordered_map<int, int> freq1, freq2;
        unordered_set<int> allElems;
        for (int num : basket1) {
            freq1[num]++;
            allElems.insert(num);
        }
        for (int num : basket2) {
            freq2[num]++;
            allElems.insert(num);
        }
        // check if sum of freqs of one elem in both arrays is odd
        for (const int& num : allElems) {
            if ((freq1[num] + freq2[num]) % 2 != 0) {
                return -1; // impossible to balance
            }
        }
        // store the elems which need to be swapped, and sort them
        vector<int> toSwap1, toSwap2;
        for(const int& num : allElems) {
            int diff = freq1[num] - freq2[num];
            if (diff > 0) {
                // num is in basket1 more than in basket2
                for (int i = 0; i < diff / 2; i++) {
                    toSwap1.push_back(num);
                }
            }
            else if (diff < 0) {
                // num is in basket2 more than in basket1
                for (int i = 0; i < -diff / 2; i++) {
                    toSwap2.push_back(num);
                }
            }
        }
        if (toSwap1.size() != toSwap2.size()) {
            return -1;
        }
        // sort the swap lists
        sort(toSwap1.begin(), toSwap1.end());
        sort(toSwap2.begin(), toSwap2.end(), greater<>());
        // calculate
        // find the global minimum element
        int globalMin = *min_element(allElems.begin(), allElems.end());
        long long cost = 0;
        int n = toSwap1.size();
        for (int i = 0; i < n; i++) {
            auto cost1 = min(toSwap1[i], toSwap2[i]);
            auto cost2 = 2 * globalMin;
            cost += min(cost1, cost2);
        }
        return cost;
    }
};
