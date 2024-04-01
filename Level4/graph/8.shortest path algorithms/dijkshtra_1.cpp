/*
  -> weighted graph,ug,dg
  -> single source to all other nodes shortest path
  -> Greedy Algorithm
  -> doesn't work for negative edges(bellman ford works)
  -> for pairs , shortest path (floyd warshell works)
*/
#include <iostream>
using namespace std;
#include <limits.h>

#define V 6 // Number of vertices in the graph

// Function to find the vertex with minimum distance
int minDist(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int distance[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << (char)(i + 65) << " \t\t" << distance[i] << endl;
}

// Function that implements Dijkstra's algorithm
void dijkstra(int graph[V][V], int src)
{
    int distance[V]; // inititalizing output array

    bool sptSet[V]; // list of finalized nodes

    // Initializing all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX, sptSet[i] = false;

    // Setting distance of source as 0
    distance[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {

        // calling minDistance to pick next vertex
        int u = minDist(distance, sptSet);

        // Mark the picked vertex as finalised
        sptSet[u] = true;

        // Relaxing all neighbours of U
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] &&
                graph[u][v] &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
        }

        // print the constructed distance array
        printSolution(distance);
    }
}
// driver function
int main()
{

    // Example graph
    // Same as Graph in example diagram above

    int graph[V][V] = {{0, 4, 5, 0, 0, 0},
                       {4, 0, 11, 9, 7, 0},
                       {5, 11, 0, 0, 3, 0},
                       {0, 9, 0, 0, 13, 2},
                       {0, 7, 3, 13, 0, 6},
                       {0, 0, 0, 2, 6, 0}};
    int source = 0;
    dijkstra(graph, source);

    return 0;
}
