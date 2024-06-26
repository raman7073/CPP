#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;

vector<vector<pair<int, int>>> adjList;
vector<bool> visited;

int dfs(int node)
{
    visited[node] = true;
    int maxCost = 0;

    for (const auto &neighbor : adjList[node])
    {
        int neighborNode = neighbor.first;
        int neighborCost = neighbor.second;
        if (!visited[neighborNode])
        {
            maxCost = max(maxCost, dfs(neighborNode) + neighborCost);
        }
    }

    visited[node] = false;
    return maxCost;
}

int main()
{
    int N, M;
    cin >> N >> M;

    adjList.resize(N + 1);
    visited.assign(N + 1, false);

    for (int i = 0; i < M; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        adjList[A].emplace_back(B, C);
        adjList[B].emplace_back(A, C);
    }

    int maxCost = 0;
    for (int i = 1; i <= N; ++i)
    {
        maxCost = max(maxCost, dfs(i));
    }

    cout << maxCost << endl;

    return 0;
}
