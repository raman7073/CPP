#include <bits/stdc++.h>
using namespace std;

// TC - O(n) ,visiting every node once

#define endl "\n"
void dfs(int currentNode, int parent, vector<vector<int>> &adj, vector<vector<int>> &par)
{

    par[currentNode][0] = parent;
    for (int nb : adj[currentNode])
    {
        if (nb == parent)
            continue;
        dfs(nb, currentNode, adj, par);
    }
}
int kthParent(int x, int k, vector<vector<int>> &par)
{
    for (int i = 0; i < log2(k)+1; i++)
    {
        if ((1 << i) & k)
        {
            x = par[x][i];
        }
    }
    return x;
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
    vector<vector<int>> par(n, vector<int>(log2(n) + 5, -1));
    dfs(0, -1, adj, par);
    for (int i = 1; i < log2(n) + 5; i++)
    {
        for (int x = 0; x < n; x++)
        {
            int intermediate = par[x][i - 1];
            if (intermediate != -1)
            {
                /*
                   par[x][i] = 2^i th parent of x
                   if y = par[x][i-1] , then
                   par[x][i] = par[y][i-1]
                */
                par[x][i] = par[intermediate][i - 1];
            }
        }
    }
    // for (int i = 0; i < par.size(); i++)
    // {
    //     for (int x : par[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    int x, k;
    cin >> x >> k;
    x--;
    int ans = kthParent(x, k, par);
    cout << ans + 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}