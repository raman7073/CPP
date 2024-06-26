#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
};

vector<int> parent;

int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void union_sets(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
        parent[v] = u;
}

int main()
{
    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i)
    {
        int K;
        cin >> K;
        cin >> edges[i].weight;
        for (int j = 0; j < K; ++j)
        {
            int vertex;
            cin >> vertex;
            if (j == 0)
                edges[i].u = vertex;
            else
            {
                edges[i].v = vertex;
                if (edges[i].u > edges[i].v)
                    swap(edges[i].u, edges[i].v);
            }
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         {
        if (a.weight != b.weight)
            return a.weight < b.weight;
        if (a.u != b.u)
            return a.u < b.u;
        return a.v < b.v; });

    int totalWeight = 0;
    int edgeCount = 0;
    for (const Edge &edge : edges)
    {
        if (find(edge.u) != find(edge.v))
        {
            totalWeight += edge.weight;
            union_sets(edge.u, edge.v);
            ++edgeCount;
        }
        if (edgeCount == N - 1)
            break;
    }

    if (edgeCount != N - 1)
        cout << "-1" << endl;
    else
        cout << totalWeight << endl;

    return 0;
}
