/*
  Coin Combination II : given infinite coins of different type, number of ordered ways to make money x
  whenever a money becomes 0 , it contributes 1 way with ordered way

  state - transition equation:
  f(n)-> number of ways to make money n using different available coins in ordered way
  f(n) = sum of f(n-coins[i]) , i = 0  to n-1 with f(0) = 1


*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> dp(1000001);

int f(int money, int n, int order, std::vector<int> &coins)
{
    // std::cout << money << std::endl;

    if (money == 0)
        return 1;
    if (money < 0)
        return 0;
    int ways = 0;
    for (int i = 0; i < n; i++)
    {
        if (order <= coins[i])
        {
            order = coins[i];
            ways += f(money - coins[i], n, order, coins);
        }
    }
    return ways;
}

int f1(int money, int n, int order, std::vector<int> &coins)
{
    // std::cout << money << std::endl;

    if (money == 0)
        return 1;
    if (money < 0)
        return 0;
    if (dp[money] != -1)
        return dp[money];
    int ways = 0;
    for (int i = 0; i < n; i++)
    {
        if (order <= coins[i])
        {
            order = coins[i];
            ways += f(money - coins[i], n, order, coins);
        }
    }
    dp[money] = ways;
    return ways;
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
    std::cout << f(m, n, -1, v);

    return 0;
}