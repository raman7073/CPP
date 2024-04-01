#include <bits/stdc++.h>
using namespace std;

// TC - O(n) ,visiting every node once

#define endl "\n"
void bfs(int currentNode, vector<int> &vis, vector<vector<int>> &adj, vector<int> &ans)
{

    queue<int> q;
    q.push(currentNode);
    while (!q.empty())
    {
        int x = q.front();
        ans.push_back(x);
        q.pop();
        vis[x] = 1;
        for (int nb : adj[x])
        {
            if (vis[nb] == 0)
            {
                q.push(nb);
            }
        }
    }
}

void solve()
{

    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs_traversal;
    vector<int> vis(n, 0);
    bfs(0, vis, adj, bfs_traversal);
    for (int x : bfs_traversal)
    {
        cout << x + 1 << "--> ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}