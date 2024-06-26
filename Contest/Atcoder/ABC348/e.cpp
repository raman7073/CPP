#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to calculate f(x) for a given vertex x
long long calculateF(vector<vector<int>> &graph, vector<int> &C, int x)
{
    int N = graph.size();
    vector<int> dist(N, INT_MAX);
    dist[x] = 0;

    queue<int> q;
    q.push(x);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr])
        {
            if (dist[neighbor] == INT_MAX)
            {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    long long fx = 0;
    for (int i = 0; i < N; i++)
    {
        fx += (long long)C[i] * dist[i];
    }

    return fx;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> graph(N);
    for (int i = 0; i < N - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--; // Convert to 0-based indexing
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<int> C(N);
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }

    long long minFx = LLONG_MAX;
    for (int i = 0; i < N; i++)
    {
        long long fx = calculateF(graph, C, i);
        minFx = min(minFx, fx);
    }

    cout << minFx << endl;

    return 0;
}