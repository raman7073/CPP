#include <bits/stdc++.h>
using namespace std;
/*
  The idea is very simple, topological sort is possible only if the graph is DAG (Directed Acyclic Graph)
i.e. Graph should be directed and it should not contain any cycle. Therefore we will just check if the
topological ordering is possible for the given graph or not.

To check if topological ordering is possible or not,
 we will use Kahn's Algorithm which uses the idea of indegrees of the vertices where the in-degree of a vertex (say
v) is nothing but the number of incoming edges toward the vertex
*/
// Adjacency List
vector<vector<int>> adj;

// Function to add edge u --> v
void addEdge(int u, int v)
{
    adj[u].push_back(v);
}

// Function to check for the cycle.
bool checkCycle(int V, int E)
{
    // Defining the array to
    // store indegrees.
    int deg[V];
    for (int i = 0; i < V; i++)
        deg[i] = 0;

    // Computing indegree of
    // each vertex using.
    for (int i = 0; i < V; i++)
        for (int x : adj[i])
            deg[x]++;

    // Queue to store vertices
    // with  having 0 indegree.
    queue<int> q;

    // Iterate from i = 0 To i
    // = V - 1 and find vertices
    // having indegree as 0.
    for (int i = 0; i < V; i++)
        if (deg[i] == 0)
            q.push(i);

    // Defining the counter.
    int counter = 0;

    // Iterating while the queue is
    // not empty.
    while (!q.empty())
    {
        // Dequeue from 'q'.
        int u = q.front();
        q.pop();
        // Increase the counter.
        counter++;

        // Iterate for all neighours
        // of vertex 'u'.
        for (int v : adj[u])
        {
            // Decrease the indegree.
            deg[v]--;

            // If deg[v] is 0, insert
            // it the q.
            if (deg[v] == 0)
                q.push(v);
        }
    }

    // Returning true if counter != V.
    return counter != V;
}
int main()
{
    // Defining the number of Vertices
    // and the number of edges.
    int V = 5, E = 7;

    // Defining Adjacency List
    adj.resize(V);
    // Building the Graph same as example 1.
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(4, 1);
    addEdge(4, 2);

    // If the graph contains cycle
    // Print YES
    if (checkCycle(V, E))
        cout << "YES\n";
    // Otherwise Print NO
    else
        cout << "NO\n";
}
