/*
Problem: Max Subsequence Sum
Problem Statement:
Given an array of integers, find the maximum sum of a subsequence such that
no two elements in the subsequence are adjacent to each other.

TC  = n * 1 = n
SC  = n


*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
int f(int i, vector<int> &dp, vector<int> &a)
{
    if (i < 0)
        return 0;
    if (dp[i] != INT_MIN) // Change -INFINITY to INT_MIN
        return dp[i];
    return dp[i] = max(a[i] + f(i - 2, dp, a), f(i - 1, dp, a));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(n, INT_MIN);
    cout << f(n - 1, dp, a) << endl;

    return 0;
}