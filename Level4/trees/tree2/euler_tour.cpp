#include <bits/stdc++.h>
using namespace std;

vector<int> flatTree;
vector<int> left(n), right(n);

#define endl "\n"
void dfs(int currentNode, int parent, vector<vector<int>> &adj)
{

    flatTree.push_back(currentNode);
    left[currentNode] = flatTree.size() - 1;
    for (int nb : adj[currentNode])
    {
        if (nb == parent)
            continue;
        dfs(nb, currentNode, adj);
    }
    flatTree.push_back(currentNode);
    right[currentNode] = flatTree.size() - 1;
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
    dfs(0, -1, adj);
    for (int x : dfs_traversal)
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