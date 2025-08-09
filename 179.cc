#include "stdcc.h"

class Solution {
  public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string ab = to_string(a) + to_string(b);
            string ba = to_string(b) + to_string(a);
            return ab > ba;
        });
        if (nums[0] == 0) return "0";
        string result;
        for (int num : nums) {
            result += to_string(num);
        }
        return result;
    }
};