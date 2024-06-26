#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Cell
{
    int row, col, energy;
};

bool isValid(int row, int col, int H, int W)
{
    return row >= 1 && row <= H && col >= 1 && col <= W;
}

bool canReachGoal(int H, int W, vector<vector<char>> &grid, unordered_map<int, int> &medicineMap)
{
    int startRow, startCol, goalRow, goalCol;
    vector<vector<bool>> visited(H + 1, vector<bool>(W + 1, false));

    // Locate start ('S') and goal ('T')
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (grid[i][j] == 'S')
            {
                startRow = i;
                startCol = j;
            }
            else if (grid[i][j] == 'T')
            {
                goalRow = i;
                goalCol = j;
            }
        }
    }

    queue<Cell> q;
    int startEnergy = (medicineMap.count((startRow * 1000 + startCol))) ? medicineMap[(startRow * 1000 + startCol)] : 0;

    if (startEnergy <= 0 && grid[startRow][startCol] != grid[goalRow][goalCol])
        return false;
    if (grid[startRow][startCol] == grid[goalRow][goalCol])
        return true;
    // cout << "start " << startRow << " " << startCol << " " << startEnergy << endl;
    q.push({startRow, startCol, startEnergy});
    visited[startRow][startCol] = true;

    while (!q.empty())
    {
        Cell curr = q.front();
        q.pop();

        int row = curr.row;
        int col = curr.col;
        int currEnergy = curr.energy;

        if (row == goalRow && col == goalCol)
            return true;

        // Explore 4-directional neighbors
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (isValid(newRow, newCol, H, W) && !visited[newRow][newCol] && grid[newRow][newCol] != '#')
            {
                int newEnergy = currEnergy - 1;

                if (medicineMap.count(newRow * 1000 + newCol))
                {
                    if (medicineMap[newRow * 1000 + newCol] > newEnergy)
                    {
                        newEnergy = medicineMap[newRow * 1000 + newCol];
                        medicineMap.erase(newRow * 1000 + newCol);
                    }
                }

                if (newEnergy >= 0)
                {
                    // cout << "new " << newRow << " " << newCol << " " << newEnergy << endl;
                    q.push({newRow, newCol, newEnergy});
                    visited[newRow][newCol] = true;
                }
            }
        }
    }

    return false;
}

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H + 1, vector<char>(W + 1));

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> grid[i][j];
        }
    }

    int N;
    cin >> N;

    unordered_map<int, int> medicineMap;
    int r, c, e;
    for (int i = 0; i < N; i++)
    {
        cin >> r >> c >> e;
        medicineMap[(r * 1000 + c)] = e;
    }

    if (canReachGoal(H, W, grid, medicineMap))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
