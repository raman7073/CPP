#include <bits/stdc++.h>
using namespace std;

// TC - O(n) ,visiting every node once

#define endl "\n"
void dfs(int currentNode, int parent, vector<vector<int>> &adj, vector<int> &ans)
{

  ans.push_back(currentNode);
  for (int nb : adj[currentNode])
  {
    if (nb == parent)
      continue;
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
  vector<int> dfs_traversal;
  dfs(0, -1, adj, dfs_traversal);
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