/*
  Coin Combination I : given infinite coins of different type, number of ways to make money x
  whenever a money becomes 0 , it contributes 1 way

  state - transition equation:
  f(n)-> number of ways to make money n using different available coins
  f(n) = sum of f(n-coins[i]) , i = 0  to n-1 with f(0) = 1


*/
#include <iostream>
#include <vector>
#include <algorithm>
vector<int> dp(1000001);

int coinChangeBU(vector<int> &coins, int amount)
{

    int n = coins.size();

    dp[0] = 1;
    for (int weight = 0; weight <= amount; weight++)
    {

        for (int i = 0; i < n; i++)
        {
            if (weight - coins[i] >= 0)
            {
                dp[weight] += dp[weight - coins[i]];
                dp[weight] %= m;
            }
        }
    }

    return dp[amount];
}

int f(int money, int n, std::vector<int> &coins)
{
    // std::cout << money << std::endl;

    if (money == 0)
        return 1;
    if (money < 0)
        return 0;
    int ways = 0;
    for (int i = 0; i < n; i++)
    {
        ways += f(money - coins[i], n, coins);
    }
    return ways;
}
int f1(int money, int n, std::vector<int> &coins)
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
        ways += f(money - coins[i], n, coins);
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
    std::cout << f(m, n, v);

    return 0;
}