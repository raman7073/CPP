#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    vector<int> dp(N + 1, 0);
    dp[0] = 1; // dp[0] is the initial expected value

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i; j <= N; j += i)
        {
            // Update dp[j] using dp[i]
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }

    int result = 0;
    for (int i = 1; i <= N; ++i)
    {
        result = (result + 1LL * A[i - 1] * dp[i] % MOD) % MOD;
    }

    cout << result << endl;

    return 0;
}
