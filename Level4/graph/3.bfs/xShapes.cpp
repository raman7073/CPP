//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the number of 'X' total shapes.
    bool isValid(int x, int y, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {
        if ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (vis[x][y] == 0) && (grid[x][y] == 'X'))
            return true;
        else
            return false;
    }
    void bfs(vector<vector<char>> &grid, int i, int j, int n, int m, vector<vector<bool>> &vis)
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
            static int rowNbr[] = {-1, 1, 0, 0};
            static int colNbr[] = {0, 0, -1, 1};
            for (int k = 0; k < 4; ++k)
            {
                if (isValid(x + rowNbr[k], y + colNbr[k], n, m, vis, grid))
                {
                    q.push({x + rowNbr[k], y + colNbr[k]});
                    vis[x + rowNbr[k]][y + colNbr[k]] = true;
                }
            }
        }
    }

    int xShape(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((vis[i][j] == false) && (grid[i][j] == 'X'))
                {

                    bfs(grid, i, j, n, m, vis);
                    ans++;
                }
            }
        }
        return ans;
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
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.xShape(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends