//{ Driver Code Starts
/* we represent graph as matrix when position matters ,
in snake ladder only connection between nodes matters ,but here Knight movement is
positional.
 */
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    struct Cell
    {
        int x, y, dist;
        Cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
    };

    // Check if (x, y) is valid chessboard coordinates
    bool isInside(int x, int y, int N)
    {
        return x >= 1 && x <= N && y >= 1 && y <= N;
    }
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        // Directions in which a Knight can move
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        // Queue for BFS
        queue<Cell> q;

        // Start from the knight's position
        q.push(Cell(KnightPos[0], KnightPos[1], 0));

        int x, y;
        bool visit[N + 1][N + 1];

        // Make all cell unvisited
        memset(visit, false, sizeof(visit));

        // Visit starting state
        visit[KnightPos[0]][KnightPos[1]] = true;

        // Loop until queue is empty
        while (!q.empty())
        {
            Cell t = q.front();
            q.pop();

            // If current cell is equal to target cell, return its distance
            if (t.x == TargetPos[0] && t.y == TargetPos[1])
                return t.dist;

            // Loop for all reachable states
            for (int i = 0; i < 8; i++)
            {
                x = t.x + dx[i];
                y = t.y + dy[i];

                // If reachable state is not yet visited and inside board, push that state into queue
                if (isInside(x, y, N) && !visit[x][y])
                {
                    visit[x][y] = true;
                    q.push(Cell(x, y, t.dist + 1));
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends