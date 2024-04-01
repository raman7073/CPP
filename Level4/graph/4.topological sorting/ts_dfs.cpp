/* Here we take help of stack . In stack , most dependent jobs are pushed first.*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void dfs(int source, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st)
{

    vis[source] = true;
    for (int nb : adj[source])
    {

        if (!vis[nb])
        {
            dfs(nb, vis, adj, st);
        }
    }
    st.push(source);
}
void ts(int V, vector<vector<int>> &graph)
{
    // Code here
    vector<bool> vis(V + 1, false);
    stack<int> st;
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, graph, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    for (int x : ans)
        cout << x << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1, vector<int>());
    int x, y;
    for (int i = 0; i < E; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    ts(V, graph);

    return 0;
}