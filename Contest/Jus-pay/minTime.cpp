#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge
{
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

int main()
{
    // Number of nodes and edges
    int n = 4, m = 4;
    unordered_map<int, int> nodeIdToIndex;
    vector<int> nodeIds = {2, 5, 7, 9}; // Unique node IDs

    // Map each node ID to an index
    for (int i = 0; i < n; ++i)
    {
        nodeIdToIndex[nodeIds[i]] = i;
    }

    vector<vector<Edge>> graph(n);

    // Adding edges to the graph
    vector<vector<int>> edges = {{2, 9, 2}, {7, 2, 3}, {7, 9, 7}, {9, 5, 1}};
    for (const auto &edge : edges)
    {
        int u = nodeIdToIndex[edge[0]];
        int v = nodeIdToIndex[edge[1]];
        int w = edge[2];
        graph[u].emplace_back(v, w);
    }

    int src = 7, des = 9;
    src = nodeIdToIndex[src];
    des = nodeIdToIndex[des];

    // Dijkstra's algorithm
    vector<int> distance(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (const Edge &edge : graph[u])
        {
            int v = edge.to;
            int weight = edge.weight;

            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    if (distance[des] == INF)
    {
        cout << "No path from " << nodeIds[src] << " to " << nodeIds[des] << endl;
    }
    else
    {
        cout << "Shortest distance from " << nodeIds[src] << " to " << nodeIds[des] << ": " << distance[des] << endl;
    }

    return 0;
}
