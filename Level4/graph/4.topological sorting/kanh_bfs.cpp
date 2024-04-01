/*
  There can be more than one topological sorting order.topological sorting sorts
  the nodes in order in which they can be processed first.it is possible only for DAG.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> bfs(int n, vector<vector<int>> &adj)
{
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < adj.size(); i++)
    {
        for (int node : adj[i])
        {
            indegree[node]++;
        }
    }
    queue<int> qu;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            qu.push(i);
        }
    }
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        ans.push_back(x);

        for (int node : adj[x])
        {
            indegree[node]--;
            if (indegree[node] == 0)
            {
                qu.push(node);
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1, vector<int>());
    int x, y;
    for (int i = 0; i < E; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    vector<int> ans = bfs(V, graph);
    for (int x : ans)
        cout << x << " ";

    return 0;
}