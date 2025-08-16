#include "stdcc.h"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 构建并查集
        int n = edges.size();
        vector<int> parent(n + 1);
        // 初始化并查集，每个节点的父节点是自己
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // 查找函数，带路径压缩
        function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // 遍历每条边
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int rootU = find(u), rootV = find(v);
            // 如果两个节点已经在同一个集合中，说明这条边导致了环的产生
            if (rootU == rootV) {
                return edge;
            }
            // 否则，将这两个节点所在的集合合并
            parent[rootU] = rootV;
        }

        return {}; // 理论上不会执行到这里
        
    }
};