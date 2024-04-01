/* Here we take help of stack . In stack , most dependent jobs are pushed first.*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
void dfs2(int source, vector<bool> &vis, vector<vector<int>> &adj)
{

    vis[source] = true;
    cout << source << " ";
    for (int nb : adj[source])
    {

        if (!vis[nb])
        {
            dfs2(nb, vis, adj);
        }
    }
}

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
vector<int> ts(int V, vector<vector<int>> &graph)
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
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1, vector<int>());
    vector<vector<int>> rev_graph(V + 1, vector<int>());
    int x, y;
    for (int i = 0; i < E; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    /*
    step 1,  to get topo order which will ensure the traverse of source to sinks
    */
    vector<int> topoOrder = ts(V, graph);

    /*
    step 2, reverse all edges , it will help in traversing from sinks to source
     done while taking input
    */
    /*
      step 3,do dfs in topo order to ensure traversal from sinks to source
    */
    vector<bool> vis(V + 1, false);
    for (int i : topoOrder)
    {
        if (!vis[i])
        {
            dfs2(i, vis, rev_graph);
            cout << endl;
        }
    }

    return 0;
}