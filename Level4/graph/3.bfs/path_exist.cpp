//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find whether a path exists from the source to destination.
    bool check(int n, int x, int y, vector<vector<int>> &grid)
    {
        return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0; // Assuming 0 is an obstacle
    }

    bool is_Possible(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        int x = -1, y = -1;

        // Find starting position
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                    goto start_found;
                }
            }
        }
    start_found:
        if (x == -1)
            return false; // Starting point not found
        q.push({x, y});

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int xi = p.first;
            int yi = p.second;
            if (grid[xi][yi] == 2)
                return true;  // Destination reached
            grid[xi][yi] = 0; // Mark as visited

            // Check and enqueue four directions
            if (check(n, xi + 1, yi, grid))
                q.push({xi + 1, yi});
            if (check(n, xi - 1, yi, grid))
                q.push({xi - 1, yi});
            if (check(n, xi, yi + 1, grid))
                q.push({xi, yi + 1});
            if (check(n, xi, yi - 1, grid))
                q.push({xi, yi - 1});
        }

        return false; // Destination not reachable
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
        bool ans = obj.is_Possible(grid);
        cout << ((ans) ? "1\n" : "0\n");
    }
    return 0;
}
// } Driver Code Ends