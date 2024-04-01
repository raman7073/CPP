//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int time = 0;

    int bridgeUtil(int v, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<int> adj[], int c, int d)
    {
        // Mark the current node as visited
        visited[v] = true;

        // Initialize discovery time and low value
        disc[v] = low[v] = ++time;

        // Go through all vertices adjacent to this
        for (int to : adj[v])
        {
            // If 'to' is not visited yet, then recur for it
            if (!visited[to])
            {
                parent[to] = v;
                if (bridgeUtil(to, visited, disc, low, parent, adj, c, d))
                    return 1;

                // Check if the subtree rooted with 'to' has a connection to one of the ancestors of 'v'
                low[v] = min(low[v], low[to]);

                // If the lowest vertex reachable from subtree under 'to' is below 'v' in DFS tree, then this is a bridge
                if (low[to] > disc[v])
                {
                    if ((v == c || v == d) && (to == c || to == d))
                        return 1;
                }
            }

            // Update low value of 'v' for parent function calls.
            // for back edge
            else if (to != parent[v])
                low[v] = min(low[v], disc[to]);
        }
        return 0;
    }
    // Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        // Code here
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);
        vector<int> disc(V), low(V), parent(V, -1);

        // Call the recursive helper function to find Bridges in DFS tree rooted with vertex 'i'
        for (int i = 0; i < V; i++)
            if (!visited[i])
                if (bridgeUtil(i, visited, disc, low, parent, adj, c, d))
                    return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends