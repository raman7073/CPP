#include <iostream>
#include <vector>

using namespace std;

// Function to rotate a polyomino 90 degrees counterclockwise
vector<string> rotatePolyomino(const vector<string>& polyomino) {
    int n = polyomino.size();
    int m = polyomino[0].size();
    vector<string> rotated(m, string(n, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rotated[j][n - 1 - i] = polyomino[i][j];
        }
    }
    return rotated;
}

// Function to check if a polyomino can be placed at a certain position on the grid
bool canPlace(const vector<string>& grid, const vector<string>& polyomino, int row, int col) {
    int n = polyomino.size();
    int m = polyomino[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (polyomino[i][j] == '#' && (row + i >= 4 || col + j >= 4 || grid[row + i][col + j] == '.')) {
                return false;
            }
        }
    }
    return true;
}

// Function to fill the grid with polyominoes
bool fillGrid(vector<string>& grid, const vector<vector<string>>& polyominoes, int idx) {
    if (idx == polyominoes.size()) {
        return true;  // All polyominoes have been placed
    }

    for (int i = 0; i < 4; ++i) {
        auto rotatedPolyomino = rotatePolyomino(polyominoes[idx]);
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                if (canPlace(grid, rotatedPolyomino, row, col)) {
                    // Place the polyomino on the grid
                    for (int k = 0; k < rotatedPolyomino.size(); ++k) {
                        for (int l = 0; l < rotatedPolyomino[0].size(); ++l) {
                            if (rotatedPolyomino[k][l] == '#') {
                                grid[row + k][col + l] = '#';
                            }
                        }
                    }

                    // Recursive call to place the next polyomino
                    if (fillGrid(grid, polyominoes, idx + 1)) {
                        return true;
                    }

                    // Backtrack (remove the polyomino from the grid)
                    for (int k = 0; k < rotatedPolyomino.size(); ++k) {
                        for (int l = 0; l < rotatedPolyomino[0].size(); ++l) {
                            if (rotatedPolyomino[k][l] == '#') {
                                grid[row + k][col + l] = '.';
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<string>> polyominoes(3, vector<string>(4));
    
    // Read input
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> polyominoes[i][j];
        }
    }

    // Initialize an empty grid
    vector<string> grid(4, "....");

    // Attempt to fill the grid with polyominoes
    if (fillGrid(grid, polyominoes, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
