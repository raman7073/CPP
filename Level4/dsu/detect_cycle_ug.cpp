//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parent, rank;
    // Find function
    int find(int node)
    {

        // If the node is the parent of
        // itself then it is the leader
        // of the tree.
        if (node == parent[node])
            return node;

        // Else, finding parent and also
        //  compressing the paths.
        return parent[node] = find(parent[node]);
    }
    bool Union(int u, int v)
    {

        // Make u as a leader
        // of its tree.
        int rep_u = find(u);

        // Make v as a leader
        // of its tree.
        int rep_v = find(v);

        // If u and v are not equal,
        // because if they are equal then
        // it means they are already in
        // same tree and it does not make
        // sense to perform union operation.
        if (rep_u != rep_v)
        {
            // Checking tree with
            // smaller depth/height.
            if (rank[rep_u] < rank[rep_v])
            {
                int temp = rep_u;
                rep_u = rep_v;
                rep_v = temp;
            }
            // Attaching lower rank tree
            // to the higher one.
            parent[rep_v] = rep_u;

            // If now ranks are equal
            // increasing rank of u.
            if (rank[rep_u] == rank[rep_v])
                rank[rep_u]++;
            return false;
        }
        return true;
    }
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[])
    {
        // Code here
        parent.resize(V);
        rank.resize(V);
        map<pair<int, int>, int> mp;
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                int a = i;
                int b = adj[i][j];
                if (mp.find({a, b}) != mp.end() or mp.find({b, a}) != mp.end())
                {
                    continue;
                }
                mp[{a, b}] = 1;
                if (Union(a, b))
                    return 1;
                else
                    continue;
            }
        }
        return 0;
    }
};
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
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.detectCycle(V, adj);
        cout << ans << "\n";
    }
    return 0;
}
