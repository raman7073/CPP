#include <iostream>
#include <vector>

const int MOD = 1000000007;

int countWays(int n)
{
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    return dp[n];
}

int main()
{
    int n;
    std::cin >> n;

    int ways = countWays(n);
    std::cout << ways << std::endl;

    return 0;
}