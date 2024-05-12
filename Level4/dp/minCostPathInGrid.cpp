/*
Problem: Given a grid of size n*m, find the minimum cost path to reach the bottom right
cell from the top left cell. You can only move right and down.


*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m)
{

    if (i >= n || j >= m)
        return INT_MAX;
    if (i == n - 1 && j == m - 1)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] + min(f(i + 1, j, grid, dp, n, m), f(i, j + 1, grid, dp, n, m));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << f(0, 0, grid, dp, n, m) << endl;
    return 0;
}