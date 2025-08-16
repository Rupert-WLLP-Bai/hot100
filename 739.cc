#include "stdcc.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 单调栈
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> s; // 存储索引
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int idx = s.top();
                s.pop();
                result[idx] = i - idx; // 计算天数差
            }
            s.push(i); // 将当前索引入栈
        }
        return result;
    }
};