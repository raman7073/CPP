#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> P(N, vector<int>(N));
    vector<vector<int>> R(N, vector<int>(N - 1));
    vector<vector<int>> D(N - 1, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> P[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            cin >> R[i][j];
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> D[i][j];
        }
    }

    vector<vector<long long>> dp(N, vector<long long>(N, 1e18));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i < N - 1)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + D[i][j]);
            }
            if (j < N - 1)
            {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + R[i][j]);
            }
            dp[i][j] += P[i][j];
        }
    }

    cout << dp[N - 1][N - 1] << endl;

    return 0;
}