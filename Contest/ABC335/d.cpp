#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int grid[N][N];

    int x = 1, i = 0, j = N / 2;
    while (x <= N*N) {
        grid[i][j] = x++;
        int new_i = (i - 1 + N) % N;
        int new_j = (j + 1) % N;
        if (grid[new_i][new_j] != 0) {
            i = (i + 1) % N;
        } else {
            i = new_i;
            j = new_j;
        }
    }

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            if (grid[a][b] == N*N) {
                cout << "T ";
            } else {
                cout << grid[a][b] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}