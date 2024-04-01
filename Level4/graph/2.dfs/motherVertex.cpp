//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void DFS(int v, vector<int> adj[], vector<bool> &visited)
    {
        visited[v] = true;
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                DFS(u, adj, visited);
            }
        }
    }
    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        int lastFinished = 0;

        // First pass: find the last finished vertex
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, adj, visited);
                lastFinished = i;
            }
        }

        // Reset visited array for second pass
        fill(visited.begin(), visited.end(), false);

        // Second pass: check if the last finished vertex can reach all vertices
        DFS(lastFinished, adj, visited);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                return -1; // If any vertex is not visited, then no mother vertex exists
        }

        return lastFinished;
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