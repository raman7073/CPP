#include <iostream>
#include <vector>

const int MOD = 1000000007;
int c = 0;
int f(int n)
{
    c++;
    if (n == 0)
        return 1; // Base case: there's one way to achieve a sum of 0
    if (n < 0)
        return 0; // Base case: no way to achieve a negative sum

    int sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i >= 0)
        {
            std::cout << " caling f of ->" << (n - i) << std::endl;
            sum += f(n - i);
        }
    }
    return sum;
}
int f2(int n, vector<int> &memo)
{
    if (n == 0)
        return 1; // Base case: there's one way to achieve a sum of 0
    if (n < 0)
        return 0; // Base case: no way to achieve a negative sum

    if (memo[n] != -1)
        return memo[n]; // Return the cached result if already computed

    int sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        sum += f(n - i, memo);
    }

    memo[n] = sum; // Store the result in memoization table
    return sum;
}

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

    int way1 = countWays(n);
    int way2 = f(n);
    std::cout << way1 << " " << way2 << std::endl;
    std::cout << c;

    return 0;
}