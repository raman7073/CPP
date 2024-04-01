#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

vector<int> findShortestPath(const vector<vector<Edge>>& graph, int src, int des) {
    int n = graph.size();
    vector<int> distance(n, INF), parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == des) break;

        for (const Edge &edge : graph[u]) {
            int v = edge.to, weight = edge.weight;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    vector<int> path;
    if (distance[des] != INF) {
        for (int v = des; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
    }
    return path;
}

bool canReach(vector<vector<Edge>>& graph, int src, int des, int ignoreNode) {
    int n = graph.size();
    vector<int> distance(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge &edge : graph[u]) {
            if (u == ignoreNode) continue;
            int v = edge.to, weight = edge.weight;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
    return distance[des] != INF;
}

int main() {
    // Input: N, friends, M, edges, src, des
    int N = 4;
    vector<int> friendIds = {2, 5, 7, 9};
    int M = 4;
    vector<tuple<int, int, int>> edges = {{2, 9, 2}, {7, 2, 3}, {7, 9, 7}, {9, 5, 1}};
    int src = 7, des = 9;

    // Convert friendIds to node indices
    unordered_map<int, int> nodeIndices;
    vector<int> nodeIds;
    for (int i = 0; i < N; ++i) {
        nodeIndices[friendIds[i]] = i;
        nodeIds.push_back(friendIds[i]);
    }

    // Create graph
    vector<vector<Edge>> graph(N);
    for (const auto& edge : edges) {
        int u = nodeIndices[get<0>(edge)];
        int v = nodeIndices[get<1>(edge)];
        int weight = get<2>(edge);
        graph[u].emplace_back(v, weight);
    }

    vector<int> shortestPath = findShortestPath(graph, nodeIndices[src], nodeIndices[des]);
    if (shortestPath.empty()) {
        cout << "No path from src to des." << endl;
        return 0;
    }

    vector<int> criticalNodes;
    for (int node : shortestPath) {
        if (node == nodeIndices[src] || node == nodeIndices[des]) continue;
        if (!canReach(graph, nodeIndices[src], nodeIndices[des], node)) {
            criticalNodes.push_back(node);
        }
    }

    cout << "Critical nodes to remove: ";
    for (int node : criticalNodes) {
        cout << nodeIds[node] << " ";
    }
    cout << endl;

    return 0;
}
