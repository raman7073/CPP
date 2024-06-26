#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<char>> S(N, vector<char>(N, ' '));
    int i = -1, j = -1, k = -1, l = -1;

    vector<vector<vector<vector<int>>>> now_dist(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, -1))));

    for (int m = 0; m < N; ++m)
    {
        for (int n = 0; n < N; ++n)
        {
            char s_;
            cin >> s_;
            if (s_ == 'P')
            {
                if (i == -1 && j == -1)
                {
                    i = m;
                    j = n;
                }
                else
                {
                    k = m;
                    l = n;
                }
                S[m][n] = '.';
            }
            else
            {
                S[m][n] = s_;
            }
        }
    }

    now_dist[i][j][k][l] = 0;
    queue<vector<int>> q;
    q.push({i, j, k, l});

    while (!q.empty())
    {
        vector<int> current = q.front();
        q.pop();
        int i = current[0], j = current[1], k = current[2], l = current[3];
        int dist = now_dist[i][j][k][l] + 1;

        
        int i_ = i, k_ = k;
        if (i > 0 && S[i - 1][j] == '.')
        {
            i_ -= 1;
        }
        if (k > 0 && S[k - 1][l] == '.')
        {
            k_ -= 1;
        }
        if (now_dist[i_][j][k_][l] == -1)
        {
            now_dist[i_][j][k_][l] = dist;
            if (i_ == k_ && j == l)
            {
                cout << dist << endl;
                return 0;
            }
            q.push({i_, j, k_, l});
        }

        // 下
        i_ = i, k_ = k;
        if (i < N - 1 && S[i + 1][j] == '.')
        {
            i_ += 1;
        }
        if (k < N - 1 && S[k + 1][l] == '.')
        {
            k_ += 1;
        }
        if (now_dist[i_][j][k_][l] == -1)
        {
            now_dist[i_][j][k_][l] = dist;
            if (i_ == k_ && j == l)
            {
                cout << dist << endl;
                return 0;
            }
            q.push({i_, j, k_, l});
        }

        // 左
        int j_ = j, l_ = l;
        if (j > 0 && S[i][j - 1] == '.')
        {
            j_ -= 1;
        }
        if (l > 0 && S[k][l - 1] == '.')
        {
            l_ -= 1;
        }
        if (now_dist[i][j_][k][l_] == -1)
        {
            now_dist[i][j_][k][l_] = dist;
            if (i == k && j_ == l_)
            {
                cout << dist << endl;
                return 0;
            }
            q.push({i, j_, k, l_});
        }

        // 右
        j_ = j, l_ = l;
        if (j < N - 1 && S[i][j + 1] == '.')
        {
            j_ += 1;
        }
        if (l < N - 1 && S[k][l + 1] == '.')
        {
            l_ += 1;
        }
        if (now_dist[i][j_][k][l_] == -1)
        {
            now_dist[i][j_][k][l_] = dist;
            if (i == k && j_ == l_)
            {
                cout << dist << endl;
                return 0;
            }
            q.push({i, j_, k, l_});
        }
    }

    cout << -1 << endl;

    return 0;
}