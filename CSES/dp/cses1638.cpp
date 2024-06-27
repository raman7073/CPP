#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MOD = 1000000007;
int f(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &dp, int n, int m)
{

    if (i >= n || j >= m)
        return 0;

    if (i == n - 1 && j == m - 1)
        if (grid[i][j] != '*')
            return 1;
        else
            return 0;
    // if there is a subproblem which is already solved
    if (dp[i][j] != -1)
        return dp[i][j];
    if (grid[i][j] != '*')
        return dp[i][j] = (f(i + 1, j, grid, dp, n, m) + f(i, j + 1, grid, dp, n, m)) % MOD;
    else
        return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << f(0, 0, grid, dp, n, n) << endl;
    return 0;
}