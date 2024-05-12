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
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        cout << "find(" << x << ")" << endl;
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

    vector<Edge> edges; // Resize the vector after declaration
    edges.resize(M);    // Resize the vector to M elements

    for (int i = 0; i < M; i++)
    {
        int K;
        cin >> K;
        vector<int> vertices(K);
        for (int j = 0; j < K; j++)
        {
            cin >> vertices[j];
        }
        int C;
        cin >> C;
        for (int j = 0; j < K; j++)
        {
            for (int k = j + 1; k < K; k++)
            {
                edges.push_back({vertices[j], vertices[k], C});
            }
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    DSU dsu(N);
    int totalWeight = 0;
    int numEdges = 0;
    for (const Edge &edge : edges)
    {
        if (dsu.find(edge.u) != dsu.find(edge.v))
        {
            dsu.unite(edge.u, edge.v);
            totalWeight += edge.weight;
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