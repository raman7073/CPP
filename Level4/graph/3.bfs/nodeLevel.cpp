//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        // code here
        vector<int> level(V, 0);
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (!vis[v])
                {

                    level[v] = level[u] + 1;
                    q.push(v);
                    vis[v] = true;

                    if (v == X)
                    {
                        return level[v];
                    }
                }
            }
        }
        // for(int x : level) cout<<x<<" ";
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E, X;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> X;

        Solution obj;
        cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

// } Driver Code Ends