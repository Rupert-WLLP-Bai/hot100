#include "stdcc.h"

class Solution {
  public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int max_val = INT_MIN;
        int min_val = INT_MAX;

        for (char c = '0'; c <= '9'; ++c) {
            string temp_max = s;
            for (char& ch : temp_max) {
                if (ch == c) {
                    ch = '9';
                }
            }
            int current_max = stoi(temp_max);
            if (current_max > max_val) {
                max_val = current_max;
            }

            string temp_min = s;
            for (char& ch : temp_min) {
                if (ch == c) {
                    ch = '0';
                }
            }
            int current_min = stoi(temp_min);
            if (current_min < min_val) {
                min_val = current_min;
            }
        }

        return max_val - min_val;
    }
};