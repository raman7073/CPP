#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;

    string T;
    cin >> T;

    vector<string> S(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> S[i];
    }
    int possible_positions = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (S[i][j] == '.')
            {
                int r = i, c = j;

                bool pos = true;
                for (char move : T)
                {
                    if (move == 'U')
                        r += dr[0];
                    else if (move == 'D')
                        r += dr[1];
                    else if (move == 'L')
                        c += dc[2];
                    else if (move == 'R')
                        c += dc[3];

                    if (r >= 0 && r < H && c >= 0 && c < W && S[r][c] == '.')
                    {
                        continue;
                    }
                    else
                    {
                        pos = false;
                        break;
                    }
                }
                if (pos)
                {
                    possible_positions++;
                }
            }
        }
    }

    // Output the number of possible positions
    cout << possible_positions << endl;

    return 0;
}
