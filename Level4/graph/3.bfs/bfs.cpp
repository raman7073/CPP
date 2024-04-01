#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> bfs(int n, vector<vector<int>> &adj)
{
    queue<int> qu;
    vector<bool> vis(n + 1, false);
    qu.push(1);
    vis[1] = true;
    vector<int> ans;
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        ans.push_back(x);

        for (int nbr : adj[x])
        {
            if (!vis[nbr])
            {
                vis[nbr] = true;
                qu.push(nbr);
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}