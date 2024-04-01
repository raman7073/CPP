#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<vector<int>> grid(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> grid[i][j];
        }
    }

    // Calculate the total number of ways to fill the grid
    long long total_ways = 1;
    for (int i = 0; i < 9; ++i) {
        total_ways *= i + 1;
    }

    // Define the invalid patterns
    vector<vector<int>> invalid_patterns = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    // Calculate the number of valid patterns
    long long valid_patterns = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            for (int k = j + 1; k < 9; ++k) {
                bool is_valid = true;
                for (const auto &pattern : invalid_patterns) {
                    if (pattern[0] == i && pattern[1] == j && pattern[2] == k) {
                        is_valid = false;
                        break;
                    }
                }
                if (is_valid) {
                    valid_patterns++;
                }
            }
        }
    }

    double probability = static_cast<double>(valid_patterns) / static_cast<double>(total_ways);

    cout << fixed << setprecision(15) << probability << endl;

    return 0;
}
