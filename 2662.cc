#include "stdcc.h"

class Solution {
  public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        // Check if start and target are the same
        if (start[0] == target[0] && start[1] == target[1]) {
            return 0;
        }

        // dijkstra
        int n = specialRoads.size();

        // Create a map to assign indices to coordinates
        map<pair<int, int>, int> coordToIndex;
        coordToIndex[{start[0], start[1]}] = 0;
        coordToIndex[{target[0], target[1]}] = 1;

        int nextIndex = 2;
        for (int i = 0; i < n; i++) {
            pair<int, int> startCoord = {specialRoads[i][0], specialRoads[i][1]};
            pair<int, int> endCoord = {specialRoads[i][2], specialRoads[i][3]};

            if (coordToIndex.find(startCoord) == coordToIndex.end()) {
                coordToIndex[startCoord] = nextIndex++;
            }
            if (coordToIndex.find(endCoord) == coordToIndex.end()) {
                coordToIndex[endCoord] = nextIndex++;
            }
        }

        int totalNodes = nextIndex;
        vector<vector<pair<int, int>>> graph(totalNodes);

        // Add special roads
        for (int i = 0; i < n; i++) {
            int startIdx = coordToIndex[{specialRoads[i][0], specialRoads[i][1]}];
            int endIdx = coordToIndex[{specialRoads[i][2], specialRoads[i][3]}];
            int cost = specialRoads[i][4];
            graph[startIdx].emplace_back(endIdx, cost);
        }

        // Add direct paths between all nodes (Manhattan distance)
        vector<pair<int, int>> coords(totalNodes);
        for (auto& [coord, idx] : coordToIndex) {
            coords[idx] = coord;
        }

        for (int i = 0; i < totalNodes; i++) {
            for (int j = 0; j < totalNodes; j++) {
                if (i != j) {
                    int manhattanDist = abs(coords[i].first - coords[j].first) +
                                        abs(coords[i].second - coords[j].second);
                    graph[i].emplace_back(j, manhattanDist);
                }
            }
        }

        // Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(totalNodes, INT_MAX);
        dist[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;

            for (auto [v, cost] : graph[u]) {
                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist[1];
    }
};