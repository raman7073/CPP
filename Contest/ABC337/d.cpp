#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    int minOps = INT_MAX;

    // Check horizontally
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j <= W - K; ++j) {
            int ops = 0;
            bool valid = true;
            for (int k = 0; k < K; ++k) {
                if (grid[i][j + k] == 'x') {
                    valid = false;
                    break;
                }
                if (grid[i][j + k] == '.') {
                    ops++;
                }
            }
            if (valid) {
                minOps = min(minOps, ops);
            }
        }
    }

    // Check vertically
    for (int j = 0; j < W; ++j) {
        for (int i = 0; i <= H - K; ++i) {
            int ops = 0;
            bool valid = true;
            for (int k = 0; k < K; ++k) {
                if (grid[i + k][j] == 'x') {
                    valid = false;
                    break;
                }
                if (grid[i + k][j] == '.') {
                    ops++;
                }
            }
            if (valid) {
                minOps = min(minOps, ops);
            }
        }
    }

    // Output the result
    cout << (minOps == INT_MAX ? -1 : minOps) << endl;

    return 0;
}
