/*
https://atcoder.jp/contests/abc211/tasks/abc211_d
 Number of shortest paths
 ->for shortest path , we can do bfs
 ->we can keep count array , here is algo
 For each u that has an edge from v,
   1.if we’ve never visited u yet, update dist[u] to
            dist[v]+1 and assign cnt[v] to cnt[u];
   2.if we’ve already visited u and dist[u]=dist[v]+1
   (ensuring not coming from parent of parent),
    add cnt[v] to cnt[u];
   3.otherwise, do nothing.

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    // Read the input
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N); // Graph representation

    // Construct the graph
    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    // Initialize
    queue<int> que;
    vector<int> dist(N, -1);
    vector<long long> cnt(N, 0);
    que.push(0);
    dist[0] = 0;
    cnt[0] = 1;

    // BFS
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (int u : G[v])
        {
            if (dist[u] == -1)
            {
                dist[u] = dist[v] + 1;
                que.push(u);
                cnt[u] = cnt[v];
            }
            else if (dist[u] == dist[v] + 1)
            {
                cnt[u] += cnt[v];
                cnt[u] %= 1000000007; // 10^9 + 7
            }
        }
    }

    cout << cnt[N - 1] << endl;

    return 0;
}
