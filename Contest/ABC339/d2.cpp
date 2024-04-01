#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

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

    // Initialize variables for BFS
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<tuple<int, int, int>> q; // (row, col, steps)

    // Add the initial positions of players to the queue
    q.push({player1.first, player1.second, 0});
    q.push({player2.first, player2.second, 0});

    // Possible directions: up, down, left, right
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int ans = -1;

    // Perform BFS
    while (!q.empty())
    {
        int row, col, steps;
        tie(row, col, steps) = q.front();
        q.pop();

        // Check if the players are at the same cell
        if (grid[row][col] == 'P')
        {
            ans = steps;
            visited[row][col] = true;
            break;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Explore adjacent cells
        for (int k = 0; k < 4; ++k)
        {
            int newRow = (row + dx[k] + N) % N;
            int newCol = (col + dy[k] + N) % N;

            // Move only to empty cells and unvisited cells
            if (grid[newRow][newCol] != '#' && !visited[newRow][newCol])
            {
                cout<<steps<<endl;
                q.push({newRow, newCol, steps + 1});
            
            }
        }
    }

    // If BFS finds a common cell, print the number of steps
    // for (int i = 0; i < N; ++i)
    // {
    //     for (int j = 0; j < N; ++j)
    //     {
    //         if (visited[i][j])
    //         {
    //             cout << visited[i][j] << endl;
    //             return 0;
    //         }
    //     }
    // }

    // If BFS does not find a common cell, print -1
    cout << ans << endl;

    return 0;
}
