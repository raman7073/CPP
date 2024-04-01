#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool contains_cycle(int source, vector<bool> &vis, vector<vector<int>> &adj, int parent)
{

    vis[source] = true;
    for (int nb : adj[source])
    {

        if (!vis[nb])
        {
            if (contains_cycle(nb, vis, adj, source))
                return true;
        }
        else if (nb != parent)
            return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> vis(V + 1, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (contains_cycle(i, vis, adj, -1))
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