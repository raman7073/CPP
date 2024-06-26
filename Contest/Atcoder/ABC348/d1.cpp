#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>

using namespace std;

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    pair<int, int> start, goal;
    unordered_map<int, int> medicineMap; // Map from cell index (R*1000+C) to energy

    // Read grid
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                start = {i, j};
            }
            else if (grid[i][j] == 'T')
            {
                goal = {i, j};
            }
            else if (grid[i][j] == '.')
            {
                // empty cell, check for medicine
                grid[i][j] = '.';
            }
        }
    }

    int N;
    cin >> N;

    // Read medicines
    for (int i = 0; i < N; ++i)
    {
        int r, c, e;
        cin >> r >> c >> e;
        medicineMap[r * 1000 + c] = e;
    }

    // BFS setup
    queue<tuple<int, int, int>> q; // (row, col, current energy)
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        auto [r, c, energy] = q.front();
        q.pop();

        // Explore neighbors
        for (auto [dr, dc] : directions)
        {
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc] && grid[nr][nc] != '#')
            {
                int newEnergy = energy;
                if (medicineMap.count(nr * 1000 + nc))
                {
                    newEnergy += medicineMap[nr * 1000 + nc];
                }
                if (newEnergy > 0)
                {
                    if (nr == goal.first && nc == goal.second)
                    {
                        cout << "Yes\n";
                        return 0;
                    }
                    q.push({nr, nc, newEnergy});
                    visited[nr][nc] = true;
                }
            }
        }
    }

    // If we exhaust all possible paths and cannot reach the goal
    cout << "No\n";

    return 0;
}
