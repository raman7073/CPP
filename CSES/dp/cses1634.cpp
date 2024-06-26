/*
  Min Coins Change : min coins needed to make sum x
  state transition equation :
    f(n) -> minimum number of coins needed to make sum x
    f(n) = 1+ min(f(n-i)) , i from 0 to coins length , f(0) = 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

int f3(int n, int m, std::vector<int> &v)
{
    std::vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0; // Base case: no coins needed to make sum 0

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - v[j] >= 0 && dp[i - v[j]] != INT_MAX)
            {
                dp[i] = std::min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }

    return dp[m] == INT_MAX ? -1 : dp[m]; // If no solution exists, return -1
}

int f2(int n, int m, std::vector<int> &v, std::vector<int> &memo)
{
    if (m == 0)
        return 0; // Base case: no coins needed to make sum 0
    if (m < 0)
        return INT_MAX; // Base case: impossible state

    if (memo[m] != -1)
        return memo[m]; // Return cached result

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int res = f(n, m - v[i], v, memo);
        if (res != INT_MAX)
        {
            ans = std::min(ans, res + 1);
        }
    }
    memo[m] = ans; // Cache the result
    return memo[m];
}

int f(int n, int m, std::vector<int> &v)
{
    if (m == 0)
        return 0; // Base case: no coins needed to make sum 0
    if (m < 0)
        return INT_MAX; // Base case: impossible state

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int res = f(n, m - v[i], v);
        if (res != INT_MAX)
        {
            ans = std::min(ans, res + 1);
        }
    }

    return ans;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    std::cout << f(n, m, v);

    return 0;
}