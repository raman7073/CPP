#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int N, K, P;
    cin >> N >> K >> P;

    vector<vector<int>> dp(2, vector<int>(P + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        int cost;
        cin >> cost;

        vector<int> parameters(K);
        for (int j = 0; j < K; ++j) {
            cin >> parameters[j];
        }

        for (int p = 0; p <= P; ++p) {
            dp[(i + 1) % 2][p] = dp[i % 2][p];
            for (int j = 0; j < K; ++j) {
                if (p + parameters[j] <= P) {
                    dp[(i + 1) % 2][p + parameters[j]] = min(dp[(i + 1) % 2][p + parameters[j]], dp[i % 2][p] + cost);
                }
            }
        }
    }

    int result = dp[N % 2][P];

    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
