#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, w;
};

struct DSU
{
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            if (rank[x] < rank[y])
            {
                swap(x, y);
            }
            parent[y] = x;
            if (rank[x] == rank[y])
            {
                rank[x]++;
            }
        }
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<Edge> edges(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.w < b.w; });

    DSU dsu(N);
    long long totalWeight = 0;
    vector<long long> minSpanningTreeWeights;
    for (int i = 0; i < N - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dsu.find(u) != dsu.find(v))
        {
            dsu.unite(u, v);
            totalWeight += w;
            minSpanningTreeWeights.push_back(totalWeight);
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (dsu.find(u) != dsu.find(v))
        {
            dsu.unite(u, v);
            totalWeight += w;
            minSpanningTreeWeights.push_back(totalWeight);
        }

        cout << minSpanningTreeWeights.back() << endl;
    }

    return 0;
}