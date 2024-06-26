#include <iostream>
#include <vector>
#include <queue>
#define MOD 998244353
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int N, M;
int u[MAXN], v[MAXN];
int dist[MAXN];
long long dp[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    dp[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }

            if (dist[neighbor] == dist[node] + 1) {
                dp[neighbor] = (dp[neighbor] + dp[node]) % MOD;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = -1;
    }

    bfs(1);

    if (dist[N] == -1) {
        cout << "-1" << endl;
    } else {
        cout << dp[N+1] << endl;
    }

    return 0;
}
