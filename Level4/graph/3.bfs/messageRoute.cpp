#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int bfs(int src, int n, vector<vector<int>> &adj)
{
    queue<int> qu;
    qu.push(src);
    vector<int> vis(n + 1, 0);
    vector<int> dis(n + 1, 0);
    vis[src] = 1;
    dis[src] = 0;
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        for (int nbr : adj[x])
        {
            if (!vis[nbr])
            {
                vis[nbr] = 1;
                dis[nbr] = dis[x] + 1;
                qu.push(nbr);
            }
        }
    }
    if (dis[n] != 0)
    {
        return dis[n] + 1;
    }
    else
    {
        return -1;
    }
}

int messageRoute(int n, vector<vector<int>> edges)
{
    vector<vector<int>> v(n + 1, vector<in>());
    for (int i = 0; i < edges.size(); i++)
    {
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    return bfs(1, n, v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}