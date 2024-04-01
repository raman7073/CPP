#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // dp[i][x][y] represents whether it's possible to reach position (x, y) after i operations
    vector<vector<vector<bool>>> dp(N + 1, vector<vector<bool>>(2 * N + 1, vector<bool>(2 * N + 1, false)));
    dp[0][N][N] = true;

    for (int i = 0; i < N; ++i) {
        for (int x = 0; x <= 2 * N; ++x) {
            for (int y = 0; y <= 2 * N; ++y) {
                if (dp[i][x][y]) {
                    // Rotate counterclockwise
                    dp[i + 1][x + A[i]][y] = true;
                    // Rotate clockwise
                    dp[i + 1][x][y + A[i]] = true;
                }
            }
        }
    }

    if (!dp[N][X + N][Y + N]) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;

        int x = X + N;
        int y = Y + N;

        string result;
        for (int i = N; i > 0; --i) {
            if (x - A[i - 1] >= 0 && dp[i - 1][x - A[i - 1]][y]) {
                result += 'L';
                x -= A[i - 1];
            } else {
                result += 'R';
                y -= A[i - 1];
            }
        }

        reverse(result.begin(), result.end());
        cout << result << endl;
    }

    return 0;
}
