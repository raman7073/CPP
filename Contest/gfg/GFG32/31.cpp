#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, graph, visited, st);
        }
    }
    st.push(node);
}

void dfsReverse(int node, vector<vector<int>> &reverseGraph, vector<bool> &visited, vector<int> &scc)
{
    visited[node] = true;
    scc.push_back(node);
    for (int neighbor : reverseGraph[node])
    {
        if (!visited[neighbor])
        {
            dfsReverse(neighbor, reverseGraph, visited, scc);
        }
    }
}

int findMinimumCost(int n, vector<int> &cost, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> reverseGraph(n + 1);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited, st);
        }
    }

    fill(visited.begin(), visited.end(), false);
    int minCost = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            vector<int> scc;
            dfsReverse(node, reverseGraph, visited, scc);
            int sccCost = INT_MAX;
            for (int junction : scc)
            {
                sccCost = min(sccCost, cost[junction - 1]);
            }
            minCost += sccCost;
        }
    }

    return minCost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    int minCost = findMinimumCost(n, cost, edges);
    cout << minCost << endl;

    return 0;
}