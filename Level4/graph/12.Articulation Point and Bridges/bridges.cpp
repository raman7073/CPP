#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
    int V;            // Number of vertices
    vector<int> *adj; // Adjacency list
    int time = 0;

    void bridgeUtil(int v, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent)
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
                bridgeUtil(to, visited, disc, low, parent);

                // Check if the subtree rooted with 'to' has a connection to one of the ancestors of 'v'
                low[v] = min(low[v], low[to]);

                // If the lowest vertex reachable from subtree under 'to' is below 'v' in DFS tree, then this is a bridge
                if (low[to] > disc[v])
                    cout << v << " -- " << to << " is a bridge\n";
            }

            // Update low value of 'v' for parent function calls.
            // for back edge
            else if (to != parent[v])
                low[v] = min(low[v], disc[to]);
        }
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // Add v to w’s list, since the graph is undirected.
    }

    // DFS based function to find bridges. It uses recursive function bridgeUtil()
    void bridge()
    {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);
        vector<int> disc(V), low(V), parent(V, -1);

        // Call the recursive helper function to find Bridges in DFS tree rooted with vertex 'i'
        for (int i = 0; i < V; i++)
            if (!visited[i])
                bridgeUtil(i, visited, disc, low, parent);
    }
};

int main()
{
    cout << "Bridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();

    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.bridge();

    return 0;
}
