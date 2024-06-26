#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    unordered_map<int, int> rowCounts, colCounts;
    int diag1Count = 0, diag2Count = 0;
    // unordered_map<int, pair<int, int>> numberToIndex;
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         numberToIndex[N * (i - 1) + j] = {i, j};
    //     }
    // }
    int ans = -1;

    for (int turn = 1; turn <= T; turn++)
    {
        int A;
        cin >> A;

        // int row = numberToIndex[A].first;
        // int col = numberToIndex[A].second;
        int row = (A - 1) / N;
        int col = (A - 1) % N;
        rowCounts[row]++;
        colCounts[col]++;
        if (row == col)
            diag1Count++;
        if (row + col == N - 1)
            diag2Count++;

        // Check if any row, column, or diagonal has all marked cells
        if (rowCounts[row] == N || colCounts[col] == N || diag1Count == N || diag2Count == N)
        {
            ans = turn;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}