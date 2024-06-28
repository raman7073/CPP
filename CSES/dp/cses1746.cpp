#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
std::vector<std::vector<int>> dp;
const int MOD = 1e9 + 7;

int f(int idx, int prev, int n, int m, const std::vector<int> &arr)
{
    // Base case: If we've reached the end of the array, return 1
    if (idx == n)
    {
        return 1;
    }

    // Variable to store the count of valid arrays
    int count = 0;

    // If the current value is known (not 0), only one choice is available
    if (arr[idx] != 0)
    {
        // Check if this value is valid given the previous value
        if (prev == 0 || std::abs(arr[idx] - prev) <= 1)
        {
            count = f(idx + 1, arr[idx], n, m, arr);
        }
    }
    else
    {
        // The current value is unknown (0), we need to try all values from 1 to m
        for (int value = 1; value <= m; value++)
        {
            if (prev == 0 || std::abs(value - prev) <= 1)
            {
                count = (count + f(idx + 1, value, n, m, arr)) % MOD;
            }
        }
    }

    return count;
}

int countArrays(int idx, int prev, int n, int m, const std::vector<int> &arr)
{
    // Base case: If we've reached the end of the array, return 1
    if (idx == n)
    {
        return 1;
    }

    // If we have already computed the value for this state, return it
    if (dp[idx][prev] != -1)
    {
        return dp[idx][prev];
    }

    // Variable to store the count of valid arrays
    int count = 0;

    // If the current value is known (not 0), only one choice is available
    if (arr[idx] != 0)
    {
        // Check if this value is valid given the previous value
        if (prev == 0 || std::abs(arr[idx] - prev) <= 1)
        {
            count = countArrays(idx + 1, arr[idx], n, m, arr);
        }
    }
    else
    {
        // The current value is unknown (0), we need to try all values from 1 to m
        for (int value = 1; value <= m; value++)
        {
            if (prev == 0 || std::abs(value - prev) <= 1)
            {
                count = (count + countArrays(idx + 1, value, n, m, arr)) % MOD;
            }
        }
    }

    // Store the result in dp array
    dp[idx][prev] = count;
    return count;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    dp.assign(n, std::vector<int>(m + 1, -1));
    int result = countArrays(0, 0, n, m, arr);
    // int result = f(0, 0, n, m, arr);
    std::cout << result << std::endl;

    return 0;
}
