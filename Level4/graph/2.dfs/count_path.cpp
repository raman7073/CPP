//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int node, int destination, vector<int> adj[], vector<bool> &visited, int &pathCount)
    {
        visited[node] = true;
        if (node == destination)
        {
            pathCount++;
        }
        else
        {
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    dfs(it, destination, adj, visited, pathCount);
                }
            }
        }
        visited[node] = false; // unmark the node to allow other paths
    }
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination)
    {
        // Code here
        vector<bool> visited(V, false);
        int pathCount = 0;

        dfs(source, destination, adj, visited, pathCount);

        return pathCount;
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends