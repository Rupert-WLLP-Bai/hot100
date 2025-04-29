#include "stdcc.h"
#include <algorithm>
#include <vector>

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 左端点排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0]; // 小的在前
        });
        vector<vector<int>> res;
        vector<int> tmp;
        tmp = intervals[0]; // 放入第一个区间
        for (const auto& vec : intervals) {
            if (vec[0] > tmp[1]) {
                // 区间不相交 将tmp放入结果集 并且重新以当前位置开始
                res.push_back(tmp);
                tmp = vec;
            } else {
                // 合并两个区间
                int left = min(vec[0], tmp[0]);
                int right = max(vec[1], tmp[1]);
                tmp = {left, right};
            }
        }
        res.push_back(tmp); // 最后还需要把最后一个结果放进去
        return res;
    }
};