#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int countBlackSquares(int N, vector<int>& A) {
    vector<int> dp(N + 1, 0);
    dp[1] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; i + A[i] * j <= N; j++) {
            dp[i + A[i] * j] += dp[i];
            dp[i + A[i] * j] %= MOD;
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = (result + dp[i]) % MOD;
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1); // Increase the size by 1 to match 1-based indexing
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int result = countBlackSquares(N, A);
    cout << result << endl;

    return 0;
}