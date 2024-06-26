#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int subtree_size[MAXN];
bool visited[MAXN];

// Function to calculate the size of each subtree
int calculateSubtreeSize(int v, int parent)
{
    subtree_size[v] = 1;
    for (int u : adj[v])
    {
        if (u != parent && !visited[u])
        {
            subtree_size[v] += calculateSubtreeSize(u, v);
        }
    }
    return subtree_size[v];
}

// Function to find the centroid of the tree
int findCentroid(int v, int parent, int treeSize)
{
    for (int u : adj[v])
    {
        if (u != parent && !visited[u] && subtree_size[u] > treeSize / 2)
        {
            return findCentroid(u, v, treeSize);
        }
    }
    return v;
}

// Function to calculate the sum of distances
long long calculateSumOfDistances(int v, int parent, int distance, const vector<int> &C)
{
    long long sum = C[v - 1] * distance;
    for (int u : adj[v])
    {
        if (u != parent && !visited[u])
        {
            sum += calculateSumOfDistances(u, v, distance + 1, C);
        }
    }
    return sum;
}

// Function to solve the problem
long long solve(int v, const vector<int> &C)
{
    calculateSubtreeSize(v, -1);
    int centroid = findCentroid(v, -1, subtree_size[v]);
    visited[centroid] = true;
    long long minSum = calculateSumOfDistances(centroid, -1, 0, C);
    for (int u : adj[centroid])
    {
        if (!visited[u])
        {
            minSum = min(minSum, solve(u, C));
        }
    }
    return minSum;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    vector<int> C(N);
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    long long answer = solve(1, C);
    cout << answer << endl;
    return 0;
}