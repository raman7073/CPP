/*
  adjacent nodes are of different color.This is two coloring problem.
  A tree is always bipartite, we can color alternate node with same color.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool dfs(int source, vector<int> &vis, vector<vector<int>> &adj, int parent, int color)
{

    vis[source] = color;
    for (int nb : adj[source])
    {

        if (!vis[nb])
        {
            if (!dfs(nb, vis, adj, source, 3 - color))
                return false;
        }
        else if (nb != parent && color == vis[nb])
            return false;
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V + 1, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, adj, -1, 1))
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}