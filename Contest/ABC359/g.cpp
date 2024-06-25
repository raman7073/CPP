#include <bits/stdc++.h>
#define endl "\n"
const int MAXN = 200005;
const int LOG = 18;

std::vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN][LOG];
int A[MAXN];

void dfs(int v, int p, int d)
{
    depth[v] = d;
    parent[v][0] = p;
    for (int i = 1; i < LOG; ++i)
    {
        if (parent[v][i - 1] != -1)
            parent[v][i] = parent[parent[v][i - 1]][i - 1];
        else
            parent[v][i] = -1;
    }
    for (int u : adj[v])
    {
        if (u != p)
            dfs(u, v, d + 1);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        std::swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = LOG - 1; i >= 0; --i)
    {
        if ((1 << i) & diff)
            u = parent[u][i];
    }
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int distance(int u, int v)
{
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}

long long solve(int N, std::vector<std::pair<int, int>> &edges, std::vector<int> &A)
{
    for (int i = 1; i <= N; ++i)
    {
        adj[i].clear();
    }

    for (auto &edge : edges)
    {
        int u = edge.first, v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(parent, -1, sizeof(parent));
    memset(depth, 0, sizeof(depth));

    dfs(1, -1, 0);

    std::unordered_map<int, std::vector<int>> value_nodes;
    for (int i = 1; i <= N; ++i)
    {
        value_nodes[A[i]].push_back(i);
    }

    long long tsum = 0;
    for (const auto &entry : value_nodes)
    {
        const std::vector<int> &nodes = entry.second;
        int M = nodes.size();
        for (int i = 0; i < M; ++i)
        {
            for (int j = i + 1; j < M; ++j)
            {
                tsum += (depth[nodes[i]] + depth[nodes[j]] - 2 * depth[lca(nodes[i], nodes[j])]);
            }
        }
    }

    return tsum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> edges(N - 1);
    for (int i = 0; i < N - 1; ++i)
    {
        std::cin >> edges[i].first >> edges[i].second;
    }
    std::vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> A[i];
    }

    std::cout << solve(N, edges, A) << endl;
    return 0;
}
