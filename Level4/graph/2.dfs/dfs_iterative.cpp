#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph
{
    int V;          // Number of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V);               // Constructor
    void addEdge(int v, int w); // Function to add an edge to the graph
    void DFS(int s);            // Function to perform DFS from a given vertex s
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int s)
{
    // Initially mark all vertices as not visited
    vector<bool> visited(V, false);

    // Create a stack for DFS
    stack<int> stack;

    // Push the current source node
    stack.push(s);

    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So we need to print the popped item only if it is not visited.
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If an adjacent has not been visited, then push it to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                stack.push(*i);
            }
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2);

    return 0;
}
