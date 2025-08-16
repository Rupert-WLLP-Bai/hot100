#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <string>
#include <limits>
#include <stack>
#include <set>

using namespace std;

struct Edge {
    int to;        // 边的终点编号
    double weight; // 权重：-ln(rate * (1 - fee))
};

// Token 名称和编号映射
unordered_map<string, int> token_id;
vector<string> token_name;

// 图的邻接表
vector<vector<Edge>> graph;

// 获取 token ID，如果不存在则自动分配
int getTokenId(const string& name) {
    if (token_id.count(name)) return token_id[name];
    int id = token_name.size();
    token_id[name] = id;
    token_name.push_back(name);
    graph.emplace_back(); // 为新 token 创建一个空的邻接表
    return id;
}

// 添加一条边（兑换路径）
void addEdge(const string& from, const string& to, double rate, double fee = 0.003) {
    int u = getTokenId(from);
    int v = getTokenId(to);
    double effectiveRate = rate * (1.0 - fee);
    double weight = -log(effectiveRate); // 乘积最大 ⇨ 权重最小
    graph[u].push_back({v, weight});
}

// Bellman-Ford 最短路径算法（返回负环节点）
bool bellmanFord(int src, vector<double>& dist, vector<int>& prev, vector<int>& negativeCycle) {
    int n = token_name.size();
    dist.assign(n, 1e9);
    prev.assign(n, -1);
    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (int u = 0; u < n; ++u) {
            if (dist[u] == 1e9) continue;
            for (auto& e : graph[u]) {
                int v = e.to;
                double w = e.weight;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    prev[v] = u;
                    updated = true; // updated表示, 有边被松弛, 即有路径被更新
                }
            }
        }
        if (!updated) break;
    }

    // 检测负权环，并记录路径
    for (int u = 0; u < n; ++u) {
        if (dist[u] == 1e9) continue;
        for (auto& e : graph[u]) {
            int v = e.to;
            double w = e.weight;
            if (dist[u] + w < dist[v]) {
                // 存在负环，从 v 开始回溯
                set<int> visited;
                int cycle = v;
                for (int i = 0; i < n; ++i) cycle = prev[cycle]; // 保证在环上
                int start = cycle;
                do {
                    negativeCycle.push_back(cycle);
                    cycle = prev[cycle];
                } while (cycle != start && !visited.count(cycle) && (visited.insert(cycle), true));
                negativeCycle.push_back(start);
                reverse(negativeCycle.begin(), negativeCycle.end());
                return false;
            }
        }
    }

    return true;
}

// 打印兑换路径（加入路径是否存在检查）
void printPath(int src, int dst, const vector<int>& prev) {
    if (prev[dst] == -1 && src != dst) {
        cout << "\n[警告] 找不到从 " << token_name[src] << " 到 " << token_name[dst] << " 的路径。"
             << endl;
        return;
    }

    stack<int> path;
    int cur = dst;
    while (cur != -1) {
        path.push(cur);
        cur = prev[cur];
    }

    cout << "\n最佳路径：";
    while (!path.empty()) {
        cout << token_name[path.top()];
        path.pop();
        if (!path.empty()) cout << " → ";
    }
    cout << endl;
}

// 打印负权环路径
void printNegativeCycle(const vector<int>& cycle) {
    cout << "\n[套利路径] 检测到负权环：";
    for (size_t i = 0; i < cycle.size(); ++i) {
        cout << token_name[cycle[i]];
        if (i + 1 < cycle.size()) cout << " → ";
    }
    cout << endl;
}

int main() {
    // 添加测试数据（模拟兑换池）
    addEdge("ETH", "USDC", 2000);
    addEdge("USDC", "DAI", 0.998);
    addEdge("ETH", "DAI", 1995);
    addEdge("ETH", "WBTC", 14.5);
    addEdge("WBTC", "USDC", 138000);
    addEdge("DAI", "UNI", 0.5);
    addEdge("UNI", "LDO", 1.2);
    addEdge("USDC", "LDO", 0.00045);
    addEdge("LDO", "ETH", 0.00049);

    string tokenIn = "ETH";
    string tokenOut = "LDO";

    int src = getTokenId(tokenIn);
    int dst = getTokenId(tokenOut);

    vector<double> dist;
    vector<int> prev;
    vector<int> negativeCycle;
    bool success = bellmanFord(src, dist, prev, negativeCycle);

    if (!success) {
        cout << "\n[错误] 系统存在套利机会，无法计算稳定的兑换率。" << endl;
        printNegativeCycle(negativeCycle);
        return 1;
    }

    if (dist[dst] > 1e8) {
        cout << "\n[错误] 无法从 " << tokenIn << " 兑换到 " << tokenOut << "，路径不存在或不可达。"
             << endl;
        return 1;
    }

    double bestRate = exp(-dist[dst]);
    cout << fixed;
    cout.precision(10);
    cout << "\n从 " << tokenIn << " 到 " << tokenOut << " 的最优兑换率为：" << bestRate << endl;

    printPath(src, dst, prev);

    return 0;
}
