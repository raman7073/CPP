/*
Given weights and values of n items, put these items in a knapsack of capacity W
 to get the maximum total value in the knapsack.

*/

#include <iostream>
#include <vector>
#include <algorithm>

int knapSackRec(int W, std::vector<int> wt, std::vector<int> val, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (wt[n - 1] > W)
    {
        return knapSackRec(W, wt, val, n - 1);
    }
    else
    {
        return std::max(val[n - 1] + knapSackRec(W - wt[n - 1], wt, val, n - 1), knapSackRec(W, wt, val, n - 1));
    }
}

int knapSack(int W, std::vector<int> wt, std::vector<int> val)
{
    int n = wt.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = std::max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W;
    std::cin >> n >> W;

    std::vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> wt[i] >> val[i];
    }

    int maxVal = knapSack(W, wt, val);
    std::cout << maxVal << std::endl;

    return 0;
}