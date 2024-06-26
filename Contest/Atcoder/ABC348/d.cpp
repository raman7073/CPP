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
bool canReachGoal(int H, int W, int sx, int sy, int gx, int gy, vector<vector<char>> &grid, unordered_map<int, int> &medicineMap)
{
    vector<vector<int>> dp(H + 1, vector<int>(W + 1, -1));
    queue<Cell> q;
    q.push({sx, sy, 0});

    while (!q.empty())
    {
        Cell curr = q.front();
        q.pop();

        int row = curr.row;
        int col = curr.col;
        int currEnergy = max(dp[row][col], medicineMap[row * 1000 + col]);
        if (medicineMap[row * 1000 + col] > dp[row][col])
        {
            medicineMap.erase(row * 1000 + col);
        }
        if (row == gx && col == gy && currEnergy >= 0)
        {
            return true;
        }
        if (currEnergy <= 0)
            continue;
        // visited[row][col] = true;
        //  Check adjacent cells
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (!isValid(newRow, newCol, H, W) || grid[newRow][newCol] == '#')
            {
                continue;
            }
            int newEnergy = currEnergy - 1;
            // place will be visited again with more energy
            if (dp[newRow][newCol] < newEnergy)
            {
                dp[newRow][newCol] = newEnergy;
                q.push({newRow, newCol, newEnergy});
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
    int startRow = -1, startCol = -1, goalRow = -1, goalCol = -1;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> grid[i][j];
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
    int N;
    cin >> N;

    unordered_map<int, int> medicineMap;
    int r, c, e;
    for (int i = 0; i < N; i++)
    {
        cin >> r >> c >> e;
        medicineMap[(r * 1000 + c)] = e;
    }

    if (canReachGoal(H, W, startRow, startCol, goalRow, goalCol, grid, medicineMap))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}