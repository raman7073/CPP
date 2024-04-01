#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void dfs(pair<int, pair<long long, long long>> node, vector<vector<pair<int, pair<int, int>>>> &adj, vector<pair<long long, long long>> &ans, vector<bool> &vis)
{
    vis[node.first] = true;
    ans[node.first] = {node.second.first, node.second.second};

    for (auto nb : adj[node.first])
    {
        if (vis[nb.first])
            continue;
        long long X = (long long)(ans[node.first].first + nb.second.first);
        long long Y = (long long)(ans[node.first].second + nb.second.second);
        dfs({nb.first, {X, Y}}, adj, ans, vis);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, pair<int, int>>>> adj(n + 1, vector<pair<int, pair<int, int>>>());
    for (int i = 0; i < m; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;

        adj[u].push_back({v, {x, y}});
        adj[v].push_back({u, {-x, -y}});
    }
    vector<pair<long long, long long>> dfs_traversal(n + 1);
    vector<bool> vis(n + 1, false);
    dfs({1, {0L, 0L}}, adj, dfs_traversal, vis);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            cout << dfs_traversal[i].first << " " << dfs_traversal[i].second << endl;
        else
            cout << "undecidable" << endl;
   }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
