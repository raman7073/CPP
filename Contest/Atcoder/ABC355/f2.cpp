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
        return a.weight > b.weight; // Min heap
    }
};

struct DSU
{
    vector<int> parent, rank;

    DSU(int n)
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

    void Union(int u, int v)
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

int MST_Kruskal(priority_queue<Edge, vector<Edge>, CompareEdge> &pq, int V)
{
    int e = 0, sum = 0;
    DSU dsu(V);

    while (e < V - 1 && !pq.empty())
    {
        Edge currEdge = pq.top();
        pq.pop();

        int u = dsu.find(currEdge.u);
        int v = dsu.find(currEdge.v);

        if (u != v)
        {
            sum += currEdge.weight;
            dsu.Union(u, v);
            e++;
        }
    }
    return sum;
}

int main()
{
    int N, Q;
    cin >> N >> Q;

    priority_queue<Edge, vector<Edge>, CompareEdge> pq; // Min-heap for initial graph
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({u - 1, v - 1, w});
    }

    for (int i = 0; i < Q; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({u - 1, v - 1, w});
        cout << MST_Kruskal(pq, N) << endl;
    }

    return 0;
}
