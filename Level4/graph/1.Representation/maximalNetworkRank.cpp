#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int maximalNetworkRank(int n, vector<vector<int>> roads)
{
    vector<vector<int>> adjacency(n, vector<int>(n, 0));
    vector<int> cityDegree(n, 0);

    for (const vector<int> &road : roads)
    {
        int city1 = road[0];
        int city2 = road[1];
        adjacency[city1][city2] = 1;
        adjacency[city2][city1] = 1;
        cityDegree[city1]++;
        cityDegree[city2]++;
    }

    int maxRank = 0;
    for (int city1 = 0; city1 < n; city1++)
    {
        for (int city2 = city1 + 1; city2 < n; city2++)
        {
            int rank = cityDegree[city1] + cityDegree[city2] - adjacency[city1][city2];
            maxRank = max(maxRank, rank);
        }
    }

    return maxRank;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}