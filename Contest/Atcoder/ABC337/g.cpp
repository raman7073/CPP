#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj[MAX_N];
int subtreeSize[MAX_N];
long long distanceSum[MAX_N];
long long result[MAX_N];

void dfs(int u, int parent) {
    subtreeSize[u] = 1;
    distanceSum[u] = 0;

    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
            distanceSum[u] += distanceSum[v] + subtreeSize[v];
        }
    }
}

void calculateF(int u, int parent, long long pathDistance) {
    result[u] = pathDistance;

    for (int v : adj[u]) {
        if (v != parent) {
            int verticesNotInSubtree = subtreeSize[1] - subtreeSize[v];
            long long distanceToNotInSubtree = distanceSum[1] - (distanceSum[v] + subtreeSize[v]);
            
            long long totalDistance = pathDistance + distanceToNotInSubtree + verticesNotInSubtree;
            calculateF(v, u, totalDistance);
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0); // Start DFS from node 1
    calculateF(1, 0, 0); // Calculate f(u) for each node

    for (int i = 1; i <= N; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
