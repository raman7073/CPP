#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Read input
    int N;
    cin >> N;

    vector<string> grid(N);

    // Read the grid
    for (int i = 0; i < N; ++i)
    {
        cin >> grid[i];
    }

    // Find the positions of the two players
    pair<int, int> player1, player2;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (grid[i][j] == 'P')
            {
                if (player1.first == 0)
                {
                    player1 = {i, j};
                }
                else
                {
                    player2 = {i, j};
                }
            }
        }
    }

    // Calculate the number of steps for each player to reach each cell
    vector<vector<int>> steps1(N, vector<int>(N, INT_MAX));
    vector<vector<int>> steps2(N, vector<int>(N, INT_MAX));

    // Possible directions: up, down, left, right
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    // BFS to calculate steps for Player 1
    vector<vector<bool>> visited1(N, vector<bool>(N, false));
    queue<pair<int, int>> q1;
    q1.push(player1);
    steps1[player1.first][player1.second] = 0;

    while (!q1.empty())
    {
        auto [row, col] = q1.front();
        q1.pop();

        for (int k = 0; k < 4; ++k)
        {
            int newRow = (row + dx[k]);
            int newCol = (col + dy[k]);

            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && grid[newRow][newCol] != '#' && !visited1[newRow][newCol])
            {
                visited1[newRow][newCol] = true;
                q1.push({newRow, newCol});
                steps1[newRow][newCol] = steps1[row][col] + 1;
            }
        }
    }

    // BFS to calculate steps for Player 2
    vector<vector<bool>> visited2(N, vector<bool>(N, false));
    queue<pair<int, int>> q2;
    q2.push(player2);
    steps2[player2.first][player2.second] = 0;

    while (!q2.empty())
    {
        auto [row, col] = q2.front();
        q2.pop();

        for (int k = 0; k < 4; ++k)
        {
            int newRow = (row + dx[k]);
            int newCol = (col + dy[k]);

            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && grid[newRow][newCol] != '#' && !visited2[newRow][newCol])
            {
                visited2[newRow][newCol] = true;
                q2.push({newRow, newCol});
                steps2[newRow][newCol] = steps2[row][col] + 1;
            }
        }
    }

    // Find the minimum number of steps for both players to reach the same cell
    int minSteps = INT_MAX;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (grid[i][j] != '#' && steps1[i][j] != INT_MAX && steps2[i][j] != INT_MAX)
            {
                minSteps = min(minSteps, max(steps1[i][j], steps2[i][j]));
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (grid[i][j] != '#' && steps1[i][j] != INT_MAX)
            {
                cout << steps1[i][j] << " ";
            }
            else
            {
                cout << "IF"
                     << " ";
            }
            
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (grid[i][j] != '#' && steps2[i][j] != INT_MAX)
            {
                cout << steps2[i][j] << " ";
            }
            else
            {
                cout << "IF"
                     << " ";
            }
        }
        cout << endl;
    }

    // If a common cell is found, print the minimum steps
    if (minSteps != INT_MAX)
    {
        cout << minSteps << endl;
    }
    else
    {
        // If no common cell is found, print -1
        cout << -1 << endl;
    }

    return 0;
}
