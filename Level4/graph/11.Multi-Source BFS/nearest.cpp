//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize the queue with all cells containing 1 and their distance as 0
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions array for the four adjacent cells (up, down, left, right)
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // BFS
        while (!q.empty())
        {
            pair<int, int> cell = q.front();
            q.pop();

            for (auto &dir : dirs)
            {
                int x = cell.first + dir[0], y = cell.second + dir[1];

                // Check if the new cell is within bounds and if updating distance is needed
                if (x >= 0 && x < n && y >= 0 && y < m)
                {
                    if (dist[x][y] > dist[cell.first][cell.second] + 1)
                    {
                        dist[x][y] = dist[cell.first][cell.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends