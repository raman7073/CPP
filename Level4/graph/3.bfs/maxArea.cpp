//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isValid(int x, int y, int n, int m, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        if ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (vis[x][y] == 0) && (grid[x][y] == 1))
            return true;
        else
            return false;
    }
    void bfs(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<bool>> &vis, int &ans)
    {
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for (int k = 0; k < 8; ++k)
            {
                if (isValid(x + rowNbr[k], y + colNbr[k], n, m, vis, grid))
                {
                    q.push({x + rowNbr[k], y + colNbr[k]});
                    ans++;
                    vis[x + rowNbr[k]][y + colNbr[k]] = true;
                }
            }
        }
    }
    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if ((vis[i][j] == false) && (grid[i][j] == 1))
                {
                    int ans = 1;
                    bfs(grid, i, j, n, m, vis, ans);
                    res = max(res, ans);
                }
            }
        }
        return res;
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
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends