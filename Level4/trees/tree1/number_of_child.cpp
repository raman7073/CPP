#include <bits/stdc++.h>
using namespace std;

// TC - O(n) ,visiting every node once

#define endl "\n"
void dfs(int currentNode, int parent, vector<vector<int>> &adj, vector<int> &ans)
{

    for (int nb : adj[currentNode])
    {
        if (nb == parent)
            continue;
        ans[currentNode]++;
        dfs(nb, currentNode, adj, ans);
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
    vector<int> child(n);
    dfs(0, -1, adj, child);
    for (int x : child)
    {
        cout << x << " ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}