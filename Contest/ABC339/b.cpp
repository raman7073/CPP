#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<char>> grid(H, vector<char>(W, '.'));
    int i = 0, j = 0;    
    int di = -1, dj = 0;
    for (int move = 0; move < N; ++move)
    {
    
        if (grid[i][j] == '.')
        {
            grid[i][j] = '#';
            int temp = di;
            di = dj;
            dj = -temp;
        }
        else
        {
            grid[i][j] = '.';
            int temp = di;
            di = -dj;
            dj = temp;
        }
        i = (i + di + H) % H;
        j = (j + dj + W) % W;
    }

    // Print the final grid
    for (int row = 0; row < H; ++row)
    {
        for (int col = 0; col < W; ++col)
        {
            cout << grid[row][col];
        }
        cout << endl;
    }

    return 0;
}
