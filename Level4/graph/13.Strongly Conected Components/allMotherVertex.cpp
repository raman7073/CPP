//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find a Mother Vertex in the Graph.
    void dfs_1(int x, stack<int> &S, vector<int> &visited, vector<int> adj[])
    {
        visited[x] = true;
        for (int i : adj[x])
        {
            if (!visited[i])
                dfs_1(i, S, visited, adj);
        }
        S.push(x);
    }

    void dfs_2(int x, vector<int> &visited, vector<vector<int>> &reverseG)
    {

        visited[x] = true;
        for (int i : reverseG[x])
        {
            if (!visited[i])
                dfs_2(i, visited, reverseG);
        }
    }
    int findMotherVertex(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, false);
        stack<int> S;
        vector<vector<int>> reverseG(V, vector<int>());

        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs_1(i, S, visited, adj);

        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int u = 0; u < V; ++u)
        {
            for (int v : adj[u])
            {
                reverseG[v].push_back(u);
            }
        }
        int ans = -1;
        int num = 0;

        while (!S.empty())
        {
            int v = S.top();
            S.pop();
            if (!visited[v])
            {

                dfs_2(v, visited, reverseG);
                num++;
                ans = v;
            }
        }
        if (num == 1)
            return ans;
        else
            return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        int ans = obj.findMotherVertex(V, adj);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends