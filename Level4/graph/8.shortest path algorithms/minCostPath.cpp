//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        // Directions: down, right, up, left
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        // Min heap to store the cell coordinates and the current cost to reach that cell.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Start from the top-left cell.
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int x = curr.second.first;
            int y = curr.second.second;

            if (vis[x][y])
                continue;
            vis[x][y] = true;

            // Check all 4 directions.
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                {
                    int newDist = curr.first + grid[nx][ny];
                    if (newDist < dist[nx][ny])
                    {
                        dist[nx][ny] = newDist;
                        pq.push({newDist, {nx, ny}});
                    }
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends