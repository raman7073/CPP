#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void dfs(int source, vector<bool> &vis, vector<vector<int>> &adj)
{

    cout << source;
    vis[source] = true;
    for (int nb : adj[source])
    {
        if (!vis[nb])
        {
            dfs(nb, vis, adj);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}