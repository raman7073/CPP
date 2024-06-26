#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    // Read the grid
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    // Compute prefix sums for efficient querying
    vector<vector<int>> prefixSum(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            if (grid[i - 1][j - 1] == 'B') {
                ++prefixSum[i][j];
            }
        }
    }

    // Process queries
    for (int q = 0; q < Q; ++q) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        // Compute the number of black squares in the specified rectangular area
        int result = prefixSum[C][D] - prefixSum[A - 1][D] - prefixSum[C][B - 1] + prefixSum[A - 1][B - 1];
        cout << result << endl;
    }

    return 0;
}
