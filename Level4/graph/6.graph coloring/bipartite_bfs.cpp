#include <bits/stdc++.h>

using namespace std;

bool bfs(const vector<vector<int>> &g, int nd, vector<int> &vis)
{

    int sz = g.size();
    vector<int> parents(sz, -1);
    queue<int> q;

    vis[nd] = 1;
    q.push(nd);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = 3 - vis[u];
                q.push(v);
                parents[v] = u;
                continue;
            }
            if (parents[u] != v && vis[v]==vis[u])
            {
                /*
                 if parent of parent of current node is itself the node then there is no cycle
                */
                cout << "node :" << v << endl;
                cout << "parent :" << u << endl;
                cout << "parent of parent:" << parents[u] << endl;
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(const vector<vector<int>> &graph)
{
    int sz = graph.size();
    vector<int> vis(sz, 0);
    for (int i = 0; i < sz; i++)
        if (!vis[i] && bfs(graph, i, vis))
            return true;
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
        {
            cout << "YES" << endl;
            return 0;
        }
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << (isBipartite(graph) ? "YES" : "NO") << endl;
    return 0;
}
