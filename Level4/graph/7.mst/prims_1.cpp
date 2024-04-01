/* for undirected connected weighted graph */
#include <bits/stdc++.h>

using namespace std;

#define V 4

// Selects the vertex which has the least weight edge of all unselected vertices.
int selectMinVertex(vector<int> &value, vector<bool> &setMST)
{
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < V; i++)
    {
        if (setMST[i] == false && value[i] < minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

// Print the minimum spanning tree
void printMst(vector<int> &parent, int graph[V][V])
{
    cout << "Src.\tDest.\tWeight\n";
    for (int i = 1; i < parent.size(); i++)
    {
        cout << i << "\t" << parent[i] << "\t" << graph[i][parent[i]] << "\n";
    }
}

int findMST(int graph[V][V])
{
    vector<int> parent(V);
    vector<int> value(V, INT_MAX);
    vector<bool> setMST(V, false);
    int res = 0;

    parent[0] = -1;
    value[0] = 0;
    // Iterate through all the vertices of the graph
    for (int i = 0; i < V; i++)
    {
        /** from all vertices connecting the currently chosen vertices,
         * select a vertex which adds minimum edge,we use value array.
         **/
        int U = selectMinVertex(value, setMST);
        setMST[U] = true;
        res += value[U];
        /**
         * Add newly added vertex as parent of all the vertices
         * it connects to except those that are already chosen.
         * This would help us print the tree later.
         **/
        for (int j = 0; j < V; j++)
        {
            if (graph[U][j] != 0 && setMST[j] == false && graph[U][j] < value[j])
            {
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }
    cout << endl;
    printMst(parent, graph);
    cout << endl;
    return res;
}

int main()
{
    /**
     * This is the adjacency matrix representation of graph where
     * the weight for the edge i,i is stored in ith row and jth column
     * **/
    int graph[V][V] = {
        {0, 75, 10, 0},
        {75, 0, 80, 150},
        {10, 80, 0, 20},
        {0, 150, 20, 0},
    };
    cout << findMST(graph);
    return 0;
}
