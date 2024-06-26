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
    vector<pair<int, int>> initial_pos;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (S[i][j] == '.')
            {
                initial_pos.push_back({i, j});
            }
        }

        from all initial_pos if he can follow path indicated by string T, count
                                                                              that in possible_positions return 0;
    }
    return 0;
}