#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<char>> grid(H, vector<char>(W));
    vector<vector<int>> left_o_count(H, vector<int>(W, 0));
    vector<vector<int>> up_o_count(H, vector<int>(W, 0));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'o') {
                left_o_count[i][j] = (j > 0 ? left_o_count[i][j-1] : 0) + 1;
                up_o_count[i][j] = (i > 0 ? up_o_count[i-1][j] : 0) + 1;
            }
        }
    }

    int min_operations = INT_MAX;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j <= W - K; ++j) {
            int needed_ops = K - (left_o_count[i][j + K - 1] - (j > 0 ? left_o_count[i][j - 1] : 0));
            if (needed_ops >= 0) {
                min_operations = min(min_operations, needed_ops);
            }
        }
    }

    for (int j = 0; j < W; ++j) {
        for (int i = 0; i <= H - K; ++i) {
            int needed_ops = K - (up_o_count[i + K - 1][j] - (i > 0 ? up_o_count[i - 1][j] : 0));
            if (needed_ops >= 0) {
                min_operations = min(min_operations, needed_ops);
            }
        }
    }

    if (min_operations == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_operations << endl;
    }

    return 0;
}
