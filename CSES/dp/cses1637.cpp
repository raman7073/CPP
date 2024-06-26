#include <iostream>
#include <vector>
int largestDigit(int n)
{
    int maxDigit = 0;
    while (n > 0)
    {
        int digit = n % 10;
        maxDigit = std::max(maxDigit, digit);
        n /= 10;
    }
    return maxDigit;
}

int f(int n)
{
    if (n <= 0)
        return 0;
    if (n >= 1 && n <= 9)
        return 1;

    int maxDigits = largestDigit(n);
    return 1 + f(n - maxDigits);
}

int f2(int n, std::vector<int> &memo)
{
    if (n <= 0)
        return 0;
    if (n >= 1 && n <= 9)
        return 1;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = 1 + f(n - largestDigit(n));
    return memo[n];
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> memo(n + 1, -1);
    int ways = f2(n, memo);
    std::cout << ways << std::endl;
    return 0;
}