#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int minTrioDegree(int n, vector<vector<int>> edges)
{
    vector<vector<int>> adjacency(n + 1, vector<int>(n + 1, 0));
    vector<int> nodeDegree(n + 1, 0);

    for (const vector<int> &edge : edges)
    {
        int node1 = edge[0];
        int node2 = edge[1];
        adjacency[node1][node2] = 1;
        adjacency[node2][node1] = 1;
        nodeDegree[node1]++;
        nodeDegree[node2]++;
    }
    int minDeg = 1233212;
    for (int node1 = 1; node1 <= n; node1++)
    {
        for (int node2 = node1 + 1; node2 <= n; node2++)
        {
            for (int node3 = node2 + 1; node3 <= n; node3++)
            {
                if (adjacency[node1][node2] && adjacency[node2][node3] && adjacency[node1][node3])
                {

                    int deg = nodeDegree[node1] + nodeDegree[node2] + nodeDegree[node3] - 6;
                    minDeg = min(deg, minDeg);
                }
            }
        }
    }
    if (minDeg == 1233212)
        minDeg = -1;
    return minDeg;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}