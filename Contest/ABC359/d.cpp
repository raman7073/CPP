#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

int is_palindrome(const string &s, int k)
{
    for (int i = 0; i < k / 2; ++i)
    {
        if (s[i] != s[k - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // DP table: dp[length][last K-1 characters][palindromic mask]
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(1 << (K - 1), vector<long long>(2, 0)));

    // Initialize dp for the first character
    if (S[0] == '?')
    {
        dp[1][0][0] = 1; // A
        dp[1][1][0] = 1; // B
    }
    else
    {
        dp[1][S[0] == 'B'][0] = 1;
    }

    for (int i = 1; i < N; ++i)
    {
        for (int mask = 0; mask < (1 << (K - 1)); ++mask)
        {
            for (int p = 0; p < 2; ++p)
            {
                if (dp[i][mask][p] == 0)
                    continue;

                for (char c : {'A', 'B'})
                {
                    if (S[i] != '?' && S[i] != c)
                        continue;

                    int new_mask = ((mask << 1) & ((1 << (K - 1)) - 1)) | (c == 'B');
                    string temp = "";
                    for (int j = 0; j < K - 2; ++j)
                    {
                        if (mask & (1 << (K - 3 - j)))
                            temp += 'B';
                        else
                            temp += 'A';
                    }
                    temp += c;

                    int pal = is_palindrome(temp, K - 1);
                    dp[i + 1][new_mask][p | pal] = (dp[i + 1][new_mask][p | pal] + dp[i][mask][p]) % MOD;
                }
            }
        }
    }

    long long result = 0;
    for (int mask = 0; mask < (1 << (K - 1)); ++mask)
    {
        result = (result + dp[N][mask][0]) % MOD;
    }

    cout << result << endl;

    return 0;
}
