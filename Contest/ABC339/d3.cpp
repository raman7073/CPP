#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    // Read input
    int N;
    cin >> N;

    vector<string> grid(N);

    // Read the grid
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    // Find the positions of the two players
    pair<int, int> player1, player2;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'P') {
                if (player1.first == 0) {
                    player1 = {i, j};
                } else {
                    player2 = {i, j};
                }
            }
        }
    }

    // Initialize variables for BFS
    vector<vector<int>> steps(N, vector<int>(N, INT_MAX));
    queue<pair<int, int>> q;

    // Possible directions: up, down, left, right
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    // Multi-source BFS
    q.push(player1);
    q.push(player2);
    steps[player1.first][player1.second] = 0;
    steps[player2.first][player2.second] = 0;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int newRow = (row + dx[k] + N) % N;
            int newCol = (col + dy[k] + N) % N;

            if (grid[newRow][newCol] != '#' && steps[newRow][newCol] == INT_MAX) {
                q.push({newRow, newCol});
                steps[newRow][newCol] = steps[row][col] + 1;
            }
        }
    }

    // Find the minimum number of steps for both players to reach the same cell
    int minSteps = INT_MAX;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] != '#' && steps[i][j] != INT_MAX) {
                minSteps = min(minSteps, max(steps[i][j], steps[i][j]));
            }
        }
    }

    // If a common cell is found, print the minimum steps
    if (minSteps != INT_MAX) {
        cout << minSteps << endl;
    } else {
        // If no common cell is found, print -1
        cout << -1 << endl;
    }

    return 0;
}
