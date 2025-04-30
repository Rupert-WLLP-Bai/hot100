#include "stdcc.h"
#include <queue>
#include <vector>

class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); // 邻接表
        vector<int> inDegree(numCourses, 0);   // 入度数组

        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]); // pre1指向pre0 即pre0的先修课程是pre1
            inDegree[pre[0]]++;              // pre0的入度加一
        }

        queue<int> q;
        // 将所有的入度为0的节点加入队列 是开始节点
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        // 遍历
        int visited = 0; // 访问的节点数
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            visited++;
            // 将其所指向的所有节点的入度减一
            for (int neighbor : graph[course]) {
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return visited == numCourses;
    }
};