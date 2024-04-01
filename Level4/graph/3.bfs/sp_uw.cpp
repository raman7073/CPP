#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
/*
  shortest path in unweighted graph from src to all other nodes
  works for equal weighted graph
*/
void bfs(int src, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dis)
{
    queue<int> qu;
    qu.push(src);
    dis[src] = 0;
    vis[src] = true;
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        for (int nbr : adj[x])
        {
            if (!vis[nbr])
            {
                vis[nbr] = true;
                dis[nbr] = dis[x] + 1;
                qu.push(nbr);
            }
        }
    }
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
        graph[y].push_back(x);
    }
    vector<int> dis(V, 0);
    vector<bool> vis(V, false);

    bfs(0, graph, vis, dis);
    for (int x : dis)
    {
        cout << x << " ";
    }
    return 0;
}