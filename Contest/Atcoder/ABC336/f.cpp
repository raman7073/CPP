#include <iostream>
#include <vector>

using namespace std;

int H, W;
vector<vector<int>> S;

bool isSorted() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] != i * W + j + 1) {
                return false;
            }
        }
    }
    return true;
}

void rotateRectangle(int x, int y) {
    vector<int> temp = {S[x][y], S[x][y + 1], S[x + 1][y], S[x + 1][y + 1]};
    S[x][y] = temp[2];
    S[x][y + 1] = temp[0];
    S[x + 1][y] = temp[3];
    S[x + 1][y + 1] = temp[1];
}

bool isValid(int x, int y) {
    return (x >= 0 && x < H - 1 && y >= 0 && y < W - 1);
}

int minOperations() {
    int operations = 0;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (isValid(i, j)) {
                if (S[i][j] > S[i + 1][j] || S[i][j] > S[i][j + 1]) {
                    rotateRectangle(i, j);
                    ++operations;
                }
            }
        }
    }

    return isSorted() ? operations : -1;
}

int main() {
    // Read input
    cin >> H >> W;
    S.resize(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> S[i][j];
        }
    }

    // Find the minimum number of operations
    int result = minOperations();

    // Print the result
    cout << result << endl;

    return 0;
}
