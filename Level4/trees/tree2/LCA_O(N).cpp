#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 1e5;

vector<int> gr[N];
int dep[N], Par[N];

void dfs(int currentNode, int par)
{
    Par[currentNode] = par;
    dep[currentNode] = dep[par] + 1;
    for (size_t i = 0; i < gr[currentNode].size(); i++)
    {
        if (g[currentNode][i] != par)
            dfs(g[currentNode][i], currentNode);
    }
}
int LCA(int u, int v)
{
    if (u == v)
    {
        return u;
    }
    // we want depth of u more than v , so if it less we swap . technique to get rid of if else
    if (dep[u] < dep[v])
        swap(u, v);

    // depth of u is more than depth of v

    int diff = dep[u] - dep[v];

    // depth of both nodes same
    while (diff--)
    {
        u = Par[u];
    }

    // until they are equal nodes keep climbing
    while (u != v)
    {
        u = Par[u];
        v = Par[v];
    }

    return u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1, 0);

    return 0;
}