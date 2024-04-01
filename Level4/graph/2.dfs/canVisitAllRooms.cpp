#include <bits/stdc++.h>
using namespace std;
void dfs(int source, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[source] = true;
    for (int nb : adj[source])
    {
        if (!vis[nb])
        {
            dfs(nb, vis, adj);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> rooms)
{
    int n = rooms.size();
    vector<bool> vis(n, false);
    dfs(0, vis, rooms);
    for (bool x : vis)
    {
        if (x == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}