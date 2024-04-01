#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    // Read input
    vector<int> X(16);
    for (int i = 0; i < 16; ++i) {
        cin >> X[i];
    }

    // Initialize dp array
    vector<vector<vector<vector<int>>>> dp(2, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, 0))));
    dp[0][0][0][0] = 1;

    // Iterate over all possible values of A
    for (int A = 1; A <= X[0] + X[1] + X[2] + X[3]; ++A) {
        vector<vector<vector<vector<int>>>> new_dp(2, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, 0))));

        // Update dp values based on the given constraints
        for (int i = 0; i <= min(A, X[0]); ++i) {
            for (int j = 0; j <= min(A - i, X[1]); ++j) {
                for (int k = 0; k <= min(A - i - j, X[2]); ++k) {
                    int l = A - i - j - k;
                    if (l <= X[3]) {
                        // Update new_dp values
                        new_dp[i > 0][j > 0][k > 0][l > 0] = (new_dp[i > 0][j > 0][k > 0][l > 0] + dp[0][i][j][k]) % MOD;
                        new_dp[i > 0][j > 0][k > 0][l == 0] = (new_dp[i > 0][j > 0][k > 0][l == 0] + dp[1][i][j][k]) % MOD;
                    }
                }
            }
        }

        // Update dp array
        dp = new_dp;
    }

    // Calculate the final result
    int result = 0;
    for (int i = 0; i <= X[0]; ++i) {
        for (int j = 0; j <= X[1]; ++j) {
            for (int k = 0; k <= X[2]; ++k) {
                for (int l = 0; l <= X[3]; ++l) {
                    result = (result + dp[i > 0][j > 0][k > 0][l > 0]) % MOD;
                }
            }
        }
    }

    // Print the result
    cout << result << endl;

    return 0;
}
