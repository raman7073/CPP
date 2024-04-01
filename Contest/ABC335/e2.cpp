#include <bits/stdc++.h>
using namespace std;

void dfs(int current, vector<vector<int>> &adjList, vector<int> &dp, vector<int> &value)
{
    for (int neighbor : adjList[current])
    {
        if (value[neighbor] >= value[current])
        {
            dp[neighbor] = max(dp[neighbor], dp[current] + 1);
            dfs(neighbor, adjList, dp, value);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> value(N + 1);
    vector<vector<int>> adjList(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> dp(N + 1, 1);

    for (int i = 1; i <= N; i++)
    {
        dfs(i, adjList, dp, value);
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << ans;

    return 0;
}
