#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>> &graph, unordered_map<int, int> &nodeToIndex, int u, int v)
{
    graph[nodeToIndex[u]].push_back(nodeToIndex[v]);
}

bool bfs(vector<vector<int>> &graph, int src, int des)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);

                if (neighbor == des)
                {
                    return true; // There is a path from src to des
                }
            }
        }
    }

    return false; // There is no path from src to des
}

int main()
{
    unordered_map<int, int> nodeToIndex;
    vector<int> nodeIds = {2, 5, 7, 9};

    for (int i = 0; i < nodeIds.size(); ++i)
    {
        nodeToIndex[nodeIds[i]] = i;
    }

    int n = nodeIds.size();
    vector<vector<int>> graph(n);

    addEdge(graph, nodeToIndex, 2, 9);
    addEdge(graph, nodeToIndex, 7, 2);
    addEdge(graph, nodeToIndex, 7, 9);
    addEdge(graph, nodeToIndex, 9, 5);

    int src = nodeToIndex[2], des = nodeToIndex[9];

    int result = bfs(graph, src, des) ? 1 : 0;
    cout << result << endl;

    return 0;
}
