#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    string R, C;
    cin >> R >> C;

    // Check if a valid solution exists
    vector<int> rowCount(3, 0), colCount(3, 0);
    for (int i = 0; i < N; ++i) {
        rowCount[R[i] - 'A']++;
        colCount[C[i] - 'A']++;
    }

    for (int i = 0; i < 3; ++i) {
        if (rowCount[i] > N || colCount[i] > N) {
            cout << "No" << endl;
            return 0;
        }
    }

    // Construct the grid
    vector<string> grid(N, string(N, '.'));

    for (int i = 0; i < N; ++i) {
        grid[i][i] = R[i];
    }

    for (int i = 0; i < N; ++i) {
        grid[i][0] = C[i];
    }

    // Print the result
    cout << "Yes" << endl;
    for (int i = 0; i < N; ++i) {
        cout << grid[i] << endl;
    }

    return 0;
}
