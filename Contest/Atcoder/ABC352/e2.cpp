#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
};

struct DSU
{
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
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
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    for (int i = 0; i < M; i++)
    {
        int K, C;
        cin >> K >> C;
        vector<int> vertices(K);
        for (int j = 0; j < K; j++)
        {
            cin >> vertices[j];
        }
        for (int j = 0; j < K - 1; j++)
        {
            edges.push_back({vertices[j], vertices[j + 1], C});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    DSU dsu(N);
    long long totalWeight = 0;
    int numEdges = 0;
    for (const Edge &edge : edges)
    {
        if (dsu.find(edge.u) != dsu.find(edge.v))
        {
            dsu.unite(edge.u, edge.v);
            totalWeight += (long long)edge.weight;
            numEdges++;
        }
        if (numEdges == N - 1)
        {
            break;
        }
    }

    if (numEdges != N - 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << totalWeight << endl;
    }

    return 0;
}