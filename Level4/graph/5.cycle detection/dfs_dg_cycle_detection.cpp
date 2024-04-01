#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool contains_cycle(int source, vector<bool> &vis, vector<vector<int>> &adj, vector<bool> &recursionStack)
{

    vis[source] = true;
    recursionStack[source] = true;
    for (int nb : adj[source])
    {

        if (!vis[nb])
        {
            if (contains_cycle(nb, vis, adj, recursionStack))
                return true;
        }
        else if (recursionStack[nb])
            return true;
    }
    recursionStack[source] = false;
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> vis(V + 1, false);
    vector<bool> recursionStack(V + 1, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (contains_cycle(i, vis, adj, recursionStack))
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