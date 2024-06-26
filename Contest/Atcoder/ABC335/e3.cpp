#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;

void solve()
{
    int n, m, i, j;
    cin >> n >> m;

    vector<int> v(n), dp(n, 0), visit(n, 0);

    for (i = 0; i < n; ++i)
        cin >> v[i];

    vector<vector<int>> adj(n);

    for (i = 0; i < m; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;

        adj[t1 - 1].push_back(t2 - 1);
        adj[t2 - 1].push_back(t1 - 1);
    }

    // Priority queue to store the tuple (value, {-score, vertex})
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({v[0], {-1, 0}});

    while (pq.size())
    {
        auto p = pq.top();
        int x = p.second.second;
        pq.pop();

        // Update dp[x] with the maximum score for vertex x
        dp[x] = max(dp[x], -p.second.first);

        // If vertex x is already visited, continue to the next iteration
        if (visit[x])
            continue;

        // Mark vertex x as visited
        visit[x] = 1;

        int n1 = adj[x].size();

        // Iterate through neighbors of vertex x
        for (i = 0; i < n1; ++i)
        {
            // If the neighbor is already visited or has a lower value, continue to the next neighbor
            if (visit[adj[x][i]] || v[adj[x][i]] < v[x])
                continue;

            // Push the neighbor into the priority queue with updated score
            if (v[adj[x][i]] == v[x])
                pq.push({v[adj[x][i]], {-dp[x], adj[x][i]}});
            else
                pq.push({v[adj[x][i]], {-dp[x] - 1, adj[x][i]}});
        }
    }

    // Print the maximum score for the path from vertex 1 to vertex N
    cout << dp[n - 1] << endl;
}

signed main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
