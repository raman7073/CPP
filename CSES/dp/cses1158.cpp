#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> dp2(1001, std::vector<int>(100001, -1));

int f(int moneyRemaining, int n, std::vector<int> &prices, std::vector<int> &pages, int i)
{
    if (moneyRemaining == 0 || i < 0)
        return 0;

    // If the price of the current book is more than the moneyRemaining, skip this book
    if (moneyRemaining - prices[i] < 0)
        return f(moneyRemaining, n, prices, pages, i - 1);

    // Either take the current book or don't take it
    return std::max(pages[i] + f(moneyRemaining - prices[i], n, prices, pages, i - 1),
                    f(moneyRemaining, n, prices, pages, i - 1));
}
int f2(int moneyRemaining, int n, std::vector<int> &prices, std::vector<int> &pages, int i)
{
    if (moneyRemaining == 0 || i < 0)
        return 0;

    if (dp2[i][moneyRemaining] != -1)
        return dp2[i][moneyRemaining];

    // If the price of the current book is more than the moneyRemaining, skip this book
    if (moneyRemaining - prices[i] < 0)
        return dp2[i][moneyRemaining] = f2(moneyRemaining, n, prices, pages, i - 1);

    // Either take the current book or don't take it
    return dp2[i][moneyRemaining] = std::max(pages[i] + f2(moneyRemaining - prices[i], n, prices, pages, i - 1),
                                             f2(moneyRemaining, n, prices, pages, i - 1));
}

int main()
{
    int n, x;
    std::cin >> n >> x;
    std::vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> prices[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> pages[i];
    }
    std::vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = x; j >= prices[i]; --j)
        {
            dp[j] = std::max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }

    // The answer is the maximum pages we can get with x money
    std::cout << dp[x] << std::endl;

    // int ans = f2(x, n, prices, pages, n - 1);
    // std::cout << ans << std::endl;

    return 0;
}
