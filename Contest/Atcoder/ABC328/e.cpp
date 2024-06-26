#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    long long u, v, w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class DisjointSet {
public:
    DisjointSet(long long size) : parent(size), rank(size, 0) {
        for (long long i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    long long find(long long x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(long long x, long long y) {
        long long rootX = find(x);
        long long rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }

private:
    vector<long long> parent;
    vector<long long> rank;
};

int main() {
    long long N, M, K;
    cin >> N >> M >> K;

    vector<Edge> edges(M);
    for (long long i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end());

    DisjointSet dsu(N);

    long long totalCost = 0;
    for (const Edge& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            totalCost = (totalCost + edge.w) % K;
        }
    }

    cout << totalCost%K << endl;

    return 0;
}
