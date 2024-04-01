#include <bits/stdc++.h>
using namespace std;

// TC - O(n) ,visiting every node once

#define endl "\n"
vector<int> inTime(1000);
vector<int> outTime(1000);
void dfs(int currentNode, int parent, vector<vector<int>> &adj, int &currentTime)
{

    inTime[currentNode] = currentTime++;
    for (int nb : adj[currentNode])
    {
        if (nb == parent)
            continue;
        dfs(nb, currentNode, adj, currentTime);
    }
    outTime[currentNode] = currentTime++;
    
}

void solve()
{

    int n, q;
    cin >> n, q;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int currentTime = 1;
    dfs(0, -1, adj, currentTime);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        // checking if x is ancestor of y
        if (inTime[y] > inTime[x] && outTime[y] < outTime[x])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}