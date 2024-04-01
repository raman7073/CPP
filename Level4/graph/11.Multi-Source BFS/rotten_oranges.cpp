//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    bool check(int m, int n, vector<vector<int>> &grid, int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 2 && grid[x][y] != 0;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        queue<pair<pair<int, int>, int>> pq;
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        //  vector<vector<bool>> vis(n,vector<int>(m,false))
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    pq.push({{i, j}, 0});
                    // vis[i][j] = true;
                }
            }
        }
        while (!pq.empty())
        {
            pair<pair<int, int>, int> p = pq.front();
            pq.pop();
            int x = p.first.first;
            int y = p.first.second;
            int t = p.second;
            time = max(time, t);
            if (check(m, n, grid, x - 1, y))
            {
                pq.push({{x - 1, y}, t + 1});
                grid[x - 1][y] = 2;
            }
            if (check(m, n, grid, x + 1, y))
            {
                pq.push({{x + 1, y}, t + 1});
                grid[x + 1][y] = 2;
            }
            if (check(m, n, grid, x, y - 1))
            {
                pq.push({{x, y - 1}, t + 1});
                grid[x][y - 1] = 2;
            }
            if (check(m, n, grid, x, y + 1))
            {
                pq.push({{x, y + 1}, t + 1});
                grid[x][y + 1] = 2;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    time = -1;
                    break;
                }
            }
        }
        return time;
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
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends