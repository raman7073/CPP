#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int u, v, weight;
};

struct CompareEdge
{
    bool operator()(const Edge &a, const Edge &b)
    {
        return a.weight > b.weight;
    }
};

struct DisjointSet
{
    vector<int> parent, rank;

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return;
        if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else
        {
            parent[rootU] = rootV;
            if (rank[rootU] == rank[rootV])
                rank[rootV]++;
        }
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<Edge> edges(N - 1); // Edges initially present in the graph
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }

    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    for (const Edge &edge : edges)
    {
        pq.push(edge);
    }

    DisjointSet dsu(N);
    long long totalWeight = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        Edge currEdge = pq.top();
        pq.pop();
        if (dsu.find(currEdge.u) != dsu.find(currEdge.v))
        {
            dsu.merge(currEdge.u, currEdge.v);
            totalWeight += currEdge.weight;
        }
    }

    vector<long long> MSTWeights(Q); // MST weights after each query
    MSTWeights[0] = totalWeight;

    for (int i = 0; i < Q; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        pq.push({u, v, w});

        while (!pq.empty())
        {
            Edge currEdge = pq.top();
            pq.pop();
            if (dsu.find(currEdge.u) != dsu.find(currEdge.v))
            {
                dsu.merge(currEdge.u, currEdge.v);
                totalWeight += currEdge.weight;
                break; // Found a new edge to add to the MST
            }
        }

        MSTWeights[i] = totalWeight;
    }

    for (int i = 0; i < Q; ++i)
    {
        cout << MSTWeights[i] << endl;
    }

    return 0;
}
