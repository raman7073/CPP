#include <bits/stdc++.h>
using namespace std;

// TC - O(n) ,visiting every node once

#define endl "\n"
void dfs(int currentNode, int parent, vector<vector<int>> &adj, vector<int> &sub)
{

  sub[currentNode] = 1;
  for (int nb : adj[currentNode])
  {

    if (nb != parent)
    {
      dfs(nb, currentNode, adj, sub);
      sub[currentNode] += sub[nb];
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

  vector<int> subtree_size(n);
  dfs(0, -1, adj, subtree_size);
  for (int x : subtree_size)
  {
    cout << x << "--> ";
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}