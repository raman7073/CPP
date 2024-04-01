#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

struct Edge
{
    int to, weight;
};

void zeroOneBFS(vector<vector<Edge>> &graph, int start, vector<int> &distance)
{
    int n = graph.size();
    distance.assign(n, INT_MAX);

    deque<int> dq;
    dq.push_front(start);
    distance[start] = 0;

    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();

        for (const Edge &edge : graph[u])
        {
            int v = edge.to;
            int weight = edge.weight;

            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;

                if (weight == 0)
                {
                    dq.push_front(v);
                }
                else
                {
                    dq.push_back(v);
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m; // Number of vertices and edges

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int start;
    cin >> start; // Starting vertex for BFS

    vector<int> distance;
    zeroOneBFS(graph, start, distance);

    // Print the distances from the starting vertex to all other vertices
    for (int i = 0; i < n; ++i)
    {
        cout << "Distance from " << start << " to " << i << ": " << distance[i] << endl;
    }

    return 0;
}
