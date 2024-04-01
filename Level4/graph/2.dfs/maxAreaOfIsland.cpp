#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>> &grid, int &count, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
    {
        return;
    }
    if (grid[i][j] == 1)
    {
        count++;
        grid[i][j] = 0;
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        dfs(nx, ny, grid, count, m, n);
    }
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            int count = 0;
            if (grid[i][j] == 1)
            {
                dfs(i, j, grid, count, m, n);
                ans = max(ans, count);
            }
        }
    }
    return ans;
}

int main(){
    
}