#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    
    long long count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'o') {
                for (int k = j + 1; k < N; ++k) {
                    if (grid[i][k] == 'o') {
                        count += 1;
                    }
                }

                for (int k = i + 1; k < N; ++k) {
                    if (grid[k][j] == 'o') {
                        count += 1;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
